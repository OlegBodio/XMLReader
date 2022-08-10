#include "resmgr.hpp"

ResMgr& ResMgr::getInstance()
{
	static ResMgr instance;
	return instance;
}

Section ResMgr::getSection(const std::string& filepath)
{
	if (!(m_cache.count(filepath)))
	{
		m_cache[filepath] = Section().getRoot(filepath);
	}
	return m_cache.find(filepath)->first;
}
