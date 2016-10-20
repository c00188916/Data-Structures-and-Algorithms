#include <vector>
#include <iostream>
#include <time.h>

int main() {

	//1 Empty Vector
	std::vector<int> emptyIntVector;

	//2 Vector with 3 random ints*
	std::vector<int> randomInts;
	srand(time(0));
	
	//3 Vector with 3 empty strings**
	std::vector<std::string> emptyStringVector;

	//4 Vector with 3 specified numbers
	std::vector<int> specifiedIntVector;
	specifiedIntVector.push_back(99);
	specifiedIntVector.push_back(88);
	specifiedIntVector.push_back(77);

	//5 Copy of a Vector
	std::vector<int> copyVector = randomInts;

	//6 Vector with first and last elements switched***
	std::vector<int> switchVector;

	//7
	std::vector<int> reducedVector;

	for (int i = 0; i < 3; i++)
	{
		randomInts.push_back(rand()); //* 3 random ints
		emptyStringVector.push_back(""); //** empty strings
		switchVector.push_back(i); 
	}

	int temp = switchVector.front; //*** swapping first element with last
	switchVector.front = switchVector.back;
	switchVector.back = temp;

	system("PAUSE");
}
