#pragma once
#ifndef _OBJECT_TYPE_H_
#define _OBJECT_TYPE_H_

/* Type Object for BaseObject. Contains a static list which has all the object types instanced so far.*/
#include <vector>
#include <string>
#include <SDL.h>

class ObjectType{
public :
	ObjectType(){}
	ObjectType(std::string texturePath, std::string id)
		:mTextureId(texturePath), mObjectId(id){
		mObjectTypes.push_back(this); 
	}
	std::string getTextureId() { return mTextureId; }
	std::string getObjectId() { return mObjectId; }
	static std::vector < ObjectType*> getObjectTypes() { return mObjectTypes; }
private:
	std::string mTextureId;
	std::string mObjectId;
	static std::vector<ObjectType*> mObjectTypes;
};
#endif // !_OBJECT_TYPE_H_