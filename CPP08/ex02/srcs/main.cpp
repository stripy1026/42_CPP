#include <iomanip>
#include <iostream>
#include <list>
#include <vector>

#include "MutantStack.hpp"
#include "color.hpp"

#define SIZE 52

static void printTitle(std::string title, bool toUpper = true)
{
    static int first;
    std::string toPrint;
    unsigned int size = (SIZE > 10 ? SIZE : 10);
    char c = '=';
    unsigned int n;

    if (first > 0)
        std::cout << std::endl;
    else
        first++;

    toPrint = " " + title + " ";
    if (toUpper)
    {
        for (int i = 0; toPrint[i]; i++)
            toPrint[i] = toupper(toPrint[i]);
    }
    n = toPrint.size();
    if (n > size)
    {
        toPrint = toPrint.substr(0, size - 2);
        toPrint[size - 4] = '.';
        toPrint[size - 3] = ' ';
        n = toPrint.size();
    }
    std::cout << std::setfill(c) << std::setw(size) << "" << std::endl;
    std::cout << std::setw(size / 2) << toPrint.substr(0, n / 2);
    std::cout << toPrint.substr(n / 2, n - n / 2);
    std::cout << std::setfill(c) << std::setw(size - size / 2 - n + n / 2) << "" << std::endl;
    std::cout << std::setfill(c) << std::setw(size) << "" << std::endl;
}

int main(void)
{

    // subject test
    printTitle("mutant stack test");

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << YELLOW "top : " RESET << mstack.top() << std::endl;

    mstack.pop();
    std::cout << YELLOW "top : " RESET << mstack.top() << std::endl;
    std::cout << YELLOW "size : " RESET << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();

    for (; it != mstack.end(); it++)
    {
        std::cout << YELLOW "value : " RESET << *it << std::endl;
    }

    printTitle("list test");

    std::list<int> list;

    list.push_back(5);
    list.push_back(17);

    std::cout << YELLOW "top : " RESET << list.back() << std::endl;

    list.pop_back();
    std::cout << YELLOW "top : " RESET << list.back() << std::endl;
    std::cout << YELLOW "size : " RESET << list.size() << std::endl;

    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    std::list<int>::iterator l_it = list.begin();

    for (; l_it != list.end(); l_it++)
    {
        std::cout << YELLOW "value : " RESET << *l_it << std::endl;
    }

    printTitle("copy constructor test");
    MutantStack<int> s_copy(mstack);
    MutantStack<int> s_oper = mstack;

    s_copy.pop();
    s_copy.pop();
    s_copy.pop();
    s_copy.push(42);
    s_copy.push(43);
    s_copy.push(44);

    MutantStack<int>::iterator c_iter = s_copy.begin();
    for (; c_iter != s_copy.end(); c_iter++)
    {
        std::cout << YELLOW "value : " RESET << *c_iter << std::endl;
    }

    printTitle("copy assginment operator test");

    s_oper.pop();
    s_oper.pop();
    s_oper.pop();
    s_oper.push(52);
    s_oper.push(53);
    s_oper.push(54);

    MutantStack<int>::iterator o_iter = s_oper.begin();
    for (; o_iter != s_oper.end(); o_iter++)
    {
        std::cout << YELLOW "value : " RESET << *o_iter << std::endl;
    }

    printTitle("reverse iterator test");
    MutantStack<int> reverse;
    reverse.push(1);
    reverse.push(2);
    reverse.push(3);
    reverse.push(4);
    reverse.push(5);

    MutantStack<int>::reverse_iterator r_iter = reverse.rbegin();

    for (; r_iter != reverse.rend(); r_iter++)
    {
        std::cout << YELLOW "value : " RESET << *r_iter << std::endl;
    }

    return 0;
}
