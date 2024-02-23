#include <iostream> 

using namespace std;

template <class T>
struct Node {
	T value;
	Node* next;
};

template <typename T>
class LinkedList {
private:
	Node<T>* head = nullptr;
	int count = 0;
public:
	void push(T value) {
		Node<T>* newNode = new Node<T>{value, head};
		head = newNode;
		count++;
	}

	void insert(T el, int index) {
		if (index == 0) {
			push(el);
			count++;
			return;
		}
		if (index > count || index < 0) {
			return;
		}
		Node<T>* buf = head;
		for (int i = 0; i < index-1; i++) {
			buf = buf->next;
		}
		Node<T>* newNode = new Node<T>{el, buf->next};
		buf->next = newNode;
		count++;
	}

	void removeElementByIndex(int index) {
		Node<T>* buf = head;
		if (index == 0) {
			dropHead();
			count--;
			return;
		}
		for (int i = 0; i < index-1; i++) {
			buf = buf->next;
		}
		Node<T>* remEl = buf->next;
		buf ->next = buf->next->next;
		delete[] remEl;
		count--;
	}

	void removeElementsByIndex(int index, int num) {
		Node<T>* buf = head;
		if (num > count-1) { return; }
		if (index == 0) {
			for (int i = 0; i < num; i++) {
				dropHead();
				count--;
			}
			return;
		}
		for (int i = 0; i < index - 1; i++) {
			buf = buf->next;
		}
		for (int i = index; i < num + 1; i++) {
			Node<T>* remEl = buf->next;
			buf->next = buf->next->next;
			delete[]remEl;
			count--;
		}
	}

	void dropHead() {
		if (count == 0) {
			return;
		}
		Node<T>* buf = head;
		head = head->next;
		count--;
		delete[] buf;
	}

	void showAll() {
		Node<T>* buf = head;
		while (buf->next != nullptr) {
			cout << buf->value << " ";
			buf = buf->next;
		}
		cout << buf->value << endl;
	}
};

int main() {
	LinkedList<int> list;
	for (int i = 0; i < 10; i++) {
		list.push(i);
	}
	list.showAll();
	list.insert(100, 0);
	list.showAll();

	list.dropHead();
	list.showAll();

	list.removeElementsByIndex(0, 9);
	list.showAll();
}