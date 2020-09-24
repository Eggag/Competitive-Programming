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
const ld eps = 1e-10;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ld dist(ld x1, ld y1, ld x2, ld y2){
	return (ld)(sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ld x, y, r;
	cin >> x >> y >> r;
	ld x1, y1, r1;
	cin >> x1 >> y1 >> r1;
	ld d = dist(x, y, x1, y1) - (r + r1);
	cout << fixed << setprecision(15);
	if(d >= 0){
		d /= 2;
		cout << d << endl;
	}
	else{
		ld d1 = dist(x, y, x1, y1);
		if((d1 + min(r, r1)) >= max(r, r1)){
			cout << eps << endl;
		}
		else{
			ld ans = max(r, r1) - (d1 + min(r, r1));
			ans /= 2;
			cout << ans << endl;
		}
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
