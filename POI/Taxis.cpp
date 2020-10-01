#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
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
const int mxN = 5e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
ll m, d;
ll x[mxN];

bool check(int g){
	if(x[0] < (m - d)) return 0;
	ll pos = 0LL;
	int ch = 0;
	rep(i, g) if(x[i] >= (m - d)) ch = i;
	ll lm = d - ((x[ch] - (m - d)) / 2);
	rep(i, g) if(i != ch){
		ll cur = x[i];
		cur -= abs(d - pos);
		if(cur > 0) pos += cur;
		if(pos >= lm) return 1;
	}
	if(pos >= lm) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> m >> d >> n;
	rep(i, n) cin >> x[i];
	sort(x, x + n);
	reverse(x, x + n);
	int l = 1, r = n;
	while(l < r){
		int mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	if(!check(l)) l = 0;
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
