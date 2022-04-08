#include "StringEditor.hpp"

StringEditor::StringEditor(std::string filename) : m_filename(filename)
{
    m_replaced_filename = filename + ".replace";
    m_fin.open(m_filename.c_str());
    if (!m_fin)
        handleError(ERR_WIOPEN, EXIT_FAILURE);
    m_fout.open(m_replaced_filename.c_str());
    if (!m_fout)
        handleError(ERR_WOOPEN, EXIT_FAILURE);
}

StringEditor::~StringEditor()
{
}
