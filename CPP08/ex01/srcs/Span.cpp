#include "Span.hpp"

Span::Span()
{
}

Span::~Span()
{
}

Span::Span(const Span &src)
{
    *this = src;
}

Span &Span::operator=(const Span &rhs)
{
    if (this == &rhs)
        return *this;
    m_data.clear();
    m_N = rhs.m_N;
    m_size = rhs.m_size;
    m_data = rhs.m_data;
    return *this;
}

Span::Span(const unsigned int N) : m_N(N), m_size(0)
{
}

void Span::addNumber(const int n)
{
    if (m_size >= m_N)
        throw Span::sizeIsFull();
    m_data.push_back(n);
    ++m_size;
}

const std::vector<int> &Span::getData() const
{
    return m_data;
}

int Span::longestSpan() const
{
    if (m_size < 2)
        throw Span::notEnoughSize();
    std::vector<int>::const_iterator min = std::min_element(m_data.begin(), m_data.end());
    std::vector<int>::const_iterator max = std::max_element(m_data.begin(), m_data.end());
    const long long res = static_cast<long long>(*max - *min);
    if (res < std::numeric_limits<int>::min() || res > std::numeric_limits<int>::max())
        std::cout << YELLOW "Warning : " RESET << "Span value is out of int range." << std::endl;
    return static_cast<int>(res);
}

int Span::shortestSpan() const
{
    std::vector<int> copy = m_data;
    long long res = std::numeric_limits<long long>::max();

    if (m_size < 2)
        throw Span::notEnoughSize();
    std::sort(copy.begin(), copy.end());
    for (std::vector<int>::const_iterator it = m_data.begin() + 1; it < m_data.end(); ++it)
        res = std::min(res, static_cast<long long>(*it - *(it - 1)));
    if (res < std::numeric_limits<int>::min() || res > std::numeric_limits<int>::max())
        std::cout << YELLOW "Warning : " RESET << "Span value is out of int range." << std::endl;
    return static_cast<int>(res);
}

void Span::addRandomPositiveNumbers(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last,
                                    const int max_value)
{
    if (max_value < 1)
    {
        std::cout << RED "Error : " RESET << "(in func : addRandomPositiveNumbers) use int bigger than 1." << std::endl;
        return;
    }
    for (std::vector<int>::const_iterator it = first; it < last; ++it)
        addNumber(rand() % max_value);
}

const char *Span::sizeIsFull::what() const throw()
{
    return "Size is full.";
}

const char *Span::notEnoughSize::what() const throw()
{
    return "Not enough size to span.";
}
