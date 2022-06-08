#ifdef _EASYFIND_HPP_

template <typename T> typename T::const_iterator easyfind(const T &container, const int find)
{
    return (std::find(container.begin(), container.end(), find));
}

#endif // _EASYFIND_HPP_
