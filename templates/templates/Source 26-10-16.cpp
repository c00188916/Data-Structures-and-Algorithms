#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(int argc, char *argv[]) {
	std::map<string, int> freq; // Map of words/frequencies
								// Initialize frequency table from command line
	for (int i = 1; i < argc; i++) {
		std::map<string, int>::iterator iter = freq.find(argv[i]);
		int frequency = (iter == freq.end() ? 0 : iter->second);
		freq[argv[i]] = ++frequency;
	}
	//-- Write count/word. Iterator returns key/value pair.
	std::map<string, int>::const_iterator iter;
	for (iter = freq.begin(); iter != freq.end(); ++iter) {
		cout << iter->second << " " << iter->first << endl;
	}

	system("PAUSE");
}