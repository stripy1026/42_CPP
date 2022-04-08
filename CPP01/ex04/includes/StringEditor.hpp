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
    std::string m_buffer;

  public:
    StringEditor(std::string filename);
    ~StringEditor();
};

#endif // _STRING_EDITOR_HPP_