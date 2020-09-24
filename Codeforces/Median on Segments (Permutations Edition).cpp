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
	int n, m;
	cin >> n >> m;
	vi p(n);
	int pos = -1;
	rep(i, n){
		cin >> p[i];
		if(p[i] == m) pos = i;
	}
	assert(pos != -1);
	int bal = 0; //+1 if larger, -1 otherwise
	map<int, int> cnt;
	ll ans = 0LL;
	repn(i, pos, n){
		if(p[i] > m) bal++;
		else bal--;
		cnt[bal]++;
		if(bal == 0 || bal == -1) ans++;;
	}
	bal = 0;
	for(int i = pos - 1; i >= 0; i--){
		if(p[i] > m) bal++;
		else bal--;
		//we don't count the initial
		ans += cnt[-bal];
		ans += cnt[-bal - 1];
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
