/*
https://www.hackerrank.com/challenges/find-median-1
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

/*

class BaseA {
public:
    static void func() {
        cout << "BaseA\n";
    }
};
class HeapA: public BaseA {
public:
    static void func() {
        cout << "HeapA\n";
    }
};

*/

void heap_findmedian_impl(vector<int> &vec, int value) {
    auto pos = lower_bound(vec.begin(), vec.end(), value);
    vec.insert(pos, value);
    int i = vec.size() - 1;
    if (i % 2 == 0) {
        float median = vec[i / 2];
        cout << median << std::endl;
    }
    else {
        float median1 = vec[i / 2];        
        float median2 = vec[i / 2 + 1];
        cout << (median1 + median2) / 2 << std::endl;
    }
}

void heap_find_median() {

    int n;
    cin >> n;
    vector<int> vec;
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout.setf(ios::fixed);

    for (int i = 0; i < n; i++) {
        int item;
        cin >> item;
        //vec.push_back(item);
        heap_findmedian_impl(vec, item);
    }
}