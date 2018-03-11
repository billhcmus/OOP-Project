#include "Marrine.h"

CMarrine::CMarrine(){
	this->HitPoints = 80;
	this->MoveMode = "Ground";
	this->Capabilities = "All";
	this->GroundDam = 12;
	this->AirDam = 12;
}

CMarrine::~CMarrine(){

}

string CMarrine::getClassName(){
	return "Marrine";
}

void CMarrine::printInfo(){
	cout << this->getClassName() << "(" << this->MoveMode << ", " << this->HitPoints << ")";
}