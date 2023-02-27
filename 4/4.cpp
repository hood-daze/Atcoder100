#include <iostream>
#include <vector> // vectorの宣言
using namespace std;
using ll = long long; // longlongの使用宣言
int main() {
	int n, m; cin >> n >> m; // 同じ行に書ける。

	vector<vector<ll>> a(n, vector<ll>(m)); // n行m列の配列を宣言。
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j]; //同じ行に書ける。
	ll ans = 0;
	for (int i = 0; i < m; i++) { // m数でループ
		for (int j = i + 1; j < m; j++) { //　どの曲の場合最大になるか調べるため、m曲すべて調べる。
			ll total = 0;
			for (int k = 0; k < n; k++) {// それぞれ生徒で最大を出す。
				total += max(a[k][i], a[k][j]);//k番目の生徒のi点とi点とj点を比べる。
			}
			ans = max(ans, total);
		}
	}
	cout << ans << endl;
}