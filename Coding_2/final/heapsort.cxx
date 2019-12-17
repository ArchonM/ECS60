#include "priorityqueue.h"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int main(int argc, char** argv) {
	int index = 0;
	std::ifstream file;
	file.open(argv[1]);
	nlohmann::json jsonObject;
	if (file.is_open()) {
		file >> jsonObject;
	}
	file.close();
	nlohmann::json Result;
	for (auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr) {
		if (index < jsonObject["metadata"]["numSamples"]) {
			Queue Value;
			Value.SetSize(jsonObject["metadata"]["maxHeapSize"]);
			vector<int> Sorted;
			for (int num = 0; num < jsonObject["metadata"]["arraySize"]; num++) {
				Value.insert(itr.value()[num]);
			}
			for (int i = jsonObject["metadata"]["arraySize"]; i > 0; i--) {
				Sorted.push_back(Value.getTop());
			}
			reverse(Sorted.begin(), Sorted.end());
			Result[itr.key()] = Sorted;
		}
		index++;
	}
	Result["metadata"]["arraySize"] = jsonObject["metadata"]["arraySize"];
	Result["metadata"]["numSamples"] = jsonObject["metadata"]["numSamples"];
	std::cout << Result.dump(2) << endl;
	//system("pause");
	return 0;
}
