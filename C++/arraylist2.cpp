#include <iostream>
#include <iterator>

template <typename T>
struct _Node {
	_Node(T data = NULL, _Node* next = nullptr) : data(data), next(next) {}
	T data;
	_Node* next;
};


//template <typename T>
//class iterator {
//	typedef struct _Node<T> Node;
//private:
//	Node* curr;
//public:
//	iterator(Node* start = nullptr) : curr(start) {}
//	iterator& operator++() {
//		curr = curr->next;
//		return *this;
//	}
//
//	T& operator*() {
//		return curr->data;
//	}
//
//	bool operator!=(const iterator& i) {
//		return (curr != i.curr);
//	}
//};


template <typename T>
class ArrayList {
//	typedef struct Node {
//		Node(T data = NULL, Node* next = nullptr) : data(data), next(next) {}
//		T data;
//		Node* next;
//} Node;
	typedef struct _Node<T> Node;
	class iterator {
		typedef struct _Node<T> Node;
	private:
		Node* curr;
	public:
		iterator(Node* start = nullptr) : curr(start) {}
		iterator& operator++() {
			curr = curr->next;
			return *this;
		}

		T& operator*() {
			return curr->data;
		}

		bool operator!=(const iterator& i) {
			return (curr != i.curr);
		}
	};
private:
	Node* start_point;
	int list_size;
public:
	ArrayList() :list_size(0), start_point(nullptr) {}
	ArrayList& push_back(T val) {
		Node* search = start_point;
		Node* new_node = new Node(val);

		if (start_point == nullptr) start_point = new_node;
		else {
			while (search->next != nullptr) search = search->next;
			search->next = new_node;
		}
		return *this;
	}

	T& operator[](int index) {
		Node* search = start_point;
		for (; index > 0; index--) search = search->next;
		return search->data;
	}

	iterator begin() {
		return iterator(start_point);
	}

	iterator end() {
		return iterator(nullptr);
	}
};

int main() {
	using namespace std;

	ArrayList<int> a;
	a.push_back(1).push_back(2);

	copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));

	return 0;
}