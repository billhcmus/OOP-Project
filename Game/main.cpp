#include "PayGame.h"
// main function
int main(){
	int nA = 5, nB = 5;
	CTerran* TeamA[5];
	CProtoss* TeamB[5];
	int choose;
	bool isInit = false;
	while (1){
		cout << "----------MENU----------" << endl;
		cout << "0. Khoi tao quan doi. " << endl;
		cout << "1. In ra danh sach quan hai doi." << endl;
		cout << "2. In ra ket qua tan cong dot dau." << endl;
		cout << "3. Tan cong theo chien thuat." << endl;
		cout << "4. Thoat." << endl;
		cout << "Ban chon: ";
		cin >> choose;
		switch (choose){
		case 0:{
				   RandomArmy(TeamA, TeamB, nA, nB);
				   isInit = true;
				   break;
		}
		case 1:{
				   if (!isInit){
					   cout << "Ban chua khoi tao!!!" << endl;
					   continue;
				   }
				   cout << "Quan so cua hai doi: " << endl;
				   ListTeam(TeamA, TeamB, nA, nB);
				   cout << endl;
				   break;
		}

		case 2:{
				   if (!isInit){
					   cout << "Ban chua khoi tao!!!" << endl;
					   continue;
				   }
				   cout << "Dot tan cong dau tien: Team A (Terran) tan cong Team B (Protoss): " << endl;
				   TeamAttack(TeamA, TeamB, nA, nB);
				   cout << "Team B (Protoss) tan cong Team A (Terran): " << endl;
				   TeamAttack(TeamB, TeamA, nB, nA);
				   break;
		}
		case 3:{
				   if (!isInit){
					   cout << "Ban chua khoi tao!!!" << endl;
					   continue;
				   }
				   int k;
				   cout << "1. Chon ngau nhien." << endl;
				   cout << "2. Chon ngau nhien linh co the tan cong. " << endl;
				   cout << "3. Chon linh co the tan cong va it mau nhat. " << endl;
				   cout << "4. Chon linh co the tan cong va nguy hiem nhat. " << endl;
				   cout << "5. Tro ve Menu chinh." << endl;
				   cout << "Ban chon: ";
				   cin >> k;
				   bool isTeamAWin;
				   switch (k){
				   case 1:{
							  do {
								  RandomAttack(TeamA, TeamB, nA, nB);
								  if (nA == 0 && nB > 0){
									 // cout << "TEAM B THANG... " << endl;								  
									  isTeamAWin = false;
									  break;
								  }
								  else if (nB == 0 && nA > 0){
									 // cout << "TEAM A THANG... " << endl;					
									  isTeamAWin = true;
									  break;
								  }
							  } while (nA != 0 && nB != 0);
				   }
				   case 2:{
							  do {
								  OptionAttack(TeamA, TeamB, nA, nB);
								  if (nA == 0 && nB > 0){
									  //cout << "TEAM B THANG... " << endl;								  
									  isTeamAWin = false;
									  break;
								  }
								  else if (nB == 0 && nA > 0){
									  //cout << "TEAM A THANG... " << endl;									 
									  isTeamAWin = true;
									  break;
								  }
							  } while (nA != 0 && nB != 0);
				   }
				   case 3:{
							  do {
								  AttackBloodLeast(TeamA, TeamB, nA, nB);
								  if (nA == 0 && nB > 0){
									 // cout << "TEAM B THANG... " << endl;								 
									  isTeamAWin = false;
									  break;
								  }
								  else if (nB == 0 && nA > 0){
									  //cout << "TEAM A THANG... " << endl;									  
									  isTeamAWin = true;
									  break;
								  }
							  } while (nA != 0 || nB != 0);
				   }
				   case 4:{
							  do {
								  AttackDanger(TeamA, TeamB, nA, nB);
								  if (nA == 0){
									  //cout << "TEAM B THANG... " << endl;									  
									  isTeamAWin = false;
									  break;
								  }
								  else if (nB == 0){
									  //cout << "TEAM A THANG... " << endl;									 
									  isTeamAWin = true;
									  break;
								  }
							  } while (nA > 0 || nB > 0);
				   }
				   case 5:{
				   }
				   }
				   if (isTeamAWin){
					   cout << endl << "Ket qua tran chien: Team A chien thang." << endl;
				   }
				   else {
					   cout << endl << "Ket qua tran chien: Team B chien thang." << endl;
				   }
				   fflush(stdin);
				   cin.get();
				   exit(0);
		}
		case 4:{
				   exit(0);
		}
		}
	} // end while

	cin.get();
	return 0;
}

// end main
