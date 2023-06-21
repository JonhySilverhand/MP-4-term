// main (������� ������  � ���������� �����������)  
#include <iostream>
#include <iomanip> 
#include "BoatC.h"
#include <tchar.h>

#define NN 8
#define MM 5
#define SPACE(n) setw(n)<<" "

using std::cout;
using std::endl;
using std::setw;

void fillArrayWithRandomValues(int* weights, int sizeOfArray, int min, int max) {

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	for (int i = 0; i < sizeOfArray; i++)
	{
		weights[i] = min + (rand() % (max - min + 1));
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int v[NN];// ���
	int c[NN]; // �����
	int minv[MM];
	int maxv[MM];
	fillArrayWithRandomValues(v, NN, 100, 200);
	fillArrayWithRandomValues(c, NN, 10, 100);
	fillArrayWithRandomValues(minv, MM, 50, 120);
	fillArrayWithRandomValues(maxv, MM, 150, 850);


	short r[MM];
	int cc = boat_�(
		MM,    // [in]  ���������� ���� ��� �����������
		minv,  // [in]  ������������ ��� ���������� �� ������  ����� 
		maxv,  // [in]  ����������� ��� ���������� �� ������  �����  
		NN,    // [in]  ����� �����������  
		v,     // [in]  ��� ������� ����������  
		c,     // [in]  ����� �� ��������� ������� ����������   
		r      // [out] ������  ��������� �����������  
	);



	cout << endl << "-- ������ � ���������� ����������� -- ";
	cout << endl << "-- ����� �����������: " << NN;
	cout << endl << "-- ���������� ------ ����������������� -- ";
	cout << endl << "      ����              ����������  ";
	clock_t t1, t2;
	for (int i = 4; i <= NN; i++) {
		t1 = clock();
		boat_�(i, minv, maxv, NN, v, c, r);
		t2 = clock();
		cout << endl << SPACE(7) << setw(2) << i << SPACE(15) << setw(6) << (t2 - t1);
	}
	cout << endl;

	cout << endl << "- ������ � ���������� ����������� �� ����� -";
	cout << endl << "- ����� ���������� �����������   : " << NN;
	cout << endl << "- ���������� ���� ��� �����������  : " << MM;
	cout << endl << "- �����������  ��� ����������  : ";
	for (int i = 0; i < MM; i++) cout << setw(3) << minv[i] << " ";
	cout << endl << "- ������������ ��� ����������  : ";
	for (int i = 0; i < MM; i++) cout << setw(3) << maxv[i] << " ";
	cout << endl << "- ��� �����������      : ";
	for (int i = 0; i < NN; i++) cout << setw(3) << v[i] << " ";
	cout << endl << "- ����� �� ���������     : ";
	for (int i = 0; i < NN; i++) cout << setw(3) << c[i] << " ";
	cout << endl << "- ������� ���������� (0,1,...,m-1) : ";
	for (int i = 0; i < MM; i++) cout << r[i] << " ";
	cout << endl << "- ����� �� ���������     : " << cc;
	cout << endl;

	system("pause");
	return 0;
}