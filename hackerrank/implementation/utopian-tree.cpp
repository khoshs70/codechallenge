#include <iostream>
#include <vector>

using namespace std;

void utopian_tree() {
    int cases;
    cin >> cases;
    vector<int> vec;
    while (cases--) {
        int cycle;
        cin >> cycle;
        int value = 1;
        for (int i = 1; i <= cycle; i++) {
            if (i % 2 == 1)
                value *= 2;
            else
                value += 1;
        } 
        vec.push_back(value);
    }
    for (auto &item : vec) {
        cout << item << std::endl;
    }
}