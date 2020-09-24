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
	ll n, m;
	cin >> n >> m;
	vector<ll> l(m);
	rep(i, m) cin >> l[i];
	ll st = 1LL;
	vector<ll> pos(m);
	rep(i, m){
		pos[i] = st;
		st += l[i];
	}
	st--;
	ll sub = st - n;
	if(st < n){
		cout << -1 << endl;
		return 0;
	}
	ll cur = 0;
	rep(i, m){
		if(sub > 0){
			ll mn = i + 1;
			pos[i] -= cur;
			ll subtr = min(sub, max(0LL, pos[i] - mn));
			cur += subtr;
			pos[i] -= subtr;
			sub -= subtr;
		}
		else pos[i] -= cur;
	}
	if(sub > 0){
		cout << "-1" << endl;
		return 0;
	}
	rep(i, m){
		if((pos[i] + l[i] - 1) > n){
			cout << "-1" << endl;
			return 0;
		}
	}
	rep(i, m) cout << pos[i] << " ";
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
