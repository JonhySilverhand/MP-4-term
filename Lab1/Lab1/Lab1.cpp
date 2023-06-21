#include "Auxil.h"                            // вспомогательные функции 
#include <iostream>
#include <ctime>
#include <locale>

using namespace std;
int fibNumber(unsigned int);

#define  CYCLE  10000000 // количество циклов  
int main()
{
    double  av1 = 0, av2 = 0;
    clock_t  t1 = 0, t2 = 0;
    setlocale(LC_ALL, "rus");
    auxil::start();                          // старт генерации 
    t1 = clock();                            // фиксация времени 
    for (int i = 0; i < CYCLE; i++)
    {
        av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
        av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
    }
    t2 = clock();                            // фиксация времени 
    std::cout << std::endl << "Количество циклов:         " << CYCLE;
    std::cout << std::endl << "Среднее значение (int):    " << av1 / CYCLE;
    std::cout << std::endl << "Среднее значение (double): " << av2 / CYCLE;
    std::cout << std::endl << "Продолжительность (у.е):   " << (t2 - t1);
    std::cout << std::endl << "                  (сек):   "
        << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
    std::cout << std::endl;

    //Рекурсия
    for (int i = 20; i < 45; i+=2)
    {
        double startTime2 = clock();
        cout << i << "-ое число Фибоначчи: " << fibNumber(i) << endl;
        double endTime2 = clock();
        double resultTime2 = (endTime2 - startTime2) / CLOCKS_PER_SEC;
        cout << "Продолжительность (у.е): " << (endTime2 - startTime2) << endl;
    }

    system("pause");
    return 0;
}