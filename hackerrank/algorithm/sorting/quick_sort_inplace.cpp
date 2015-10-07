/*
https://www.hackerrank.com/challenges/quicksort3/submissions/code/12792295
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int partition(vector<int> &ar, int low, int high) {    
    int pivot = ar[high]; 
    int j = low - 1;
    int i = low;    
    for (i = low; i < high; i++) {
        if (ar[i] < pivot) {
            j++;
            swap(ar[j], ar[i]);
        }
    }
    swap(ar[j + 1], ar[high]); 
    for (int v : ar) {
        cout << v << " ";
    }
    cout << std::endl;
    return j + 1;
}

void quicksort(vector<int> &ar, int low, int high) {
    if (low < high) {
        int mid = partition(ar, low, high);
        quicksort(ar, low, mid - 1);
        quicksort(ar, mid + 1, high);
    }

}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int ar_size;
    vector<int> ar;
    cin >> ar_size;
    for (int _ar_i = 0; _ar_i < ar_size; _ar_i++) {
      int _ar_tmp;
      cin >> _ar_tmp;
      ar.push_back(_ar_tmp);
    }
    quicksort(ar, 0, ar_size - 1);    
    return 0;
}
