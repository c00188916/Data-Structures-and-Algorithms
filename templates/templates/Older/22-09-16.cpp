//example of use of auto datatype

#include <iostream>>
#include <algorithm>
#include <vector>

int main() {
	std::vector<int> v;

	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	std::cout << "Smallest Element: ";

	auto result = std::min(v.begin(), v.end());

	std::cout << *result << std::endl;
	system("PAUSE");
}