// 各要素について選択するかしないかの2択となるので、2n通りの組み合わせがあります。 ←　ポイント

using namespace std;
#define int long long
int n;
int a[30];
bool rec(int d, int t) {// recursibve
  
    if (t == 0) return true;// totalが0になった場合、つまり作れる場合trueを返す。
    // d==nつまり、長さnまで達したらアウトtotalが大きくなりすぎてもアウト。
    if (d == n || t < 0) return false;    
    // 再起関数を使っている。
    // d+1をすることで、それぞれtrueとfalseを判定。
    // 数字を使用する場合、- する。
    return rec(d + 1, t) || rec(d + 1, t - a[d]);
}
signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int q;
    cin >> q;
    int m[q];
    for (int i = 0; i < q; i++) cin >> m[i];
    for (int i = 0; i < q; i++) cout << (rec(0, m[i]) ? "yes" : "no") << endl;// 1行でやっている・・・！

    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    
    vector <int> A;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        A.push_back(a);
    }

    int q; cin >> q;
    vector <int> m;
    for (int i = 0; i < q; i++)
    {
        int M; cin >> M;
        m.push_back(M);
    }

    for (auto mi : m) 
    {
        // それぞれのmについて考察。
        // Aのすべての組み合わせを考える。
        //　⇒　むずくない？

        
        cout << "no\n";
    }

}
