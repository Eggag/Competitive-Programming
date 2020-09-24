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
	ll a, b, n, m;
	cin >> a >> b >> n >> m;
	//we like the a guys
	//the b guys kinda suck
	//we can use the a guys to equalize stuff
	//but b's are bad
	//hmm
	//once the a guys are done equalizing
	//they go one by one, right
	//so we might need to subtract one
	//from the min
	if((a + b) < (n + m)){
		cout << "No" << endl;
		return;
	}
	if(b < a) swap(a, b); // a < b now
	ll a1 = a, b1 = b;
	if((b - a) > n){
		if(a >= m){
			cout << "Yes" << endl;
			return;
		}
	}
	if((b - a) <= n){
		n -= (b - a);
		b = a;
		b -= (n + 1) / 2;
		if(b >= m){
			cout << "Yes" << endl;
			return;
		}
	}
	a = a1, b = b1;
	if(a >= m) cout << "Yes" << endl;
	else cout << "No" << endl;
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
