/* VECTOR RESIZING
#include <vector>
#include <iostream>

int main() {
	std::vector<int> v;			// declare an int vector
	v.push_back(10);			// add to rear
	v.push_back(20);
	v.push_back(30);
	v.at(0) = v.at(2);			// copy 30 into 10
	v[0] = v[2];				// same as v.at(0) = v.at(2)
	v.pop_back();				// erase the last item
	int size = v.size();		// size should be 2
	v.resize(32);				// make vector hold 32 items
	v.resize(10);				// cells from subscript 2 to subscript 31 are
								// padded with zeros
}
*/

//#include <vector> //Vector Reallocating
//#include <iostream>
//using namespace std;
//int main() {
//	// create vector of size 10, init elements to 0
//	std::vector<int> v(10, 0);
//
//	std::vector<int>::iterator i = v.begin();
//
//	// capacity is 10 (memory reallocation will
//	// occur if another element is added)
//	cout << v.capacity() << endl;
//	cout << v.size() << endl; // size is 10
//							  // memory is reallocated to accommodate growth
//	v.push_back(20);
//	std::cout << *i << std::endl;
//	cout << v.capacity() << endl;
//	system("PAUSE");
//}

//#include <vector>
//#include <iostream>
//using namespace std;
//int main() {
//	std::vector<int> v(10, 0);
//	// capacity is 10
//	cout << v.capacity() << endl;
//	cout << v.size() << endl; // size is 10
//							  // reserve memory for 10 additional elements
//	auto iter = v.begin();
//	v.reserve(20);
//	*iter;
//	// size is 10, capacity is now increased
//	cout << "new capacity" << v.capacity() << endl;
//		system("PAUSE");
//}

#include <vector>
#include <iostream>
using namespace std;
int main() {
	std::vector<int> v(10, 0);
	v.reserve(100000);
	int oldCap = v.capacity();
	std::vector<int>(v).swap(v);
	int newCap = v.capacity();

	cout << "new capacity " << v.capacity() << endl;

	system("PAUSE");
		
}