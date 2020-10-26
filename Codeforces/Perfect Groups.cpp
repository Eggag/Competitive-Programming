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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n), d(n, 0);
	rep(i, n) cin >> a[i];
	map<vi, int> m;
	int id = 1;
	rep(j, n){
		vi cr;
		int nm = a[j];
		if(nm < 0) cr.pb(-1), nm *= -1;
		for(int i = 2; (i * i) <= nm; i++){
			int cnt = 0;
			while(nm % i == 0){
				nm /= i;
				cnt++;
			}
			if(cnt & 1) cr.pb(i);
		}
		if(nm > 1) cr.pb(nm);
		sort(all(cr));
		int res = m[cr];
		if(a[j]){
			if(res) d[j] = res;
			else m[cr] = id, d[j] = id, id++;
		}
	}
	vi cnt(n + 1, 0);
	rep(i, n){
		vi vis(n + 1, 0);
		int un = 0;
		repn(j, i, n){
			if(!vis[d[j]] && a[j]) un++;
			vis[d[j]] = 1;
			cnt[max(un, 1)]++;
		}
	}
	repn(i, 1, n + 1) cout << cnt[i] << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
