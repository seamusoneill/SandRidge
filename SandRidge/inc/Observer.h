#pragma once
#ifndef _OBSERVER_H_
#define _OBSERVER_H_
class Observer
{
public:
	virtual void onNotify(int val) = 0;
};
#endif// !_OBSERVER_H_
