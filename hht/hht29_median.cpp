#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int toexg = low - 1;
    for (int i = low; i <= high - 1; i++) {
        if (arr[i] <= pivot) {
            swap(arr[toexg + 1], arr[i]);
            toexg++;
        }
    }
    swap(arr[toexg + 1], arr[high]);
    return toexg + 1;
}

static void verify() {
    vector<int> vec = { 0, 1, 2, 4, 6, 5, 3, 5, 4, 8, 11, 34, 77, 45, 33, 42, 65, 89, 90, 65, 37, 35, 3, 1, 4, 6, 8, 42, 68, 66, 42, 22, 6, 9, 98, 97, 94, 25, 27, 29, 101 };
    vector<int>::iterator iter = vec.begin();
    int size = vec.size();
    int median = (size - 1 + 0) / 2;
    nth_element(vec.begin(), vec.begin() + median, vec.end());
    cout << vec[median];
}
void hht29_median() {
    verify();
    //vector<int> vec = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
    vector<int> vec = { 0, 1, 2, 4, 6, 5, 3, 5, 4, 8, 11, 34, 77, 45, 33, 42, 65, 89, 90, 65, 37, 35, 3, 1, 4, 6, 8, 42, 68, 66, 42, 22, 6, 9, 98, 97, 94, 25, 27, 29, 101 };
    int nth = (vec.size()-1) / 2;
    int low = 0;
    int high = vec.size() - 1;
    int cut = partition(&vec[0], low, high);
    while (cut!=nth) {        
        if (cut < nth) {
            low = cut + 1;
        }
        else  {
            high = cut - 1;
        } 
        cut = partition(&vec[0], low, high);
    }
    cout << vec[nth];
}
