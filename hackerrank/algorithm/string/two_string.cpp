/*
https://www.hackerrank.com/challenges/two-strings
*/
/*
https://www.hackerrank.com/challenges/two-strings
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<string> output;
    for (int i = 0;i < t; i++) {
        string a,b;
        cin>>a;
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin>>b;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        /*unordered_set<char> sa,sb;
        for (char &ch : a) {
            sa.insert(ch);
        }
        for (char &ch : b) {
            sb.insert(ch);
        }*/
        
        vector<char> result;
        set_intersection(a.begin(),a.end(),b.begin(),b.end(),back_inserter(result));
        if (result.empty()) {
            output.push_back("NO");
        } else {
            output.push_back("YES");
        }         
    }
    for (string str:output) {
        cout<<str<<std::endl;
    }        
    return 0;
}


