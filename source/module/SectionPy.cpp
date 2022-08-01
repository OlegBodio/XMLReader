#include <pybind11/pybind11.h>
#include "SectionPy.hpp"

SectionPy::SectionPy(const std::string& name, const std::string& value)
	:root(name, value) 
	{}
void SectionPy::addChild(const Section& child) { root.addChild(child); }
void SectionPy::setValue(const std::string& value) { root.setValue(value); }
void SectionPy::write(const std::string& path) const { root.write(path); }
Section SectionPy::getRoot(const std::string& filePath) const { return root.getRoot(filePath); }
std::string SectionPy::getName() const { return root.getName(); }
std::string SectionPy::getValue() const { return root.getValue(); }

PYBIND11_MODULE(section_py_module, module)
{
	pybind11::class_<SectionPy>(module, "SectionPy")
		.def(pybind11::init<>())
		.def(pybind11::init<const std::string&, const std::string&>(), "constructor 2", pybind11::arg("name"), pybind11::arg("value") = "")
		.def("addChild", &SectionPy::addChild, pybind11::arg("child"))
		.def("setValue", &SectionPy::setValue, pybind11::arg("value"))
		.def("write", &SectionPy::write, pybind11::arg("path"))
		.def("getRoot", &SectionPy::getRoot, pybind11::arg("filePath"))
		.def("getName", &SectionPy::getName)
		.def("getValue", &SectionPy::getValue)
		;
}
