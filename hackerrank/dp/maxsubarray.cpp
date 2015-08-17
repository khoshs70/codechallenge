#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

void maxsub() {
    //vector<int> vec = { 2, - 1, 2, 3, 4, - 5 };
    int num;
    cin >> num;
    int maxsum[10], tmpsum[10], notcontsum[10];

    for (int j = 0; j < num; j++) {
        int size;
        cin >> size;
        vector<int> vec;
        for (int s = 0; s < size; s++) {
            int v;
            cin >> v;
            vec.push_back(v);
        }

        
        int n = vec.size();
        int start = 0;
        int lastneg = 1;
        tmpsum[j] = 0;
        for (; start < n; start++) {
            if (vec[start] > 0) {
                tmpsum[j] = vec[start];
                start++;
                break;
            }
            else {
                if (lastneg == 1)
                    lastneg = vec[start];
                else if (vec[start]>lastneg)
                    lastneg = vec[start];
            }
        }

        if (start == n) {
            if (tmpsum[j]>0) {
                notcontsum[j] = maxsum[j] = tmpsum[j];
            }
            else {
                notcontsum[j] = maxsum[j] = tmpsum[j] = lastneg;
            }            
        }
        else {
            notcontsum[j] = maxsum[j] = tmpsum[j];
        }

        if (tmpsum[j]>0) {
            for (int i = start; i < n; i++) {
                if (vec[i] >0)
                    notcontsum[j] += vec[i];
                if (tmpsum[j] > 0)
                    tmpsum[j] += vec[i];
                else
                    tmpsum[j] = vec[i];
                if (tmpsum[j] > maxsum[j])
                    maxsum[j] = tmpsum[j];

            }
        }
    }
    for (int j = 0; j < num; j++) {
        cout << maxsum[j] << " " << notcontsum[j] << std::endl;
    }

}