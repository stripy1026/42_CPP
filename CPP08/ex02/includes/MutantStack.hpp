#ifndef _MUTANT_STACK_HPP_
#define _MUTANT_STACK_HPP_

#include <stack>

template <typename T> class MutantStack : public std::stack<T>
{
  public:
    MutantStack();
    virtual ~MutantStack();
    MutantStack(const MutantStack &src);
    MutantStack &operator=(const MutantStack<T> &rhs);

    // typedef
    typedef typename std::stack<T>::container_type container_type;
    typedef typename container_type::iterator iterator;
    typedef typename container_type::const_iterator const_iterator;
    typedef typename container_type::reverse_iterator reverse_iterator;
    typedef typename container_type::const_reverse_iterator const_reverse_iterator;

    // iterators
    iterator begin(void);
    iterator end(void);
    const_iterator cbegin(void) const;
    const_iterator cend(void) const;
    reverse_iterator rbegin(void);
    reverse_iterator rend(void);
    const_reverse_iterator crbegin(void) const;
    const_reverse_iterator crend(void) const;
};

#include "MutantStack.tpp"

#endif // _MUTANT_STACK_HPP_
