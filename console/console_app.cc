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
				for (int i = 0; i < 8; ++i)
					cin >> points[i];
				create_ellipse(points, right_points);
				Ellipse ellipse(right_points);
				cout << "\n������� ������ (�� 1 �� " << figure_list.size() + 1 << "), �� �������� �� ������ �������� �������: " << endl;
				cin >> index;
				figure_list.figure_insert(make_shared<Ellipse>(ellipse), index - 1);
			}
			else if (temp == 2) {
				cout << "\n������� ��������� ���������� x � y ��� ������ �����: " << endl;
				for (int i = 0; i < 8; ++i)
					cin >> points[i];
				create_trapezoid(points, right_points);
				Trapezoid trapezoid(right_points); 
				cout << "\n������� ������ (�� 1 �� " << figure_list.size() + 1 << "), �� �������� �� ������ �������� �������: " << endl;
				cin >> index;
				figure_list.figure_insert(make_shared<Trapezoid>(trapezoid), index - 1);
			}
			else if (temp == 3) {
				cout << "\n������� ��������� ���������� x � y ��� ������ �����: " << endl;
				for (int i = 0; i < 8; ++i)
					cin >> points[i];
				create_rectangle(points, right_points);
				Rectangle rectangle(right_points);
				cout << "\n������� ������ (�� 1 �� " << figure_list.size() + 1 << "), �� �������� �� ������ �������� �������: " << endl;
				cin >> index;
				figure_list.figure_insert(make_shared<Rectangle>(rectangle), index - 1);
			}
			else
				cout << "�� ������� �������� ��� ������";
			cout << "�� ������� �������� �������.\n" << endl;
			system("pause");
			break;

		case 2:
			system("cls");
			cout << "2. ������� ������� �� ������ �� ���������� �������\n" << endl;
			cout << "\n������� ������ �������� ������� ����� ������� �� 1 �� " << figure_list.size() + 1 << endl;
			cin >> index;
			figure_list.indexed_delete(index - 1);
			cout << "�������� ������ �������.\n" << endl;
			system("pause");
			break;

		case 3:
			system("cls");
			cout << "3. ������� ������ �� �����\n" << endl;
			figure_list.print();
			system("pause");
			break;

		case 4: 
			system("cls");
			cout << "4. ����� � ������ ������ ������ � ������������ ��������\n" << endl;
			cout << "��������� ������ � ����� ������� ��������: \n" << endl;
			figure_list.max_square_search().print();
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
				create_ellipse(points, right_points);
				Ellipse ellipse(right_points);
				figure_list.figure_add(make_shared<Ellipse>(ellipse));
			}
			else if (temp == 2) {
				cout << "\n������� ��������� ���������� x � y ��� ������ �����: " << endl;
				for (int i = 0; i < 8; ++i)
					cin >> points[i];
				create_trapezoid(points, right_points);
				Trapezoid trapezoid(right_points);
				figure_list.figure_add(make_shared<Trapezoid>(trapezoid));
			}
			else if (temp == 3) {
				cout << "\n������� ��������� ���������� x � y ��� ������ �����: " << endl;
				for (int i = 0; i < 4; ++i)
					cin >> points[i];
				create_rectangle(points, right_points);
				Rectangle rectangle(right_points);
				figure_list.figure_add(make_shared<Rectangle>(rectangle));
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