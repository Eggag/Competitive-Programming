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

bool intersect(int l, int r, int l1, int r1){
	if(l >= l1 && l <= r1) return 1;
	if(r >= l1 && r <= r1) return 1;
	if(l1 >= l && l1 <= r) return 1;
	if(r1 >= l && r1 <= r) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;
		int d1 = n * (a - b), d2 = n * (a + b);
		if(intersect(c - d, c + d, d1, d2)) cout << "Yes" << endl;
		else cout << "No" << endl;
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
