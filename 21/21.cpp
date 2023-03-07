#include <iostream>
#include <vector>
#include <algorithm>

#define inf ((1LL << 62) - (1LL << 31))
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

// 二部探索の問題

// 整理
// N = 風船の数 ：1≦N≦100,000
// i = 風船
// H[i] = 高度
// S[i] = 増加量/s

int main()
{
    int N = 0;
    cin >> N;
    vector<int> H(N);
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
        cin >> S[i];
    }

    // 最小の得点
    int M;
    cin >> M;
    vector<int> Q(M);

}

//　実は、この問題は最小化問題としてそのまま考えるのは大変で、最
//　小化問題の代わりに、ある高さ X 以下を保ちながら風船を割ること
//　ができるか、という判定問題に変形することで効率的にとくことがで
//　きるようになります。

// 風船 𝑖 は (𝑋 − 𝐻𝑖)/𝑆𝑖 秒以内に割らなければならないと考える。
// 𝑋 < HiだとこのXでは不可能


//• 実は、ある値 Opt を基準として、
//・ Opt > X ならば、どうやっても達成できない。
//・ Opt ≦ X ならば、先ほどの貪欲法アルゴリズムで達成できる。
//という性質が成り立ちます。

//区間[left, right](left≦right) の内部に Opt がある
//(left≦Opt≦right) とわかっている場合に、left≦half≦right となる half
//を考え、
//X = half が条件を満たす→ Opt は区間[half, right] 内にある。
//X = half が条件を満たさない→ Opt は区間[left, half) 内にある。
//として区間を狭めていくという方針です。
//• half は(left + right) / 2 辺りの整数を取ることが多いです。


// O(𝑁log𝑁 ∗ log(𝐻 + 𝑁𝑆))

// 模範解答

#define inf ((1LL << 62) - (1LL << 31))
#define all(x) (x).begin(), (x).end()

int main()
{
    ll N;
    cin >> N;
    vector<ll> H(N), S(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> H[i] >> S[i];
    }
    // ここまではok
    ll ng = 0;
    ll ok = inf;

    while (abs(ok - ng) > 1)// okがng以下になったら抜ける。
    {
        ll mid = (ok + ng) / 2;
        vector<pair<ll, ll>> timelim(N);// optを考える。
        for (ll i = 0; i < N; i++)
        {
            timelim[i].first = (mid - H[i]) / S[i]; // 期限時間-初期時間 /毎秒速度 秒以内に割らなければならないと
            timelim[i].second = i;// 風船。
        }
        sort(all(timelim));// 割りやすいものから順。
        bool frag = 1;
        for (ll i = 0; i < N; i++)
        {
            ll num = timelim[i].second;// それぞれ風船
            if (S[num] * i + H[num] > mid) // 時間を加味したものがmidより大きければ、アウト。
                frag = 0;
        }
        if (frag)
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;
}