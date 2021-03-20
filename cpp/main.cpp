#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cmath>
#include <fstream>
#include "mergesort.cpp"
//#include "insertionsort.cpp"
#include "selectionsort.cpp"
#include "bubblesort.cpp"
#include "introsort.cpp"

using namespace std;
using namespace chrono;

vector<double> makeRandArray(int size) {
    vector<double> arr;
    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<double> distr(0,1);

    for(int x = 0; x < size; x++) {
        arr.push_back(distr(eng));
    }

    return arr;
}

vector<double> makeSortedArray(int size) {
    vector<double> arr;

    for(int i = 0; i < size; i++)
        arr.push_back(i);
    
    return arr;
}

vector<double> makeReverseArray(int size) {
    vector<double> arr;

    for(int i = size; i > 0; i--)
        arr.push_back(i);

    return arr;
}

vector<double> makeConstantArray(int size) {
    vector<double> arr;

    for(int i = 0; i < size; i++)
        arr.push_back(10);
    
    return arr;
}

void printArray(vector<double> a) {
    cout << "[";
    for(double x : a)
        cout << " " << x << ",";
    cout << " ]" << endl;
}

bool isSorted(vector<double> check) {
    for(int x = 0; x < check.size() - 1; x++)
        if(check[x] > check[x+1])
            return false;

    return true;
}

long getTime() {
    auto duration = system_clock::now().time_since_epoch();
    return duration_cast<milliseconds>(duration).count();
}


int main() {
    ofstream myfile;
    myfile.open("./cpp/data.csv");
    myfile << "Array Size,Intro,std::sort,Merge,Heap" << endl;
    int s = 2000000, begin = 50000, step = 50000;

    for(int i = begin; i <= s; i += step) {
        double quickTime = 0, introTime = 0, stdTime = 0, mergeTime = 0, heapTime = 0;
        for(int x = 0; x < 20; x++) {
            vector<double> res = makeConstantArray(i);
            
            long millis = getTime();
            //quickSort(res, 0, i-1);
            long millis2 = getTime();
            //quickTime += millis2 - millis;
            //make sure our implementation of quicksort is working
            if(!isSorted(res))
                return 1;
            
            res = makeConstantArray(i);

            millis = getTime();
            introSort(res, 0, i-1);
            millis2 = getTime();
            introTime += millis2 - millis;
            //make sure our implementation of hybridsort is working
            if(!isSorted(res))
                return 1;

            res = makeConstantArray(i);

            millis = getTime();
            sort(res.begin(), res.end());
            millis2 = getTime();
            stdTime += millis2 - millis;
            
            res = makeConstantArray(i);
            
            millis = getTime();
            mergeSort(res, 0, i-1);
            millis2 = getTime();
            mergeTime += millis2 - millis;
            //make sure our implementation of mergesort is working
            if(!isSorted(res))
                return 1;

            res = makeConstantArray(i);
            
            millis = getTime();
            make_heap(res.begin(), res.end());
            sort_heap(res.begin(), res.end());
            millis2 = getTime();
            heapTime += millis2 - millis;
            //make sure our implementation of mergesort is working
            if(!isSorted(res))
                return 1;
            
            /*
            res = makeRandArray(i);
            
            millis = getTime();
            insertionSort(res);
            millis2 = getTime();
            cout << "Runtime of insertion sort: " << millis2 - millis << "ms" << endl;
            //make sure our implementation of insertion sort is working
            if(!isSorted(res))
                return 1;

            res = makeRandArray(i);
            
            millis = getTime();
            selectionSort(res);
            millis2 = getTime();
            cout << "Runtime of selection sort: " << millis2 - millis << "ms" << endl;
            //make sure our implementation of selection sort is working
            if(!isSorted(res))
                return 1;

            res = makeRandArray(i);
            
            millis = getTime();
            bubbleSort(res);
            millis2 = getTime();
            cout << "Runtime of bubble sort: " << millis2 - millis << "ms" << endl;
            //make sure our implementation of bubble sort is working
            if(!isSorted(res))
                return 1;*/

            
        }
        quickTime /= 20;
        introTime /= 20;
        stdTime /= 20;
        mergeTime /= 20;
        heapTime /= 20;

        myfile <<  i << "," << introTime << "," << stdTime << "," << mergeTime << "," << heapTime << endl;

        cout << "Array of size " << i << endl;
        //cout << "Runtime of quicksort: " << quickTime << "ms" << endl;
        cout << "Runtime of introsort: " << introTime << "ms" << endl;
        cout << "Runtime of std::sort: " << stdTime << "ms" << endl;
        cout << "Runtime of mergesort: " << mergeTime << "ms" << endl;
        cout << "Runtime of heap sort: " << heapTime << "ms" << endl;

        cout << endl;
    }

    myfile.close();

    return 0;
}