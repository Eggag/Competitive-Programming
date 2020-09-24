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

int cnt[110];

void solve(){
	int n;
	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	rep(i, n){
		int x;
		cin >> x;
		cnt[x]++;
	}
	int ans = 0;
	repn(i, 2, 105){
		int cur = 0;
		repn(j, 1, 55){
			int k = i - j;
			if(j > k) break;
			if(!(j >= 1 && k >= 1)) continue;
			if(j == k) cur += cnt[j] / 2;
			else cur += min(cnt[j], cnt[k]);
		}
		ans = max(cur, ans);
	}
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
