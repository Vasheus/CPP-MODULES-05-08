# This project has been created as part of the 42 curriculum.

# C++ Modules (05 → 08)

## Description

This repository contains a series of C++ exercises from the 42 curriculum (Modules 05 to 08).

These modules focus on advanced object-oriented programming concepts, including exception handling, class design, inheritance hierarchies, polymorphism, type casting, templates, and STL containers.

The goal is to strengthen modern C++ skills by building structured systems that simulate real-world programming patterns such as bureaucratic workflows, type conversion systems, and generic data structures.

---

## Topics Covered

- Exception handling and custom exceptions
- Class design and encapsulation
- Abstract classes and interfaces
- Inheritance and polymorphism
- Runtime type identification and casting
- Static methods and utility classes
- Function and class templates
- STL containers and iterators
- Algorithmic thinking with generic programming

---

## Project Structure

Each module is independent and builds on previous concepts:

Module05/
Module06/
Module07/
Module08/


---

## Concepts Overview

### Module 05 – Repetition and Exceptions

Introduction to robust class design and exception handling in a bureaucratic system simulation.

- Custom exception classes  
- Grade-based validation system  
- Bureaucrat and Form interactions  
- Abstract forms and execution workflow  
- Intern-based form creation  

Small systems include:
- Bureaucrat management
- Form signing and execution workflow
- Office simulation with error handling

---

### Module 06 – C++ Casts

Focus on type conversion, serialization, and runtime type identification.

- Scalar type conversion (char, int, float, double)  
- Handling pseudo-literals (nan, inf, -inf)  
- Pointer serialization and deserialization  
- Runtime type identification without RTTI utilities  

Exercises include:
- ScalarConverter (type conversion system)
- Serializer (pointer ↔ integer conversion)
- Base/A/B/C type identification system

---

### Module 07 – C++ Templates

Introduction to generic programming and reusable code design.

- Function templates (swap, min, max)  
- Generic iteration over arrays  
- Class templates  
- Type-safe reusable algorithms  

Core idea:  
Design flexible code that works with any type while preserving type safety.

Exercises include:
- Generic utility functions
- Iteration over arrays with function templates
- Custom dynamic array implementation

---

### Module 08 – STL Containers & Algorithms

Advanced usage of STL and container-based programming.

- Generic search algorithms  
- Span computation over datasets  
- Custom iterable stack implementation  
- STL iterators  

Core idea:  
Extend and utilize STL containers to build efficient and reusable structures.

Exercises include:
- easyfind (generic container search)
- Span (range analysis on integers)
- MutantStack (iterable stack)

---

## Notes

- Memory management is carefully handled (no leaks expected)  
- Code follows 42 Norm rules when applicable  
- Each module builds progressively on previous concepts  
- Strong focus on exception safety and robust design  
- Emphasis on understanding modern C++ architecture  