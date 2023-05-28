#pragma once

namespace kos { 
	enum FigureType { 
		ellipse,
		trapezoid,
		rectangle
	};
	struct Point { 
		float x;
		float y;
		float p_len(Point point); 
	};
	class Figure { 
	private:
		FigureType type; 
		Point apex[4]; 
	public:
		Figure(); 
		Figure(FigureType type, Point* points); 
		Figure* create(FigureType type, Point* points);
		Figure* create_ellipse(float* ellipse_points);
		Figure* create_rectangle(float* rectangle_points);
		Figure* create_trapezoid(float* trapezoid_points);
		bool operator== (const Figure figure) const;
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
		Figure** figures;
		int _size = 0;
	public:
		FigureList();
		~FigureList();
		Figure* operator[](const int index) const;
		void figure_add(Figure* figure);
		Figure* indexed_get(int index);
		int get_size();
		void figure_insert(Figure* figure, int index);
		void indexed_delete(int index);
		Figure max_square_search();
		void figure_print();
	};
}