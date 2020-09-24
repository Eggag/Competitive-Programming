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
const int MAXN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll n, m;
ll a[MAXN], b[MAXN];

bool check(ll rad){
	//3 sec. limit is good news!
	//O(nlog()^2)
	rep(i, n){ //for each city
		//check the closest ahead and behind
		//if not reachable from either return false
		int f = 0;
		int pos = lb(b, b + m, a[i]) - b;
		if(pos >= 0 && pos < m && abs(b[pos] - a[i]) <= rad) f = 1;
		pos--;
		if(pos >= 0 && pos < m && abs(a[i] - b[pos]) <= rad) f = 1;
		if(!f) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	ll l = 0, r = 1e10;
	while(l < r){
		ll mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
