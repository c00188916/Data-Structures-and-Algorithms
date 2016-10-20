#include <iostream>
#include "Adder.h"
#include <stack>

template <typename T, int size, T zero>
class Array {
private:
	T m_array[size];
public:
	void set(T item, int index) {
		m_array[index] = item;
	}
	T get(int index) {
		return m_array[index];
	}
	void clear(int index) {
		m_array[index] = zero;
	}
};

int main() {
	
	Adder<int> intAdder;
	Adder<float> floatAdder;

	float f;
	int i;

	for (i = 0, f = 0; i < 10; i++, f += 1.1f) {
		intAdder.add(i);
		floatAdder.add(f);
	}
	std::cout << "The integer sum using an intAdder: " << intAdder.sum() << std::endl;

	std::cout << "The float sum using a floatAdder: " << floatAdder.sum() << std::endl;

	Array<int, 3, '3'> myFloatArray;
	myFloatArray.clear(0);

	std::cout << "Enter a number: " << std::endl;
	int number = 0;
	int result = 0;
	std::cin >> number;
	result = number;

	std::stack<int> myStack;

	while (result % 2 == 0)
	{
		myStack.push(result % 2);
		result /= 2;
	}
	myStack.push(result);

	std::string output;

	while (!myStack.empty())
	{
		std::cout << std::endl << myStack.top() << std::endl;
		myStack.pop();
	}



	system("PAUSE");
}
