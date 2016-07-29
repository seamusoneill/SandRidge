#include "ObjectFactory.h"

ObjectFactory* ObjectFactory::mInstance = 0;

std::vector<ObjectType*> ObjectType::mObjectTypes;

ObjectFactory* ObjectFactory::instance(){
	if (mInstance == 0)
		ObjectFactory();
	return mInstance;
}

ObjectFactory::ObjectFactory()
{
}

ObjectFactory::~ObjectFactory()
{
}

BaseObject* ObjectFactory::createObject(std::string id, int posX, int posY)
{
	BaseObject* obj = new BaseObject();

	for (int i = 0; ObjectType::getObjectTypes().size(); ++i)
	{
		if (id == ObjectType::getObjectTypes()[i]->getObjectId())
		{
			obj->initialise(ObjectType::getObjectTypes()[i], posX, posY);
		}
	}

	return obj;
}