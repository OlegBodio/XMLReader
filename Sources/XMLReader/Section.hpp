#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include<regex>

namespace SS 
{ 
const char OPENING_TAG = '<'; 
const char CLOSING_TAG = '>';
const char SLASH = '/';
const std::string OPENING_TAG_WITH_SLASH = "</";
const char TAB = '\t'; 
const unsigned short END_OFFSET = 2;
const std::regex REGEX_CLOSING_TAG("</[A-Za-z0-9]{1,}>"); 
const std::regex REGEX_OPENING_TAG("<[A-Za-z0-9]{1,}>");
}

class Section
{
public: 
	Section() = default;
	Section(const std::string& name, const std::string& value = "");
	void addChild(const Section& child);
	void setValue(const std::string& value); 
	void write(const std::string& path) const;
  std::string toStr(unsigned tab = 0) const;

private:
	std::string m_name = "root";
	std::string m_value = "";
	std::vector<Section> m_childs;
  void write(std::fstream& f, unsigned tab) const; 
	std::string tabulate(unsigned count = 0) const;
	std::string openTag() const;
	std::string closeTag() const;
	
};
//a
