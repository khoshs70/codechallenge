/*
https://www.hackerrank.com/challenges/fibonacci-modified
Tn+2 = (Tn+1)2 + Tn
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string multiply(string &num1, string num2) {
    string res;
    int a, b, c, m, n, l, k, sum, carry;
    char d;

    m = num1.size() - 1;
    n = num2.size() - 1;
    carry = 0;
    for (int i = m; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            l = res.size() - 1;
            a = num1[i] - '0';
            b = num2[j] - '0';
            k = (m - i) + (n - j);

            if (l >= k) c = res[l - k] - '0';
            else c = 0;

            sum = a * b + c + carry;
            carry = sum / 10;
            d = char(sum % 10 + '0');

            if (l >= k) res[l - k] = d;
            else res.insert(0, &d, 1);

            if (j == 0 && carry) {
                d = char(carry + '0');
                res.insert(0, &d, 1);
                carry = 0;
            }
        }
    }

    return res[0] == '0' ? "0" : res;
}

string add(string s1, string s2){//字符串模拟大整数加法，返回字符串的大数
    string s;
    int len1, len2;
    len1 = s1.size() - 1; len2 = s2.size() - 1;
    int i = 0, flag = 0;
    while (len1>-1 && len2>-1){
        int sum = flag + (s1[len1--] - '0') + (s2[len2--] - '0');
        s += char((sum) % 10 + '0');
        flag = sum / 10;
    }
    while (len1>-1){
        int sum = flag + (s1[len1--] - '0');
        s += char((sum) % 10 + '0');
        flag = sum / 10;
    }
    while (len2>-1){
        int sum = flag + (s2[len2--] - '0');
        s += char((sum) % 10 + '0');
        flag = sum / 10;
    }
    if (flag) s += char('0' + flag);
    //cout<<s<<endl;
    for (int i = 0; i<s.size() / 2; i++){
        char c = s[i];
        s[i] = s[s.size() - i - 1];
        s[s.size() - i - 1] = c;
    }
    return s;
}
void fibonacci_modify() {
    unsigned long long a, b,n;
    cin >> a >> b >> n;
    
    string first = to_string(a);
    string second = to_string(b);
    string val;
    for (int i = 2; i < n; i++) {
        val = add (first, multiply(second, second));
        first = second;
        second = val;        
    }
    cout << val << std::endl;
}
/*
java 方案
Scanner sc = new Scanner(System.in);
String str = sc.nextLine();
//String b = sc.nextLine();
String tokens[] = str.split("\\s+");

int n = Integer.parseInt(tokens[2]);
BigInteger first = new BigInteger(tokens[0]);
BigInteger second = new BigInteger(tokens[1]);

BigInteger val = new BigInteger("0");
for (int i = 2; i < n; i++) {
val = second.multiply(second).add(first);
first = second;
second = val;
}
System.out.println(val);
*/