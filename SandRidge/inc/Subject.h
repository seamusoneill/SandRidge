#pragma once
#include <vector>
#include <list>
#include "Observer.h"

class Subject
{
public:
	Subject();
	~Subject();
	std::vector<Observer*> list;//observers
	void Attach(Observer* o);
	void Detach(Observer* o);
	void Notify(int num);
};
