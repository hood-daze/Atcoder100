#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// おそらくXXの問題
int main()
{
    // 数の整理
    // N = 国会議員の数
    // M = 人間関係の数(x,y)
    
    // 条件の整理
    // 2のn乗り物個の組み合わせがある。


    // 回答
    int N, M; cin >> N >> M;
    vector<pair<int, int>> xy[10];
    for (int i = 0; i < M; i++)
    {
        int x, y; cin >> x >> y;
        xy[i].push_back(make_pair(x, y));
        // setで重複をなくすとか？
    }
    // わからない・・・

    cout << "";
}



// 配列の宣言
// vector<int> s[10];

// 2次元配列の宣言と初期化
// vector<vector<int>> array_2d(rows, vector<int>(cols, 0));


// for文
//for (int i = 0; i < N; i++)
//{
//
//}




// 答え。

