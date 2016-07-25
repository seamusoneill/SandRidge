#include "Subject.h"
using namespace std;

Subject::Subject()
{
}


Subject::~Subject()
{
}

void Subject::Attach(Observer *o)//attaches observer to the subject
{
	m_observers.push_back(o);
}
void Subject::Detach(Observer *o)//detaches observer from the subject
{
	m_observers.erase(std::remove(m_observers.begin(), m_observers.end(), o), m_observers.end());
}

void Subject::Notify(int val)//notifies list of observers of change
{
	for (vector<Observer*>::const_iterator iter = m_observers.begin(); iter != m_observers.end(); ++iter){
		if (*iter != 0){
			(*iter)->onNotify(val);
		}
	}
}