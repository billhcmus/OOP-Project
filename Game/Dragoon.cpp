#include "Dragoon.h"


 CDragoon::CDragoon(){
	this->HitPoints = 90;
	this->PlasmaShields = 30;
	this->MoveMode = "Ground";
	this->Capabilities = "All";
	this->GroundDam = 20;
	this->AirDam = 20;
}

 CDragoon::~CDragoon(){

 }

string CDragoon::getClassName(){
	return "Dragoon";
}

void CDragoon::printInfo(){
	cout << this->getClassName() << "(" << this->MoveMode << ", " << this->HitPoints << "/" << this->PlasmaShields << ")";
}