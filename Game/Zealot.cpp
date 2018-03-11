#include "Zealot.h"

CZealot::CZealot(){
	this->HitPoints = 80;
	this->PlasmaShields = 20;
	this->MoveMode = "Ground";
	this->Capabilities = "Ground";
	this->GroundDam = 16;
	this->AirDam = 0;
}

CZealot::~CZealot(){

}

string CZealot::getClassName(){
	return "Zealot";
}

void CZealot::printInfo(){
	cout << this->getClassName() << "(" << this->MoveMode << ", " << this->HitPoints << "/" << this->PlasmaShields << ")";
}