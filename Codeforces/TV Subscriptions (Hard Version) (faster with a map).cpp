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

void solve(){
	int n, k, d;
	cin >> n >> k >> d;
	vi a(n);
	rep(i, n) cin >> a[i];
	int ans = 1e9;
	int prev;
	int num = 0;
	map<int, int> cnt;
	rep(j, d){
		if(!cnt[a[j]]){
			num++;
		}
		cnt[a[j]]++;
	}
	ans = min(num, ans);
	prev = num;
	repn(i, d, n){
		cnt[a[i - d]]--;
		int num = prev;
		if(!cnt[a[i - d]]) num--;
		if(!cnt[a[i]]) num++;
		cnt[a[i]]++;
		ans = min(ans, num);
		prev = num;
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
