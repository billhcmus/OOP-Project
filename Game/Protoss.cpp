#include "Protoss.h"
#include "Terran.h"
string CProtoss::getClassName(){
	return	NULL;
}

int CProtoss::getHP(){
	return this->HitPoints;
}

int CProtoss::getTotalDame(){
	return this->AirDam + this->GroundDam;
}

string CProtoss::getCapabilities(){
	return this->Capabilities;
}
void CProtoss::printInfo(){

}

void CProtoss::Attack(CTerran &ob){
	if (ob.MoveMode == "Ground"){
		 if (ob.HitPoints > 0){
			 ob.HitPoints -= this->GroundDam;
		}
	}
	else{
		 if (ob.HitPoints > 0){
			 ob.HitPoints -= this->AirDam;
		}
	}
	// Xuất ra thông tin của đợt đánh này
	ob.printInfo();
}
