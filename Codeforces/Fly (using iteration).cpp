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
const int MAXN = 1005;
const ld EPS = 1e-7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ld n, m;
ld a[MAXN], b[MAXN];

bool check(ld cur){
	ld w = m + cur;
	ld req = 0;
	rep(i, n){
		if(!i){ //only do liftoff
			ld now = w / a[i];
			req += now;
			w -= now;
		}
		else{
			ld now1 = w / b[i];
			req += now1;
			w -= now1;
			ld now = w / a[i];
			req += now;
			w -= now;
		}
	}
	ld l = w / b[0];
	req += l;
	return (cur >= req);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	ld l = 0, r = 1e10;
	rep(i, 1000){
		ld mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout << fixed << setprecision(20);
	if(l > 1.1e9) cout << -1 << endl;
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
