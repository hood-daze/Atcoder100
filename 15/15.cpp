int N, X[8], Y[8];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) cin >> X[i] >> Y[i];

    vector<int> ord;
    rep(i, 0, N) ord.push_back(i);

    long double sm = 0;
    do {
        rep(i, 0, N - 1) {
            int a = ord[i];
            int b = ord[i + 1];

            long double dx = X[a] - X[b];
            long double dy = Y[a] - Y[b];

            sm += sqrt(dx * dx + dy * dy); // 平方数の求め方。
        }
    // allでは最初の要素へのポインタと、ordの最後の要素の次の要素へのポインタの間の範囲を指定しています。
    // 次の順列を生成する関数 0.1.2.3で順列にする。
    } while (next_permutation(all(ord)));

    // sqrt関数も

    // 距離の平均
    rep(i, 0, N) sm /= (i + 1);
    printf("%.10Lf\n", sm);
}



#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// 順列全探索の問題
int main()
{
    // 数の整理
    // N = 町の数　
    
    // 条件の整理
    // 

    // 回答
    int N; cin >> N;
    vector<pair<int, int>> xy(10);
    for (int i = 0; i < N; i++)
    {
        int x, y; cin >> x >> y;
        xy[i] = make_pair(x, y);
    }
    // 順列をどうプログラミングで実装すればいい？



    cout << "" << endl;
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


