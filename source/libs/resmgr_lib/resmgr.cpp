#include "resmgr.hpp"

ResMgr& ResMgr::getInstance()
{
	static ResMgr instance;
	return instance;
}