#include "../src/geometry_lib/check_figure.hpp"
#include "../src/geometry_lib/check_separator.hpp"
#include "../src/geometry_lib/circle_area.hpp"
#include "../src/geometry_lib/circle_perimeter.hpp"
#include "../src/geometry_lib/get_circle_params.hpp"
#include "../src/geometry_lib/get_triangle_params.hpp"
#include "../src/geometry_lib/intersection_of_circles.hpp"
#include "../src/geometry_lib/length_of_segment.hpp"
#include "../src/geometry_lib/triangle_area.hpp"
#include "../src/geometry_lib/triangle_perimeter.hpp"
#include "../thirdparty/ctest.h"
#include <string>

CTEST(triangle_perimeter, test_int)
{
    const double expected = 9;
    double a = 2;
    double b = 3;
    double c = 4;
    double result = triangle_perimeter(a, b, c);
    ASSERT_DBL_NEAR(expected, result);
}

CTEST(triangle_perimeter, test_double)
{
    const double expected = 10;
    double a = 2.5;
    double b = 3.5;
    double c = 4;
    double result = triangle_perimeter(a, b, c);
    ASSERT_DBL_NEAR(expected, result);
}

CTEST(triangle_area, test_double)
{
    const double expected = 5.28;
    double a = 6;
    double b = 5;
    double c = 2.2;
    double perimeter = 13.2;
    double result = triangle_area(a, b, c, perimeter);
    ASSERT_DBL_NEAR(expected, result);
}

CTEST(length_of_segment, test_int)
{
    const double expected = 3;
    double x1 = 1, x2 = 4, y1 = 3, y2 = 3;
    double result = length_of_segment(x1, y1, x2, y2);
    ASSERT_DBL_NEAR(expected, result);
}

CTEST(length_of_segment, test_double)
{
    const double expected = 3.1622777;
    double x1 = 1, x2 = 4, y1 = 3, y2 = 4;
    double result = length_of_segment(x1, y1, x2, y2);
    ASSERT_DBL_NEAR(expected, result);
}

CTEST(intersection_of_circles, test_true)
{
    double x1 = 3, y1 = 4, x2 = 6, y2 = 3, radius1 = 2, radius2 = 3;
    bool result = intersection_of_circles(x1, y1, radius1, x2, y2, radius2);
    ASSERT_TRUE(result);
}

CTEST(intersection_of_circles, test_false)
{
    double x1 = 3, y1 = 4, x2 = 11, y2 = 3, radius1 = 2, radius2 = 1;
    bool result = intersection_of_circles(x1, y1, radius1, x2, y2, radius2);
    ASSERT_FALSE(result);
}

CTEST(get_triangle_params, test_double)
{
    const double expected0 = -3;
    const double expected1 = -2;
    const double expected2 = -1;
    const double expected3 = 0;
    const double expected4 = -3.3;
    const double expected5 = 2;
    const double expected6 = -3;
    const double expected7 = -2;

    string input = "triangle((-3 -2, -1 0.0, -3.3 2.0, -3 -2))";
    vector<double> result = get_triangle_params(input);
    double result0 = result[0], result1 = result[1], result2 = result[2],
           result3 = result[3], result4 = result[4], result5 = result[5],
           result6 = result[6], result7 = result[7];

    ASSERT_DBL_NEAR(expected0, result0);
    ASSERT_DBL_NEAR(expected1, result1);
    ASSERT_DBL_NEAR(expected2, result2);
    ASSERT_DBL_NEAR(expected3, result3);
    ASSERT_DBL_NEAR(expected4, result4);
    ASSERT_DBL_NEAR(expected5, result5);
    ASSERT_DBL_NEAR(expected6, result6);
    ASSERT_DBL_NEAR(expected7, result7);
}

CTEST(get_circle_params, test_double)
{
    const double expected0 = 3;
    const double expected1 = 4;
    const double expected2 = 2;

    string input = "circle(3 4, 2)";
    vector<double> result = get_circle_params(input);
    double result0 = result[0], result1 = result[1], result2 = result[2];

    ASSERT_DBL_NEAR(expected0, result0);
    ASSERT_DBL_NEAR(expected1, result1);
    ASSERT_DBL_NEAR(expected2, result2);
}

CTEST(circle_area, test_double)
{
    const double expected = 12.5663706;
    double radius = 2;
    double result = circle_area(radius);
    ASSERT_DBL_NEAR(expected, result);
}

CTEST(circle_perimeter, test_double)
{
    const double expected = 12.5663706;
    double radius = 2;
    double result = circle_perimeter(radius);
    ASSERT_DBL_NEAR(expected, result);
}

CTEST(check_separator, test_true)
{
    char open_bracket = '(';
    char close_bracket = '(';
    char space = ' ';
    char comma = ',';

    ASSERT_TRUE(check_separator(open_bracket));
    ASSERT_TRUE(check_separator(close_bracket));
    ASSERT_TRUE(check_separator(space));
    ASSERT_TRUE(check_separator(comma));
}

CTEST(check_figure, test_triangle)
{
    const char* expected = "triangle";
    string input = "triangle((-3 -2, -1 0.0, -3.0 2.0, -3 -2))";
    const char* result = check_figure(input).c_str();
    ASSERT_STR(expected, result);
}

CTEST(check_figure, test_circle)
{
    const char* expected = "circle";
    string input = "circle(3 4, 2)";
    const char* result = check_figure(input).c_str();
    ASSERT_STR(expected, result);
}

CTEST(check_figure, test_not_found)
{
    const char* expected = "not found";
    string input = "circdsfdsle(3 4, 2)";
    const char* result = check_figure(input).c_str();
    ASSERT_STR(expected, result);
}