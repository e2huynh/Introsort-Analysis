#include <vector>
#include <iostream>

using namespace std;

void merge(vector<double>& arr, int left, int mid, int right) {
    int n = mid - left + 1, m = right - mid;
    vector<double> leftArr, rightArr;
    for(int i = 0; i < n; i++)
        leftArr.push_back(arr[left+i]);
    for(int i = 0; i < m; i++)
        rightArr.push_back(arr[mid+1+i]);

    int x = 0, y = 0, k = left;
    while(x < n && y < m) {
        if(leftArr[x] <= rightArr[y])
            arr[k] = leftArr[x++];
        else
            arr[k] = rightArr[y++];
        k++;
    }

    while(x < n) {
        arr[k++] = leftArr[x++];
    }

    while(y < m) {
        arr[k++] = rightArr[y++];
    }
}

void mergeSort(vector<double>& arr, int left, int right) {
    if(left >= right)
        return;
    int mid = (left + right-1) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}