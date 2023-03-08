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