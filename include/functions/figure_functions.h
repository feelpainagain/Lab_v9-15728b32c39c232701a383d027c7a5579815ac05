#pragma once

#include<vector>
#include<memory>
#include<iostream>

using namespace std;

namespace kos { 

	class Figure;

	using FigurePtr = std::shared_ptr<Figure>;

	struct Point { 
		float x;
		float y;
		float p_len(Point point); 
	};

	class Figure { 
	protected:
		Figure() = default;
	private:
	public:
		Point apex[4];
		bool operator== (const Figure& figure);
		Point* get_point();
		float virtual get_perim() = 0;
		float virtual get_square() = 0;
		void virtual set_min_framing_rectangle(Point* points) = 0;
		bool virtual check_figure() = 0;
		void virtual print();
		virtual unique_ptr<Figure> clone() const = 0;
		virtual ~Figure() = default;
	};

	class Ellipse: public Figure {
	public:
		Ellipse();
		Ellipse(Point* points);
		float get_perim() override;
		float get_square() override;
		void set_min_framing_rectangle(Point* points) override;
		bool check_figure() override;
		void print() override;
		unique_ptr<Figure> clone() const override;
	};

	class Trapezoid : public Figure {
	public:
		Trapezoid();
		Trapezoid(Point* points);
		float get_perim() override;
		float get_square() override;
		void set_min_framing_rectangle(Point* points) override;
		bool check_figure() override;
		void print() override;
		unique_ptr<Figure> clone() const override;
	};

	class Rectangle : public Figure {
	public:
		Rectangle();
		Rectangle(Point* points);
		float get_perim() override;
		float get_square() override;
		void set_min_framing_rectangle(Point* points) override;
		bool check_figure() override;
		void print() override;
		unique_ptr<Figure> clone() const override;
	};

	class FigureList { 
	private:
		vector<FigurePtr> figure_list;
	public:

		FigureList() = default;
		FigureList(const FigureList& OtherList);

		void swap(FigureList& OtherList) noexcept;

		FigurePtr operator[](const int index) const;
		FigureList& operator=(FigureList list);

		int size();

		void figure_add(FigurePtr figure);
		void figure_insert(FigurePtr a, int index);
		void indexed_delete(int index);
		Figure& max_square_search();
		void print();

	};
}