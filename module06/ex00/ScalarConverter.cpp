#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string &str)
{
    return (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
}

bool ScalarConverter::isInt(const std::string &str)
{
    if (str.empty())
        return false;

    size_t i;
    bool neg;
    
    neg = false;
    i = 0;
    if (str[i] == '+' || str[i] == '-')
    {
        neg = (str[i] == '-');
        i++;
        if (i == str.size())
            return false;
    }

    long long value;
    value = 0;

    for (; i < str.size(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;

        int digit = str[i] - '0';

        if (!neg && (value > (INT_MAX - digit) / 10))
            return false;

        if (neg && (-value < (INT_MIN + digit) / 10))
            return false;

        value = value * 10 + digit;
    }
    return true;
}



bool ScalarConverter::isFloat(const std::string &str)
{
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return true;

    if (str.empty())
        return false;

    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;

    bool dot;
    int digits;
    digits = 0;
    dot = false;

    for (; i < str.size(); i++)
    {
        if (str[i] == '.')
        {
            if (dot)
                return false;
            dot = true;
        }
        else if (std::isdigit(str[i]))
            digits++;
        else if (str[i] == 'f' && i == str.size() - 1)
            break;
        else
            return false;
    }

    if (digits == 0)
        return false;

    return dot;
}



bool ScalarConverter::isDouble(const std::string &str)
{
    if (str == "nan" || str == "+inf" || str == "-inf")
        return true;

    if (str.empty())
        return false;

    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;

    bool dot = false;
    int digits = 0;

    for (; i < str.size(); i++)
    {
        if (str[i] == '.')
        {
            if (dot)
                return false;
            dot = true;
        }
        else if (std::isdigit(str[i]))
        {
            digits++;
        }
        else
            return false;
    }

    if (digits == 0)
        return false;

    return dot;
}


bool ScalarConverter::isPseudo(const std::string &str)
{
    return (str == "nan"  || str == "+inf"  || str == "-inf" ||
            str == "nanf" || str == "+inff" || str == "-inff");
}


void ScalarConverter::fromChar(char c)
{
    std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << "\n";
}

void ScalarConverter::fromInt(int n)
{
    if (n >= 32 && n <= 126)
        std::cout << "char: '" << static_cast<char>(n) << "'\n";
    else if (n >= 0 && n <= 255)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: impossible\n";

    std::cout << "int: " << n << "\n";

    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(n) << "f\n";

    std::cout << "double: " << std::fixed << std::setprecision(1)
              << static_cast<double>(n) << "\n";
}


void ScalarConverter::fromFloat(float f)
{
    if (std::isnan(f) || std::isinf(f))
        std::cout << "char: impossible\n";
    else if (f >= 32 && f <= 126)
        std::cout << "char: '" << static_cast<char>(f) << "'\n";
    else if (f >= 0 && f <= 255)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: impossible\n";

    if (std::isnan(f) || std::isinf(f) || f > 2147483647.0f || f < -2147483648.0f)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(f) << "\n";

    std::cout << "float: " << std::fixed << std::setprecision(1)
              << f << "f\n";

    std::cout << "double: " << std::fixed << std::setprecision(1)
              << static_cast<double>(f) << "\n";
}


void ScalarConverter::fromDouble(double d)
{
    if (std::isnan(d) || std::isinf(d))
        std::cout << "char: impossible\n";
    else if (d >= 32 && d <= 126)
        std::cout << "char: '" << static_cast<char>(d) << "'\n";
    else if (d >= 0 && d <= 255)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: impossible\n";

    if (std::isnan(d) || std::isinf(d) || d > 2147483647.0 || d < -2147483648.0)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(d) << "\n";

    if (std::isnan(d) || std::isinf(d))
    {
        std::cout << "float: " << static_cast<float>(d) << "f\n";
    }
    else if (d > 3.402823466e+38 || d < -3.402823466e+38)
    {
        std::cout << "float: impossible\n";
    }
    else
    {
        std::cout << "float: " << std::fixed << std::setprecision(1)
                  << static_cast<float>(d) << "f\n";
    }
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
}


void ScalarConverter::fromPseudo(const std::string &str)
{
    if (str == "nan" || str == "nanf")
        std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";

    else if (str == "+inf" || str == "+inff")
        std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n";

    else if (str == "-inf" || str == "-inff")
        std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
}



void ScalarConverter::convert(const std::string &str) 
{
    if (isPseudo(str))
        return fromPseudo(str);
    if (isChar(str))
        return fromChar(str[0]);
    if (isInt(str))
        return fromInt(std::atoi(str.c_str()));
    if (isFloat(str))
        return fromFloat(std::atof(str.c_str()));
    if (isDouble(str))
        return fromDouble(std::atof(str.c_str()));

    std::cout << "Error: invalid literal\n";
}
