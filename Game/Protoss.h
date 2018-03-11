#ifndef _PROTOSS_H
#define _PROTOSS_H
#include <iostream>
#include <string> 
using namespace std;

class CProtoss{
protected:
	int HitPoints; // Máu
	int PlasmaShields; // Giáp bảo vệ
	string MoveMode; // Chế độ di chuyển
	string Capabilities; // Khả năng tấn công
	int GroundDam;
	int AirDam;
public:
	friend class CTerran;
	void Attack(CTerran &);
	int getHP();
	int getTotalDame();
	string getCapabilities();
	virtual string getClassName();
	virtual void printInfo();	
};

#endif