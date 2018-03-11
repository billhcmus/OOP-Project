#ifndef	_TERRAN_H
#define _TERRAN_H
#include <iostream>
#include <string>
using namespace std;
class CTerran{
protected:
	int HitPoints; // Máu
	string MoveMode; // Chế độ di chuyển
	string Capabilities; // Khả năng tấn công
	int GroundDam;
	int AirDam;
public:
	CTerran();
	~CTerran();
	friend class CProtoss;
	void Attack(CProtoss &);
	int getHP();
	int getTotalDame();
	string getCapabilities();
	virtual string getClassName();
	virtual void printInfo();
};
#endif