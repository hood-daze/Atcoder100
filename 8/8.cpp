#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, A[100], B[100], minx = (1LL << 60);// 2の60乗。LLがないと、リテラルはint型のみになります。

long long solve(int p1, int p2) {
	long long V1 = 0;
	for (int i = 1; i <= N; i++) {
		V1 += abs(p1 - A[i]);
		V1 += abs(A[i] - B[i]);
		V1 += abs(B[i] - p2);
	}
	return V1;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];

	vector<long long>E;
	for (int i = 1; i <= N; i++) E.push_back(A[i]);
	for (int i = 1; i <= N; i++) E.push_back(B[i]);

	for (long long v1 : E) {
		for (long long v2 : E) {
			minx = min(minx, solve(v1, v2));
		}
	}
	cout << minx << endl;
	return 0;
}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    int N;
//    cin >> N;
//
//    
//    vector<int> A(N);
//    vector<int> B(N);
//
//    for (int i = 0; i < N; i++)
//    {
//        cin >> A[i] >> B[i];
//    }
//    // 入口と出口の全組み合わせを検索。
//    // ただし半分の長さでよさそう。
//
//    long long ans = 1000000000;
//    for (int i = 0; i < N; i++)
//    {
//        long long sum = 0;
//        for (int j = 0; j < N; j++)
//        {
//            // iとjの全組み合わせ。
//            int time = abs(i - A[i]) + abs(B[j] - A[i]);
//            sum += time;
//        }
//        ans = min(sum, ans);
//    }
//
//    cout << ans;
//
//    return 0;
//}
//
