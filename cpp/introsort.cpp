#include <vector>
#include <math.h>
#include <algorithm>
#include "quicksort.cpp"
#include "insertionsort.cpp"

using namespace std;

void introSorting(vector<double>& array, int low, int high, int depth) {
    if(high - low > 16) {
        if(!depth) {
            make_heap(array.begin() + low, array.begin() + high+1);
            sort_heap(array.begin() + low, array.begin() + high+1);
        }
        else {
            int index = medianOf3Partition(array, low, high);
            introSorting(array, low, index - 1, depth - 1);
            introSorting(array, index + 1, high, depth - 1);
        }
    }
}

void introSort(vector<double>& arr, int l, int h) {
    int maxDepth = log2(arr.size()) * 2;

    introSorting(arr, l, h, maxDepth);
    insertionSort(arr);
}