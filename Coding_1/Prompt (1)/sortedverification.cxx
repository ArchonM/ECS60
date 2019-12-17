#include <cstdio>
#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <vector>

#include "json.hpp"

using json = nlohmann::json;
using namespace std;

int main(int argc, char** argv) {

    ifstream file;
    file.open(argv[1]);
    json jsonObject;
    // Store the contents filename into jsonObject
    if (file.is_open()) {
        file >> jsonObject;
    }
    file.close();

    //initiate
    int arrayNum = jsonObject["metadata"]["numSamples"];
    int arraySize = jsonObject["metadata"]["arraySize"];
    int inversion = 0;
    bool is_Sorted = true;
    int total_inversion = 0;
    json result;

    for (auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr) {
        if (itr.key() != "metadata")
        {
            for (int i = 0; i < arraySize-1; i++)
            {
                if (itr.value()[i] >= itr.value()[i+1])
                {
                    result[itr.key()]["ConsecutiveInversions"][to_string(i)] = {itr.value()[i], itr.value()[i+1]};
                    inversion++;
                    is_Sorted = false;
                }
            }
        }
        if (!is_Sorted)
        {
            total_inversion++;
            is_Sorted = true;
            result[itr.key()]["sample"] = itr.value();
        }
    }

    result["metadata"]["arraySize"] = arraySize;
    result["metadata"]["file"] = argv[1];
    result["metadata"]["numSamples"] = arrayNum;
    result["metadata"]["samplesWithInversions"] = total_inversion;

    cout<<result<<endl;

    return 0;
}
