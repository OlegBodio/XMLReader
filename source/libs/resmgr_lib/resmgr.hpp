#include "section.hpp"
#include<map>

class ResMgr
{
public:
	static ResMgr& getInstance();
	Section getSection(const std::string& filepath, bool addCache = true);

private:
	std::map<std::string, Section> m_cache;
	ResMgr(const ResMgr& other) = delete;
	ResMgr operator=(const ResMgr& other) = delete;
	ResMgr() = default;

};