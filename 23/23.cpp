#include <iostream>
#include <vector>
#include <algorithm>

#define inf ((1LL << 62) - (1LL << 31))
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

// 深さ優先探索(DFS)の問題

// d[v]: vを最初に発見した発見時刻
// f[v]: vの隣接リストを調べ終えた完了時刻
// 有向グラフ G=(V,E)　= 隣接リスト
// S = 数列
// q = 数列Tの数　:上限は50'000
// C = SとTの共通する整数の個数

//　出力
// id、d、f ・・・それぞれ頂点番号、発見時刻、完了時刻


int main()
{
    int n = 0;
    cin >> n;
    int ui[100][100];

    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        int k;
        cin >> k;

        for (int i = 0; i < k; i++) {
            cin >> ui[u][i];
        }

    }

    int ans = 0;
    cout << ans << endl;
}

// 本当の答え

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>

using namespace std;

int common_time = 1, n;// どんな頭すればここで1,nを宣言できるのか。。

int table[101][101], time_table[101][2];// time_tableを作成しているのが興味深い

void func(int node) {// 一つの頂点について。
	if (time_table[node][0] == 0) {// 発見時刻
		time_table[node][0] = common_time++;
	}
	else {
		return;//　すでに発見していたら再起関数の終わりにする。
	}
	for (int i = 1; i <= n; i++) {
		if (table[node][i] == 1) {
			func(i);
		}
	}
	time_table[node][1] = common_time++;// 完了時刻を増やす。
}

int main() {
	int row, num, col;
	scanf("%d", &n);// 達人はscanfを使用している? intだからかな？

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			table[i][k] = 0;// 0でtableを初期化。こうやって手間暇かけてやるのか・・・
		}
		time_table[i][0] = 0;// timetableも初期化しているのか。
		time_table[i][1] = 0;

	}

	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &row, &num);
		for (int k = 1; k <= num; k++) {
			scanf("%d", &col);
			table[row][col] = 1;// 隣接する頂点の番号がcol rowは頂点の番号
		}
	}

	for (int i = 1; i <= n; i++) {// ここで深さ優先探索DPS
		func(i);
	}

	for (int i = 1; i <= n; i++) {
		printf("%d %d %d\n", i, time_table[i][0], time_table[i][1]);
		// 達人はprintfをする。
		// 頂点の番号　頂点の発見時刻 完了時刻
	}

	return 0;
}