#pragma once
#ifndef _CREATE_OBJECT_TYPES_H_
#define _CREATE_OBJECT_TYPES_H_

#include "ObjectType.h"

class CreateObjectTypes
{
public:
	CreateObjectTypes()
	{
		ObjectType* playerType = new ObjectType("dot", "player");
		ObjectType* treeType = new ObjectType("tree1", "tree");
	}
};
#endif // !_CREATE_OBJECT_TYPES_H_
