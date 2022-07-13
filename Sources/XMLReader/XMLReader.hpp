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

bool isClosingTag(const std::string& line) const; 
bool isOpeningTag(const std::string& line) const; 
bool isTabulation(const std::string& line) const;
bool isValueInLine(const std::string& line) const;
bool isChild(const std::string& line, const std::string& childLine) const;
void fillChilds(Section& root, const std::string& line, unsigned index); 
unsigned countTabulations(const std::string& line) const;
Section getSectionFromLine(const std::string& line) const;
};