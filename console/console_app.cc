#include <iostream>
#include <functions/figure_functions.h>
#include <string>

using namespace std;
using namespace kos;

int main() {
	setlocale(LC_ALL, "Russian");
	int choise;
	int temp;
	float points[8];
	int index;
	Figure figure;
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
				for (int i = 0; i < 4; ++i)
					cin >> points[i];
				cout << "\nВведите индекс (от 1 до " << figure_list.get_size() + 1 << "), по которому вы хотите вставить элемент: " << endl;
				cin >> index;
				figure_list.figure_insert(figure.create_ellipse(points), index - 1);
			}
			else if (temp == 2) {
				cout << "\nВведите поочерёдно координаты x и y для каждой точки: " << endl;
				for (int i = 0; i < 8; ++i)
					cin >> points[i];
				cout << "\nВведите индекс (от 1 до " << figure_list.get_size() + 1 << "), по которому вы хотите вставить элемент: " << endl;
				cin >> index;
				figure_list.figure_insert(figure.create_trapezoid(points), index - 1);
			}
			else if (temp == 3) {
				cout << "\nВведите поочерёдно координаты x и y для каждой точки: " << endl;
				for (int i = 0; i < 4; ++i)
					cin >> points[i];
				cout << "\nВведите индекс (от 1 до " << figure_list.get_size() + 1 << "), по которому вы хотите вставить элемент: " << endl;
				cin >> index;
				figure_list.figure_insert(figure.create_rectangle(points), index - 1);
			}
			else
				cout << "Вы выбрали неверный тип фигуры";
			cout << "Вы успешно вставили элемент.\n" << endl;
			system("pause");
			break;

		case 2:
			system("cls");
			cout << "2. Удалить элемент из списка по указанному индексу\n" << endl;
			cout << "\nВведите индекс элемента который нужно удалить от 1 до " << figure_list.get_size() + 1 << endl;
			cin >> index;
			figure_list.indexed_delete(index - 1);
			cout << "Удаление прошло успешно.\n" << endl;
			system("pause");
			break;

		case 3:
			system("cls");
			cout << "3. Вывести список на экран\n" << endl;
			figure_list.figure_print();
			system("pause");
			break;

		case 4: 
			system("cls");
			cout << "4. Найти в списке первую фигуру с максимальной площадью\n" << endl;
			figure = figure_list.max_square_search();
			/*int result = 0, result_index;
			for (int i = 0; i < figure_list.get_size(); i++) {
				if (figure.get_square() > result) {
					result = figure.get_square();
					result_index = i;
				}
			}*/
			cout << "Самая большая площадь " << figure.get_square() << "\n";
			system("pause");
			break;

		case 5:
			system("cls");
			cout << "5. Вставить фигуру.\n" << endl;
			cout << "Выберите тип фигуры (1 - эллипс, 2 - трапеция, 3 - прямоугольник): ";
			cin >> temp;
			if (temp == 1) {
				cout << "\nВведите поочерёдно координаты x и y для каждой точки: " << endl;
				for (int i = 0; i < 4; ++i)
					cin >> points[i];
				figure_list.figure_add(figure.create_ellipse(points));
			}
			else if (temp == 2) {
				cout << "\nВведите поочерёдно координаты x и y для каждой точки: " << endl;
				for (int i = 0; i < 8; ++i)
					cin >> points[i];
				figure_list.figure_add(figure.create_trapezoid(points));
			}
			else if (temp == 3) {
				cout << "\nВведите поочерёдно координаты x и y для каждой точки: " << endl;
				for (int i = 0; i < 4; ++i)
					cin >> points[i];
				figure_list.figure_add(figure.create_rectangle(points));
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