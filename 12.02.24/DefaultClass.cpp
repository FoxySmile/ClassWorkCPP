#include <iostream>

using namespace std;

template <typename T>
class Stack {
private:
	T* stack = nullptr;
	int count = 0;
	int capacity;
public:
	Stack(int capacity){
		stack = new T[capacity];
		this->capacity = capacity;
	}
	Stack(Stack& st) {
		this->count = st.count;
		this->capacity = st.capacity;
		if (stack != nullptr) {
			delete[]stack;
		}
		stack = new T[count];
		for (int i = 0; i < count; i++) {
			stack[i] = st.stack[i];
		}
	}

	~Stack() {
		if (this->stack != nullptr); {
			delete[] stack;
		}
	}

	Stack operator= (Stack& st) {
		this->count = st.count;
		this->capacity = st.capacity;
		if (stack != nullptr) {
			delete[]stack;
		}
		stack = new T[count];
		for (int i = 0; i < count; i++) {
			stack[i] = st.stack[i];
		}
	}

	T top() {
		return stack[count-1];
	}

	bool empty() {
		return !count;
	}

	int size() {
		return count;
	}

	void add(T el) {
		if (count >= capacity) return;
		stack[count++] = el;
	}

	T remove() {
		if (count == 0) return NULL;
		count--;
		return stack[count];
	}
};

template <typename T>
void showInfo(Stack <T> stack) {
	while (!stack.empty()) {
		cout << stack.remove() << ", ";
	}
}

template <typename T>
class Queue {
private:
	T* queue = nullptr;
	int count = 0;
	int capacity;
public:
	Queue(int capacity) {
		queue = new T[capacity];
		this->capacity = capacity;
	}
	Queue(Queue& qu) {
		this->count = qu.count;
		this->capacity = qu.capacity;
		if (queue != nullptr) {
			delete[]queue;
		}
		queue = new T[count];
		for (int i = 0; i < count; i++) {
			queue[i] = qu.queue[i];
		}
	}
	~Queue() {
		if (queue != nullptr) {
			delete[]queue;
		}
	}

	void operator= (Queue& qu) {
		this->capacity = qu.capacity;
		this->count = qu.count;
		if (queue != nullptr) {
			delete[]queue;
		}
		queue = new T[count];
		for (int i = 0; i < count; i++) {
			queue[i] = qu.queue[i];
		}
	}

	void add(T el) {
		if (count >= capacity) {
			return;
		}
		queue[count++] = el;
	}

	bool empty() {
		return !count;
	}

	T front() {
		return queue[0];
	}

	T back() {
		return queue[count - 1];
	}

	int size() {
		return count;
	}

	T remove() {
		if (count <= 0) return NULL;
		T buf = queue[0];
		for (int i = 0; i < count - 1; i++) {
			queue[i] = queue[i + 1];
		}
		count--;
		return buf;
	}

	T push_range(Queue qu) {
		if (count + qu.count > capacity) return;
		for (int i = 0; i < count; i++) {
			queue[count++] = qu.queue[i];
		}
	}
};

template <typename T>
void showQueue(Queue <T> qu) {
	while (!qu.empty()) {
		cout << qu.remove() << ", ";
	}
}

int main() {
	/*Stack<int> st(10);
	for (int i = 0; i < 10; i++) {
		st.add(i);
	}
	showInfo(st);*/
	Queue<int> qu(3);
	qu.add(10);
	qu.add(22);
	showQueue(qu);
}