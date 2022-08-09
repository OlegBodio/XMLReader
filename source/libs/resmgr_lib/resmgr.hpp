#include "section.hpp"
#include<map>

class ResMgr
{
private:
	std::map<std::string, Section> m_cache;
	ResMgr(const ResMgr& other) = delete;
	ResMgr operator=(const ResMgr& other) = delete;
	ResMgr() = default;

public:
	ResMgr& getInstance()
	{
		static ResMgr instance;
		return instance;
	}
};