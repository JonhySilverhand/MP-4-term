// Main
#include <iostream>
#include "Combi3.h"
#include <iomanip> 
#include <tchar.h>

using std::cout;
using std::setw;
using std::endl;
#define N 5
#define INF INT_MAX
int main()
{
	setlocale(LC_ALL, "rus");
	int AA[N][N] = { //0   1    2    3     4        
				  { INF, 22, 32, INF, 11},    //  0
				  { 11, INF,  26,  57, 73},    //  1
				  { 13,  33, INF, 86, 60},    //  2 
				  { 28,  47,  44, INF, 33},    //  3
				  { 82,  77,  52,  24, INF} };   //  4  
	cout << " --- Генератор перестановок ---";
	cout << endl << "Исходное множество: ";
	cout << "{ ";
	for (int i = 0; i < sizeof(AA) / 2; i++)
		cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	cout << "}";
	cout << endl << "Генерация перестановок ";
	combi3::permutation p(sizeof(AA) / 2);
	__int64  n = p.getfirst();
	while (n >= 0)
	{
		cout << endl << setw(4) << p.np << ": { ";
		for (int i = 0; i < p.n; i++)
			cout << AA[p.ntx(i)] << ((i < p.n - 1) ? ", " : " ");
		cout << "}";
		n = p.getnext();
	};
	cout << endl << "всего: " << p.count() << endl;
	system("pause");
	return 0;
}