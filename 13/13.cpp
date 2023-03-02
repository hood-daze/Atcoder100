#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c; // rowとcolum 
    cin >> r >> c;
    vector<vector<int>> senbei(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> senbei[i][j];
        }
    }
    int mina = 1000000;
    //r<=10なので行についてbit全探索
    for (int i = 0; i < (1 << r); i++) {
        int ans = 0;
        for (int j = 0; j < c; j++) {
            int cnt = 0;
            for (int k = 0; k < r; k++) {
                if ((i >> k) & 1 && senbei[k][j] == 0) cnt++;
                if (!((i >> k) & 1) && senbei[k][j] == 1) cnt++;
            }
            if (cnt >= (r + 1) / 2) ans += r - cnt;
            else ans += cnt;
        }
        mina = min(mina, ans);

    }
    cout << r * c - mina << endl;
}


// コピペで使える便利変数宣言


// int N; cin >> N;


// 配列の宣言
// vector<int> s[10];

// 2次元配列の宣言と初期化
// vector<vector<int>> array_2d(rows, vector<int>(cols, 0));


// for文
//for (int i = 0; i < N; i++)
//{
//
//}


