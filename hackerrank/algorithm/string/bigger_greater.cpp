/*
https://www.hackerrank.com/challenges/bigger-is-greater
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void bigger_greater0() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string w;
        cin >> w;

        int n = w.length();
        int j, k;
        for (j = n - 2; j >= 0; j--)
        {
            for (k = n - 1; k > j && w[k] <= w[j]; k--)
                ;
            if (k == j)
                continue;
            swap(w[k], w[j]);            
            sort(w.begin() + j + 1, w.end());
            break;
        }
        if (j < 0)
            cout << "no answer" << endl;
        else
            cout << w << endl;
    }
}

void bigger_greater() {
    int tc;
    string s;
    scanf_s("%d", &tc);
    while (tc--) {
        cin >> s;
        if (next_permutation(s.begin(), s.end())) printf("%s\n", s.c_str());
        else printf("no answer\n");
    }
}