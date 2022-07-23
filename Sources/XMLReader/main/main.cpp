#include "Section.hpp"
#include <iostream>
#include<regex>


int main() 
{

std::fstream f("../../../Data/root.xml");
if (f.is_open())
{
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
}

Section rootf;
rootf = rootf.getRoot("../../../Data/root.xml");
rootf.write("../../../Data/new.xml");
}