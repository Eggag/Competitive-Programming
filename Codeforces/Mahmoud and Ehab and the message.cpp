#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k, m;
	cin >> n >> k >> m;
	int a[n];
	string s[n];
	rep(i, n) cin >> s[i];
	rep(i, n) cin >> a[i];
	map<string, int> r;
	rep(i, n){
		r[s[i]] = a[i];
	}
	rep(i, k){
		int d;
		cin >> d;
		vi c, c1;
		rep(j, d){
			int x;
			cin >> x;
			c1.pb(x);
			c.pb(a[x - 1]);
		}
		sort(all(c));
		int mn = c[0];
		rep(j, c.size()){
			r[s[c1[j] - 1]] = mn;
		}
	}
	ll ans = 0LL;
	rep(i, m){
		string a;
		cin >> a;
		ans += (int)(r.find(a)->se);
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
