#include <cstdio>
#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

#include "json.hpp"
#include "mergesort.h"
#include "insertionsort.h"
#include "quicksort.h"

using json = nlohmann::json;
using namespace std;

int main(int argc, char** argv) {

    json jsonObject;
    ifstream file;
    file.open(argv[1]);

    if (file.is_open())
    {
        file >> jsonObject;
    }

    file.close();

    std::vector<int> test;
    std::vector<int> temp;

    int arratNum = jsonObject["metadata"]["numSamples"];
    int arraySize = jsonObject["metadata"]["arraySize"];
    unsigned long long start = 0;
    unsigned long long end = 0;
    unsigned long long double timeCost = 0;
    int num_Cmp = 0;
    int num_MemoAccess = 0;

    cout<<"Sample,InsertionSortTime,InsertionSortCompares,InsertionSortMemaccess,MergeSortTime,MergeSortCompares,MergeSortMemaccess,QuickSortTime,QuickSortCompares,QuickSortMemaccess"<<endl;
    for (auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr)
    {

        if (itr.key() != "metadata")
        {
            cout<<itr.key()<<",";
            for (int i = 0; i < arraySize; i++)
            {
                test.push_back(itr.value()[i]);
            }
            temp = test;

            start = clock();
            InsertionSort(&temp, &num_Cmp, &num_MemoAccess);
            end = clock();
            timeCost = (end - start)/CLOCKS_PER_SEC;
            cout<<setiosflags(ios::showpoint)<<setprecision(7)<<(double) timeCost<<",";
            cout<<num_Cmp<<","<<num_MemoAccess<<",";
            temp = test;
            num_Cmp = 0;
            num_MemoAccess = 0;

            start = clock();
            MergeSort(&temp, &num_Cmp, &num_MemoAccess);
            end = clock();
            timeCost = (end - start)/CLOCKS_PER_SEC;
            cout<<setiosflags(ios::showpoint)<<setprecision(7)<<(double) timeCost<<",";
            cout<<num_Cmp<<","<<num_MemoAccess<<",";
            temp = test;
            num_Cmp = 0;
            num_MemoAccess = 0;

            start = clock();
            QuickSort(&temp, &num_Cmp, &num_MemoAccess);
            end = clock();
            timeCost = (end - start)/CLOCKS_PER_SEC;
            cout<<setiosflags(ios::showpoint)<<setprecision(7)<<(double) timeCost<<",";
            cout<<num_Cmp<<","<<num_MemoAccess;
            temp = test;
            num_Cmp = 0;
            num_MemoAccess = 0;



            test.clear();
            temp.clear();
            cout<<endl;
        }

    }


}
