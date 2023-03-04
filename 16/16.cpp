#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

// 順列全探索の問題
int main()
{
    // 整理
    // N = 順列の大きさ
    // P,Q数列

    // 回答
    int N; cin >> N;
    vector<int> p(N);
    vector<int> q(N);
    for (int i = 0; i < N; i++)
    {
        int pi; cin >> pi;
        p[i] = pi;
    }

    for (int i = 0; i < N; i++)
    {
        int qi; cin >> qi;
        q[i] = qi;
    }

    // ソートされた順列の作成。
    vector<int> sorted_p(N);
    for (int i = 0; i < N; i++)
    {
        sorted_p[i] = i + 1;
    }

    int a = 0;
    int b = 0;
    int count = 0;
    do
    {
        if(sorted_p == p) {
            a = count;
        }

        if(sorted_p ==q) {
            b = count;
        }
        count++;
    } while (next_permutation(sorted_p.begin(), sorted_p.end()));


    int ans = abs(a - b);
    cout << ans << endl;

    return 0;
}


// コピペで使える便利変数宣言


// int N; cin >> N;


// 配列の宣言
// vector<int> s(r, vector<int> c);

// 2次元配列の宣言と初期化
// vector<vector<int>> array_2d(rows, vector<int>(cols, 0));


// for文
//for (int i = 0; i < N; i++)
//{
//
//}


