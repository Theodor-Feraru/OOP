#include<iostream>
#include<cmath>

using namespace std;

class Point
{
private:
	
	int _x, _y;

public:
	Point(int x, int y)
	{
		_x = x;
		_y = y;
	}

	void set_coords(int x, int y)
	{
		_x = x;
		_y = y;
	}

	int get_x()
	{
		return _x;
	}

	int get_y()
	{
		return _y;
	}

	static float distance(Point, Point);
	static float triangle_area(Point, Point, Point);
	static bool coliniarity(Point, Point, Point);
	static void property(Point, Point, Point);
	static void equation(Point, Point);
};

float Point::distance(Point a, Point b)
{
	return sqrt(pow(a.get_x() - b.get_x(), 2) + pow(a.get_y() - b.get_y(), 2));
}

float Point::triangle_area(Point a, Point b, Point c)
{
	Point m = Point((a.get_x() + b.get_x()) / 2, (a.get_y() + b.get_y()) / 2);
	float height = Point::distance(c, m);
	float base = Point::distance(a, b);

	return base * height / 2;
}

bool Point::coliniarity(Point a, Point b, Point c)
{
	if (triangle_area(a, b, c) == 0) return true;
	return false;
}

void Point::property(Point a, Point b, Point c)
{
	float ab = distance(a, b);
	float bc = distance(b, c);
	float ac = distance(a, c);

	if (ab == bc && bc == ac)
	{
		cout << "ABC -> equilateral triangle\n";
		return;
	}
	else if (ab == bc || bc == ac || ac == ab)
	{
		cout << "ABC -> isosceles triangle\n";
		return;
	}
	
	if (pow(ab, 2) == pow(bc, 2) + pow(ac, 2) || pow(bc, 2) == pow(ab, 2) + pow(ac, 2) || pow(ac, 2) == pow(bc, 2) + pow(ab, 2))
	{
		cout << "ABC -> right triangle\n";
		return;
	}

	cout << "ABC -> ordinary triangle\n";
}

void Point::equation(Point a, Point b)
{
	if (a.get_x() == b.get_y())
	{
		cout << "x = " << a.get_x();
		return;
	}
	if (a.get_y() == b.get_y())
	{
		cout << "y = " << a.get_y();
		return;
	}

	float coef_x = b.get_y() - a.get_y();
	float coef_y = b.get_x() - a.get_x();

	float free_term = (coef_x * a.get_x() + coef_y * a.get_y())/coef_y;
	coef_x /= coef_y;

	cout << "y = " << coef_x << "x + " << free_term << endl;
}

void main()
{
	Point a = Point(3, 1);
	Point b = Point(2, 2);
	Point c = Point(3, 3);

	cout << "Distance A -> B: " << Point::distance(a, b) << endl;
	cout << "Distance B -> C: " << Point::distance(b, c) << endl;
	cout << "Distance C -> A: " << Point::distance(c, a) << endl;
	cout << "Area of triangle: " << Point::triangle_area(a, b, c) << endl;
	Point::property(a, b, c);

	cout << "Equation of AB: ";
	Point::equation(a, b);
	cout << "Equation of BC: ";
	Point::equation(b, c);
	cout << "Equation of AC: ";
	Point::equation(a, c);
}
