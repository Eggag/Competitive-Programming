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

bool cmp(pair<int, pi> a, pair<int, pi> b){
	return a.se.se > b.se.se;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, pi>> p(n);
	ll tot = 0;
	rep(i, n) cin >> p[i].se.fi >> p[i].se.se, tot += p[i].se.fi, p[i].fi = i;
	sort(all(p), cmp); //sort by capacity
	int ans = n;
	vi p1(n, 0);
	rep(i, n){
		if(!tot){
			p1[p[i].fi] = 0;
			continue;
		}
		ans--;
		if(tot >= p[i].se.se){
			tot -= p[i].se.se;
			p1[p[i].fi] = p[i].se.se;
		}
		else{
			p1[p[i].fi] = tot; //how much is left
			tot = 0;
		}
	}
	cout << ans << endl;
	rep(i, n) cout << p1[i] << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
