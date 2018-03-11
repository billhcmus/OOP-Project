#include "Terran.h"

class CFirebat : public CTerran{
public:
	CFirebat();
	~CFirebat();
	virtual string getClassName();
	virtual void printInfo();
};