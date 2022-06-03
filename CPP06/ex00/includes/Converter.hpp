#ifndef _CONVERTER_HPP_
#define _CONVERTER_HPP_

#include <cstdlib>
#include <iostream>

#include "color.hpp"

class Converter
{
  private:
    const std::string m_input;
    std::string m_type;

    char m_char;
    int m_int;
    float m_float;
    double m_double;

    bool m_can_char;
    bool m_can_int;

    Converter();
    Converter(const Converter &src);
    Converter &operator=(const Converter &rhs);

    void m_detectType();

  public:
    ~Converter();

    Converter(const std::string &input);

    const std::string &getInput() const;
    const std::string &getType() const;

    void detectType();

    void printChar(std::ostream &o) const;
    void printInt(std::ostream &o) const;
    void printFloat(std::ostream &o) const;
    void printDouble(std::ostream &o) const;
};

std::ostream &operator<<(std::ostream &o, const Converter &converter);

#endif // _CONVERTER_HPP_
