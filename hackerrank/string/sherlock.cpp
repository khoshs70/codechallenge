#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define MAX 26

bool isAnagram(vector<int> &count1, vector<int> &count2) {
    for (int i = 0; i < MAX; i++) {
        if (count1[i] != count2[i])
            return false;
    }
    return true;
}

int findPair(string str, int start, char *tmp, int n) {
    int len = str.length();

    if (strlen(tmp) > len - start) {
        return 0;
    }

    
    vector<int> count1(MAX,0);
    vector<int> countTW(MAX,0);
    int cnt = 0;
    int i;
    
    // 建立一个长度和pattern 相等的count window,起始位置为start,即原str起始字符后一位
    // 如果pattern 长度为2的话，那么这个count window的起始位置=pattern的结束位置，有一个重叠
    for (i = 0; i < n && (start + i) < len; i++) {
        count1[tmp[i] - 'a']++;
        countTW[str[start + i] - 'a']++;
    }   
    
    int j;
    //window 长度为n,从window后面一个位置起循环
    for (j = start + i; j < len; j++) {    
        if (isAnagram(count1, countTW)) {
            cnt++;
            cout << "Found at Index " << (j - n) << endl;
        }
        // Remove the first character of previous window        
        countTW[str[start] - 'a']--;
        // Add current character to current window
        countTW[str[j] - 'a']++;
        start++;
    }
    if (j == len) {
        if (isAnagram(count1, countTW)) {
            cnt++;
        }
    }
    

    //delete[]count1;
    //delete[]count2;

    return cnt;
}

int countPairs(string str) {
    int n = str.length();
    if (n < 2) {
        return 0;
    }

    int cnt = 0;
    char *tmp = new char[n+1];
    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = i; j < n; j++) {
            tmp[k] = str[j];
            tmp[k + 1] = '\0';

            cnt += findPair(str, i + 1, tmp, k + 1);
            k++;
        }
    }
    delete[]tmp;
    return cnt;
}

void sherlock_anagram() {
    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;
        cout << countPairs(str) << endl;
    }

    
}
