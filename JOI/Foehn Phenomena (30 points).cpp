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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, q, s, t;
	cin >> n >> q >> s >> t;
	vector<ll> a(n + 1);
	rep(i, n + 1) cin >> a[i];
	ll cur = 0;
	repn(i, 1, n + 1){
		if(a[i] > a[i - 1]) cur -= (a[i] - a[i - 1]) * s;
		else cur += (a[i - 1] - a[i]) * t;
	}
	rep(i, q){
		int l, r, x;
		cin >> l >> r >> x;
		//only need to take care of endpoints
		if(l > 0){
			//reverse the prev
			if(a[l] > a[l - 1]) cur += (a[l] - a[l - 1]) * s;
			else cur -= (a[l - 1] - a[l]) * t;
			a[l] += x;
			if(a[l] > a[l - 1]) cur -= (a[l] - a[l - 1]) * s;
			else cur += (a[l - 1] - a[l]) * t;
			a[l] -= x;
		}
		if(r < n){
			if(a[r + 1] > a[r]) cur += (a[r + 1] - a[r]) * s;
			else cur -= (a[r] - a[r + 1]) * t;
			a[r] += x;
			if(a[r + 1] > a[r]) cur -= (a[r + 1] - a[r]) * s;
			else cur += (a[r] - a[r + 1]) * t;
			a[r] -= x;
		}
		repn(j, l, r + 1) a[j] += x; 
		cout << cur << endl;
	}
	return 0;
}

/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
