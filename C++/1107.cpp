#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point(int x = 0, int y = 0) :x(x), y(y) {}

	void print_point() {
		cout << "x = " << x << ", y = " << y << endl;
	}

	Point operator+(const Point& r) {
		return Point(this->x + r.x, this->y + r.y);
	}

	void operator=(const Point& r) {
		this->x = r.x;
		this->y = r.y;
	}

	Point operator*(int n) {
		return Point(x * n, y * n);
	}

	Point& operator++() {
		this->x += 1;
		this->y += 1;
		return *this;
	}

	Point operator++(int) {
		const Point temp = *this;
		operator++();
		return temp;
	}

	operator string() {
		return "test";
	}

	operator int() {
		return x + y;
	}	

	bool operator<(const Point& p) { return this->x < p.x; }
	bool operator>(const Point& p) { return this->x > p.x; }

	friend Point operator*(int n, Point& p);
	friend ostream& operator<<(ostream& os, Point& p);
};

Point operator*(int n, Point& p) { return p * n; }

ostream& operator<<(ostream& os, Point& p) {
	os << p.x << ", " << p.y;
	return os;
}

int main() {
	Point x(1, 2), y(3, 4);
	x = x + y;
	x.print_point();
	x = x * 5;
	y = 2 * y;
	x.print_point();

	(++x)++;
	x.print_point();

	cout << "======" << endl;

	Point* ptr = new Point(100, 100);

	vector<Point> v;
	v.push_back(x);
	v.push_back(y);
	v.push_back(*ptr);
	sort(v.begin(), v.end());
	for (auto& a : v) a.print_point();
	cout << "x: " << &x << endl;
	cout << "y: " << &y << endl;
	cout << "ptr: " << ptr << endl;


	cout << "======" << endl;
	cout << x;

	return 0;
}