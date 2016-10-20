#include <vector>
#include <iostream>
#include <algorithm>

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
private:
	int m_ttl;
public:
	IsExpired(int ttl) : m_ttl(ttl){

	}
	bool operator() (Particle const & particle) const {
		// Assumes ttl can never be negative.
		return (particle.ttl() == m_ttl);
	}
};

int main() {
	std::vector<Particle> v;
	for (int i = 0; i < 5; ++i) {
		// Each Particle has a different ttl
		v.push_back(Particle(i));
	}
	std::cout << "Enter ttl: ";
	int ttl;
	std::cin >> ttl;
	// Lets erase the particles with a ttl of 0.

	v.erase(remove_if(v.begin(), v.end(), IsExpired(ttl)), v.end());

	//auto endOfRangeIter = remove_if(v.begin(), v.end(), isExpired);

	system("PAUSE");
}