#include <iostream>
#include <iomanip>
#include <tchar.h>
#include "Auxil.h"
#include "Boat.h"
#include "Combi1.h"
#include "Combi2.h"
#include "Combi3.h"
#include "Combi4.h"
#define SPACE(n) std::setw(n)<<" "
#define N (sizeof(AA)/2)
#define M 3
#define NN 25 //всего контейнеров
#define MM 5 //количество мест для контейнеров - 5
#define V 1500
using namespace std;


/*
ЗАДАНИЕ ДЛЯ ВЫПОЛНЕНИЯ:
Задание 1.  Разработать генератор подмножеств заданного множества. 
Задание 2.  Разработать генератор сочетаний 
Задание 3.  Разработать генератор перестановок
Задание 4.  Разработать генератор размещений  

Задание 5.  Решить  в соответствии с вариантом задачу:
(Вариант 3, 7, 11, 15) об оптимальной загрузке судна 
(веса контейнеров сгенерировать случайным образом: ограничение по общему весу – 1500 кг., 
количество мест на судне для контейнеров – 5, количество контейнеров 25, веса контейнеров 100 – 900 кг., доход от перевозки 10 – 150 у.е.);

Задание 6. Исследовать зависимость времени вычисления необходимое для решения задачи (в соответствии с вариантом) от размерности задачи:
(Вариант 3, 7, 11, 15) об оптимальной загрузке судна (количество мест на судне для контейнеров – 6, количество контейнеров 25 – 35
*/
void task1() {
    char  AA[][2] = { "A", "B", "C", "D" };
    std::cout << std::endl << " - Генератор множества всех подмножеств -";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA) / 2; i++)
        std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация всех подмножеств  ";
    combi1::subset s1(sizeof(AA) / 2);     // создание генератора   
    int  n = s1.getfirst();                // первое (пустое) подмножество    
    while (n >= 0)                         // пока есть подмножества 
    {
        std::cout << std::endl << "{ ";
        for (int i = 0; i < n; i++)
            std::cout << AA[s1.ntx(i)] << ((i < n - 1) ? ", " : " ");
        std::cout << "}";
        n = s1.getnext();                  // cледующее подмножество 
    };
    std::cout << std::endl << "всего: " << s1.count() << std::endl;
}
void task2() {
    char  AA[][2] = { "A", "B", "C", "D", "E" };
    std::cout << std::endl << " --- Генератор сочетаний ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA) / 2; i++)
        std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация сочетаний ";
    combi2::xcombination xc(sizeof(AA) / 2, 3);
    std::cout << "из " << xc.n << " по " << xc.m;
    int  n = xc.getfirst();
    while (n >= 0)
    {
        std::cout << std::endl << xc.nc << ": { ";
        for (int i = 0; i < n; i++)
            std::cout << AA[xc.ntx(i)] << ((i < n - 1) ? ", " : " ");
        std::cout << "}";
        n = xc.getnext();
    };
    std::cout << std::endl << "всего: " << xc.count() << std::endl;
}
void task3() {
    char  AA[][2] = { "A", "B", "C", "D" };
    std::cout << std::endl << " --- Генератор перестановок ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA) / 2; i++)
        std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация перестановок ";
    combi3::permutation p(sizeof(AA) / 2);
    __int64  n = p.getfirst();
    while (n >= 0)
    {
        std::cout << std::endl << std::setw(4) << p.np << ": { ";
        for (int i = 0; i < p.n; i++)
            std::cout << AA[p.ntx(i)] << ((i < p.n - 1) ? ", " : " ");
        std::cout << "}";
        n = p.getnext();
    };
    std::cout << std::endl << "всего: " << p.count() << std::endl;
}
void task4() {
    char  AA[][2] = { "A", "B", "C", "D" };
    std::cout << std::endl << " --- Генератор размещений ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < N; i++)
        std::cout << AA[i] << ((i < N - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация размещений  из  " << N << " по " << M;
    combi4::accomodation s(N, M);
    int  n = s.getfirst();
    while (n >= 0) {
        std::cout << std::endl << std::setw(2) << s.na << ": { ";
        for (int i = 0; i < 3; i++)
            std::cout << AA[s.ntx(i)] << ((i < n - 1) ? ", " : " ");
        std::cout << "}";
        n = s.getnext();
    };
    std::cout << std::endl << "всего: " << s.count() << std::endl;
}

void task5() {
    int   v[NN], // вес каждого контейнера 
       c[NN]; //доход от перевозки каждого контейнера 
    for (int i = 0; i < NN; i++) {
        v[i] = rand() % 900 + 100;
    }
    for (int i = 0; i < NN; i++) {
        c[i] = rand() % 150 + 10;
    }
    short  r[MM];
    int cc = boat(
        V,   // [in]  максимальный вес груза
        MM,  // [in]  количество мест для контейнеров     
        NN,  // [in]  всего контейнеров  
        v,   // [in]  вес каждого контейнера  
        c,   // [in]  доход от перевозки каждого контейнера     
        r    // [out] результат: индексы выбранных контейнеров  
    );
    clock_t t1, t2;
    std::cout << std::endl << "- Задача о размещении контейнеров на судне";
    std::cout << std::endl << "- общее количество контейнеров    : " << NN;
    std::cout << std::endl << "- количество мест для контейнеров : " << MM;
    std::cout << std::endl << "- ограничение по суммарному весу  : " << V;
    std::cout << std::endl << "- вес контейнеров                 : ";
    for (int i = 0; i < NN; i++) std::cout << std::setw(3) << v[i] << " ";
    std::cout << std::endl << "- доход от перевозки              : ";
    for (int i = 0; i < NN; i++) std::cout << std::setw(3) << c[i] << " ";
    std::cout << std::endl << "- выбраны контейнеры (0,1,...,m-1): ";
    for (int i = 0; i < MM; i++) std::cout << r[i] << " ";
    std::cout << std::endl << "- доход от перевозки              : " << cc;
    std::cout << std::endl << "- общий вес выбранных контейнеров : ";
    int s = 0; for (int i = 0; i < MM; i++) s += v[r[i]]; std::cout << s;
    std::cout << std::endl << std::endl;
}
void task6() {
    clock_t t1, t2;
    auxil::start();
    int   v[35], // вес каждого контейнера 
       c[35]; //доход от перевозки каждого контейнера 
    for (int i = 0; i < 35; i++) {
        v[i] = rand() % 900 + 100;
        c[i] = rand() % 150 + 10;
    }
    short  r[6];
    cout << endl << SPACE(7) << setw(2) << "Кол-во контейнейров"
        << SPACE(15) << setw(6) << "Время";
    for (int i = 25; i <= 35; i++) {
        t1 = clock();
        boat(V,6,i,v,c,r);
        t2 = clock();
        cout << endl << SPACE(15) << setw(2) << i
            << SPACE(23) << setw(6) << (t2 - t1);
    }
    std::cout << std::endl << std::endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");
    int switcher;
    for (;;)
    {
        cout << "\n1. Генератор подмножеств заданного множества\n";
        cout << "2. Генератор сочетаний\n";
        cout << "3. Генератор перестановок\n";
        cout << "4. Генератор размещений\n";
        cout << "5. Задача об оптимальной загрузке судна\n";
        cout << "6. Зависимость времени вычисления\n";
        cout << "0. Выйти\n";
        cout << "Номер задания: ";
        cin >> switcher;
        switch (switcher) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 6:
            task6();
            break;
        case 0:
            exit(0);
            break;
        }
    }
    std::cout << std::endl << std::endl;
    system("pause");
    return 0;
}


