#include <iostream>
#include <cmath>

using namespace std;

class Circle {
public:
	Circle(int radius) {
		Circle::radius = radius;
	}
	int radius;
	double getArea() {
		return 3.14 * pow(radius, 2);
	};
};

class Cake : public Circle {

};

int main() {
	Circle ccl(13);
	printf("%lf\n", ccl.getArea());

	return 0;
}