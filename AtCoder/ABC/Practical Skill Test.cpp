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

int a[305][305];
pi q1[305 * 305];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int h, w, d;
	cin >> h >> w >> d;
	rep(i, h) rep(j, w){
		cin >> a[i][j];
		q1[a[i][j]] = mp(i, j);
	}
	vector<pi> cnt[305 * 305];
	repn(i, 1, (h * w) + 1){
		int md = i % d;
		cnt[md].pb(q1[i]);
	}
	vi cnt1[305 * 305];
	rep(i, d){
		cnt1[i].pb(0);
		repn(j, 1, cnt[i].size()){
			int cur = cnt1[i][j - 1] + abs(cnt[i][j].fi - cnt[i][j - 1].fi) +  abs(cnt[i][j].se - cnt[i][j - 1].se);
			cnt1[i].pb(cur);
		}	
	}
	int q;
	cin >> q;
	rep(i, q){
		int l, r;
		cin >> l >> r;
		int md = l % d;
		if(md){
			int one = (r + (d - md)) / d;
			int two = (l + (d - md)) / d;
			one--, two--;
			cout << (one > 0 ? cnt1[md][one] : 0) - (two > 0 ? cnt1[md][two] : 0) << endl;
		}
		else{
			int one = r / d;
			int two = l / d;
			one--, two--;
			cout << (one > 0 ? cnt1[md][one] : 0) - (two > 0 ? cnt1[md][two] : 0) << endl;
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
