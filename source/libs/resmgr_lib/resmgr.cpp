#include "resmgr.hpp"

ResMgr& ResMgr::getInstance()
{
	static ResMgr instance;
	return instance;
}

Section ResMgr::getSection(const std::string& filepath, bool addCache)
{
	if (!(m_cache.count(filepath)))
	{
		if(addCache)
		{
			auto section = Section().getRoot(filepath);
			m_cache[filepath] = section;
			return section;
		}
		else
		{
			return Section().getRoot(filepath);
		}	
	}
	else
	{
		return m_cache.find(filepath)->second;
	}
}
