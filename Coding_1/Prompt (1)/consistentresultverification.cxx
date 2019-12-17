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

    json sample1;
    json sample2;

    ifstream file;
    file.open(argv[1]);
    if (file.is_open()) {
        file >> sample1;
    }
    file.close();

    file.open(argv[2]);
    if (file.is_open()) {
        file >> sample2;
    }
    file.close();

    json result;
    int arraySize = sample1["metadata"]["arraySize"];
    int mismatch = 0;
    int total_mismatch = 0;
    bool is_matched = true;



    for (auto itr = sample1.begin(); itr != sample1.end(); ++itr) {
        if (itr.key() != "metadata")
        {
            for (int i = 0; i < arraySize; i++)
            {
                if (itr.value()[i] != sample2[itr.key()][i])
                {

                    result[itr.key()]["Mismatches"][to_string(i)] = {itr.value()[i], sample2[itr.key()][i]};
                    mismatch++;
                    is_matched = false;
                }
            }
        }
        if(!is_matched)
        {
            total_mismatch++;
            is_matched = true;
            result[itr.key()]["sample1"] = itr.value();
            result[itr.key()]["sample2"] = sample2[itr.key()];
        }
    }

    result["metadata"]["samplesWithConflictingResults"] = total_mismatch;
    result["sample1"]["metadata"]["arraySize"] = sample1["metadata"]["arraySize"];
    result["sample1"]["metadata"]["file"] = argv[1];
    result["sample1"]["metadata"]["numSamples"] = sample1["metadata"]["numSamples"];
    result["sample2"]["metadata"]["arraySize"] = sample2["metadata"]["arraySize"];
    result["sample2"]["metadata"]["file"] = argv[2];
    result["sample2"]["metadata"]["numSamples"] = sample2["metadata"]["numSamples"];

    cout<<result<<endl;

    return 0;
}
