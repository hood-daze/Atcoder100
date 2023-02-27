// windowsだと#include<bits/stdc++.h> ができない。
// 提出のさい、コメントアウトする。

// #include<bits/stdc++.h> 
#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0) continue;
        int cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) cnt += 1;
        }
        if (cnt == 8) ans += 1;
    }
    cout << ans << endl;
}


// 以下、自分の答え。

//#include <iostream>
//using namespace std;
//int main() {
//    int n;
//    cin >> n;
//    
//    int answer = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        if (i % 2 == 1) {
//            continue;
//        }
//
//        int count = 0;
//
//        for (int j = 2; j <= i/2; j++)
//        {
//            if (i % j == 0) {
//                count++;
//            }
//        }
//
//        if (count == 8) {
//            answer++;
//        }
//    }
//
//    cout << answer;
//
//    return 0;
//}
