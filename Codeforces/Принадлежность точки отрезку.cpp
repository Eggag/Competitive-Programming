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

bool ccw(ll x, ll y, ll x1, ll y1, ll x2, ll y2){
	return (((x1 - x) * (y2 - y)) - ((y1 - y) * (x2 - x)));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("point3.in", "r", stdin);
	freopen("point3.out", "w", stdout);
	ll x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	if(x1 > x2) swap(x1, x2), swap(y1, y2);
	if(!(x >= x1 && x <= x2 && y >= min(y1, y2) && y <= max(y1, y2))){
		cout << "NO" << endl;
		return 0;
	}
	if(ccw(x1, y1, x2, y2, x, y) == 0){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
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
