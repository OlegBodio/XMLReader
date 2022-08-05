#include <pybind11/pybind11.h>
#include<pybind11/stl_bind.h>
#include "SectionPy.hpp"

PYBIND11_MAKE_OPAQUE(std::vector<std::string>);

SectionPy::SectionPy(const std::string& name, const std::string& value)
	:m_root(name, value) 
	{}

SectionPy::SectionPy(const Section& root):m_root(root)
{}

Section SectionPy::getSection() const { return m_root; }

void SectionPy::addChild(const SectionPy& child) 
{ 
	m_root.addChild(child.getSection()); 
}

void SectionPy::setValue(const std::string& value) { m_root.setValue(value);}

void SectionPy::write(const std::string& path) const { m_root.write(path); }

SectionPy SectionPy::getRoot(const std::string& filePath) const { return m_root.getRoot(filePath); }

std::string SectionPy::getName() const { return m_root.getName(); }
std::string SectionPy::getValue() const { return m_root.getValue(); }
void SectionPy::operator=(const SectionPy& other)
{
	m_root = other.m_root;
}





PYBIND11_MODULE(section_py_module, module)
{
	pybind11::bind_vector<std::vector<std::string>>(module, "VectorStr");

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
