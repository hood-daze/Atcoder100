#include <iostream>
#include <vector>
#include <algorithm>

#define inf ((1LL << 62) - (1LL << 31))
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

// 二部探索の問題

// 整理
// n = 数列Sの中の整数の数 :上限は100'000
// S = 数列
// q = 数列Tの数　:上限は50'000
// C = SとTの共通する整数の個数

int main()
{
    int N = 0;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++)cin >> S[i];

    int M;
    cin >> M;
    vector<int> Q(M);

    for (int i = 0; i < M; i++)cin >> Q[i];
    sort(Q.begin(), Q.end());

    int left = 0, right, m, count = 0;

    for (int i = 0; i < M; i++) {
        right = N - 1;
        m = (left + right) / 2;

        while (left <= right) {
            if (S[m] == Q[i]) {
                count++;
                left = m + 1;
                break;
            }
            else if (S[m] > Q[i]) {
                right = m - 1;
            }
            else { //S[m] < Q[i]
                left = m + 1;
            }
            m = (left + right) / 2;
        }
    }
    printf("%d\n", count);
}

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) v.begin(), v.end()
const int dbg = 0;

int main()
{
    double p;
    cin >> p;
    double x = -1.5 * log2(1.5 / p / log(2));
    x = max(x, 0.0);
    double ans = x + p / pow(2.0, x / 1.5);
    printf("%.8lf\n", ans);
}



// 3分探索

//B問題
//問題概要 : コンピュータは 2 年に 1.5 倍のペースで高速になる。現在 P 年かか
//る計算を、適切なタイミングで始めて計算が終わるまでの時間を最小化せよ。
//解説 :
//x 年後に計算を始めるとき、計算が終わるまでの時間は f(x) = x + 2^(−x / 1.5)P
//年です。これは、凸関数と凸関数の和なので、凸関数です。よって、三分探
//索によって最小値を求めることができます。
//また、f
//′
//(x) の零点を求め、そのときの値を出力しても大丈夫です。その場
//合、零点が 0 未満のときは f(0) = P を出力する必要があります。

// 入出力ストリームで浮動小数点型の桁数を指定したい場合はsetprecisionマニピュレータを使います。<iomanip>ヘッダーをインクルードする必要があります。

