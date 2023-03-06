// LUOGU_RID: 103890510
#include<cstdio>
#include<algorithm>
using namespace std;

int n, a[100005], b[100005], c[100005];
long long ans;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++)
    {
        int p = lower_bound(a + 1, a + n + 1, b[i]) - a;
        int q = upper_bound(c + 1, c + n + 1, b[i]) - c;
        ans += 1ll * (p - 1) * (n - q + 1);
    }
    printf("%lld\n", ans);

    return 0;
}
