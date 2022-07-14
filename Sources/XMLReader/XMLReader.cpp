#include <algorithm> 
#include "XMLReader.hpp"

using namespace SS;

//git are you here?

XMLReader::XMLReader(const std::string& filePath)
: m_file(filePath) 
{
  std::string line;
  while(getline(m_file, line))
  { 
    m_lines.push_back(line);
  }
}

bool XMLReader::isClosingTag(const std::string& line) const
{ 
	return std::regex_match(line, REGEX_CLOSING_TAG);
}

bool XMLReader::isOpeningTag(const std::string& line) const
{
	return std::regex_match(line, REGEX_OPENING_TAG);
}

bool XMLReader::isTabulation(const std::string& line) const
{
  return (*(line.begin()) == TAB);
}

bool XMLReader::isValueInLine(const std::string& line) const
{
  if(isOpeningTag(line))
  {
    if(isClosingTag(line))
    {
      return true;
    }
    else
    {
      return (*(--line.end()) != CLOSING_TAG);
    }
  }
  return false;
}

unsigned XMLReader::countTabulations(const std::string& line) const
{
  return std::count(line.begin(), line.end(), TAB);
}

bool XMLReader::isChild(const std::string& line, const std::string& childLine) const
{
  return (countTabulations(childLine) - countTabulations(line)) == 1; 
}

Section XMLReader::getSectionFromLine(const std::string& line) const
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
    while(*lineEnd != CLOSING_TAG) 
    {
      --lineEnd;
    }
    if (isClosingTag(line))
    {
    --closingTagIter;
    while(*closingTagIter != SLASH) 
      {
        --closingTagIter;
      }
    --closingTagIter;
    }
  }
  std::string tagName(openingTagIter, lineStart);
  std::string tagValue(lineStart + 1, closingTagIter);
  return Section(tagName, tagValue);
}

void XMLReader::fillChilds(Section& root, const std::string& line, unsigned index)  
{
  unsigned length = m_lines.size();  
  for (unsigned i = index; i < length - 2; ++i)
  {
    std::string line = m_lines[i]; 
    for (unsigned j = i + 1; j < length - 1; ++j)
    {
      std::string nextLine = m_lines[j]; 
      if(isChild(line, nextLine))
      {
        if(isChild(nextLine, m_lines[j + 1]))
        { 
          Section child = getSectionFromLine(nextLine); 
          fillChilds(child, nextLine, j); 
          root.addChild(child); 
        }
        else
        {
          Section child = getSectionFromLine(nextLine); 
          root.addChild(child);
          continue;
        }
      }
    }
  }
}

Section XMLReader::getRoot()
{
  Section root = getSectionFromLine(m_lines[0]);
  fillChilds(root, m_lines[0], 0);
  return root;
}


