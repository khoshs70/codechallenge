/*
https://www.hackerrank.com/challenges/maxsubarray
The max sum for both contiguous and non-contiguous elements is the sum of ALL the elements (as they are all positive).

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

void maxsub0() {
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
            // 找到第一个大于0的值，其实没有必要，因为可以通过检查cursum是否大于0来判断
            if (vec[start] > 0) {
                tmpsum[j] = vec[start];
                start++;
                break;
            }
            else {
                //找到最后一个最接近于0的负数，也没有必要，只为了设置一个阀值？
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
                notcontsum[j] = maxsum[j] = tmpsum[j] = lastneg;//设置最接近0的负数，什么意思？
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

int findmaxsub(vector<int> &arr, int &arg) {
    int n = arr.size();
    int sum = 0;
    int big = ~0;
    int ncsum = 0;
    for (int i = 0; i < n; i++) {
        if (sum < 0) {
            sum = arr[i];
        }
        else {
            sum += arr[i];            
        }
        if (arr[i] > 0) {
            ncsum += arr[i];
        }
        big = max(sum, big);
    }
    if (big == ~0) {
        big = arr[0];
        arg = arr[0];
    }
    else {
        arg = ncsum;
    }    
    
    return big;
}

void maxsub() {
    int num;
    cin >> num;    
    vector<pair<int, int>> vsum;// (num, make_pair(0, 0));

    for (int j = 0; j < num; j++) {
        int size;
        cin >> size;
        vector<int> vec;
        for (int s = 0; s < size; s++) {
            int v;
            cin >> v;
            vec.push_back(v);
        }
        int ncsum = 0;    
        int sum = findmaxsub(vec, ncsum);
        vsum.push_back(make_pair(sum,ncsum));        
    }

    for (auto pair : vsum) {
        cout << pair.first << " " << pair.second << std::endl;
    }    
}