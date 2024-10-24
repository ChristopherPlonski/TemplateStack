#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

template<typename T>
class Stack {

public:
	Stack() {
		stackVector = vector<T>();
	}
	void push(T value) {
		stackVector.push_back(value);
	}
	T pop() {
		if (stackVector.empty()) {
			throw("Stack is empty");
			return T();
		}

		T topValue = stackVector.back();

		stackVector.pop_back();

		return topValue;
	}

private:
	vector<T> stackVector;

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