#include <gtest/gtest.h>
#include <functions/broken_line_functions.h>
#include <stdexcept>
#include <iostream>

using namespace broken_line;

TEST(FunctionsTests,PointTest) {
	Point<int> a;
	Point<int> b(1,0);
	Point<int> c(a);
	Point<int> d = a;
	EXPECT_NEAR(a.len(b),1,0.1);
	EXPECT_TRUE(a==c);
	EXPECT_TRUE(a == d);
	//b.print();
}

TEST(FunctionsTests, BrokenLineTest) {
	
}

	//• конструктор с параметром : координата точки;
	//• конструктор с параметром : количество точек;
	//• конструктор с параметрами(создает ломаную из точек, координаты каждой из которых лежат в диапазоне[m1, m2];
	//• оператор[] для чтения / записи вершины ломаной по её индексу;
	//• оператор сложения двух ломаных(конкатенация);
	//• оператор сложения ломаной и вершины(добавление вершины в конец ломаной);
	//• оператор сложения вершины и ломаной(вставка вершины в начало ломаной);
	//• вычисление длины ломаной.