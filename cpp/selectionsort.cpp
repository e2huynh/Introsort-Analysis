#include <vector>

using namespace std;

void selectionSort(vector<double>& arr) {
    int i, j, min_idx, n = arr.size();  
    
    for(i = 0; i < n-1; i++) {
        min_idx = i;
        for(j = i+1; j < n; j++)  
            if (arr[j] < arr[min_idx])
                min_idx = j;
  
        swap(arr[min_idx], arr[i]);
    }  
} 