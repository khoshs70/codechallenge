/*
A zero-indexed array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:

int solution(int A[], int N);

that, given a zero-indexed array A, returns the value of the missing element.

For example, given array A such that:

A[0] = 2
A[1] = 3
A[2] = 1
A[3] = 5
the function should return 4, as it is the missing element.

Assume that:

N is an integer within the range [0..100,000];
the elements of A are all distinct;
each element of array A is an integer within the range [1..(N + 1)].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// corner case , single element, 2 element, first or last element miss

static int solution(vector<int> &A) {
    // write your code in C++11
    if (A.empty())
        return 1;
    int n = A.size();

    int misssum = 0;
    int maxVal = 0;
    for (auto i : A) {
        misssum += i;
        maxVal = max(i, maxVal);
    }
    
    if (maxVal <= n)
        return n+1;

    int sum = 0;
    for (int i = 1; i <= maxVal; i++) {
        sum += i;
    }
    return (sum - misssum);
}

void miss_integer() {
    vector<int> vec = { 2, 3, 1, 5 };
    int ret = solution(vec);
    cout << ret;

}