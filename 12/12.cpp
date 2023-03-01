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

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// 最大クリークの問題
int main()
{
    // 数の整理
    // N = 国会議員の数
    // M = 人間関係の数(x,y)

    // 考え方
    // 派閥に入れる・入れない2通り。
    // 

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




#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // この発想はなかった。
    // 無向グラフの場合、2次元配列を作ればいいのか。
    vector<vector<bool>> relate(n, vector<bool>(n));
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        // 人は1から番号がつけられている。
        // 配列は0なので下げる。

        x--;
        y--;
        relate[x][y] = true;
        relate[y][x] = true;
    }
    int ans = 0;
    for (int b = 0; b < (1 << n); b++) {
        vector<int> t;
        for (int i = 0; i < n; i++) {
            if ((b >> i) & 1) t.push_back(i);
        }
        bool f = true;
        for (int a : t) {
            for (int b : t) {
                if (a == b) continue;
                f &= relate[a][b];
            }
        }
        if (f)
            ans = max(ans, (int)t.size());
    }
    cout << ans << endl;
}
