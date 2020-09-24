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

bool cmp(pair<string, int> a, pair<string, int> b){
	return a.fi.size() > b.fi.size();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	int m;
	cin >> m;
	vector<pair<string, int>> p(m);
	rep(i, m) cin >> p[i].fi >> p[i].se;
	sort(all(p), cmp);
	int ans = s.size();
	int po = 0;
	while(po < n){
		int f = 0;
		rep(i, m){
			if((po + (p[i].fi.size() - 1)) < n){
				string a = s.substr(po, p[i].fi.size());
				if(a == p[i].fi){
					ans += p[i].se;
					po += p[i].fi.size();
					f = 1;
					break;
				}
			}
		}
		if(!f) po++;
	}
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
