#include <vector>
#include <math.h>
#include <algorithm>
#include "quicksort.cpp"
#include "insertionsort.cpp"

using namespace std;

void introSorting(vector<double>& array, int low, int high, int depth) {
    if(low >= high)
        return;
    if(high - low > 16) {
        if(!depth) {
            make_heap(array.begin() + low, array.begin() + high+1);
            sort_heap(array.begin() + low, array.begin() + high+1);
        }
        else {
            int i, j;
            medianOf3Partition3(array, low, high, i, j);
            introSorting(array, low, i, depth - 1);
            introSorting(array, j, high, depth - 1);
        }
    }
}

void introSort(vector<double>& arr, int l, int h) {
    int maxDepth = log2(arr.size()) * 2;

    introSorting(arr, l, h, maxDepth);
    insertionSort(arr);
}