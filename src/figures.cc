#include <functions/figure_functions.h>

#include <cmath>
#include<stdexcept>
#include<iostream>

#define MAX(x,y) (x) > (y) ? (x) : (y) 
#define MIN(x,y) (x) > (y) ? (y) : (x) 

using namespace kos; 

using namespace std; 

float Point::p_len(Point point) { 
	return sqrt( pow( this->x - point.x, 2 ) + pow( this->y - point.y , 2 ) );
}

Figure::Figure() {
	this->type = rectangle;
	for (int i = 0; i < 4; i++) {
		this->apex[i] = { 0,0 };
	}
}

Figure::Figure(FigureType type, Point* points) {
	this->type = type;
	for (int i = 0; i < 4; i++) {
		this->apex[i] = points[i];
	}
}

//Figure::Figure(FigureType type, Point* points) {
//	this->type = type;
//	if (type == rectangle) {
//		this->apex[0] = points[0]; 
//		this->apex[1] = { points[1].x, points[0].y }; 
//		this->apex[2] = { points[1].x, points[1].y }; 
//		this->apex[3] = { points[0].x, points[1].y }; 
//	}
//	else {
//		for (int i = 0; i < 4; i++) {
//			this->apex[i] = points[i];
//		}
//	}
//}


Figure* Figure::create_ellipse(float* ellipse_points) {
	this->type = ellipse;
	apex[0].x = ellipse_points[0];
	apex[0].y = apex[2].y = ellipse_points[1];
	apex[1].x = apex[3].x = ellipse_points[2];
	apex[1].y = ellipse_points[3];
	apex[2].x = apex[1].x * 2 - apex[0].x;
	apex[3].y = apex[0].y * 2 - apex[1].y;
	return new Figure(type, apex);
}
Figure* Figure::create_rectangle(float* rectangle_points) {
	type = rectangle;
	apex[0].x = apex[3].x = rectangle_points[0];
	apex[0].y = apex[1].y = rectangle_points[1];
	apex[1].x = apex[2].x = rectangle_points[2];
	apex[2].y = apex[3].y = rectangle_points[3];
	return new Figure(type, apex);
}
Figure* Figure::create_trapezoid(float* trapezoid_points) {
	type = trapezoid;
	for (int i = 0, j = 0; i < 4; ++i) {
		apex[i].x = trapezoid_points[j];
		apex[i].y = trapezoid_points[j + 1];
		j += 2;
	}
	return new Figure(type, apex);
}

bool Figure::operator== (const Figure figure) const { 
	if (this->type != figure.type)
		return false;
	for (int i = 0; i < 4; i++) {
		if ((this->apex[i].x != figure.apex[i].x) || (this->apex[i].y != figure.apex[i].y))
			return false;
	}
	return true;
}

void Figure::set_type(FigureType Type) { 
	this->type = Type;
}

FigureType Figure::get_type() { 
	return this->type;
}

void Figure::set_apex(Point* apex){ 
	for (int i = 0; i < 4; i++) {
		this->apex[i] = apex[i];
	}
}

float Figure::get_point(char a, int i) { 
	switch (a) {
	case 'x': return this->apex[i].x;
	case 'y': return this->apex[i].y;
	}
}

float Figure::get_perim() { 
	float perim = 0;
	float ose[2]; //полуоси
	switch(this->type) {
	case ellipse: 
		ose[0] = (this->apex[0].p_len(this->apex[2])) / 2;
		ose[1] = (this->apex[1].p_len(this->apex[3])) / 2;
		return 4 * ((3.14 * ose[0] * ose[1] + ose[0] - ose[1]) / (ose[0] + ose[1]));
	case trapezoid:
		for (int i = 0; i < 3; i++) {
			perim += this->apex[i].p_len(this->apex[i+1]);
		}
		perim += this->apex[3].p_len(this->apex[0]);
		return perim;
	case rectangle:
		Point array1 = { apex[0].x, apex[0].y };
		Point array2 = { apex[1].x, apex[1].y };
		Point array3 = { apex[2].x, apex[2].y };
		Point array4 = { apex[3].x, apex[3].y };
		perim += array1.p_len(array2);
		perim += array2.p_len(array3);
		perim += array3.p_len(array4);
		perim += array4.p_len(array1);
		//for (int i = 0; i < 3; i++) {
		//	perim += this->apex[i].p_len(this->apex[i + 1]);
		//}
		//perim += this->apex[3].p_len(this->apex[0]);
		return perim;
	}
}

float Figure::get_square() {
	float ose[2];
	float a, b, c, d;
	switch (this->type) {
	case ellipse:
		ose[0] = (this->apex[0].p_len(this->apex[2])) / 2;
		ose[1] = (this->apex[1].p_len(this->apex[3])) / 2;
		return 3.14 * ose[0] * ose[1];
	case trapezoid:
		b = this->apex[0].p_len(this->apex[1]);
		d = this->apex[1].p_len(this->apex[2]);
		a = this->apex[2].p_len(this->apex[3]);
		c = this->apex[0].p_len(this->apex[3]);
		return (a + b) / 2 * sqrt(c * c - pow(((a - b) * (a - b) + c * c - d * d) / ((a - b) * 2), 2));
	case rectangle:
		Point array1 = { apex[0].x, apex[0].y };
		Point array2 = { apex[1].x, apex[1].y };
		Point array3 = { apex[2].x, apex[2].y };
		int len1 = array1.p_len(array2);
		int len2 = array2.p_len(array3);
		return len1*len2;
	}
}

void Figure::set_min_framing_rectangle(Figure figure) {
	this->type = rectangle;
	switch (figure.type) {
	case ellipse:
		this->apex[0] = {figure.apex[0].x, figure.apex[1].y};
		this->apex[1] = {figure.apex[2].x, figure.apex[1].y};
		this->apex[2] = {figure.apex[2].x, figure.apex[3].y};
		this->apex[3] = {figure.apex[0].x, figure.apex[3].y};
		break;
	case trapezoid:
		this->apex[0] = { MIN(figure.apex[0].x, figure.apex[3].x), figure.apex[0].y};
		this->apex[1] = { MAX(figure.apex[1].x, figure.apex[2].x), figure.apex[0].y };
		this->apex[2] = { MAX(figure.apex[1].x, figure.apex[2].x), figure.apex[3].y };
		this->apex[3] = { MIN(figure.apex[0].x, figure.apex[3].x), figure.apex[3].y };
		break;
	case rectangle:
		for(int i=0; i<4; i++)
		this->apex[i] = figure.apex[i];
		break;
	}
}

Figure* FigureList::operator[](const int index) const {
	if ((index < 0) || (_size <= index)) {
		throw out_of_range("[FigureList::operator[]] Index is out of range.");
	}
	return figures[index];
}



int FigureList::get_size() {
	return _size;
}

Figure* FigureList::indexed_get(int index) {
	if ((index < 0) || (_size <= index)) {
		throw 0;
	}
	return this->figures[index];
}

void FigureList::figure_add(Figure* figure) {
	auto copy = new Figure * [_size + 1];
	for (int i = 0; i < _size; ++i) {
		copy[i] = figures[i];
	}
	copy[_size] = figure;
	delete[] figures;
	figures = copy;
	this->_size++;
}

void FigureList::figure_insert(Figure* figure, int index) {
	if ((index < 0) || (_size < index)) {
		throw out_of_range("[FigureList::operator[]] Index is out of range.");
	}
	auto copy = new Figure * [_size + 1];
	for (int i = 0; i < _size; i++) {
		if (i < index)
			copy[i] = figures[i];
		else
			copy[i + 1] = figures[i];
	}
	copy[index] = figure;
	delete[] figures;
	figures = copy;
	this->_size++;
}

void FigureList::indexed_delete(int index) {
	if ((index < 0) || (index > _size)) {
		throw runtime_error("Runtime_error");
	}
	auto copy = new Figure * [_size - 1];
	/*for (int i = index; i < _size-1; i++) {
			figures[i] = figures[i + 1];
	}
	for (int i = index; i < _size - 1; i++) {
		copy[i] = figures[i];
	}*/
	for (int i = 0; i < _size - 1; ++i) {
		if (index > i)
			copy[i] = figures[i];
		else
			copy[i] = figures[i + 1];
	}
	delete[] figures;
	figures = copy;
	this->_size--;
}

Figure FigureList::max_square_search() {
	if (_size == 0) {
		throw 0;
	}
	Figure result_figure(*figures[0]);
	for (int i = 0; i < _size; i++) {
		if (result_figure.get_square() < (*figures[i]).get_square())
			result_figure = *figures[i];
	}
	return result_figure;
}

FigureList::FigureList() {
	figures = new Figure * [0];
	_size = 0;
}

FigureList::~FigureList() {
	for (int i = 0; i < _size; ++i) {
		delete figures[i];
	}
	delete[] figures;
}

Figure* Figure::create(FigureType type, Point* points) {
	return new Figure(type, points);
}

void FigureList::figure_print() {
	cout << "В массиве сейчас находится " << _size << " фигур \n";
	for (int i = 0; i < _size; i++) {
		cout << "Фигура номер " << i + 1 << ".\n" <<
			"Тип: " << figures[i]->get_type() << ".\n" <<
			"Площадь: " << (*figures[i]).get_square() << ".\n" <<
			"Периметр: " << figures[i]->get_perim() << ".\n" <<
			"Координаты точек:" << endl;
		if ((figures[i]->get_type() == ellipse) || (figures[i]->get_type() == rectangle)) {
			for (int j = 0; j < 4; j++) {
				cout << "(" << figures[i]->get_point('x', j) << ", ";
				cout << figures[i]->get_point('y', j) << ") ";
			}
			cout << "\n" << endl;
		}
		else {
			for (int j = 0; j < 4; j++) {
				cout << "(" << figures[i]->get_point('x', j) << ", ";
				cout << figures[i]->get_point('y', j) << ") ";
			}
		}
	}
}