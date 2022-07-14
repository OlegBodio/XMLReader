#include "Section.hpp"

using namespace SS;

std::string Section::tabulate(unsigned count) const
{
	std::string str_t;
	for (int i = 0; i < count; i++)
	{
		str_t += TAB; 
	}
	return str_t;
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

Section::Section(const std::string& name, const std::string& value)
	: m_name(name)
	, m_value(value)
{}

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