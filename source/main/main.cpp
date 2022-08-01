#include <pybind11/embed.h>
#include "section.hpp"
#include "Python.h"

namespace py = pybind11;

int main ()
{
    py::scoped_interpreter python;
    auto sectionPy = py::module_::import("main.py");
    return 0;
}
