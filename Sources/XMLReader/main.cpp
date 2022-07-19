#include "Section.hpp"
#include <iostream>
#include<regex>


int main() 
{
	
std::fstream f("root.xml");
Section root = Section("root");
Section firstChild = Section("firstChild");
firstChild.setValue("1"); 
root.addChild(firstChild);
Section secondChild = Section("secondChild");
secondChild.setValue("2");
Section test = Section("Test", "value in constr");
secondChild.addChild(test);
root.addChild(secondChild);
root.write("root.xml");
f.close();

auto fromLine = Section::fromLine;
Section rootf;
rootf = rootf.getRoot("../../Sources/XMLReader/data/root.xml");
std::cout << root.toStr();
rootf.write("../../Sources/XMLReader/data/new.xml");

}