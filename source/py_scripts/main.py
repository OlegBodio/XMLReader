from section_py_module import SectionPy

section = SectionPy('root')
childSection = SectionPy("child")
section.addChild(childSection)
section.setValue('test')
section.write('test.xml')