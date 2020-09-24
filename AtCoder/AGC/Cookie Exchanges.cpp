#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int a, b, c;
	cin >> a >> b >> c;
	map<pi, int> cnt;
	int nm = 0;
	while(true){
		int a1 = a, b1 = b, c1 = c;
		if((a1 & 1) || (b1 & 1) || (c1 & 1)){
			cout << nm << endl;
			return 0;
		}
		b1 = c / 2 + a / 2;
		a1 = c / 2 + b / 2;
		c1 = a / 2 + b / 2;
		if(cnt[mp(a1, b1)]){
			cout << -1 << endl;
			return 0;
		}
		cnt[mp(a1, b1)] = 1;
		a = a1, b = b1, c = c1;
		nm++;
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
