#include <gtest/gtest.h>

#include <stdexcept>

#include <iostream>

#include <functions/figure_functions.h>

using namespace kos;
 
TEST(FunctionsTests, p_len_Test1) {
    Point x = { -2,1 }, y = { 1,1 };
    float len = x.p_len(y);
    EXPECT_NEAR(len, 3, 0.1);
}

TEST(FunctionsTests, get_type_Test2) {
    Point cur_point[2] = { -1,1,1,-1};
    Figure cur_figure(rectangle, cur_point);
    FigureType cure_type = cur_figure.get_type();
    EXPECT_EQ(cure_type, rectangle);
}

TEST(FunctionsTests, get_point_Test3) {
    Point cur_point[2] = { -1,1,1,-1 };
    Figure cur_figure(rectangle, cur_point);
    char coordinate = 'y';
    float cur_Point = cur_figure.get_point(coordinate, 1);
    EXPECT_EQ(cur_Point , -1);
}

//TEST(FunctionsTests, get_perim_ForRectangle_Test4) {
//    Point cur_point[4] = { -1,1,1,-1 };
//    Figure cur_figure(rectangle, cur_point);
//    float cur_perim = cur_figure.get_perim();
//    EXPECT_EQ(cur_perim, 8);
//}
TEST(FunctionsTests, get_perim_ForEllipse_Test5) {
    Point cur_point[4] = { -1,0,0,1,1,0,0,-1 };
    Figure cur_figure(ellipse, cur_point);
    float cur_perim = cur_figure.get_perim();
    EXPECT_NEAR(cur_perim, 6.28, 0.1);
}
TEST(FunctionsTests, get_perim_ForTrapezoid_Test6) {
    Point cur_point[4] = {-1,3,1,3,5,0,-5,0};
    Figure cur_figure(trapezoid, cur_point);
    float cur_perim = cur_figure.get_perim();
    EXPECT_NEAR(cur_perim, 22, 0.1);
}
TEST(FunctionsTests, get_square_ForEllipse_Test7) {
    Point cur_point[4] = { -1,0,0,1,1,0,0,-1 };
    Figure cur_figure(ellipse, cur_point);
    float cur_square = cur_figure.get_square();
    EXPECT_NEAR(cur_square, 3.14, 0.1);
}
TEST(FunctionsTests, get_squareFor_Trapezoid_Test8) {
    Point cur_point[4] = { -1,1,1,1,2,0,-2,0 };
    Figure cur_figure(trapezoid, cur_point);
    float cur_square = cur_figure.get_square();
    EXPECT_NEAR(cur_square, 3 , 0.1);
}
//TEST(FunctionsTests, get_square_ForRectangle_Test9) {
//    Point cur_point[2] = { -1,1,1,-1 };
//    Figure cur_figure(rectangle, cur_point);
//    float cur_square = cur_figure.get_square();
//    EXPECT_NEAR(cur_square, 4 , 0.1);
//}

TEST(FunctionsTests, set_min_framing_rectangle_For_Ellipse_Test10) {
    //Point cur_point[4] = { -1,0,0,1,1,0,0,-1 };
    float cur_points[4] = { -1, 0 , 0, 1 };
    Figure cur_figure; //(ellipse, cur_point);
    cur_figure.create_ellipse(cur_points);
    Figure framing_rectangle;
    framing_rectangle.set_min_framing_rectangle(cur_figure);
    int flag=0;
   // Point right_points[4] = { -1,1,1,1,1,-1,-1,-1 };
    float right_point[4] = { -1,1,1,-1 };
    Figure right_figure;//(rectangle, right_points);
    right_figure.create_rectangle(right_point);
    if (framing_rectangle == right_figure)
        flag++;
    EXPECT_TRUE(flag);
}

TEST(FunctionsTests, set_min_framing_rectangle_Fortrapezoid_Test11) {
    Point cur_point[4] = { -1,1,1,1,2,0,-2,0 };
    Figure cur_figure(trapezoid, cur_point);
    Figure framing_rectangle;
    framing_rectangle.set_min_framing_rectangle(cur_figure);
    int flag = 0;
    Point right_points[4] = { -2,1,2,1,2,0,-2,0 };
    Figure right_figure(rectangle, right_points);
    if (framing_rectangle == right_figure)
        flag++;
    EXPECT_TRUE(flag);
}

TEST(FunctionsTests, set_min_framing_rectangle_Forrectangle_Test12) {
    Point cur_point[2] = { -1,1,1,-1 };
    Figure cur_figure(rectangle, cur_point);
    Figure framing_rectangle;
    framing_rectangle.set_min_framing_rectangle(cur_figure);
    int flag = 0;
    if (framing_rectangle == cur_figure)
        flag++;
    EXPECT_TRUE(flag);
}

TEST(FunctionsTests, get_size_Test13) {
    FigureList sample_list;
    float sample_points[4] = { -1,1,1,-1 };
    Figure sample_figure;
    sample_list.figure_add(sample_figure.create_rectangle(sample_points));
    int a = sample_list.get_size();
    EXPECT_EQ(a, 1);
}

TEST(FunctionsTests, indexed_get_figure_add_Test14) {
    FigureList sample_list;
    float sample_points[4] = { -1,1,1,-1 };
    Point sample_points_p[4] = { -1,1,1,1,1,-1,-1,-1 };
    Figure sample_figure(rectangle, sample_points_p);
    sample_list.figure_add(sample_figure.create_rectangle(sample_points));
    Figure test_figure = *sample_list.indexed_get(0);
    int flag = 0;
    if (test_figure == sample_figure) {
        flag++;
    }
    EXPECT_TRUE(flag);
}

TEST(FunctionsTests, figure_insert_Test15) {
    FigureList sample_list;
    Figure figure;
    float sample_points[4] = { -1,1,1,-1};
    float sample_points_2[4] = { -2,0,0,1 };
    sample_list.figure_add(figure.create_rectangle(sample_points));
    sample_list.figure_insert(figure.create_ellipse(sample_points_2), 0);
    bool flag = false;
    if (*sample_list.indexed_get(0) == *figure.create_ellipse(sample_points_2))
        flag = true;
    EXPECT_TRUE(flag);
}

TEST(FunctionsTests, indexed_delete_Test16) {
    FigureList sample_list;
    Figure figure;
    bool flag = false;
    float sample_point1[4] = { -1,1,1,-1};
    sample_list.figure_add(figure.create_rectangle(sample_point1));
    float sample_point2[4] = { -2,0,0,1 };
    sample_list.figure_insert(figure.create_ellipse(sample_point2), 0);
    sample_list.indexed_delete(0);
    if (*sample_list.indexed_get(0) == *figure.create_rectangle(sample_point1)) {
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(FunctionsTests, max_square_search_Test17) {
    Figure figure;
    FigureList sample_list;
    float ellipse_points[4] = { -2,0,0,1 };
    float trapezoid_points[8] = {-9,9,9,9,8,0,-8,0};
    float rectangle_points[4] = {-4,3,4,-3};

    sample_list.figure_add(figure.create_ellipse(ellipse_points));
    sample_list.figure_add(figure.create_trapezoid(trapezoid_points));
    sample_list.figure_add(figure.create_rectangle(rectangle_points));

    bool flag = false;
    if (sample_list.max_square_search() == *figure.create_trapezoid(trapezoid_points)) {
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(FunctionsTests, max_square_search_emptylist_Test18) {
    FigureList sample_list;
    Point ellipse_points[4] = { -2,0,0,1,2,0,0,-1 };
    Point trapezoid_points[4] = { -9,9,9,9,8,0,-8,0 };
    Point rectangle_points[4] = { -4,3,4,3,4,-3,-4,-3 };
    Figure test_ellipse(ellipse, ellipse_points);
    Figure test_trapezoid(trapezoid, trapezoid_points);
    Figure test_rectangle(rectangle, rectangle_points);
    Figure result_figure;
    int flag = 0;
    try {
        result_figure = sample_list.max_square_search();
    }
    catch (int error) {
        std::cout << "\n\tIndex is Out_of_range\n\n";
        flag++;
    }
    if (result_figure == test_trapezoid) {
        flag++;
    }
    EXPECT_TRUE(flag);
}

TEST(FunctionsTests, indexed_get_figure_add_invalidindex_Test19) {
    Figure figure;
    FigureList sample_list;
    float sample_points[4] = { -1,1,1,-1 };
    sample_list.figure_add(figure.create_rectangle(sample_points));
    Figure test_figure;
    int flag = 0;
    try {
        test_figure = *sample_list.indexed_get(-1);
    }
    catch (int error) {
        std::cout << "\n\tIndex is Out_of_range\n\n";
        flag++;
    }
    if (test_figure == figure) {
        flag++;
    }
    EXPECT_TRUE(flag);
}


TEST(FunctionsTests, indexed_delete_invalidindex_Test20) {
    FigureList sample_list;
    Point sample_points[4] = { -1,1,1,1,1,-1,-1,-1 };
    Figure sample_figure(rectangle, sample_points), figure;
    Figure void_figure;
    sample_list.figure_add(figure.create(rectangle, sample_points));
    Point cur_point[4] = { -1,1,1,1,2,0,-2,0 };
    Figure cur_figure(trapezoid, cur_point);
    sample_list.figure_add(figure.create(trapezoid, cur_point));
    bool flag = false;
    /*sample_list.indexed_delete(-1);
    if (*sample_list.indexed_get(0) == cur_figure) {
        flag = true;
    }
EXPECT_TRUE(flag);*/
    EXPECT_ANY_THROW(sample_list.indexed_delete(-1), std::runtime_error);
}



