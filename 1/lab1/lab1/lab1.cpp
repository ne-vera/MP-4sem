#include "Auxil.h"                            // вспомогательные функции 
#include <iostream>
#include <ctime>
#include <locale>
#define  CYCLE  100000                       // количество циклов  
int main()
{
	double  av1 = 0, av2 = 0;
	clock_t  t1 = 0, t2 = 0;
	setlocale(LC_ALL, "rus");  // старт генерации 
	auxil::start();
	for (int i = 100000; i <= 1000000; i+=100000) {
		av1 = 0;
		av2 = 0;

		t1 = clock();                            // фиксация времени 
		for (int j = 0; j < i; j++)
		{
			av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
			av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
		}
		t2 = clock();                            // фиксация времени 
		std::cout << std::endl << "количество циклов:         " << i;
		std::cout << std::endl << "среднее значение (int):    " << av1 / i;
		std::cout << std::endl << "среднее значение (double): " << av2 / i;
		std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
		std::cout << std::endl << "                  (сек):   "
			<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}
