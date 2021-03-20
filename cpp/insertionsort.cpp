#include <vector>

using namespace std;

void insertionSort(vector<double>& arr) { 
    int i, key, j, n = arr.size(); 
    for (i = 1; i < n; i++){ 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 


void insertionSortSubarray(vector<double>& arr, int left, int right) {
    int i, key, j, n = right + 1; 
    for (i = left + 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1;
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
}
 