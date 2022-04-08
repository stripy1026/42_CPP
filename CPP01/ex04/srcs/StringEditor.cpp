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

void StringEditor::m_replaceRecursive(std::string s1, std::string s2, std::string buffer)
{
    size_t pos;

    pos = buffer.find(s1);
    if (pos == std::string::npos)
        m_fout << buffer << std::endl;
    else
    {
        m_fout << buffer.substr(0, pos);
		m_fout << s2;
		m_replaceRecursive(s1, s2, buffer.substr(pos + s1.size()));
    }
}

void StringEditor::replace(std::string s1, std::string s2)
{
    std::string buffer;

    while (getline(m_fin, buffer))
        m_replaceRecursive(s1, s2, buffer);
}