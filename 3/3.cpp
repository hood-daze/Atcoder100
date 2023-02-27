// windowsだと#include<bits/stdc++.h> ができない。
// 提出のさい、コメントアウトする。
// C++ (Clang 10.0.0)だとiostreamでも大丈夫。
// C (GCC 9.2.1)だとだめ。

// #include<bits/stdc++.h> 
#include <iostream>
#include <array>

using namespace std;

int main() {
    string str; cin >> str;
    int len = str.length();
    int count = 0;
    int high = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == 'A' || str[i] == 'T' || str[i] == 'G' || str[i] == 'C') {
            count++;
            high = max(high, count);
        }
        else {
            count = 0;
        }
    }
    cout << high;
}

// 以下、自分の答え。