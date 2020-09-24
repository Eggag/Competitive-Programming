#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[5005][5005];
multiset<ll> mx[5005];
int wait[5005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k, x;
	cin >> n >> k >> x;
	vector<ll> a(n + 1);
	repn(i, 1, n + 1) cin >> a[i];
	rep(i, n + 1) rep(j, x + 1) dp[i][j] = -1e18;
	dp[0][x] = 0LL;
	mx[x].insert(0LL);
	repn(i, 1, n + 1){
		rep(j, x){
			if(mx[j + 1].size()){
				auto it = mx[j + 1].end();
				it--;
				dp[i][j] = max(dp[i][j], *it + a[i]);
				if(mx[j].size()){
					auto mxx = mx[j].end();
					mxx--;
					if(dp[i][j] >= *mxx){
						wait[j] = mx[j].size();
						mx[j].clear();
					}
				}
				if(dp[i][j] >= 0) mx[j].insert(dp[i][j]);
			}
			if(i - k >= 0){
				if(wait[j + 1]) wait[j + 1]--;
				else{
					auto it = mx[j + 1].find(dp[i - k][j + 1]);
					if(it != mx[j + 1].end()) mx[j + 1].erase(it);
				}
			}
		}
	}
	ll ans = -1e18;
	repn(i, n - k + 1, n + 1) ans = max(ans, dp[i][0]);
	if(ans < 0) ans = -1;
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
