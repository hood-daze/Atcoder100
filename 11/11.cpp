#include <iostream>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, M;
vector<int> S[10];
int P[10];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M;
    rep(i, 0, M) {
        int k; cin >> k;
        rep(j, 0, k) {
            int s; cin >> s; s--;
            S[i].push_back(s);
        }
    }
    rep(i, 0, M) cin >> P[i];

    int ans = 0;
    rep(msk, 0, 1 << N) {
        int ok = 0;
        rep(m, 0, M) {
            int cnt = 0;
            fore(s, S[m]) if (msk & (1 << s)) cnt++;// ここが全て。mskのsビット目が1であるかどうかを調べる
            if (cnt % 2 == P[m]) ok++;
        }
        if (ok == M) ans++;
    }
    cout << ans << endl;
}
















#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// これはおそらくビット全探索の問題。
int main()
{
    // 数の整理
    
    // N = スイッチの数
    // M = 電球
    // k[i] = 電球iがつながっているスイッチ数
    
    // 条件の整理
    // onの個数 % 2

    // それぞれの長さが10の二次元配列を作成する。

    vector<vector<int>> s_2d(10, vector<int>(10, 0));
    int N, M; cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int k; cin >> k; 
        for (int i = 0; i < k; i++)
        {
            cin >> s_2d[i][k];
        }

    }
    vector<int> p = vector<int>(10, 0);
    for (int i = 0; i < M; i++)
    {
        cin >> p[i];
    }

    for (int i = 0; i < M; i++)
    {
        if( % 2== p[i])
        
        for (auto s: s_2d[i])
        {
            
        }
    }

    cout << "";
}

// コピペで使える便利変数宣言

// vector<pair<int, int>> v;