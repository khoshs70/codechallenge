/*
A non-empty zero-indexed array A consisting of N integers is given. Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].

The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

For example, consider array A such that:

A[0] = 3
A[1] = 1
A[2] = 2
A[3] = 4
A[4] = 3
We can split this tape in four places:

P = 1, difference = |3 − 10| = 7
P = 2, difference = |4 − 9| = 5
P = 3, difference = |6 − 7| = 1
P = 4, difference = |10 − 3| = 7
Write a function:

int solution(vector<int> &A);

that, given a non-empty zero-indexed array A of N integers, returns the minimal difference that can be achieved.

For example, given:

A[0] = 3
A[1] = 1
A[2] = 2
A[3] = 4
A[4] = 3
the function should return 1, as explained above.

Assume that:

N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−1,000..1,000].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.

Copyright 2009–2015 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++11
    int sum = accumulate(A.begin(), A.end(), 0);
    int n = A.size();
    int leftsum = 0;
    int mindiff = -1;

    for (int i = 0; i < n-1; i++) {
        leftsum += A[i];
        int rightsum = sum - leftsum;
        if (mindiff == -1) {
            mindiff = abs(leftsum - rightsum);
        }
        else {
            if (abs(leftsum - rightsum) < mindiff) {
                mindiff = abs(leftsum - rightsum);
            }
        }
        
    }
    return mindiff;
    /*
    
    int low = 0, high = n - 1;
    int sumlow = A[0];
    int sumhigh = A[n - 1];

    while (high - low > 1) {
        bool low_flag1 = (A[low + 1] > 0) ? true : false;
        bool high_flag1 = (A[high -1] > 0) ? true : false;
        
        bool low_small = (sumlow < sumhigh) ? true : false;
        bool low_inc = 
        if (sumlow < sumhigh) {
            if (A[low + 1] > 0) {
                low++;
                sumlow += A[low];
            } 
        }            
        else {
            high--;
            sumhigh += A[high];
        }            
    }
    
    return abs(sumlow - sumhigh);
    */

}

void absolute_diff() {
    vector<int> vec = {3,1,2,4,5};
    int ret = solution(vec);
    cout << ret;
}