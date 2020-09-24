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
#define y1 abababa

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll n;
ll x, y, x1, y1;
ll ver = 0LL, hor = 0LL;
string s;

bool check(ll g){
	//we need to know where it is going to be
	ll x2 = (g / n) * ver;	
	rep(i, g % n){
		if(s[i] == 'L') x2--;
		else if(s[i] == 'R') x2++;
	}
	ll y2 = (g / n) * hor;
	rep(i, g % n){
		if(s[i] == 'U') y2++;
		else if(s[i] == 'D') y2--;
	}
	ll x3 = x + x2, y3 = y + y2;
	return (g >= (abs(x1 - x3) + abs(y1 - y3)));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> x >> y;
	cin >> x1 >> y1;
	cin >> n;
	cin >> s;
	rep(i, n){
		if(s[i] == 'L') ver--;
		else if(s[i] == 'R') ver++;
	}
	rep(i, n){
		if(s[i] == 'D') hor--;
		else if(s[i] == 'U') hor++;
	}
	ll l = 0, r = 1e15;
	while(l < r){
		ll mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	if(l == 1e15) cout << -1 << endl;
	else cout << l << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
