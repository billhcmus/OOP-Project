#include "Zealot.h"
#include "Dragoon.h"
#include "Scout.h"
#include "Marrine.h"
#include "Firebat.h"
#include "Wraith.h"
#include <ctime>
void RandomArmy(CTerran*[], CProtoss*[], int, int);
void ListTeam(CTerran*[], CProtoss*[], int, int); // Xuất thông tin 2 đội
//template <class X, class Y> void TeamAttack(X*[], Y*[], int, int); // Tấn công theo thứ tự
void RandomAttack(CTerran*[], CProtoss*[], int&, int&); // Tấn công ngẫu nhiên
void OptionAttack(CTerran*[], CProtoss*[], int&, int&); // Tấn công tùy chọn ngẫu nhiên
void AttackBloodLeast(CTerran*[], CProtoss*[], int&, int&); // Tấn công lính ít máu nhất
void AttackDanger(CTerran*[], CProtoss*[], int&, int&); // Tấn công con lính nguy hiểm nhất quy định con có tổng dame lớn nhất
void deleteElementA(CTerran*[], int pos, int&);
void deleteElementB(CProtoss*[], int pos, int&);

template <class X, class Y> void TeamAttack(X* TeamA[], Y* TeamB[], int &nA, int &nB){
	for (int i = 0; i < nA; i++){
		TeamA[i]->printInfo();
		cout << " attacks ";
		TeamB[i]->printInfo();
		cout << "=> ";
		TeamA[i]->Attack(*TeamB[i]);
		cout << endl;
	}
}