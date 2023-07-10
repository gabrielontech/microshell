#include "../includes/ScalarConverter.hpp"


#include <cmath>
#include <iostream>
#include <sstream>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
  *this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
  if (this != &rhs) {
    // Do the copy
  }
  return *this;
}


void ScalarConverter::convert(const std::string& literal) {

  if (literal.size() == 1 && std::isprint(literal[0]) && !isdigit(literal[0])) {
    // char literal
    char value = literal[0];
    std::cout << "char: " << value << std::endl;

    int intValue = static_cast<int>(value);
    if (!std::isprint(intValue)) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << intValue << std::endl;
    }

    float floatValue = static_cast<float>(value);
    if (!std::isprint(floatValue)) {
        std::cout << "float: impossible" << std::endl;
    } else {
        std::cout << "float: " << floatValue << ".0f" << std::endl;
    }

    double doubleValue = static_cast<double>(value);
    if (!std::isprint(doubleValue)) {
         std::cout << "double: impossible" << std::endl;
    } else {
    std::cout << "double: " << doubleValue << ".0" << std::endl;
    }

  } else if ((literal.find('.') != std::string::npos ||
             literal.find('f') != std::string::npos) || (literal == "nan" || literal == "nanf")
             || (literal == "-inf" || literal == "-inff") || (literal == "+inf" || literal == "+inff")
             ) {
    // float or double literal
    // Handle special pseudo-literals (-inff, +inff, nanf)
    if (literal == "-inff" || literal == "-inf") {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      std::cout << "float: " << -std::numeric_limits<float>::infinity() << "f" <<  std::endl;
      std::cout << "double: "<< -std::numeric_limits<double>::infinity() << std::endl;
    } else if (literal == "+inff" || literal == "+inf") {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      std::cout << "float: "<< std::numeric_limits<float>::infinity() << "f" << std::endl;
      std::cout << "double: " << std::numeric_limits<double>::infinity() << std::endl;
    } else if (literal == "nanf" || literal == "nan") {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      std::cout << "float: " << std::numeric_limits<float>::quiet_NaN() << "f"<< std::endl;
      std::cout << "double:" << std::numeric_limits<double>::quiet_NaN() << std::endl;
    } else {
      // Conversion of float or double
      // Handle conversions and overflows
      std::stringstream ss(literal);
      float floatValue;
      ss >> floatValue;
      if (ss.fail()) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
      } else {
        std::cout << "char: "<<  static_cast<char>(floatValue) << std::endl;
        std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
        std::cout << "float: " << floatValue << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(floatValue) << ".0"<< std::endl;
      }
    }
  } else {
    // int literal
    std::stringstream ss(literal);
    int intValue;
    ss >> intValue;
    if (ss.fail()) {
     std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    } else {
        if (intValue >= std::numeric_limits<char>::min() && intValue <= std::numeric_limits<char>::max()) {
    std::cout << "char: Not displayable" << std::endl;
} else {
   std::cout << "char: " << static_cast<char>(intValue) << std::endl;
}
    std::cout << "int: " << intValue << std::endl;
    std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(intValue) << ".0"<<std::endl;
    }
  }
}