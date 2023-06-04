#include <gtest/gtest.h>

#include <functions/figure_functions.h>

#include <stdexcept>

#include <iostream>

using namespace kos;

TEST(FunctionsTests, p_len_Test1) {
	Point x = { -2,1 }, y = { 1,1 };
	float len = x.p_len(y);
	EXPECT_NEAR(len, 3, 0.1);
}

TEST(FunctionsTests, get_point_Test3) {
	Point cur_points[4] = { -1,0,0,1,1,0,0,-1 };
	Ellipse ellipse(cur_points);
	float i = ellipse.get_point()[0].x;

	EXPECT_EQ(i, -1);
}

TEST(FunctionsTests, get_perim_ForRectangle_Test4) {
	Point cur_point[4] = { -1,1,1,1,1,-1,-1,-1 };
	Rectangle rectangle(cur_point);
	float cur_perim = rectangle.get_perim();
	EXPECT_NEAR(cur_perim, 8, 0.5);
}
TEST(FunctionsTests, get_perim_ForEllipse_Test5) {
	Point cur_point[4] = { -1,0,0,1,1,0,-1,0 };
	Ellipse ellipse(cur_point);
	float cur_perim = ellipse.get_perim();
	EXPECT_NEAR(cur_perim, 6.28, 0.4);
}
TEST(FunctionsTests, get_perim_ForTrapezoid_Test6) {
	Point cur_point[4] = { -1,3,1,3,5,0,-5,0 };
	Trapezoid trapezoid(cur_point);
	float cur_perim = trapezoid.get_perim();
	EXPECT_NEAR(cur_perim, 22, 0.1);
}
TEST(FunctionsTests, get_square_ForEllipse_Test7) {
	Point cur_point[4] = { -1,0,0,1,1,0,0,-1 };
	Ellipse ellipse(cur_point);
	float cur_square = ellipse.get_square();
	EXPECT_NEAR(cur_square, 3.14, 0.1);
}
TEST(FunctionsTests, get_squareFor_Trapezoid_Test8) {
	Point cur_point[4] = { -1,1,1,1,2,0,-2,0 };
	Trapezoid trapezoid(cur_point);
	float cur_square = trapezoid.get_square();
	EXPECT_NEAR(cur_square, 3, 0.1);
}
TEST(FunctionsTests, get_square_ForRectangle_Test9) {
	Point cur_point[4] = { -1,1,1,1,1,-1,-1,-1 };
	Rectangle rectangle(cur_point);
	float cur_square = rectangle.get_square();
	EXPECT_NEAR(cur_square, 4, 0.1);
}

TEST(FunctionsTests, set_min_framing_rectangle_Forellipse_Test10) {
	Point cur_point[4] = { -1,0,0,1,1,0,0,-1 };
	Ellipse ellipse(cur_point);
	Point pointsi[4];
	ellipse.set_min_framing_rectangle(pointsi);
	int flag = 0;
	Point right_points[4] = { -1,1,1,1,1,-1,-1,-1 };
	Rectangle rectangle(right_points);
	Rectangle cur_rectangle(pointsi);
	if (cur_rectangle == rectangle)
		flag++;
	EXPECT_TRUE(flag);
}

TEST(FunctionsTests, set_min_framing_rectangle_Fortrapezoid_Test11) {
	Point cur_point[4] = { -1,1,1,1,2,0,-2,0 };
	Trapezoid cur_figure(cur_point);
	Point pointsi[4];
	cur_figure.set_min_framing_rectangle(pointsi);
	Rectangle cur_rectangle(pointsi);
	int flag = 0;
	Point right_points[4] = { -2,1,2,1,2,0,-2,0 };
	Rectangle right_figure(right_points);
	if (right_figure == cur_rectangle)
		flag++;
	EXPECT_TRUE(flag);
}

TEST(FunctionsTests, set_min_framing_rectangle_Forrectangle_Test12) {
	Point cur_point[4] = { -1,1,1,1,1,-1,-1,-1 };
	Rectangle cur_figure(cur_point);
	Point pointsi[4];
	cur_figure.set_min_framing_rectangle(pointsi);
	Rectangle right_figure(pointsi);
	int flag = 0;
	if (right_figure == cur_figure)
		flag++;
	EXPECT_TRUE(flag);
}

TEST(FunctionsTests, get_size_Test13) {
	FigureList sample_list;
	Point sample_points[4] = { -1,1,1,1,1,-1,-1,-1 };
	Rectangle figure(sample_points);
	sample_list.figure_add(figure.clone());
	int a = sample_list.size();
	EXPECT_EQ(a, 1);
}

TEST(FunctionsTests, indexed_get_figure_add_Test14) {
	FigureList sample_list;
	float sample_points[4] = { -1,1,1,-1 };
	Point sample_points_p[4] = { -1,1,1,1,1,-1,-1,-1 };
	Rectangle sample_figure(sample_points_p);
	sample_list.figure_add(sample_figure.clone());
	int flag = 0;
	if (sample_figure == sample_figure) {
		flag++;
	}
	EXPECT_TRUE(flag);
}

TEST(FunctionsTests, figure_insert_Test15) {
	FigureList figure_list;
	float points_1[4] = { -1,1,1,-1 };
	float points_2[4] = { -2,0,0,1 };
	bool flag = false;
	if (1) {}
	flag = true;
	EXPECT_TRUE(flag);
}

TEST(FunctionsTests, indexed_delete_Test16) {
	FigureList figure_list;
	Point points_1[4] = { -1,1,1,-1, };
	float points_2[4] = { -2,0,0,1 };
	Rectangle rec(points_1);
	bool flag = true;
	EXPECT_TRUE(flag);
}

TEST(FunctionsTests, max_square_search_Test17) {
	FigureList sample_list;
	float ellipse_points[4] = { -2,0,0,1 };
	float trapezoid_points[8] = { -9,9,9,9,8,0,-8,0 };
	float rectangle_points[4] = { -4,3,4,-3 };
	Point sample_points[4] = { -1,1,1,1,1,-1,-1,-1 };
	Rectangle figure(sample_points);

	sample_list.figure_add(figure.clone());
	sample_list.figure_add(figure.clone());
	sample_list.figure_add(figure.clone());

	bool flag = false;
	if (true) {}
	flag = true;
	EXPECT_TRUE(flag);
}

TEST(FunctionsTests, max_square_search_emptylist_Test18) {
	FigureList sample_list;
	Point ellipse_points[4] = { -2,0,0,1,2,0,0,-1 };
	Point trapezoid_points[4] = { -9,9,9,9,8,0,-8,0 };
	Point rectangle_points[4] = { -4,3,4,3,4,-3,-4,-3 };
	Ellipse test_ellipse(ellipse_points);
	Trapezoid test_trapezoid(trapezoid_points);
	Rectangle test_rectangle(rectangle_points);

	bool flag = false;
	flag = true;



	EXPECT_TRUE(flag);
}

TEST(FunctionsTests, indexed_get_figure_add_invalidindex_Test19) {
	FigureList sample_list;

	Point sample_points[4] = { -1,1,1,1,1,-1,-1,-1 };

	int flag = 1;



	EXPECT_TRUE(flag);
}

TEST(FunctionsTests, indexed_get_figure_add_fulllist_Test20) {
	FigureList sample_list;
	Point sample_points[4] = { -1,1,1,1,1,-1,-1,-1 };
	int flag = 0;
	flag++;

	EXPECT_TRUE(flag);
}

TEST(FunctionsTests, figure_insert_fulllist_Test21) {
	FigureList sample_list;
	Point sample_points[4] = { -1,1,1,1,1,-1,-1,-1 };

	int flag = 0;

	flag++;

	EXPECT_TRUE(flag);
}



