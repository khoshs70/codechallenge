/*
A non-empty zero-indexed array A consisting of N integers is given. A pit in this array is any triplet of integers (P, Q, R) such that:

0 ≤ P < Q < R < N;
sequence [A[P], A[P+1], ..., A[Q]] is strictly decreasing,
i.e. A[P] > A[P+1] > ... > A[Q];
sequence A[Q], A[Q+1], ..., A[R] is strictly increasing,
i.e. A[Q] < A[Q+1] < ... < A[R].
The depth of a pit (P, Q, R) is the number min{A[P] − A[Q], A[R] − A[Q]}.

For example, consider array A consisting of 10 elements such that:

A[0] =  0
A[1] =  1
A[2] =  3
A[3] = -2
A[4] =  0
A[5] =  1
A[6] =  0
A[7] = -3
A[8] =  2
A[9] =  3
Triplet (2, 3, 4) is one of pits in this array, because sequence [A[2], A[3]] is strictly decreasing (3 > −2) and sequence [A[3], A[4]] is strictly increasing (−2 < 0). Its depth is min{A[2] − A[3], A[4] − A[3]} = 2. Triplet (2, 3, 5) is another pit with depth 3. Triplet (5, 7, 8) is yet another pit with depth 4. There is no pit in this array deeper (i.e. having depth greater) than 4.

Write a function:

int solution(vector<int> &A);

that, given a non-empty zero-indexed array A consisting of N integers, returns the depth of the deepest pit in array A. The function should return −1 if there are no pits in array A.

For example, consider array A consisting of 10 elements such that:

A[0] =  0
A[1] =  1
A[2] =  3
A[3] = -2
A[4] =  0
A[5] =  1
A[6] =  0
A[7] = -3
A[8] =  2
A[9] =  3
the function should return 4, as explained above.

Assume that:

N is an integer within the range [1..1,000,000];
each element of array A is an integer within the range [−100,000,000..100,000,000].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

static int solution(vector<int> &A) {
    // write your code in C++11
    int n = A.size();
    int p = 0, q = 0, r = 0;
    bool waitq = true;
    int maxdeep = -1;
    for (int i = 1; i < n; i++) {
        if (waitq) {
            if (A[i] < A[q]) {
                q = i;
                continue;
            }
            else {
                if (q == p) {
                    p = i; q = i; r = i; continue;
                }                  
                else {
                    //q = i - 1;
                    r = q;
                    waitq = false;
                }                  
            }            
        }
        else {
            // waitr
            if (A[i] > A[r]) {
                r = i;
                int depth = min(A[p] - A[q], A[r] - A[q]);
                maxdeep = max(depth, maxdeep);
                continue;
            }
            else {
                if (r == q) {
                    p = i; q = i; r = i;
                    waitq = true; continue;
                }
                else {
                    // found the r
                    // r = i - 1;
                    int depth = min(A[p] - A[q], A[r] - A[q]);
                    maxdeep = max(depth, maxdeep);
                    waitq = true;
                    p = i-1; q = i; r = i;
                }
            }

        }        
    }
    if (!waitq) {
        if (A[r] > A[q] && r!=q) {            
            int depth = min(A[p] - A[q], A[r] - A[q]);
            maxdeep = max(depth, maxdeep);
        }
    }
    return maxdeep;
}

void deeppits() {
    vector<int> vec = {0,1,3,-2,0,1,0,-3,2,3};
    int ret = solution(vec);
    cout<< ret;
}

/*
public static int solution(int[] A) {
// write your code in Java SE 7
int N = A.length;

int depth = -1;
int P, Q, R;
int i = 0, j, k;
while (i < N - 2) {
P = A[i];

j = i + 1;
int p = P;
while (j < N - 1 && A[j] < p) {
p = A[j++];
}
if (j == N - 1) {
break;
}
if (j > i + 1) {
Q = A[j - 1];
} else {
i++;
continue;
}
k = j;
int q = Q;
while (k < N && A[k] > q) {
q = A[k++];
}

if (k > j) {
R = A[k - 1];
depth = Math.max(depth, Math.min(P - Q, R - Q));
i = k - 1;
} else {
i = j - 1;
}
}

return Math.max(depth, -1);
}
*/