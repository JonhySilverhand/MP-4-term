#include <iostream>
#include <iomanip> 
#include "Salesman.h"
#define N 5
int main()
{
    setlocale(LC_ALL, "rus");
    int d[N][N] = { //0   1    2    3     4        
                  { INF, 22, 32, INF, 11},    //  0
                  { 11, INF,  26,  57, 73},    //  1
                  { 13,  33, INF, 86, 60},    //  2 
                  { 28,  47,  44, INF, 33},    //  3
                  { 82,  77,  52,  24, INF} };   //  4  
    int r[N];                     // результат 
    int s = salesman(
        N,          // [in]  количество городов 
        (int*)d,          // [in]  массив [n*n] расстояний 
        r           // [out] массив [n] маршрут 0 x x x x  

    );
    std::cout << std::endl << "-- Задача коммивояжера -- ";
    std::cout << std::endl << "-- количество  городов: " << N;
    std::cout << std::endl << "-- матрица расстояний : ";
    for (int i = 0; i < N; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < N; j++)

            if (d[i][j] != INF) std::cout << std::setw(3) << d[i][j] << " ";

            else std::cout << std::setw(3) << "INF" << " ";
    }
    std::cout << std::endl << "-- оптимальный маршрут: ";
    for (int i = 0; i < N; i++) std::cout << r[i] << "-->"; std::cout << 0;
    std::cout << std::endl << "-- длина маршрута     : " << s;
    std::cout << std::endl;
    system("pause");
    return 0;
}