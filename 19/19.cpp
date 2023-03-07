#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

// 二部探索の問題

// 整理
// d = 環状線のメートル長さ
// n = 店舗の数
// S[i] = 店舗
// d[i] = S1 ~ Siまでのメートル長さ
// k = S1から見たときの宅配先の位置メートル
// m = 注文の個数

// 各注文に対する宅配時の移動距離
int main()
{
    int d, n, m; cin >> d >> n >> m;

    vector<int> dn(n-1);


    for (int i = 0; i < n-1; i++)cin >> dn[i];// dn[n]にはd+2の値が入る。

    vector<int> k(m);
    for (int i = 0; i < m; i++)cin >> k[i];

    for (int i = 0; i < m; i++) {
        
    }

    sort(dn.begin(), dn.end());

    int left = 0, right, mid, count = 0;

    for (int i = 0; i < m; i++) {
        right = n - 1;
        mid = (left + right) / 2;

        int dist = 0;
        while (left <= right) {
            if (dn[mid] == k[i]) {
                dist = 0;
                left = mid + 1;
                break;
            }
            else if (dn[mid] > k[i]) {
                dist = min(dn[mid], k[i]);
                right = mid - 1;
            }
            else { //S[m] < Q[i]
                dist = min(dn[mid], k[i]);
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }
    }
    printf("%d\n", count);
}

// 考えたこと
// 問題を読んでどのパターンで行くのか見抜く能力が必要だ。

#include<bits/stdc++.h>
#define LL long long 
using namespace std;
int ary[100007];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int d, n, m;
    cin >> d >> n >> m;
    for (int i = 1; i < n; i++)cin >> ary[i];
    ary[n] = d;
    sort(ary, ary + n + 1);

    long long sum = 0;
    while (m--) {// おしゃっれ
        int q;
        cin >> q;
        int t = lower_bound(ary, ary + n + 1, q) - ary;
        sum += min(ary[t] - q, q - ary[t - 1]);
    }

    cout << sum << "\n";

}