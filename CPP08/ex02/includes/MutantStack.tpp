#ifdef _MUTANT_STACK_HPP_

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
    return (this->c.begin());
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
    return (this->c.end());
}

template <typename T> typename MutantStack<T>::const_iterator MutantStack<T>::cbegin(void) const
{
    return (this->c.cbegin());
}

template <typename T> typename MutantStack<T>::const_iterator MutantStack<T>::cend(void) const
{
    return (this->c.cend());
}

template <typename T> typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void)
{
    return (this->c.rbegin());
}

template <typename T> typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void)
{
    return (this->c.rend());
}

template <typename T> typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin(void) const
{
    return (this->c.crbegin());
}

template <typename T> typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend(void) const
{
    return (this->c.crend());
}

template <typename T> MutantStack<T>::MutantStack() : MutantStack<T>::stack()
{
}

template <typename T> MutantStack<T>::~MutantStack()
{
}

template <typename T> MutantStack<T>::MutantStack(const MutantStack<T> &src) : MutantStack<T>::stack(src)
{
}

template <typename T> MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &rhs)
{
    if (this != &rhs)
        MutantStack<T>::stack::operator=(rhs);
    return (*this);
}

#endif // _MUTANT_STACK_HPP_
