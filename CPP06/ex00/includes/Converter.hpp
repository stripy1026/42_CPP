#ifndef _CONVERTER_HPP_
#define _CONVERTER_HPP_

#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>

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
    bool m_can_float;
    bool m_is_erange;

    Converter();
    Converter(const Converter &src);
    Converter &operator=(const Converter &rhs);

    void m_detectType();
    void m_convertChar();
    void m_convertInt();
    void m_convertFloat();
    void m_convertDouble();

  public:
    ~Converter();

    Converter(const std::string &input);

    const std::string &getInput() const;
    const std::string &getType() const;
    const bool &getIsErange() const;

    void detectType();

    void printChar(std::ostream &o) const;
    void printInt(std::ostream &o) const;
    void printFloat(std::ostream &o) const;
    void printDouble(std::ostream &o) const;
};

std::ostream &operator<<(std::ostream &o, const Converter &converter);

#endif // _CONVERTER_HPP_
