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
		cout << "������������ ������ ����� 2\n" <<
			"�������� ����������� ����� ����\n" <<
			"1. �������� ������� � ������ �� ���������� �������\n" <<
			"2. ������� ������� �� ������ �� ���������� �������\n" <<
			"3. ������� ������ �� �����\n" <<
			"4. ����� � ������ ������ ������ � ������������ ��������\n" << 
			"5. �������� ������.\n" <<
			"6. ����� �� ���������\n" << endl;
		cout << "��� �����: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			system("cls");
			cout << "1. �������� ������� � ������ �� ���������� �������\n" << endl;
			cout << "�������� ��� ������ (1 - ������, 2 - ��������, 3 - �������������): ";
			cin >> temp;
			if (temp == 1) {
				cout << "\n������� ��������� ���������� x � y ��� ������ �����: " << endl;
				for (int i = 0; i < 4; ++i)
					cin >> points[i];
				cout << "\n������� ������ (�� 1 �� " << figure_list.get_size() + 1 << "), �� �������� �� ������ �������� �������: " << endl;
				cin >> index;
				figure_list.figure_insert(figure.create_ellipse(points), index - 1);
			}
			else if (temp == 2) {
				cout << "\n������� ��������� ���������� x � y ��� ������ �����: " << endl;
				for (int i = 0; i < 8; ++i)
					cin >> points[i];
				cout << "\n������� ������ (�� 1 �� " << figure_list.get_size() + 1 << "), �� �������� �� ������ �������� �������: " << endl;
				cin >> index;
				figure_list.figure_insert(figure.create_trapezoid(points), index - 1);
			}
			else if (temp == 3) {
				cout << "\n������� ��������� ���������� x � y ��� ������ �����: " << endl;
				for (int i = 0; i < 4; ++i)
					cin >> points[i];
				cout << "\n������� ������ (�� 1 �� " << figure_list.get_size() + 1 << "), �� �������� �� ������ �������� �������: " << endl;
				cin >> index;
				figure_list.figure_insert(figure.create_rectangle(points), index - 1);
			}
			else
				cout << "�� ������� �������� ��� ������";
			cout << "�� ������� �������� �������.\n" << endl;
			system("pause");
			break;

		case 2:
			system("cls");
			cout << "2. ������� ������� �� ������ �� ���������� �������\n" << endl;
			cout << "\n������� ������ �������� ������� ����� ������� �� 1 �� " << figure_list.get_size() + 1 << endl;
			cin >> index;
			figure_list.indexed_delete(index - 1);
			cout << "�������� ������ �������.\n" << endl;
			system("pause");
			break;

		case 3:
			system("cls");
			cout << "3. ������� ������ �� �����\n" << endl;
			figure_list.figure_print();
			system("pause");
			break;

		case 4: 
			system("cls");
			cout << "4. ����� � ������ ������ ������ � ������������ ��������\n" << endl;
			figure = figure_list.max_square_search();
			/*int result = 0, result_index;
			for (int i = 0; i < figure_list.get_size(); i++) {
				if (figure.get_square() > result) {
					result = figure.get_square();
					result_index = i;
				}
			}*/
			cout << "����� ������� ������� " << figure.get_square() << "\n";
			system("pause");
			break;

		case 5:
			system("cls");
			cout << "5. �������� ������.\n" << endl;
			cout << "�������� ��� ������ (1 - ������, 2 - ��������, 3 - �������������): ";
			cin >> temp;
			if (temp == 1) {
				cout << "\n������� ��������� ���������� x � y ��� ������ �����: " << endl;
				for (int i = 0; i < 4; ++i)
					cin >> points[i];
				figure_list.figure_add(figure.create_ellipse(points));
			}
			else if (temp == 2) {
				cout << "\n������� ��������� ���������� x � y ��� ������ �����: " << endl;
				for (int i = 0; i < 8; ++i)
					cin >> points[i];
				figure_list.figure_add(figure.create_trapezoid(points));
			}
			else if (temp == 3) {
				cout << "\n������� ��������� ���������� x � y ��� ������ �����: " << endl;
				for (int i = 0; i < 4; ++i)
					cin >> points[i];
				figure_list.figure_add(figure.create_rectangle(points));
			}
			else
				cout << "�� ������� �������� ��� ������";
			cout << "�� ������� �������� ������. \n";
			system("pause");
			break;

		case 6:
			system("cls");
			cout << "���������� ������.";
			return(false);

		default:
			system("cls");
			cout << "�� ����� �������� ������� ������\n";
			system("pause");
			break;
		}
	}
}