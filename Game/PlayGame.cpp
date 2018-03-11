#include "PayGame.h"



void ListTeam(CTerran* TeamA[], CProtoss*TeamB[], int nA, int nB){
	cout << "Team A: " << endl;
	for (int i = 0; i < nA; i++){
		TeamA[i]->printInfo();
		cout << endl;
	}
	cout << endl << "Team B:" << endl;
	for (int i = 0; i < nB; i++){
		TeamB[i]->printInfo();
		cout << endl;
	}
}


void deleteElementA(CTerran* TeamA[], int pos, int &nA){
	delete TeamA[pos];
	for (int i = pos; i < nA - 1; i++){
		TeamA[i] = TeamA[i + 1];
	}
	TeamA[nA - 1] = NULL;
	nA--;
}

void deleteElementB(CProtoss* TeamB[], int pos, int &nB){
	delete TeamB[pos];
	for (int i = pos; i < nB - 1; i++){
		TeamB[i] = TeamB[i + 1];
	}
	TeamB[nB - 1] = NULL;
	nB--;
}
// chọn ngẫu nhiên
void RandomAttack(CTerran* TeamA[], CProtoss* TeamB[], int &nA, int &nB){
	srand(time(0));
	int j;
	// Team A tấn công team B
	for (int i = 0; i < nA; i++){
		if (TeamA[i]->getHP() < 0){
			deleteElementA(TeamA, i, nA);
		}
	}
	if (nB == 0 || nA == 0){
		return;
	}
	cout << endl << "Team A tan cong team B: " << endl;
	for (int i = 0; i < nA; i++){
		if (nB > 0){
			j = rand() % nB;
		}
		else {
			break;
		}
		if (TeamB[j]->getHP() > 0){
			TeamA[i]->printInfo();
			cout << " attacks ";
			TeamB[j]->printInfo();
			cout << "=> ";
			TeamA[i]->Attack(*TeamB[j]);
			cout << endl;
		}
		else{
			deleteElementB(TeamB, j, nB);
		}
	}
	for (int i = 0; i < nB; i++){
		if (TeamB[i]->getHP() < 0){
			deleteElementB(TeamB, i, nB);
		}
	}
	if (nA == 0 || nB == 0){
		return;
	}
	//Team B phản công
	cout << endl << "Team B phan cong: " << endl;
	for (int i = 0; i < nB; i++){
		if (nA > 0){
			j = rand() % nA;
		}
		else{
			break;
		}
		if (TeamA[j]->getHP() > 0){
			TeamB[i]->printInfo();
			cout << " attacks ";
			TeamA[j]->printInfo();
			cout << "=> ";
			TeamB[i]->Attack(*TeamA[j]);
			cout << endl;
		}
		else{
			deleteElementA(TeamA, j, nA);
			//nA--;
		}
	}
}

void OptionAttack(CTerran* TeamA[], CProtoss* TeamB[], int &nA, int &nB){
	srand(time(0));
	int j = INT_MAX;
	string strB;
	string strA;
	// Team A tấn công team B
	for (int i = 0; i < nA; i++){
		if (TeamA[i]->getHP() < 0){
			deleteElementA(TeamA, i, nA);
		}
	}
	if (nB == 0 || nA == 0){
		return;
	}
	cout << "Team A tan cong: " << endl;
	for (int i = 0; i < nA; i++){
		strA = TeamA[i]->getCapabilities();
		// chọn lính có thể tấn công
		if (strA == "All"){
			if (nB > 0){
				j = rand() % nB;
			}
			else{
				return;
			}
		}
		else if (strA == "Air"){
			for (int k = 0; k < nB; k++){
				if (TeamB[k]->getCapabilities() == "Air"){
					j = k;
				}
			}
		}
		else{
			for (int k = 0; k < nB; k++){
				if (TeamB[k]->getCapabilities() == "Ground"){
					j = k;
				}
			}
		}
		//kết thúc chọn
		if (j != INT_MAX){
			if (TeamB[j] != NULL){
				TeamA[i]->printInfo();
				cout << " attacks ";
				TeamB[j]->printInfo();
				cout << "=> ";
				TeamA[i]->Attack(*TeamB[j]);
				cout << endl;
			}
		}
		for (int i = 0; i < nB; i++){
			if (TeamB[i]->getHP() <= 0){
				deleteElementB(TeamB, i, nB);
			}
		}
	}

	// Team B phản công
	for (int i = 0; i < nB; i++){
		if (TeamB[i]->getHP() < 0){
			deleteElementB(TeamB, i, nB);
		}
	}
	if (nA == 0 || nB == 0){
		return;
	}
	cout << "Team B phan cong: " << endl;
	j = INT_MAX;
	for (int i = 0; i < nB; i++){
		strB = TeamB[i]->getCapabilities();
		// chọn lính có thể tấn công
		if (strB == "All"){
			if (nA > 0){
				j = rand() % nA;
			}
			else{
				return;
			}
		}
		else if (strB == "Air"){
			for (int k = 0; k < nA; k++){
				if (TeamA[k]->getCapabilities() == "Air"){
					j = k;
				}
			}
		}
		else{
			for (int k = 0; k < nA; k++){
				if (TeamA[k]->getCapabilities() == "Ground"){
					j = k;
				}
			}
		}
		//kết thúc chọn
		if (j != INT_MAX){
			if (TeamA[j] != NULL){
				TeamB[i]->printInfo();
				cout << " attacks ";
				TeamA[j]->printInfo();
				cout << "=> ";
				TeamB[i]->Attack(*TeamA[j]);
				cout << endl;
			}
		}
		for (int k = 0; k < nA; k++){
			if (TeamA[k]->getHP() <= 0){
				deleteElementA(TeamA, k, nA);
			}
		}
	}
}

// Tấn công quân ít máu nhất

void AttackBloodLeast(CTerran* TeamA[], CProtoss* TeamB[], int& nA, int& nB){
	// TeamA tấn công
	string strA;
	string strB;
	int MinHP = INT_MAX, k = INT_MAX;
	for (int i = 0; i < nA; i++){
		if (TeamA[i]->getHP() < 0){
			deleteElementA(TeamA, i, nA);
		}
	}
	if (nB == 0 || nA == 0){
		return;
	}
	cout << "Team A tan cong: " << endl;
	for (int i = 0; i < nA; i++){
		strA = TeamA[i]->getCapabilities();
		// Trường hợp quân team A có thể đánh cả trên cạn lẫn trên không thì chọn tùy ý team B
		if (strA == "All"){
			for (int j = 0; j < nB; j++){
				int HP = TeamB[j]->getHP();
				if (HP < MinHP){
					MinHP = HP;
					k = j;
				}
			}// k != INT_MAX đề phòng trường hợp không tìm đc lính đánh
			// Tấn công phần tử ít máu nhất
			if (k != INT_MAX){
				if (TeamB[k] != NULL){
					TeamA[i]->printInfo();
					cout << " attacks ";
					TeamB[k]->printInfo();
					cout << "=> ";
					TeamA[i]->Attack(*TeamB[k]);
					cout << endl;
				}
			}
		}
		// Trường hợp quân A là quân chỉ tấn công dường bộ
		else if (strA == "Ground"){
			k = INT_MAX;
			for (int j = 0; j < nB; j++){
				strB = TeamB[j]->getCapabilities();
				if (strB == "Ground"){
					int HP = TeamB[j]->getHP();
					if (HP < MinHP){
						MinHP = HP;
						k = j;
					}
				}
			}
			// Tấn công phần tử ít máu nhất
			if (k != INT_MAX){
				if (TeamB[k] != NULL){
					TeamA[i]->printInfo();
					cout << " attacks ";
					TeamB[k]->printInfo();
					cout << "=> ";
					TeamA[i]->Attack(*TeamB[k]);
					cout << endl;
				}
			}
		}
		else{
			k = INT_MAX;
			for (int j = 0; j < nB; j++){
				strB = TeamB[j]->getCapabilities();
				if (strB == "Air"){
					int HP = TeamB[j]->getHP();
					if (HP < MinHP){
						MinHP = HP;
						k = j;
					}
				}
			}
			// Tấn công phần tử ít máu nhất
			if (k != INT_MAX){
				if (TeamB[k] != NULL){
					TeamA[i]->printInfo();
					cout << " attacks ";
					TeamB[k]->printInfo();
					cout << "=> ";
					TeamA[i]->Attack(*TeamB[k]);
					cout << endl;
				}
			}
		}
		for (int i = 0; i < nB; i++){
			if (TeamB[i]->getHP() <= 0){
				deleteElementB(TeamB, i, nB);
			}
		}
	}

	// quân B phản công
	for (int i = 0; i < nB; i++){
		if (TeamB[i]->getHP() < 0){
			deleteElementB(TeamB, i, nB);
		}
	}
	if (nA == 0 || nB == 0){
		return;
	}
	cout << "Team B phan cong: " << endl;
	MinHP = INT_MAX;
	k = INT_MAX;
	for (int i = 0; i < nB; i++){
		strB = TeamB[i]->getCapabilities();
		// Trường hợp quân team B có thể đánh cả trên cạn lẫn trên không thì chọn tùy ý team A
		if (strB == "All"){
			for (int j = 0; j < nA; j++){
				int HP = TeamA[j]->getHP();
				if (HP < MinHP){
					MinHP = HP;
					k = j;
				}
			}
			// Tấn công phần tử ít máu nhất
			// k != INT_MAX đề phòng trường hợp không tìm đc lính đánh
			if (k != INT_MAX){
				if (TeamA[k] != NULL){
					TeamB[i]->printInfo();
					cout << " attacks ";
					TeamA[k]->printInfo();
					cout << "=> ";
					TeamB[i]->Attack(*TeamA[k]);
					cout << endl;
				}
			}
		}
		// Trường hợp quân B là quân chỉ tấn công dường bộ
		else if (strB == "Ground"){
			k = INT_MAX;
			MinHP = INT_MAX;
			for (int j = 0; j < nA; j++){
				strA = TeamA[j]->getCapabilities();
				if (strA == "Ground"){
					int HP = TeamA[j]->getHP();
					if (HP < MinHP){
						MinHP = HP;
						k = j;
					}
				}
			}
			// Tấn công phần tử ít máu nhất
			if (k != INT_MAX){
				if (TeamA[k] != NULL){
					TeamB[i]->printInfo();
					cout << " attacks ";
					TeamA[k]->printInfo();
					cout << "=> ";
					TeamB[i]->Attack(*TeamA[k]);
					cout << endl;
				}
			}
		}
		else{
			k = INT_MAX;
			MinHP = INT_MAX;
			for (int j = 0; j < nA; j++){
				strA = TeamA[j]->getCapabilities();
				if (strA == "Air"){
					int HP = TeamA[j]->getHP();
					if (HP < MinHP){
						MinHP = HP;
						k = j;
					}
				}
			}
			// Tấn công phần tử ít máu nhất
			if (k != INT_MAX){
				if (TeamA[k] != NULL){
					TeamB[i]->printInfo();
					cout << " attacks ";
					TeamA[k]->printInfo();
					cout << "=> ";
					TeamB[i]->Attack(*TeamA[k]);
					cout << endl;
				}
			}
		}
		for (int i = 0; i < nA; i++){
			if (TeamA[i]->getHP() <= 0){
				deleteElementA(TeamA, i, nA);
			}
		}
	}
}

// Tấn công đối tượng nguy hiểm nhất

void AttackDanger(CTerran* TeamA[], CProtoss* TeamB[], int& nA, int& nB){
	// TeamA tấn công
	string strA;
	string strB;
	int MaxDame = INT_MIN, k = INT_MAX;
	for (int i = 0; i < nA; i++){
		if (TeamA[i]->getHP() < 0){
			deleteElementA(TeamA, i, nA);
		}
	}
	if (nB == 0 || nA == 0){
		return;
	}
	cout << "Team A tan cong: " << endl;
	for (int i = 0; i < nA; i++){
		strA = TeamA[i]->getCapabilities();
		// Trường hợp quân team A có thể đánh cả trên cạn lẫn trên không thì chọn tùy ý team B
		if (strA == "All"){
			for (int j = 0; j < nB; j++){
				int Dame = TeamB[j]->getTotalDame();
				if (Dame > MaxDame){
					MaxDame = Dame;
					k = j;
				}
			}// k != INT_MAX đề phòng trường hợp không tìm đc lính đánh
			// Tấn công phần tử nhiều dame nhất
			if (k != INT_MAX){
				if (TeamB[k] != NULL){
					TeamA[i]->printInfo();
					cout << " attacks ";
					TeamB[k]->printInfo();
					cout << "=> ";
					TeamA[i]->Attack(*TeamB[k]);
					cout << endl;
				}
			}
		}
		// Trường hợp quân A là quân chỉ tấn công dường bộ
		else if (strA == "Ground"){
			k = INT_MAX;
			MaxDame = INT_MIN;
			for (int j = 0; j < nB; j++){
				strB = TeamB[j]->getCapabilities();
				if (strB == "Ground"){
					int Dame = TeamB[j]->getTotalDame();
					if (Dame > MaxDame){
						MaxDame = Dame;
						k = j;
					}
				}
			}
			// Tấn công phần tử ít máu nhất
			if (k != INT_MAX){
				if (TeamB[k] != NULL){
					TeamA[i]->printInfo();
					cout << " attacks ";
					TeamB[k]->printInfo();
					cout << "=> ";
					TeamA[i]->Attack(*TeamB[k]);
					cout << endl;
				}
			}
		}
		else{
			k = INT_MAX;
			MaxDame = INT_MIN;
			for (int j = 0; j < nB; j++){
				strB = TeamB[j]->getCapabilities();
				if (strB == "Air"){
					int Dame = TeamB[j]->getTotalDame();
					if (Dame > MaxDame){
						MaxDame = Dame;
						k = j;
					}
				}
			}
			// Tấn công phần tử ít máu nhất
			if (k != INT_MAX){
				if (TeamB[k] != NULL){
					TeamA[i]->printInfo();
					cout << " attacks ";
					TeamB[k]->printInfo();
					cout << "=> ";
					TeamA[i]->Attack(*TeamB[k]);
					cout << endl;
				}
			}
		}
		for (int i = 0; i < nB; i++){
			if (TeamB[i]->getHP() <= 0){
				deleteElementB(TeamB, i, nB);
			}
		}
	}

	// quân B phản công
	for (int i = 0; i < nB; i++){
		if (TeamB[i]->getHP() < 0){
			deleteElementB(TeamB, i, nB);
		}
	}
	if (nA == 0 || nB == 0){
		return;
	}
	cout << "Team B phan cong: " << endl;
	MaxDame = INT_MIN;
	k = INT_MAX;
	for (int i = 0; i < nB; i++){
		strB = TeamB[i]->getCapabilities();
		// Trường hợp quân team B có thể đánh cả trên cạn lẫn trên không thì chọn tùy ý team A
		if (strB == "All"){
			for (int j = 0; j < nA; j++){
				int Dame = TeamA[j]->getTotalDame();
				if (Dame > MaxDame){
					MaxDame = Dame;
					k = j;
				}
			}
			// Tấn công phần tử ít máu nhất
			// k != INT_MAX đề phòng trường hợp không tìm đc lính đánh
			if (k != INT_MAX){
				if (TeamA[k] != NULL){
					TeamB[i]->printInfo();
					cout << " attacks ";
					TeamA[k]->printInfo();
					cout << "=> ";
					TeamB[i]->Attack(*TeamA[k]);
					cout << endl;
				}
			}
		}
		// Trường hợp quân B là quân chỉ tấn công dường bộ
		else if (strB == "Ground"){
			k = INT_MAX;
			MaxDame = INT_MIN;
			for (int j = 0; j < nA; j++){
				strA = TeamA[j]->getCapabilities();
				if (strA == "Ground"){
					int Dame = TeamA[j]->getTotalDame();
					if (Dame > MaxDame){
						MaxDame = Dame;
						k = j;
					}
				}
			}
			// Tấn công phần tử ít máu nhất
			if (k != INT_MAX){
				if (TeamA[k] != NULL){
					TeamB[i]->printInfo();
					cout << " attacks ";
					TeamA[k]->printInfo();
					cout << "=> ";
					TeamB[i]->Attack(*TeamA[k]);
					cout << endl;
				}
			}
		}
		else{
			k = INT_MAX;
			MaxDame = INT_MIN;
			for (int j = 0; j < nA; j++){
				strA = TeamA[j]->getCapabilities();
				if (strA == "Air"){
					int Dame = TeamA[j]->getTotalDame();
					if (Dame > MaxDame){
						MaxDame = Dame;
						k = j;
					}
				}
			}
			// Tấn công phần tử ít máu nhất
			if (k != INT_MAX){
				if (TeamA[k] != NULL){
					TeamB[i]->printInfo();
					cout << " attacks ";
					TeamA[k]->printInfo();
					cout << "=> ";
					TeamB[i]->Attack(*TeamA[k]);
					cout << endl;
				}
			}
		}
		for (int i = 0; i < nA; i++){
			if (TeamA[i]->getHP() <= 0){
				deleteElementA(TeamA, i, nA);
			}
		}
	}
}
// khởi tạo quân
void RandomArmy(CTerran* TeamA[], CProtoss* TeamB[], int nA, int nB){
	int i = 0;
	int j = 0;
	srand(time(0));
	do {
		int idx = rand() % 3;
		int idy = rand() % 3;
		if (idx == 0){
			TeamA[i++] = new CMarrine;
		}
		else if (idx == 1){
			TeamA[i++] = new CFirebat;
		}
		else if (idx == 2){
			TeamA[i++] = new CWraith;
		}

		if (idy == 0){
			TeamB[j++] = new CZealot;
		}
		else if (idy == 1){
			TeamB[j++] = new CDragoon;
		}
		else if (idy == 2){
			TeamB[j++] = new CScout;
		}
	} while (i < nA && j < nB);
}