#include <iostream>
using namespace std;
int main(void) {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int max_piza = max(X, Y) * 2; // 考え得る限りの最大のピザ数。
    int ans = 1e9; // 最大値で初期化。
    for (int i = 0; i <= max_piza; i += 2) { //半分のピザでは意味がないので、2ずつ増加。

        int A_piza = max(0, (X - i / 2) * A);// Xピザの料金。
        int B_piza = max(0, (Y - i / 2) * B);// Yピザの料金。
        int C_piza = C * i;// abピザの料金。
        int total_piza = A_piza + B_piza + C_piza;

        ans = min(ans, total_piza);

    }
    cout << ans << endl;
}