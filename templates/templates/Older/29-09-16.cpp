#include <vector>
#include <iostream>
#include <algorithm>

//int main() {
//	std::vector<int> v;
//	v.push_back(35);
//	v.push_back(10);
//	v.push_back(5);						// order is 35,10,5
//	auto iter = v.begin();
//	v.insert(iter, 3, 100);				// order is 100,100,100,35,10,5
//	iter = v.begin();
//	v.erase(iter);						// remove the element pointed to by iter
//	iter = v.erase(iter, iter + 2);		// remove the next two elements,
//										// order is now 35,10,5
//	sort(v.begin(), v.end());			// sort is an STL algorithm
//										// order is now 5, 10, 35
//										// iterate over entire vector v and output the sorted vector
//
//	for (iter = v.begin(); iter != v.end(); ++iter) {
//		std::cout << *iter << std::endl;
//	}
//
//}

// Sample Particle class.
class Particle {
private:
	int m_ttl;
public:
	Particle(int ttl = 10) : m_ttl(ttl) {}
	int ttl() const { return m_ttl; }
};
// A global predicate.
bool isExpired(Particle const & particle) {
	// Assumes ttl can never be negative.
	return (particle.ttl() == 0);
}

class IsExpired {
public:
	bool operator() (Particle const & particle) const {
		// Assumes ttl can never be negative.
		return (particle.ttl() == 0);
	}
};

int main() {
	//std::vector<int> v;
	//v.push_back(3);
	//for (int i = 0; i < 10; ++i) {
	//	// Note: 3 will now appear twice in the vector
	//	v.push_back(i);
	//}
	//v.erase(remove(v.begin(), v.end(), 3), v.end());

	std::vector<Particle> v;
	for (int i = 0; i < 5; i++)
	{
		v.push_back(Particle(i));
	}
	v.erase(remove_if(v.begin(), v.end(), IsExpired()), v.end());
}
