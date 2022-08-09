#include "resmgr.hpp"

ResMgr& ResMgr::getInstance()
{
	static ResMgr instance;
	return instance;
}

Section ResMgr::getSection(const std::string& filepath)
{
	if (!isSection(filepath))
	{
		addSection(filepath);
	}
	return m_cache.find(filepath)->first;
}

void ResMgr::addSection(const std::string& filepath)
{
	m_cache[filepath] = Section().getRoot(filepath);
}

bool ResMgr::isSection(const std::string& filepath) const
{
	return m_cache.count(filepath);
}