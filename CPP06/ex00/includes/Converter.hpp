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
	char convertToChar() const;
};

#endif // _CONVERTER_HPP_