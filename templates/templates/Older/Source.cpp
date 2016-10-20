#include <iostream>

//Declares the template function.
template <typename T>
T sum(T const* pArray, int const ELEMENTS);

//Template function that won't work.
template <typename T>
T wontWork(T value);

int main() {
	int intArray[] = { 1,2,3,4 };
	float floatArray[] = { 1.0f,2.0f,3.0f,4.5f };

	std::cout << sum(intArray, 4) << std::endl;
	std::cout << sum(floatArray, 4) << std::endl;
	system("PAUSE");
}

template <typename T>
T sum(T const* pArray, int const ELEMENTS) {
	T sum = 0;
	for (int index = 0; index < ELEMENTS; index++) {
		sum += pArray[index] * pArray[index];
	}
	return sum;
}

template<typename T>
T wontWork(T value) {
	T val;
	return val;
}