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
const ld eps = 1e-7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("point1.in", "r", stdin);
	freopen("point1.out", "w", stdout);
	ld x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	//ax + by + c
	//-(ax + c) / b = y
	//0 == -(ax + c)
	if(b){

		ld y1 = -(a * x + c) / b;
		cout << ((abs(y - y1) < eps) ? "YES" : "NO") << endl;
	}
	else cout << (((abs(-(a * x + c))) == 0) ? "YES" : "NO") << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
