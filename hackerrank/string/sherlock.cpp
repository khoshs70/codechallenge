#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

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

void sherlock_anagram0() {
    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;
        cout << countPairs(str) << endl;
    }    
}

// better solution
void sherlock_anagram() {
    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;
        unordered_map<string, int> ma;  // save key
        // split sub str
        int size = str.length();
        for (int len = 1; len < size; len++) { // allow sub str only, not the whole string
            for (int pos = 0; pos <= size - len; pos++) {
                string sub = str.substr(pos, len);
                sort(sub.begin(), sub.end());
                ma[sub]++;
            }
        }
        long long cnt = 0;
        for (auto t : ma) {
            if (t.second > 1)
                cnt += (long long)t.second * (t.second - 1) / 2;
        }
        cout << cnt << endl;
    }
}

/*
int cases;
scanf("%d", &cases);
getchar();
while (cases--) {
unordered_map<string, int> mp;
string s;
getline(cin, s);
int n = s.size();
for (int len = 1; len < n; ++len) {
for (int i = 0; i <= n - len; ++i) {
string t = s.substr(i, len);
sort(t.begin(), t.end());
mp[t]++;
}
}
long long ans = 0;
for (auto t : mp) {
ans += (long long)t.second * (t.second - 1) / 2;
}
printf("%lld\n", ans);
}
return 0;*/
