#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// using ll = long long; AOJではこれが使えない。
typedef long long ll;
// 二部探索の問題
// 整理
// n = 数列Sの中の整数の数 :上限は100'000
// S = 数列
// q = 数列Tの数　:上限は50'000
// C = SとTの共通する整数の個数

// 計算量705'032'704 7億
int main()
{    
    int n; cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; i++)
    {
        int si; cin >> si;
        S[i] = si;
    }

    int q; cin >> q;
    vector<int> T(n);
    for (int i = 0; i < q; i++)
    {
        int ti; cin >> ti;
        T[i] = ti;
    }
    // 共通の整数の個数。
    int count;
    for (int i = 0; i < q; i++)
    {
        for (int j = 0;j < n; i++)
        {
            if (T[q] == S[i]) {
                count++;
            }
            
        }
    }
    cout << count << endl;

    return 0;
}

// 反省
// 入力処理を書きながら考える。
// ループさせるとき二重ループを予め予想し、添え字の文字を変える。iとj
// 計算量を考える。そういうプログラムを作っても良さそう。
// マウスを使うのを辞める。
// ctrl + tabで切り替える。

// Sの要素は昇順に整列されている
// →　binary saerch
// O(log n)

// 答え

#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int main() {
    int N;
    scanf("%d", &N);
    int S[N];
    for (int i = 0; i < N; i++)scanf("%d", &S[i]);

    int M;
    scanf("%d", &M);

    int Q[M];
    for (int i = 0; i < M; i++)scanf("%d", &Q[i]);
    sort(Q, Q + M);

    int left = 0, right, m, count = 0;

    for (int i = 0; i < M; i++) {
        right = N - 1;
        m = (left + right) / 2;

        while (left <= right) {
            if (S[m] == Q[i]) {
                count++;
                left = m + 1;
                break;
            }
            else if (S[m] > Q[i]) {
                right = m - 1;
            }
            else { //S[m] < Q[i]
                left = m + 1;
            }
            m = (left + right) / 2;
        }
    }
    printf("%d\n", count);
}

