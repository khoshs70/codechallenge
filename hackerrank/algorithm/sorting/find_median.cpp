#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// not a good solution
void find_median() {
    /*int size;
    cin >> size;
    vector<int> vec;
    for (int i = 0; i < size; i++) {
        int item;
        cin >> item;
        vec.push_back(item);
    }*/

    vector<int> vec = { 0, 1, 2, 4, 6, 5, 3 ,5,4,8,11,34,77,45,33,42,65,89,90,65,37,35,3,1,4,6,8,42,68,66,42,22,6,9,98,97,94,25,27,29,101};
    vector<int>::iterator iter = vec.begin();
    int size = vec.size();
    int median = (size - 1 + 0) / 2;
    nth_element(vec.begin(), vec.begin() + median, vec.end());
    cout << vec[median];
}

void find_median0() {

}

