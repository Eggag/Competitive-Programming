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
	ll n, k;
	cin >> n >> k;
	vector<ll> x(n);
	rep(i, n) cin >> x[i];
	ll a;
	cin >> a;
	vector<ll> c(n);
	rep(i, n) cin >> c[i];
	ll cur = k;
	ll cost = 0;
	multiset<ll> pos;
	rep(i, n){
		pos.insert(c[i]);
		if(cur < x[i]){
			ll div = ((x[i] - cur) + a - 1) / a; //how many more we need
			if(div > (int)pos.size()){
				cout << -1 << endl;
				return 0;
			}
			int cnt = 0;
			vector<ll> er;
			for(auto x : pos){
				cost += x;
				//pos.erase(x);
				er.pb(x);
				cnt++;
				if(div == cnt) break;
			}
			rep(j, er.size()) pos.erase(pos.find(er[j]));
			cur += (div * a);
		}
	}
	cout << cost << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
