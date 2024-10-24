#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

template<typename T>

// Class with dynamically allocating heap memory ourselves.
class Stack {

public:
	Stack() {
		stackSize = 0;
		stackArray = new T[0];
	}

	void push(T value) {
		stackSize++;
		T* newStackArray = new T[stackSize];

		for (int i = 0; i < stackSize - 1; i++) {
			newStackArray[i] = stackArray[i];
		}

		newStackArray[stackSize - 1] = value;

		stackArray = newStackArray;
	}

	T pop() {
		if (stackSize == 0) {
			throw("Stack is empty");
			return NULL;
		}

		T topValue = stackArray[stackSize-1];

		stackSize--;
		T* newStackArray = new T[stackSize];

		for (int i = 0; i < stackSize; i++) {
			newStackArray[i] = stackArray[i];
		}

		stackArray = newStackArray;

		return topValue;
	}

private:
	T* stackArray;
	int stackSize;
};

int main() {
	cout << "Tests starting. \n";

	Stack<int> intStack = Stack<int>();

	intStack.push(1);
	intStack.push(2);
	intStack.push(3);

	assert(intStack.pop() == 3);
	assert(intStack.pop() == 2);
	assert(intStack.pop() == 1);

	Stack<string> stringStack = Stack<string>();

	stringStack.push("Hello");
	assert(stringStack.pop() == "Hello");
	stringStack.push("World");
	assert(stringStack.pop() == "World");

	cout << "Tests done. \n";
}

// Working Stack with Vector
//class Stack {
//
//public:
//	Stack() {
//		stackVector = vector<T>();
//	}
//	void push(T value) {
//		stackVector.push_back(value);
//	}
//	T pop() {
//		if (stackVector.empty()) {
//			throw("Stack is empty");
//			return T();
//		}
//
//		T topValue = stackVector.back();
//
//		stackVector.pop_back();
//
//		return topValue;
//	}
//
//private:
//	vector<T> stackVector;
//
//};