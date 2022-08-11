#include "resmgr.hpp"
#include <string>

class SectionPy
{
private:
	Section m_root;
	Section getSection() const;
	SectionPy(const Section& root);
public:
	SectionPy() = default;
	SectionPy(const std::string& name, const std::string& value);
	void addChild(const SectionPy& child);
	void setValue(const std::string& value);
	void write(const std::string& path) const;
	SectionPy getRoot(const std::string& filePath, bool addCache = true) const;
	std::string getName() const;
	std::string getValue() const;
	void operator=(const SectionPy& other);
};
