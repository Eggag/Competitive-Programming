#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#ifdef LOCAL
clock_t timer = clock();
#endif

ll dp[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int N, W;
	cin >> N >> W;
	int w[N], v[N];
	for(int i = 0; i < N; i++){
		cin >> w[i] >> v[i];
	}
	for(int i = 0; i < N; i++){
		for(int j = W - w[i]; j >= 0; j--){
			dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);
		}
	}
	ll ans = 0;
	for(int i = 0; i <= W; i++){
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
#ifdef LOCAL
        cout << "Total Time: " << (double)(clock() - timer) / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
