#include <pybind11/embed.h>
#include "section.hpp"
#include "Python.h"
#include <iostream>

namespace py = pybind11;

int main ()
{
    auto pathRoot = Section("root").getRoot("../source/data/paths.xml");
    py::scoped_interpreter python;
    auto sys = py::module_::import("sys");
    auto& append = sys.attr("path").attr("append");
    for (auto child : pathRoot.childs())
    {
        append(child.getValue());
    }
    py::object main = py::module_::import("main");
  
    return 0;
}
