#include "Firebat.h"


CFirebat::CFirebat(){
	this->HitPoints = 100;
	this->MoveMode = "Ground";
	this->Capabilities = "Ground";
	this->GroundDam = 18;
	this->AirDam = 0;
}

CFirebat::~CFirebat(){

}

string CFirebat::getClassName(){
	return "Firebat";
}

void CFirebat::printInfo(){
	cout << this->getClassName() << "(" << this->MoveMode << ", " << this->HitPoints << ")";
}