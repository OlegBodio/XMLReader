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






void XMLReader::fillChilds(Section& root, const std::string& line, unsigned index)  
{
    /*
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
  */
}

Section XMLReader::getRoot()
{
  /*Section root = getSectionFromLine(m_lines[0]);
  fillChilds(root, m_lines[0], 0);
  return root;*/
    return Section();
}


