#include <cstdio>
#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

#include "json.hpp"

using json = nlohmann::json;
using namespace std;

int main()
{
    cout<<"current clock: "<< clock()<< endl;
    cout<<"clocks per second: "<< CLOCKS_PER_SEC<< endl;
    json test;
    int i = 1;
    int j = 2;
    char string[] = "Say:";
    long long start = 0;
    long long end = 0;
    double timeCost = 0;

    start = clock();
    test[to_string(i)] = {1, 2};
    test["2"] = 4;
    test[string] = "Hello World!";
    test["2"] = 3;
    test["root"]["array"]["1"] = {1,2};
    test["root"]["array"]["2"] = {2,3};
    test["3"] = test["1"];
    std::vector<int> v(test["1"].begin(), test["1"].end());
    std::vector<int> v1(test["root"]["array"]["2"].begin(),test["root"]["array"]["2"].end());
    json test2;
    test2["root"] = test["root"];
    cout<<test<<endl<<endl;

    cout<<test2<<endl<<endl;

    std::vector<int> temp;
    temp = v;
    temp = v1;

    cout<<temp[1]<<endl;

    end = clock();

    timeCost = (end - start)/CLOCKS_PER_SEC;


    return 0;
}
