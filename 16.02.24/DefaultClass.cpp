#include <iostream>

using namespace std;

template<typename T>
struct Node {
	T value;
	Node<T>* left = nullptr;
	Node<T>* right = nullptr;
};

template<typename T>
class BinaryTree {
private:
	Node<T>* root = nullptr;
	int count = 0;

	void showAll(Node<T>* el) {
		cout << el->value << " ";
		if (el->left != nullptr) {
			showAll(el->left);
		}
		if (el->right != nullptr) {
			showAll(el->right);
		}
	}
public:
	void add(T value) {
		Node<T>* newNode = new Node<T>{ value };
		if (root == nullptr) {
			root = newNode;
			count++;
			return;
		}
		Node<T>* buf = root;
		while (true) {
			if (value > buf->value) {
				if (buf->right == nullptr) {
					buf->right = newNode;
					break;
				}
				buf = buf->right;
			}
			else {
				if (buf->left == nullptr) {
					buf->left = newNode;
					break;
				}
				buf = buf->left;
			}
		}
		count++;
	}
	
	void remove(T el) {
		Node<T>* parent = root;
		Node<T>* buf
		while (el !=) {
			if (el > buf->value) {

			}
			else if (el < buf->value) {

			}
		}
	}

	void show() {
		if (root != nullptr) {
			showAll(root);
		}
	}
};

int main() {
	int ar[]{ 13, 43, 55, 32, 64, 21 };
	BinaryTree<int> bt;
	for (int i = 0; i < size(ar); i++) {
		bt.add(ar[i]);
	}
	bt.show();
}