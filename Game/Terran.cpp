#include "Terran.h"
#include "Protoss.h"
string CTerran::getClassName(){
	return NULL;
}

void CTerran::printInfo(){

}

CTerran::CTerran(){

}
CTerran::~CTerran(){

}

int CTerran::getHP(){
	return this->HitPoints;
}

int CTerran::getTotalDame(){
	return this->AirDam + this->GroundDam;
}

string CTerran::getCapabilities(){
	return this->Capabilities;
}

void CTerran::Attack(CProtoss &ob){
	if (ob.MoveMode == "Ground"){
		if (ob.PlasmaShields >= this->GroundDam){
			ob.PlasmaShields -= this->GroundDam;
		}
		else{
			ob.HitPoints += ob.PlasmaShields;
			ob.PlasmaShields = 0;
			ob.HitPoints -= this->GroundDam;
		}
	}
	else{
		if (ob.PlasmaShields >= this->AirDam){
			ob.PlasmaShields -= this->AirDam;
		}
		else{
			ob.HitPoints += ob.PlasmaShields;
			ob.PlasmaShields = 0;
			ob.HitPoints -= this->AirDam;
		}
	}
	// Xuất ra thông tin của đợt đánh này
	ob.printInfo();
}

