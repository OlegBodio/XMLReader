#include "XMLReader.hpp"
#include <iostream>

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

XMLReader reader("data/root.xml");
auto rootAfterRead = reader.getRoot();
std::cout<<rootAfterRead.toStr();
rootAfterRead.write("data/new.xml");
}