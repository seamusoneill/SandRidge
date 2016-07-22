#include "Subject.h"
#include <algorithm>
using namespace std;

Subject::Subject()
{
}


Subject::~Subject()
{
}

void Subject::Attach(Observer *o)//attaches observer to the subject
{
	list.push_back(o);
}
void Subject::Detach(Observer *o)//detaches observer from the subject
{
	list.erase(std::remove(list.begin(), list.end(), o), list.end());
}

void Subject::Notify(int val)//notifies list of observers of change
{
	for (vector<Observer*>::const_iterator iter = list.begin(); iter != list.end(); ++iter){
		if (*iter != 0){
			(*iter)->onNotify(val);
		}
	}
}