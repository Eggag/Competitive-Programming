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
	int n;
	cin >> n;
	vi a(n);
	int mn = 1e9, mx = 0;
	rep(i, n) cin >> a[i], mn = min(a[i], mn), mx = max(mx, a[i]);
	if((mx - mn) > 1){
		cout << "No" << endl;
		return 0;
	}
	if((mx - mn) == 0){
		if(mn == (n - 1)){ //everyone is unique
			cout << "Yes" << endl;
			return 0;
		}
		cout << (((n / mn) > 1) ? "Yes" : "No") << endl;
		return 0;
	}
	int un = 0; //number of unique colors
	rep(i, n) if(a[i] == mn) un++;
	cout << ((mx >= un + 1 && mx <= (un + (n - un) / 2)) ? "Yes" : "No") << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
