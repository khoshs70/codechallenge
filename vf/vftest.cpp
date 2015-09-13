#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
static int wssolution(int A, int B) {
    // write your code in C++11
    A = (A < 0) ? 0 : A;
    if (B == 0)
        return 1;
    if (B < 0)
        return 0;    
    int low = (int)sqrt(A);
    int high = (int)sqrt(B);
    return high - low + 1;
}

void whole_square() {
    cout << wssolution(-100, 0);
    cout << wssolution(-100, 17);
    cout << wssolution(-100, -90);
    cout << wssolution(-1000, 90000);
    cout << wssolution(4, 17);
}

static int sisolution(int N) {
    // write your code in C++11
    std::string s = std::to_string(N);
    sort(s.begin(), s.end());
    int count = 1;
    while (next_permutation(s.begin(), s.end())) {
        //cout << s << std::endl;
        count++;
    }
    return count;
}

int getsum(int n)
{
    return n * (n + 1) / 2;
}

static int arsolution(vector<int> &A) {
    // write your code in C++11    
    int n = A.size();
    if (n < 3)
        return 0;
    int step = A[1]-A[0];
    int start = 0;
    int end = 1;
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (A[i] - A[i - 1] != step) {
            end = i - 1;
            if (end - start + 1 < 3) {
                // not count
            }
            else {
                //count
                int num = (end - start + 1) -3 + 1;
                count += num * (num + 1) / 2;                
                if (count >1000000000) return -1;
            }
            start = i - 1;
            end = i;
            step = A[i] - A[i - 1];
        }
    }
    int num = (n - 1 - start + 1) - 3 + 1;
    count += num * (num + 1) / 2;
    if (count >1000000000) return -1;
    return count;
}

void vftest() {
    //whole_square();
    //cout << sisolution(1213) << std::endl;
    //cout << sisolution(52832) << std::endl;

    vector<int> vec = {-1,1,3,3,3,2,1,0};
    cout << arsolution(vec) << std::endl;
    vector<int> vec1 = { 1,3,5,7,9};
    cout << arsolution(vec1) << std::endl;


}