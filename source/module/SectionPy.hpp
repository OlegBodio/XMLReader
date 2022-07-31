#include "section.hpp"

class SectionPy
{
private:
	Section root;

public:
	SectionPy() = default;
	SectionPy(const std::string& name, const std::string& value = "");
	void addChild(const Section& child);
	void setValue(const std::string& value);
	void write(const std::string& path) const;
	Section getRoot(const std::string& filePath) const;
	std::string getName() const;
	std::string getValue() const;
};