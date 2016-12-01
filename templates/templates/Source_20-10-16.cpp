#include <algorithm>
#include <list>
#include <iostream>

class Player {
public: 
	int m_health, m_skillLevel;

	//Overload the < operator
	bool operator<(Player & const p) const {
		return m_health < p.m_health;
	}
};

int main() {
	std::list<int> intList1, intList2;

	intList1.push_back(10);
	intList1.push_back(20);
	intList1.push_back(30);

	auto end = intList1.end();
	//Splice from list1 into list2
	//intList2.splice(intList2.begin(), intList1, end);

	auto it = intList1.begin();
	it++;
	//intList2.splice(intList2.begin(), intList1, it, intList1.end());

	//Range based loop to process the list
	for (auto &i : intList1) {
		std::cout << i << std::endl;
	}
	//CLASS EXERCISE
	std::list<std::string> stringList;
	stringList.push_back("eggs");
	stringList.push_back("milk");
	stringList.push_back("sugar");
	stringList.push_back("chocolate");
	stringList.push_back("flour");

	stringList.pop_front();
	stringList.push_front("coffee");
	auto iter = std::find(stringList.begin(), stringList.end(), "sugar");
	if (iter != stringList.end()) {
		*iter = "honey";
	}
	iter = std::find(stringList.begin(), stringList.end(), "milk");
	stringList.insert(iter, "baking powder");

	std::list<Player> myList;
	Player p1, p2;
	p1.m_health = 10;
	p2.m_health = 5;
	myList.push_back(p1);
	myList.push_back(p2);
	myList.sort();

	system("PAUSE");
}