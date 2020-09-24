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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<ll> l(n);
	rep(i, n) cin >> l[i];
	sort(all(l));
	vector<ll> p;
	vector<ll> av;
	rep(i, n){
		/*
		if(i < (n - 1) && l[i] == l[i + 1]){
			p.pb(l[i]);
			i++;
		}
		else av.pb(l[i]);
		*/
		av.pb(l[i]);
	}
	for(int i = av.size() - 1; i >= 0; i--){
		if(i > 0 && (av[i] - av[i - 1]) <= 1){
			ll num = min(av[i], av[i - 1]);
			p.pb(num);
			i--;
		}
	}
	ll ans = 0LL;
	sort(all(p));
	reverse(all(p));
	for(int i = 0; i < p.size(); i += 2){
		if(i < (p.size() - 1)) ans += (ll)(p[i] * p[i + 1]);
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
