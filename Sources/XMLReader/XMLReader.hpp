#include "Section.hpp" 

class XMLReader
{
public: 
XMLReader(const std::string& filePath); 
Section getRoot();

private:
std::string m_line;
std::string m_tagName; 
std::string m_value;
std::vector<std::string> m_lines; 
std::ifstream m_file;



void fillChilds(Section& root, const std::string& line, unsigned index); 

};

