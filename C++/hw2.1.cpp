#include <iostream>​

using namespace std;

class Circle {
public:
    int radius;
    double getArea();
};
double Circle::getArea() {
    return 3.14 * radius * radius;
}

int main() {
    Circle *donut = new Circle;
    donut->radius = 1;
    double area = donut->getArea();
    cout << "donut area is " << area << endl;
    delete(donut);

    Circle *pizza = new Circle;
    pizza->radius = 30;
    area = pizza->getArea();
    cout << "pizza area is " << area << endl;
    delete(pizza);

    return 0;
}