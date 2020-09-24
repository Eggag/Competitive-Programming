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

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

map<int, int> m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, M;
	cin >> n >> M;
	ll a[n];
	rep(i, n) cin >> a[i];
	sort(a, a + n);
	rep(i, M){
		int b, c;
		cin >> b >> c;
		m[c] += b;
	}
	ll sum = 0LL;
	rep(i, n){
		if(m.size() && m.rbegin() -> fi > a[i]){
			a[i] = m.rbegin() -> fi;
			m.rbegin() -> se--;
			if(m.rbegin() -> se == 0) m.erase(m.rbegin() -> fi);
		}
		sum += a[i];
	}
	cout << sum << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
