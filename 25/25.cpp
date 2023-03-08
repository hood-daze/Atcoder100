#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>

using namespace std;


// XXの問題
// 整理
// w,h = 地図の幅と高さ
// ci, j  i, jは1からはじまる。0= 海, 1= 陸
// 0 0 入力の終わり



int main() {

	while (true) {
		int w, h;
		scanf("%d", &w);// 達人はscanfを使用している? intだからかな？
		scanf("%d", &h);
		if (w == 0 && h == 0) break;

		int table[101][101];

		for (int i = 1; i <= h; i++) {
			for (int k = 1; k <= w; k++) {
				cin >> table[h][w];				 
			}
		}
	}

	return 0;
}


#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

int map[50][50], width, height;

//これはコピペで覚えましょう。
int dx[8] = { -1,0,1,-1,1,-1,0,1 }, dy[8] = { -1,-1,-1,0,0,1,1,1 }; 

// 島問題ではrengecheckが必須。
bool rangeCheck(int row, int col) {
	if (row >= 0 && row <= height - 1 && col >= 0 && col <= width - 1)return true;
	else {
		return false;
	}
}

// グラフの連結成分数は、深さ優先探索で計算

void erase(int row, int col) {
	map[row][col] = 0;

	// 島が続く限り、eraseして0にする。
	for (int i = 0; i < 8; i++) {
		if (rangeCheck(row + dy[i], col + dx[i]) == true && map[row + dy[i]][col + dx[i]] == 1) {
			erase(row + dy[i], col + dx[i]);
		}
	}
}


int main() {

	int count;

	while (true) {
		scanf("%d %d", &width, &height);// こういう風にもにゅーりょくできるのか。
		if (width == 0 && height == 0)break;// 最後の入力

		for (int i = 0; i < height; i++) {
			for (int k = 0; k < width; k++) {
				scanf("%d", &map[i][k]);
			}
		}
		//　ここまであっている。

		count = 0;

		// 変数名も参考になる。
		for (int row = 0; row < height; row++) {
			for (int col = 0; col < width; col++) {
				if (map[row][col] == 1) {// 陸だったら
					count++;// 島が一つ
					erase(row, col);
				}
			}
		}


		printf("%d\n", count);

	}


	return 0;
}