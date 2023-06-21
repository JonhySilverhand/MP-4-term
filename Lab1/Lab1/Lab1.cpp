#include "Auxil.h"                            // ��������������� ������� 
#include <iostream>
#include <ctime>
#include <locale>

using namespace std;
int fibNumber(unsigned int);

#define  CYCLE  10000000 // ���������� ������  
int main()
{
    double  av1 = 0, av2 = 0;
    clock_t  t1 = 0, t2 = 0;
    setlocale(LC_ALL, "rus");
    auxil::start();                          // ����� ��������� 
    t1 = clock();                            // �������� ������� 
    for (int i = 0; i < CYCLE; i++)
    {
        av1 += (double)auxil::iget(-100, 100); // ����� ��������� ����� 
        av2 += auxil::dget(-100, 100);         // ����� ��������� ����� 
    }
    t2 = clock();                            // �������� ������� 
    std::cout << std::endl << "���������� ������:         " << CYCLE;
    std::cout << std::endl << "������� �������� (int):    " << av1 / CYCLE;
    std::cout << std::endl << "������� �������� (double): " << av2 / CYCLE;
    std::cout << std::endl << "����������������� (�.�):   " << (t2 - t1);
    std::cout << std::endl << "                  (���):   "
        << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
    std::cout << std::endl;

    //��������
    for (int i = 20; i < 45; i+=2)
    {
        double startTime2 = clock();
        cout << i << "-�� ����� ���������: " << fibNumber(i) << endl;
        double endTime2 = clock();
        double resultTime2 = (endTime2 - startTime2) / CLOCKS_PER_SEC;
        cout << "����������������� (�.�): " << (endTime2 - startTime2) << endl;
    }

    system("pause");
    return 0;
}