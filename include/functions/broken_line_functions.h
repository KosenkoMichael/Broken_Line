#pragma once

#include<iostream>
#include<stdlib.h>
#include<random>
#include<conio.h>


using namespace std;

namespace broken_line {

	template<typename T>
	T random(T a, T b) {
		std::random_device random_device; // Источник энтропии.
		std::mt19937 generator(random_device()); // Генератор случайных чисел.
		// (Здесь берется одно инициализирующее значение, можно брать больше)
		std::uniform_int_distribution<> distribution(a, b); // Равномерное распределение [a, b]
		T x = distribution(generator); // Случайное число.
		return x;
	}

	template<typename T> 
	struct Point {
		T x;
		T y;
		Point():x(0),y(0){}
		Point(T _x, T _y) :x(_x), y(_y) {}
		Point(const Point<T>& rhs) :x(rhs.x), y(rhs.y) {}
		float len(Point& rhs) {
			return static_cast<float>(sqrt((x - rhs.x) * (x - rhs.x) + (y - rhs.y) * (y - rhs.y)));
		}
		bool operator == (Point<T> rhs) {
			if ((x == rhs.x) && (y == rhs.y))
				return true;
			return false;
		}
		void operator = (Point<T> rhs) {
			x = rhs.x;
			y = rhs.y;
		}
		void print() {
			cout << x << " " << y << endl;
		}
	};

	template<typename T>
	class BrokenLine {
		Point<T>** _data;
		int _size;
	public:
		BrokenLine() {
			_data = new Point<T>*;
			_data[0] = new Point<T>;
			_size = 1;
		}
		BrokenLine(Point<T>& rhs) { // Конструктор по координатам точки
			_data = new Point<T>*;
			_data[0] = new Point<T>(rhs.x, rhs.y);
			_size = 1;
		}
		BrokenLine(size_t size) { // Конструктор по размеру
			_data = new Point<T>*[size];
			for (int i = 0; i < size; ++i)
				_data[i] = new Point<T>;
			_size = size;
		}
		BrokenLine(int count, T x1, T x2, T y1, T y2) {
				_data = new Point<T>*[count];
				for (int i = 0; i < count; ++i)
					_data[i] = new Point<T>(random(x1,x2), random(y1,y2));
				_size = count;
		}
		~BrokenLine() {
			for (int i = 0; i < _size; ++i)
				delete _data[i];
			delete[] _data;
		}
		void push_back(Point<T>& point) {
			Point<T>** copy = new Point<T>*[_size + 1];
			for (int i = 0; i < _size; ++i)
				copy[i] = new Point<T>(*_data[i]);
			copy[_size] = new Point<T>(point);
			for (int i = 0; i < _size; ++i)
				delete _data[i];
			delete[] _data;
			_data = copy;
			_size++;
		}
		void push_front(Point<T>& point) {
			Point<T>** copy = new Point<T>*[_size + 1];
			for (int i = 1; i < _size+1; ++i)
				copy[i] = new Point<T>(*_data[i-1]);
			copy[0] = new Point<T>(point);
			for (int i = 0; i < _size; ++i)
				delete _data[i];
			delete[] _data;
			_data = copy;
			_size++;
		}
		float len() {
			float len = 0;
			for (int i = 1; i < _size; ++i) {
				len += (*_data[i]).len(*_data[i - 1]);
			}
			return len;
		}
		Point<T>& operator[](size_t index) { //Оператор для чтения/записи по индексу
			return *_data[index];
		}
		BrokenLine<T> operator+(BrokenLine<T>& rhs) {
			BrokenLine<T> new_line(*_data[0]);
			for (int i = 1; i <_size; ++i)
				new_line.push_back(*_data[i]);
			for (int i = 0; i < rhs._size; ++i)
				new_line.push_back(*rhs._data[i]);
			return new_line;
		}
		int size() {
			return _size;
		}
		void print() {
			for (int i = 0; i < _size; ++i)
				(*_data[i]).print();
		}
	};

};