#ifndef __ENTITY_INFO_H__
#define __ENTITY_INFO_H__

#include <iostream>
#include <string>

class EntityInfo
{
public:
	int _level;
	std::string _entityName;

	EntityInfo(int level, std::string entityName)
	{
		this->_entityName = entityName;
		this->_level = level;
	}
};

#endif // !__ENTITY_INFO_H__
