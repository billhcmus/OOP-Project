#include "Wraith.h"


CWraith::CWraith(){
	this->HitPoints = 120;
	this->MoveMode = "Air";
	this->Capabilities = "All";
	this->GroundDam = 8;
	this->AirDam = 20;
}

CWraith::~CWraith(){

}

string CWraith::getClassName(){
	return "Wraith";
}

void CWraith::printInfo(){
	cout << this->getClassName() << "(" << this->MoveMode << ", " << this->HitPoints << ")";
}