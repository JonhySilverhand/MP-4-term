#include <iostream>
#include "Combi1.h"
#include "Knapsack.h"
#define NN 4
int main()
{
    setlocale(LC_ALL, "rus");
    int V = 100,                // ����������� �������              
        v[] = { 25, 30, 60, 20 },     // ������ �������� ������� ����  
        c[] = { 25, 10, 20, 30 };     // ��������� �������� ������� ���� 
    short m[NN];                // ���������� ��������� ������� ����  {0,1}   

    int maxcc = knapsack_s(

        V,   // [in]  ����������� ������� 
        NN,  // [in]  ���������� ����� ��������� 
        v,   // [in]  ������ �������� ������� ����  
        c,   // [in]  ��������� �������� ������� ����     
        m    // [out] ���������� ��������� ������� ����  
    );

    std::cout << std::endl << "-------- ������ � ������� --------- ";
    std::cout << std::endl << "- ���������� ��������� : " << NN;
    std::cout << std::endl << "- ����������� �������  : " << V;
    std::cout << std::endl << "- ������� ���������    : ";
    for (int i = 0; i < NN; i++) std::cout << v[i] << " ";
    std::cout << std::endl << "- ��������� ���������  : ";
    for (int i = 0; i < NN; i++) std::cout << v[i] * c[i] << " ";
    std::cout << std::endl << "- ����������� ��������� �������: " << maxcc;
    std::cout << std::endl << "- ��� �������: ";
    int s = 0; for (int i = 0; i < NN; i++) s += m[i] * v[i];
    std::cout << s;
    std::cout << std::endl << "- ������� ��������: ";
    for (int i = 0; i < NN; i++) std::cout << " " << m[i];
    std::cout << std::endl << std::endl;

    system("pause");
    return 0;
}
