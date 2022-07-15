#include "XMLReader.hpp"
#include <iostream>
#include<regex>


int main() 
{
	/*
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
*/
auto fromLine = Section::fromLine;
Section root;
root = root.getRoot("../../Sources/XMLReader/data/root.xml");
std::cout << root.toStr();
root.write("../../Sources/XMLReader/data/new.xml");
//const std::string line = "<root>1";

}