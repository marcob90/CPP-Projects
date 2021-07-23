#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
 
int main() {
 
	std::map<std::string, int> mapOfWordCount;
	// Insert Element in map
	mapOfWordCount.insert({"first", 1});
	mapOfWordCount.insert(std::pair<std::string, int>("second", 2));
	mapOfWordCount.insert(std::pair<std::string, int>("third", 3));
	mapOfWordCount.insert(std::pair<std::string, int>("third", 4));
	mapOfWordCount.insert(std::pair<std::string, int>("third", 5));
 
	// Create a map iterator and point to beginning of map
	std::map<std::string, int>::iterator it = mapOfWordCount.begin();
 
	// Iterate over the map using Iterator till end.
	while (it != mapOfWordCount.end())
	{
		// Accessing KEY from element pointed by it.
		std::string word = it->first;
 
		// Accessing VALUE from element pointed by it.
		int count = it->second;
 
		std::cout << word << " :: " << count << std::endl;
 
		// Increment the Iterator to point to next entry
		it++;
	}
	return 0;
}
