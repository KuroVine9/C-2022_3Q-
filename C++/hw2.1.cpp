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
    Circle *donut = new Circle; //동적할당
    donut->radius = 1;  //. 대신 -> 연산자 사용
    double area = donut->getArea();
    cout << "donut area is " << area << endl;
    delete(donut);

    Circle *pizza = new Circle;
    pizza->radius = 30;
    area = pizza->getArea();
    cout << "pizza area is " << area << endl;

    delete(pizza);  //메모리 해제

    return 0;
}