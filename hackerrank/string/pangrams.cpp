#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void pangrams() {
    string str;
    getline(cin, str);
    int counts[26] = { 0 };
    int length = str.length();

    for (int i = 0; i < length; i++) {
        int ch = str[i];        
        if (ch != ' ') {
            ch = tolower(ch);            
            counts[ch - 'a']++;            
        }
    }
    bool flag = true;
    for (int i = 0; i < 26; i++) {
        if (counts[i] == 0) {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "pangram" << std::endl;
    else
        cout << "not pangram" << std::endl;
}