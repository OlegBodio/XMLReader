#include "Section.hpp"

using namespace SS;

Section Section::getRoot(const std::string& filePath) const
{
	strings lines = Section::getLines(filePath);
	Section root;
	unsigned short length = lines.size();
	auto startLine = lines.begin();
	auto endLine = lines.end();
	root.getChilds(startLine, endLine);
	return root;
}

void Section::getChilds(strings::iterator startIter, strings::iterator endIter)
{
	auto nextLineIter = startIter + 1;
	while (nextLineIter != endIter)
	{
		if (isChild(*startIter, *nextLineIter))
		{
			auto child = fromLine(*nextLineIter);
			if(!isClosingTag(*nextLineIter))
			{
				child.getChilds(nextLineIter, std::find(nextLineIter, endIter, child.closeTag()));
			}
			addChild(child);
		}
		++nextLineIter;
	}
}

bool Section::isChild(const std::string& line, const std::string& childLine) const
{
	return ((countTabulations(childLine) - countTabulations(line)) == 1 && isOpeningTag(childLine));
}


// Little important 

Section::Section(const std::string& name, const std::string& value)
	: m_name(name)
	, m_value(value)
{}

Section Section::fromLine(const std::string& line)
{
	auto lineStart = line.begin();
	auto lineEnd = line.end() - END_OFFSET;
	auto closingTagIter = line.end();
	auto openingTagIter = line.begin();
	while (*openingTagIter != OPENING_TAG)
	{
		++openingTagIter;
	}
	++openingTagIter;
	while (*lineStart != CLOSING_TAG)
	{
		++lineStart;
	}

	if (isValueInLine(line))
	{
		while (*lineEnd != CLOSING_TAG)
		{
			--lineEnd;
		}
		if (isClosingTag(line))
		{
			--closingTagIter;
			while (*closingTagIter != SLASH)
			{
				--closingTagIter;
			}
			--closingTagIter;
		}
	}
	std::string tagName(openingTagIter, lineStart);
	std::string tagValue(lineEnd + 1, closingTagIter);
	return Section(tagName, tagValue);
}

void Section::addChild(const Section& child)
 {
	 m_childs.push_back(child);
 }

void Section::setValue(const std::string& value)
	{
		m_value = value;
	}

void Section::write(std::fstream& f, unsigned tab) const
	{
		f << toStr(tab);
	}

void Section::write(const std::string& path) const
	{
    std::fstream f(path);
    write(f,0);
	}

std::string Section::getName()
{
	return m_name;
}

std::string Section::getValue()
{
	return m_value;
}

bool Section::isClosingTag(const std::string& line)
{
	return std::regex_search(line, REGEX_CLOSING_TAG);
}

bool Section::isOpeningTag(const std::string& line)
{
	return std::regex_search(line, REGEX_OPENING_TAG);
}

bool Section::isTabulation(const std::string& line)
{
	return (*(line.begin()) == TAB);
}

bool Section::isValueInLine(const std::string& line)
{
	return std::regex_search(line, REGEX_VALUE_IN_LINE);
}

unsigned Section::countTabulations(const std::string& line) const
{
	return std::count(line.begin(), line.end(), TAB);
}

std::string Section::openTag() const
{
	return OPENING_TAG + m_name + CLOSING_TAG;
}

std::string Section::closeTag() const
{
	return OPENING_TAG_WITH_SLASH + m_name + CLOSING_TAG;
}

std::string Section::toStr(unsigned tab) const
{
	std::string str_s = "";
	if (m_childs.size() > 0)
	{
		str_s += tabulate(tab) + openTag() + m_value + "\n";
		for (auto child : m_childs)
		{
			str_s += child.toStr(tab + 1);
		}
		str_s += tabulate(tab) + closeTag() + "\n";
	}
	else
	{
		str_s += tabulate(tab) + openTag() + m_value + closeTag() + "\n";
	}
	return str_s;
}

std::string Section::tabulate(unsigned count) const
{
	std::string str_t;
	for (int i = 0; i < count; i++)
	{
		str_t += TAB;
	}
	return str_t;
}

strings Section::getLines(const std::string& filePath)
{
	std::vector<std::string> lines;
	std::fstream f(filePath);
	if (f.is_open())
	{
		std::string line;

		while (getline(f, line))
		{
			lines.push_back(line);
		}
	}

	return lines;
}
