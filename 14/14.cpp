#include <iostream>
#include <vector>

// 答え。
using namespace std;
typedef long long ll;
int main() {
	int n, k;
	cin >> n >> k;
	
	// ll型にする。
	vector<ll> a(n);
	// * ll型の最大値は大体、2^{63}-1　約9京
	// * int型の最大値は大体、2^{31}-1　約21億
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//　最小値を出すので大きい数字で初期化
	ll ans = 1e12;
	// nの建物について大きくするかしないか、すべてのケース
	for (int i = 0; i < 1 << n; i++) {
		int cnt = 1;
		ll tmp = 0;
		ll cur = a[0];

		// iを2進数で表現したとき、
		// すべての桁(すべての組み合わせ)について高くするのかどうか調べたい。
		// なので、nビットを順に調べている。
		for (int j = 1; j < n; j++) {
			if ((i >> j) & 1) {
				// 選択された建物の数
				cnt++; 
				//現在の状態での高さ差 0より大きい場合。つまり、右の建物のほうが大きい場合。
				tmp += max(cur - a[j] + 1, 0LL); 
				cur = max(cur + 1, a[j]);
			}
			cur = max(cur, a[j]);
		}
		if (cnt >= k) {
			ans = min(ans, tmp);
		}
	}
	cout << ans << endl;
}


#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// おそらくXXの問題
int main()
{
    // 数の整理
    // N = 建物の数
    // K = 色
    // j < i だとiが見える。

    // 回答
    int N, K; cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < K; i++)
    {
        int k; cin >> k;
        for (int i = 0; i < k; i++)
        {
            int ai; cin >> ai;
            a[i] = ai;
        }        
    }

    // 左の建物より大きくするかしないか。2N上の組み合わせがある。2eN　-1 かな？
    for (int i = 0; i < (1 << N); i++)
    {
        // K個左から見えるよう、お金を払う
        // お金の最小コストを比べる。；

    }

    // 出力最小金額
    cout << "" << endl;
}


// コピペで使える便利変数宣言


// int N; cin >> N;


// 配列の宣言
// vector<int> a(N);
// vector<int> s(r, vector<int> c);

// 2次元配列の宣言と初期化
// vector<vector<int>> array_2d(rows, vector<int>(cols, 0));


// for文
//for (int i = 0; i < N; i++)
//{
//
//}


