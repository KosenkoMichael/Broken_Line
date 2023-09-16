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

	//� ����������� � ���������� : ���������� �����;
	//� ����������� � ���������� : ���������� �����;
	//� ����������� � �����������(������� ������� �� �����, ���������� ������ �� ������� ����� � ���������[m1, m2];
	//� ��������[] ��� ������ / ������ ������� ������� �� � �������;
	//� �������� �������� ���� �������(������������);
	//� �������� �������� ������� � �������(���������� ������� � ����� �������);
	//� �������� �������� ������� � �������(������� ������� � ������ �������);
	//� ���������� ����� �������.