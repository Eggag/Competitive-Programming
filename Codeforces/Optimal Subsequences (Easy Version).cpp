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

vi best[105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n), b(n);
	rep(i, n) cin >> a[i], b[i] = a[i];
	sort(all(b));
	reverse(all(b));
	rep(i, n){
		map<int, vi> ap;
		rep(j, n) ap[a[j]].pb(j);
		int prev = 0;
		for(int j = i; j >= 0; j--){
			int now = lb(all(ap[b[j]]), prev) - ap[b[j]].begin();
			if(now == ap[b[j]].size()) now--;
			prev = ap[b[j]][now];
			best[i].pb(ap[b[j]][now]);
			ap[b[j]].erase(ap[b[j]].begin() + now);
		}
		sort(all(best[i]));
	}
	int m;
	cin >> m;
	rep(i, m){
		int k, pos;
		cin >> k >> pos;
		k--, pos--;
		cout << a[best[k][pos]] << endl;
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
