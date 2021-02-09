#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
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

int cnt[21];
ll tot[21], sub[21][21];
ll dp[2][(1 << 21)];

void ckmin(ll &a, ll b){
	a = min(a, b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	vi m(21, -1);
	int cr = 0;
	rep(i, n){
		cin >> a[i];
		if(~m[a[i]]) a[i] = m[a[i]];
		else m[a[i]] = cr++, a[i] = m[a[i]];
	}
	rep(i, n){
		tot[a[i]] += i - cnt[a[i]];
		cnt[a[i]]++;
	}
	rep(i, cr){
		int nm = 0;
		rep(j, n){
			if(a[j] == i) nm++;
			else sub[i][a[j]] += nm;
		}
	}
	rep(i, 2) rep(j, (1 << 21)) dp[i][j] = 1e18;
	dp[0][0] = 0;
	repn(i, 1, cr + 1){
		int cur = i & 1, prev = 1 - cur;
		rep(j, (1 << cr)) if(dp[prev][j] != 1e18){
			rep(k, cr) if(!(j & (1 << k))){
				ll cst = tot[k];
				rep(l, cr) if(j & (1 << l)) cst -= sub[l][k];
				ckmin(dp[cur][j | (1 << k)], dp[prev][j] + cst);
			}
		}
		rep(j, (1 << 21)) dp[prev][j] = 1e18;
	}
	cout << dp[cr & 1][(1 << cr) - 1] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
