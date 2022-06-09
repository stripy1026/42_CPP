#ifndef _SPAN_HPP_
#define _SPAN_HPP_

#include <algorithm>
#include <ctime>
#include <exception>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

#include "color.hpp"

class Span
{
  private:
    unsigned int m_N;
    unsigned int m_size;
    std::vector<int> m_data;

    // Orthodox Canonical Class Form
    Span();

  public:
    // Orthodox Canonical Class Form
    ~Span();
    Span(const Span &src);
    Span &operator=(const Span &rhs);

    // Constructor
    Span(const unsigned int N);

    // Accessor
    const std::vector<int> &getData() const;

    // Other functions
    void addNumber(const int n);
    int shortestSpan() const;
    int longestSpan() const;
    void fillUsingIterRange(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last);

    // exceptions
    class sizeIsFull : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class notEnoughSize : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

#endif // _SPAN_HPP_
