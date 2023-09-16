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
	cout << b;
}

TEST(FunctionsTests, BrokenLineTest) {
	Point<float> point_1(1.1, 2.2);
	Point<float> point_2(3.3, 4.4);
	BrokenLine<float> line_1(point_1);
	cout << line_1;
	cout << endl;
	BrokenLine<float> line_2(5);
	cout << line_2;
	cout << endl;
	BrokenLine<float> line_3(5, 0, 10, 0, 20);
	cout << line_3;
	cout << endl;
	line_1[0] = point_2;
	line_3.push_back(point_2);
	line_3.push_front(point_1);
	cout << line_3.len()<<endl;
	BrokenLine<float> line_4 = line_1 + line_2;
	cout<<line_4;
}

	//• конструктор с параметром : координата точки;
	//• конструктор с параметром : количество точек;
	//• конструктор с параметрами(создает ломаную из точек, координаты каждой из которых лежат в диапазоне[m1, m2];
	//• оператор[] для чтения / записи вершины ломаной по её индексу;
	//• оператор сложения двух ломаных(конкатенация);
	//• оператор сложения ломаной и вершины(добавление вершины в конец ломаной);
	//• оператор сложения вершины и ломаной(вставка вершины в начало ломаной);
	//• вычисление длины ломаной.
	// использованы только cin cout
	// реализовано правило трех и copy and swap