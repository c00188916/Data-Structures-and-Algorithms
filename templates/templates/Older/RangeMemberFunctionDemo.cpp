#include <iostream>
#include <vector>

class Particle {
public:
	Particle(int ttl = 0) : m_ttl(ttl) {
		std::cout << "Constructor called " << m_ttl << std::endl;
	}
	// other member functions...
	Particle(Particle const & particle) : m_ttl(particle.m_ttl) {
		std::cout << "Copy constructor called " << m_ttl << std::endl;
	}

	Particle & operator=(Particle const & particle) {
		m_ttl = particle.m_ttl;
		std::cout << "Assignment operator called " << particle.m_ttl << std::endl;
		return *this;
	}

	~Particle() {
		std::cout << " ~Particle() " << m_ttl << std::endl;
	}

private:
	int m_ttl;
};

void main() {


	int numValues = 3;

	Particle data[] = { Particle(1),Particle(2),Particle(3) };
	std::vector<Particle> v;

	//v.reserve(6);
	v.push_back(Particle(4));
	v.push_back(Particle(5));
	v.push_back(Particle(6));

	std::cout << "-------------------------------------" << std::endl;

	std::vector<Particle>::iterator insertLoc(v.begin());

	/*for (int i = 0; i < numValues; ++i) {
		insertLoc = v.insert(insertLoc, data[i]);
		std::cout << "-------------------------------------" << std::endl;
	}*/

	v.insert(v.begin(), data, data + numValues);

	system("PAUSE");
}