#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <cmath>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);
    ~ScalarConverter();

    static bool isChar(const std::string &str);
    static bool isInt(const std::string &str);
    static bool isFloat(const std::string &str);
    static bool isDouble(const std::string &str);
    static bool isPseudo(const std::string &str);

    static void fromChar(char c);
    static void fromInt(int n);
    static void fromFloat(float f);
    static void fromDouble(double d);
    static void fromPseudo(const std::string &str);

public:
    static void convert(const std::string &str);
};

#endif
