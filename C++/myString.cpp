#define _CRT_SECURE_NO_WARNINGS
#define MODE 0
// 0: 연결리스트 1: 동적배열
#include <iostream>
#include <cstring>

using namespace std;

// 동적배열로 구현
#if MODE
class myString {
private: 
	char* data;
	int size;
public:
	myString(char* str): size(strlen(str)) {
		data = new char[strlen(str) + 1];
		strcpy(data, str);
	}
	myString() : data(nullptr), size(0) {}

	char operator[](int index) const {
		return data[index];
	}

	myString operator+(myString& val) {
		char* temp = new char[this->size + val.size + 1];
		strcpy(temp, this->data);
		strcat(temp, val.data);
		return myString(temp);
	}

	myString& operator=(const myString& val) {
		delete[] data;
		data = new char[val.size + 1];
		strcpy(data, val.data);
		this->size = val.size;
		return *this;
	}

	void operator+=(const myString& val) {
		data = strcat(this->data, val.data);
		size += val.size;
	}

	bool operator==(const myString& val) {
		return !(strcmp(this->data, val.data));
	}

	int getSize() {
		return size;
	}

	friend ostream& operator<<(ostream& os, const myString& str);
	friend istream& operator>>(istream& is, myString& str);

	~myString() {
		if(!data) delete[] data;
	}
};
ostream& operator<<(ostream& os, const myString& str) {
	for (int i = 0; str[i]!='\0'; i++) os << str[i];
	return os;
}
istream& operator>>(istream& is, myString& str) {
	char temp[100];
	is >> temp;
	str = myString(temp);
	return is;
}
#endif

// 연결리스트로 구현
#if !MODE
typedef struct _Node {
	_Node(char data = NULL) : data(data), prev(nullptr), next(nullptr) {}
	char data;
	struct _Node* prev, * next;
} Node;
class LinkedString {
private:
	Node* start_point;
	int list_size;
public:
	LinkedString() : start_point(nullptr), list_size(0) {}
	LinkedString(char* str) : start_point(nullptr), list_size(0) {
		for (int i = 0; i<strlen(str); i++) {
			push_back(str[i]);
		}
	}
	LinkedString(LinkedString& val) : start_point(nullptr), list_size(0) {
		for (auto a : val) push_back(a);
	}
	~LinkedString() {
		for (Node* temp = start_point, *search = start_point; temp != nullptr; search = temp) {
			temp = search->next;
			delete search;
		}
	}
	class iterator {
	public:
		Node* search_point;
	public:
		iterator(Node* search_point = nullptr) : search_point(search_point) {}
		iterator& operator++() {
			search_point = search_point->next;
			return *this;
		}
		iterator& operator--() {
			search_point = search_point->prev;
			return *this;
		}
		iterator& operator+(int index) {
			for (; index > 0; index--) search_point = search_point->next;
			return *this;
		}
		iterator& operator-(int index) {
			for (; index > 0; index--) search_point = search_point->prev;
			return *this;
		}
		char& operator*() {
			return search_point->data;
		}
		bool operator==(const iterator& iter) {
			return search_point == iter.search_point;
		}
		bool operator!=(const iterator& iter) {
			return search_point != iter.search_point;
		}
	};
	class reverse_iterator {
	private:
		Node* search_point;
	public:
		reverse_iterator(Node* search_point = nullptr) : search_point(search_point) {}
		reverse_iterator& operator++() {
			search_point = search_point->prev;
			return *this;
		}
		reverse_iterator& operator--() {
			search_point = search_point->next;
			return *this;
		}
		reverse_iterator& operator+(int index) {
			for (; index > 0; index--) search_point = search_point->prev;
			return *this;
		}
		reverse_iterator& operator-(int index) {
			for (; index > 0; index--) search_point = search_point->next;
			return *this;
		}
		char& operator*() {
			return search_point->data;
		}
		bool operator==(const reverse_iterator& riter) {
			return search_point == riter.search_point;
		}
		bool operator!=(const reverse_iterator& riter) {
			return search_point != riter.search_point;
		}
	};

	char& operator[] (int index) {
		Node* search;
		for (search = start_point; index > 0; index--) {
			search = search->next;
		}
		return search->data;
	}
	char& front() {
		return start_point->data;
	}
	char& back() {
		Node* search = start_point;
		for (; search->next != nullptr; search = search->next);
		return search->data;
	}
	LinkedString operator+(LinkedString& val) {
		if (start_point == nullptr) return val;
		else {
			LinkedString temp;
			for (auto a: *this) {
				temp.push_back(a);
			}
			for (auto a : val) { 
				temp.push_back(a);
			}
			return temp;
		}
	}
	void operator+=(LinkedString& val) {
		for (auto a : val) push_back(a);
	}
	bool operator==(LinkedString& val) {
		iterator iter_this = this->begin();
		iterator iter_val = val.begin();
		for (; iter_this != this->end() || iter_val != val.end(); ++iter_this, ++iter_val) {
			if (*iter_this != *iter_val) return false;
		}
		return true;
	}
	LinkedString& push_back(char val) {
		Node* newNode = new Node(val);
		if (start_point == nullptr) {
			start_point = newNode;
		}
		else {
			Node* search;
			for (search = start_point; search->next != nullptr; search = search->next);
			search->next = newNode;
			newNode->prev = search;
		}
		list_size++;
		return *this;
	}
	LinkedString& push_front(char val) {
		Node* newNode = new Node(val);
		newNode->next = start_point;
		start_point->prev = newNode;
		start_point = newNode;
		list_size++;
		return *this;
	}
	LinkedString& pop_back() {
		Node* search;
		for (search = start_point; search->next != nullptr; search = search->next);
		if (search == start_point) { start_point = nullptr; }
		else { search->prev->next = nullptr; }
		delete search;
		list_size--;
		return *this;
	}
	LinkedString& pop_front() {
		if (start_point->next == nullptr) {
			delete start_point;
			start_point = nullptr;
		}
		else {
			Node* search = start_point->next;
			start_point->next->prev = nullptr;
			delete start_point;
			start_point = search;
		}
		list_size--;
		return *this;
	}
	iterator erase(iterator iter) {
		Node* search = iter.search_point;
		if (iter.search_point == start_point) {
			search->next->prev = nullptr;
			start_point = search->next;
		}
		else {
			search->prev->next = search->next;
			if (search->next != nullptr) search->next->prev = search->prev;
		}
		search = search->next;
		delete(iter.search_point);
		list_size--;
		return iterator(search);
	}


	iterator begin() { return iterator(start_point); }
	iterator end() { return iterator(); }
	reverse_iterator rbegin() {
		Node* search;
		for (search = start_point; search->next != nullptr; search = search->next);
		return reverse_iterator(search);
	}
	reverse_iterator rend() { return reverse_iterator(); }

	friend ostream& operator<<(ostream& os, LinkedString& list);
	friend istream& operator>>(istream& is, LinkedString& list);
};
ostream& operator<<(ostream& os, LinkedString& list) {
	for (auto a : list) os << a;
	return os;
}
istream& operator>>(istream& is, LinkedString& list) {
	char* input = new char[100];
	is >> input;
	for (int i = 0; i < strlen(input); i++) list.push_back(input[i]);
	return is;
}
#endif

//동적배열 테스트 main()
#if MODE
int main() {
	myString str1 = "I like ";
	myString str2 = "string class";
	myString str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3) cout << "동일" << endl;
	else cout << "동일하지 않음" << endl;

	myString str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "input: " << str4 << endl;

	return 0;
}
#endif

//연결리스트 테스트 main()
#if !MODE
int main() {
	LinkedString str1 = "I like ";
	LinkedString str2 = "string class";
	LinkedString str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3) cout << "동일" << endl;
	else cout << "동일하지 않음" << endl;

	LinkedString str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "input: " << str4 << endl;

	return 0;
}
#endif