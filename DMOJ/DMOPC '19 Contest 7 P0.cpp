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
	ld a, b, c, d;
	cin >> a >> b >> c >> d;
	//2
	cout << fixed << setprecision(10);
	cout << (ld)((a + b) / 2) << endl;
	cout << (ld)((a + c) / 2) << endl;
	cout << (ld)((a + d) / 2) << endl;
	cout << (ld)((b + c) / 2) << endl;
	cout << (ld)((b + d) / 2) << endl;
	cout << (ld)((c + d) / 2) << endl;
	//3
	cout << (ld)((a + b + c) / 3) << endl;
	cout << (ld)((a + b + d) / 3) << endl;
	cout << (ld)((a + c + d) / 3) << endl;
	cout << (ld)((b + c + d) / 3) << endl;
	//4
	cout << (ld)((a + b + c + d) / 4) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
