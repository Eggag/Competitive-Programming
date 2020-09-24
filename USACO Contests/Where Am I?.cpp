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
	freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<string, int> m;
	rep(i, n) repn(j, i, n){
		m[s.substr(i, j - i + 1)]++;
	}
	vi cnt(105, 1);
	for(pair<string, int> x : m){
		cnt[(int)x.fi.size()] = max(cnt[(int)x.fi.size()], x.se);
	}
	repn(i, 1, 101){
		if(cnt[i] == 1){
			cout << i << endl;
			return 0;
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
