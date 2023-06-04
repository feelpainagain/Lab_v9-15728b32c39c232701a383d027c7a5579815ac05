#include <iostream>
#include <functions/figure_functions.h>
#include <string>

using namespace std;
using namespace kos;

void create_ellipse(float* ellipse_points, Point* points) {
	points[0].x = ellipse_points[0];
	points[0].y = points[2].y = ellipse_points[1];
	points[1].x = points[3].x = ellipse_points[2];
	points[1].y = ellipse_points[3];
	points[2].x = points[1].x * 2 - points[0].x;
	points[3].y = points[0].y * 2 - points[1].y;

}

void create_rectangle(float* rectangle_points, Point* points) {
	points[0].x = points[3].x = rectangle_points[0];
	points[0].y = points[1].y = rectangle_points[1];
	points[1].x = points[2].x = rectangle_points[2];
	points[2].y = points[3].y = rectangle_points[3];
}

void create_trapezoid(float* trapezoid_points, Point* points) {
	for (int i = 0, j = 0; i < 4; ++i) {
		points[i].x = trapezoid_points[j];
		points[i].y = trapezoid_points[j + 1];
		j += 2;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int choise;
	int temp;
	float points[8];
	int index;
	Point right_points[4];
	FigureList figure_list;
	while (true) {
		system("cls");
		cout << "Лаботаторная работа номер 2\n" <<
			"Выберите необходимый пункт меню\n" <<
			"1. Вставить элемент в список по указанному индексу\n" <<
			"2. Удалить элемент из списка по указанному индексу\n" <<
			"3. Вывести список на экран\n" <<
			"4. Найти в списке первую фигуру с максимальной площадью\n" << 
			"5. Добавить фигуру.\n" <<
			"6. Выход из программы\n" << endl;
		cout << "Ваш выбор: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			system("cls");
			cout << "1. Вставить элемент в список по указанному индексу\n" << endl;
			cout << "Выберите тип фигуры (1 - эллипс, 2 - трапеция, 3 - прямоугольник): ";
			cin >> temp;
			if (temp == 1) {
				cout << "\nВведите поочерёдно координаты x и y для каждой точки: " << endl;
				for (int i = 0; i < 8; ++i)
					cin >> points[i];
				create_ellipse(points, right_points);
				Ellipse ellipse(right_points);
				cout << "\nВведите индекс (от 1 до " << figure_list.size() + 1 << "), по которому вы хотите вставить элемент: " << endl;
				cin >> index;
				figure_list.figure_insert(make_shared<Ellipse>(ellipse), index - 1);
			}
			else if (temp == 2) {
				cout << "\nВведите поочерёдно координаты x и y для каждой точки: " << endl;
				for (int i = 0; i < 8; ++i)
					cin >> points[i];
				create_trapezoid(points, right_points);
				Trapezoid trapezoid(right_points); 
				cout << "\nВведите индекс (от 1 до " << figure_list.size() + 1 << "), по которому вы хотите вставить элемент: " << endl;
				cin >> index;
				figure_list.figure_insert(make_shared<Trapezoid>(trapezoid), index - 1);
			}
			else if (temp == 3) {
				cout << "\nВведите поочерёдно координаты x и y для каждой точки: " << endl;
				for (int i = 0; i < 8; ++i)
					cin >> points[i];
				create_rectangle(points, right_points);
				Rectangle rectangle(right_points);
				cout << "\nВведите индекс (от 1 до " << figure_list.size() + 1 << "), по которому вы хотите вставить элемент: " << endl;
				cin >> index;
				figure_list.figure_insert(make_shared<Rectangle>(rectangle), index - 1);
			}
			else
				cout << "Вы выбрали неверный тип фигуры";
			cout << "Вы успешно вставили элемент.\n" << endl;
			system("pause");
			break;

		case 2:
			system("cls");
			cout << "2. Удалить элемент из списка по указанному индексу\n" << endl;
			cout << "\nВведите индекс элемента который нужно удалить от 1 до " << figure_list.size() + 1 << endl;
			cin >> index;
			figure_list.indexed_delete(index - 1);
			cout << "Удаление прошло успешно.\n" << endl;
			system("pause");
			break;

		case 3:
			system("cls");
			cout << "3. Вывести список на экран\n" << endl;
			figure_list.print();
			system("pause");
			break;

		case 4: 
			system("cls");
			cout << "4. Найти в списке первую фигуру с максимальной площадью\n" << endl;
			cout << "Параметры фигуры с самой большой площадью: \n" << endl;
			figure_list.max_square_search().print();
			system("pause");
			break;

		case 5:
			system("cls");
			cout << "5. Добавить фигуру.\n" << endl;
			cout << "Выберите тип фигуры (1 - эллипс, 2 - трапеция, 3 - прямоугольник): ";
			cin >> temp;
			if (temp == 1) {
				cout << "\nВведите поочерёдно координаты x и y для каждой точки: " << endl;
				for (int i = 0; i < 4; ++i)
					cin >> points[i];
				create_ellipse(points, right_points);
				Ellipse ellipse(right_points);
				figure_list.figure_add(make_shared<Ellipse>(ellipse));
			}
			else if (temp == 2) {
				cout << "\nВведите поочерёдно координаты x и y для каждой точки: " << endl;
				for (int i = 0; i < 8; ++i)
					cin >> points[i];
				create_trapezoid(points, right_points);
				Trapezoid trapezoid(right_points);
				figure_list.figure_add(make_shared<Trapezoid>(trapezoid));
			}
			else if (temp == 3) {
				cout << "\nВведите поочерёдно координаты x и y для каждой точки: " << endl;
				for (int i = 0; i < 4; ++i)
					cin >> points[i];
				create_rectangle(points, right_points);
				Rectangle rectangle(right_points);
				figure_list.figure_add(make_shared<Rectangle>(rectangle));
			}
			else
				cout << "Вы выбрали неверный тип фигуры";
			cout << "Вы успешно добавили фигуру. \n";
			system("pause");
			break;

		case 6:
			system("cls");
			cout << "Завершение работы.";
			return(false);

		default:
			system("cls");
			cout << "Вы ввели неверный вариант ответа\n";
			system("pause");
			break;
		}
	}
}