#include <iostream>
#include <queue>
#include <functional>
#include <string>
#include <utility>

class Node
{
private:
	std::pair<std::string, int> m_data;
public:
	Node(int cost)
	{
		m_data.second = cost;
	}
	int getCost() const {
		return m_data.second;
	}
};

class NodeComparer
{
private:

public:
	bool operator()(Node const & n1, Node const & n2) {
		return  n1.getCost() < n2.getCost();
	}
};

int main() {
	std::priority_queue<Node, std::vector<Node>, NodeComparer> pq;
	pq.push(Node(10));
	pq.push(Node(20));
	pq.push(Node(30));
	std::cout << pq.top().getCost() << std::endl;
	pq.pop();
	system("PAUSE");
}