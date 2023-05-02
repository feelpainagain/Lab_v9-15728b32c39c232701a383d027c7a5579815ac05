#pragma once

namespace kos { //объявление пространства имён
	enum FigureType { //перечисление доступных фигур
		ellipse,
		trapezoid,
		rectangle
	};
	struct Point { //структура поинт, с полями х и у, метод len
		float x;
		float y;
		float p_len(Point point); //метод, принимает тип поинт на вход
	};
	class Figure { //класс, на практике ничем не отличается от структур
	private:
		FigureType type; //тип фигуры
		Point apex[4]; //массив типа поинт из 4 элементов по имени апекс
	public:
		Figure(); //конструктор по умолчанию (без параметров)
		Figure(FigureType type, Point* points); //конструктор с параметрами
		Figure(Point* points);
		void create_ellipse(float* ellipse_points); //методы
		void create_rectangle(float* rectangle_points);
		void create_trapezoid(float* trapezoid_points);
		bool operator== (const Figure figure) const; //???
		FigureType get_type();
		float get_point(char a, int i);
		void set_type(FigureType Type);
		void set_apex(Point* apex);
		float get_perim();
		float get_square();
		void set_min_framing_rectangle(Figure figure);
	};
	class FigureList { 
	private:
		const static int capacity = 3; //вместимость
		Figure figures[capacity]; //массив
		int count = 0; //число
	public:
		Figure operator[](const int index) const; //индексатор для работы с экземпляром класса как с массивом
		void figure_add(Figure figure);
		Figure indexed_get(int index);
		int get_count();
		void figure_insert(Figure figure, int index);
		void indexed_delete(int index);
		Figure max_square_search();
	};
}