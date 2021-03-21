#include <vector>
#include <iostream>
#include <random>

using namespace std;

int randPivot(int l, int h) {
    srand(time(nullptr));
    return l + rand() % (h-l);
}

int randPartition(vector<double>& array, int low, int high) {
    int pivotIndex = randPivot(low, high);
    swap(array[pivotIndex], array[high]);
    double pivot = array[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++) {
        if(array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i+1], array[high]);
    return i + 1;
}

int partition(vector<double>& array, int low, int high) {
    double pivot = array[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++) {
        if(array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i+1], array[high]);
    return i + 1;
}

int medianOf3Partition(vector<double>& array, int low, int high) {
    int mid = (low+high)/2;
    if(array[mid] < array[low])
        swap(array[low], array[mid]);
    if(array[high] < array[low])
        swap(array[low], array[high]);
    if(array[mid] < array[high])
        swap(array[mid], array[high]);
    if(array[low] > array[mid])
        swap(array[low], array[high]);
    double pivot = array[high];
    
    int i = low - 1;
    for(int j = low; j <= high - 1; j++) {
        if(array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i+1], array[high]);
    return i + 1;
}

//median of 3 for the pivot and 3-way partitioning
void medianOf3Partition3(vector<double>& array, int low, int high, int& i, int& j) {
    i = low - 1, j = high;
    int p = low - 1, q = high;

    int mid = (low+high)/2;
    if(array[mid] < array[low])
        swap(array[low], array[mid]);
    if(array[high] < array[low])
        swap(array[low], array[high]);
    if(array[mid] < array[high])
        swap(array[mid], array[high]);
    if(array[low] > array[mid])
        swap(array[low], array[high]);
    double pivot = array[high];
    mid = low;
    
    while(true) {
        while(array[++i] < pivot)
            ;
        
        while(pivot < array[--j])
            if(j == low)
                break;

        if(i >= j)
            break;

        swap(array[i], array[j]);

        if(array[i] == pivot) {
            p++;
            swap(array[p], array[i]);
        }

        if(array[j] == pivot) {
            q--;
            swap(array[j], array[q]);
        }
    }

    swap(array[i], array[high]);

    j = i - 1;
    for(int k = low; k < p; k++, j--)
        swap(array[k], array[j]);

    i++;
    for(int k = high - 1; k > q; k--, i++)
        swap(array[i], array[k]);
}

void quickSort(vector<double>& array, int low, int high) {
    if(low < high) {
        int i, j;
        medianOf3Partition3(array, low, high, i, j);

        quickSort(array, low, j);
        quickSort(array, i, high);
    }
}

void randQuickSort(vector<double>& array, int low, int high) {
    if(low < high) {
        int index = randPartition(array, low, high);

        randQuickSort(array, low, index - 1);
        randQuickSort(array, index + 1, high);
    }
}