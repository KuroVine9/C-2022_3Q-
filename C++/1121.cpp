#include <iostream>

typedef struct Node{
	Node(char data = NULL, Node* next = nullptr) :data(data), next(next) {}
	char data;
	Node* next;
} Node;

class myString {
private:
	Node* start_point;
	unsigned int size;
public:
	myString() : start_point(nullptr), size(0) {}

private:
	void push_back(char data) {
		Node* node = new Node(data);
		if (size == 0) start_point = node;
		else()
	}
};