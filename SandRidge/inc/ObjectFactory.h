#pragma once
#ifndef _OBJECT_FACTORY_H_
#define _OBJECT_FACTORY_H_

/* Class which creates object based on the id passed by the map generator.
Also makes sure that each object type is only initilialised once so that the list of object types is as short as possible.
perhaps map generator should be responsible for this.
TODO implement this
*/
#include "BaseObject.h"
#include "ResourceManager.h"

class ObjectFactory
{
public:
	static ObjectFactory* instance();

	BaseObject* createObject(std::string id,int posX, int posY);
private:
	static ObjectFactory* mInstance;
	ObjectFactory();
	~ObjectFactory();
};
#endif // !_OBJECT_FACTORY_H_
