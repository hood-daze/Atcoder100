#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using u64 = unsigned long long;

int main() {
	int n1;
	cin >> n1;

	vector<pair<int, int>> v;
	for (auto i = 0; i < n1; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y }); // {, }.push_back
	}

	int n2;
	cin >> n2;
	set<pair<int, int>> v2; // 
	for (auto i = 0; i < n2; i++) {
		int x, y;
		cin >> x >> y;
		v2.insert({ x, y });
	}

	// 写真に写っているn回回す。	
	for (auto i : v2) {
		int x = i.first - v[0].first;
		int y = i.second - v[0].second;

		bool flag = true;
		// 探したい星座を構成する星
		// ひとつでもflagがたてばだめ。
		for (auto j : v) {
			pair<int, int> trans = { j.first + x, j.second + y }; // 星座を移動した位置を取る。
			if (v2.find(trans) == v2.end()) {
				// findで見つけられなかったら最後の要素の次を参照するイテレータを返す。
				// v2.end()はset コンテナの最後の要素の次を参照するイテレータを返す。
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << x << " " << y << endl;
			return 0;
		}
	}
}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    int m; cin >> m;
//
//	// 星座を構成するものを0,0で初期化。
//	vector<pair<int, int>> xy(m, make_pair(0, 0)); 
//
//	int n = 0;
//	for (int i = 0; i < m + 1 ; i++)
//	{
//		if (i <= m) {
//			int x, y; cin >> x >> y;
//			xy[i] = make_pair(x, y);
//		}
//		else if (i = m + 1) {
//			cin >> n;
//		}
//	}
//
//	// 写真に写っている n 個の星を0,0で初期化。
//	vector<pair<int, int>> xy2(m, make_pair(0, 0));
//	for (int i = 0; i < n; i++)
//	{
//		int x, y; cin >> x >> y;
//		xy2[i] = make_pair(x, y);
//	}
//
//	for (int i = 0; i <= 10e6; i++)
//	{
//
//	}
//
//	int xt, yt;
//
//
//	cout << xt << yt << endl;
//}
