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

int vis[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, p, w, d;
	cin >> n >> p >> w >> d;
	if(!p){
		cout << "0 0 " << n << endl;
		return 0;
	}
	if(p < d){
		cout << -1 << endl;
		return 0;
	}
	memset(vis, 0, sizeof(vis));
	ll i = 0;
	while(1){
		ll y = i * d;
		i++;
		if(p < y) continue;
		ll x = p - y;
		if(x % w != 0){
			if(vis[x % w]) break;
			vis[x % w] = 1;
			continue;
		}
		x /= w;
		ll z = n - (x + (y / d));
		if(z < 0) continue;
		cout << x << " " << y / d << " " << z << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
