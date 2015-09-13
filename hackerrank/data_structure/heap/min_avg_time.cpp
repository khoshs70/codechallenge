/*
https://www.hackerrank.com/challenges/minimum-average-waiting-time
*/

#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

struct customer {
    unsigned long long idx;
    unsigned long long waitT;
    customer(unsigned long long a,unsigned long long b) {
        idx = a; waitT = b;
    }
};

auto custCompare = [](vector<customer>::value_type &a, vector<customer>::value_type &b){return a.waitT > b.waitT; };

void getCustomers(map<unsigned long long, unsigned long long>&m, vector<customer> &v, unsigned long long &beforeT) {
    while (!m.empty()) {
        auto iter = m.begin();
        if (iter->first <= beforeT) {
            v.push_back(customer(iter->first,iter->second));
            push_heap(v.begin(), v.end(), custCompare);
            m.erase(iter);
        }
        else {
            // if aheap is empty?
            if (v.empty()) {
                v.push_back(customer(iter->first, iter->second));
                push_heap(v.begin(), v.end(), custCompare);
                m.erase(iter);

            }
            break;
        }
    }
}

void minAvgWaitTime() {
    int num;
    cin >> num;
    map<unsigned long long, unsigned long long> m;
    for (int i = 0; i < num; i++) {
        unsigned long long idx, t;
        cin >> idx >> t;
        m.insert(make_pair(idx,t));
    }
    
    // map<int, int> m = { { 0, 3 }, { 1, 9 }, { 2, 6 } };
    // map<int, int> m = { { 961148050, 385599125 }, { 951133776, 376367013 }, { 283280121, 782916802 }, { 317664929, 898415172 }, { 980913391, 847912645 } };
    // exp = 1418670047

    // first item 
    unsigned long long  curT = 0;
    unsigned long long people = 0;
    unsigned long long  totalT = 0;
    vector<customer> aheap;
    auto iter = m.begin();
    //curT = iter->first + iter->second; // move forward
    //people++;
    //totalT += iter->second;
    aheap.push_back(customer(iter->first,iter->second));
    push_heap(aheap.begin(), aheap.end(), custCompare);
    m.erase(iter);


    // loop
    while (!aheap.empty()) {      
        pop_heap(aheap.begin(), aheap.end(), custCompare);
        auto pair = aheap.back();
        unsigned long long offsetT;
        if (curT > pair.idx ) {
            offsetT = curT - pair.idx;
        }
        else {
            offsetT =  0;
            curT = pair.idx;
        }
        totalT = totalT + pair.waitT + offsetT; 
        curT += pair.waitT;
        people++;
        
        aheap.erase(aheap.end()-1);
        getCustomers(m, aheap, curT);
    }
    cout << totalT / people << std::endl;
}