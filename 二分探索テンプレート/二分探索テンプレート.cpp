#include <iostream>
#include <vector>
#include <algorithm>
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