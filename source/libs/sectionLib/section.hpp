#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include<regex>

using strings = std::vector<std::string>;

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
const std::regex REGEX_VALUE_IN_LINE(">[A-Za-z0-9]{1,}");
}

class Section
{
public: 
	Section() = default;
	Section(const std::string& name, const std::string& value = "");
	void addChild(const Section& child);
	void setValue(const std::string& value); 
	void write(const std::string& path) const;
	Section getRoot(const std::string& filePath) const;
	
	std::string getName() const;
	std::string getValue() const;

private:
	std::string m_name = "root";
	std::string m_value = "";
	std::vector<Section> m_childs;
	std::string toStr(unsigned tab = 0) const;
	void write(std::fstream& f, unsigned tab) const; 
	std::string tabulate(unsigned count = 0) const;
	std::string openTag() const;
	std::string closeTag() const;
	void getChilds(strings::iterator startIter, strings::iterator endIter);
	bool isChild(const std::string& line, const std::string& childLine) const;
	unsigned countTabulations(const std::string& line) const;
	static bool isValueInLine(const std::string& line);
	static bool isClosingTag(const std::string& line);
	static bool isOpeningTag(const std::string& line);
	static bool isTabulation(const std::string& line);
	static strings getLines(const std::string& filePath);
	static Section fromLine(const std::string& line);
};


