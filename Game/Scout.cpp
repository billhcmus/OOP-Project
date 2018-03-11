#include "Scout.h"


CScout::CScout(){
	this->HitPoints = 100;
	this->PlasmaShields = 40;
	this->MoveMode = "Air";
	this->Capabilities = "All";
	this->GroundDam = 8;
	this->AirDam = 28;
}

string CScout::getClassName(){
	return "Scout";
}

void CScout::printInfo(){
	cout << this->getClassName() << "(" << this->MoveMode << ", " << this->HitPoints << "/" << this->PlasmaShields << ")";
}