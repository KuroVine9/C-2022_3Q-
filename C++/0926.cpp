#include <iostream>
#include <cmath>



#if 0
class TestClass {
private:
	int x;
	int y;
public:
	TestClass(int x, int y) {
		this->x = x;
		TestClass::y = y;
	}
	void PrintCom() const {
		printf("X: %d\tY: %d\n", x, y);
	}
};

int main() {
	TestClass test = TestClass(5, 5);
	test.PrintCom();

	TestClass* test1 = new TestClass(2, 6);
	test1->PrintCom();
	delete test1;

	TestClass test2(1, 7);
	/*TestClass test2 = { 1, 5 };*/
	test2.PrintCom();

	return 0;
}
#endif

#if 0
class Circle {
private:
	int radius;
public:
	Circle() :Circle(1) {}
	Circle(int radius) {
		printf("°´Ã¼ »ı¼ºµÊ(%d)\n",radius);
		this->radius = radius;
	}
	~Circle() {
		printf("°´Ã¼ ¼Ò¸êµÊ(%d)\n",radius);
	}
	double getArea() {
		return 3.14 * pow(radius, 2);
	}
};

int main() {
	Circle donut(3);
	Circle pizza;
	printf("%.2lf\t%.2lf\n", donut.getArea(), pizza.getArea());

	return 0;
}
#endif

#if 0
class AAA {
private:
	int& ref;
	const int& num;
public:
	AAA(int& a, const int& b) :ref(a), num(b) {	//constÈ­µÈ º¯¼ö ÃÊ±âÈ­ À§ÇØ »ç¿ë
		printf("%d, %d\n", a, b);
	}
};

int main() {
	int a = 1;
	AAA aaa(a, 2);

	return 0;
}
#endif

class CTest {
private:
	int num;
public:
	CTest(int num) {
		this->num = num;
	}
	CTest& Adder(int n) {
		this->num += n;
		return *this;
	}
	CTest& ShowNumber() {
		printf("%d\n", num);
		return *this;
	}
};

int main() {
	CTest a(5);
	a.Adder(2).Adder(6).ShowNumber();

	return 0;
}