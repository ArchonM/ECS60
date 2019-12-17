#include "priorityqueue.h"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
	int index = 0;
	std::ifstream file;
	file.open(argv[1]);
	nlohmann::json jsonObject;
	if (file.is_open()) {
		file >> jsonObject;
	}
	file.close();
	Queue Value;
	Value.SetSize(jsonObject["metadata"]["maxHeapSize"]);
	for (auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr) {
		if (index < jsonObject["metadata"]["numOperations"]) {
			if (itr.value()["operation"] == "insert") {
				Value.insert(itr.value()["key"]);
			}
			else if (itr.value()["operation"] == "removeMax") {
				Value.removeMax();
			}
			else if (itr.value()["operation"] == "removeKey") {
				Value.removeKey(itr.value()["key"]);
			}
			else if (itr.value()["operation"] == "change") {
				Value.change(itr.value()["key"], itr.value()["newKey"]);
			}
		}
		index++;
	}
	Value.print(jsonObject["metadata"]["numOperations"]);
	return 0;
}