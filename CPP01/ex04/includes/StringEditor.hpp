#ifndef _STRING_EDITOR_HPP_
#define _STRING_EDITOR_HPP_

#include <fstream>

#include "handleError.hpp"

class StringEditor
{
  private:
    std::ifstream m_fin;
    std::ofstream m_fout;
    std::string m_filename;
    std::string m_replaced_filename;

    void m_replaceRecursive(std::string s1, std::string s2, std::string buffer);

  public:
    StringEditor(std::string filename);
    ~StringEditor();

    void replace(std::string s1, std::string s2);
};

#endif // _STRING_EDITOR_HPP_