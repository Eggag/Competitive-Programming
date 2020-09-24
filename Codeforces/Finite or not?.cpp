#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

ll gcd(ll a, ll b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	ll p, q, b;
	cin >> p >> q >> b;
	ll g = gcd(p, q);
	p /= g;
	q /= g;
	if(p % q == 0){
		cout << "Finite" << endl;
		return;
	}
	ll g1 = gcd(q, b);
	while(g1 != 1){
		while(q % g1 == 0) q /= g1;
		g1 = gcd(q, b);
	}
	if(q == 1) cout << "Finite" << endl;
	else cout << "Infinite" << endl;
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
