#ifndef _ARRAY_TPP_
#define _ARRAY_TPP_

#include <exception>

template <typename T> class Array
{
  private:
    T *m_data;
    unsigned int m_size;

  public:
    // Orthodox Canonical Class Form
    Array();
    ~Array();
    Array(const Array<T> &src);
    Array<T> &operator=(const Array<T> &rhs);

    // Constructors
    Array(const unsigned int n);

    // Accessors
    T &operator[](const unsigned int i) const;

    // Other functions
    unsigned int size() const;

    // Exceptions
    class OutOfRange : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

template <typename T> Array<T>::Array() : m_data(NULL), m_size(0)
{
}

template <typename T> Array<T>::~Array()
{
    delete[] m_data;
}

template <typename T> Array<T>::Array(const Array<T> &src) : m_data(NULL), m_size(0)
{
    *this = src;
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
    if (this == &rhs)
        return (*this);
    if (m_size)
        delete[] m_data;
    m_size = rhs.m_size;
    m_data = new T[m_size];
    for (unsigned int i = 0; i < m_size; ++i)
        m_data[i] = rhs.m_data[i];
    return (*this);
}

template <typename T> Array<T>::Array(const unsigned int n) : m_data(new T[n]()), m_size(n)
{
}

template <typename T> T &Array<T>::operator[](const unsigned int i) const
{
    if (m_size <= i)
        throw OutOfRange();
    return (m_data[i]);
}

template <typename T> unsigned int Array<T>::size() const
{
    return m_size;
}

template <typename T> const char *Array<T>::OutOfRange::what() const throw()
{
    return ("index is out of range.");
}

// external functions

template <typename T> std::ostream &operator<<(std::ostream &o, const Array<T> &array)
{
    unsigned int max = 5;

    o << "[" << array.size() << "] ";
    for (unsigned int i = 0; i < array.size() && i < max; i++)
        o << array[i] << " ";
    if (max < array.size())
        o << "...";
    o << std::endl;
    return (o);
}

#endif // _ARRAY_TPP_
