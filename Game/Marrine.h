#include "Terran.h"

class CMarrine : public CTerran{
public:
	CMarrine();
	~CMarrine();
	virtual string getClassName();
	virtual void printInfo();
};