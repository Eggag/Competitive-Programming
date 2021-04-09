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

bool f(int a, int b, int c){
	return a >= b && a <= c;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi p(n), pos(n + 1);
	rep(i, n) cin >> p[i], pos[p[i]] = i;
	set<int> ps;
	int ans = 0;
	for(int i = n; i >= 1; i--){
		int l = 0, r = n - 1;
		auto it = ps.lb(pos[i]);
		if(it != ps.end()) r = *it - 1;
		if(it != ps.begin()) l = *(--it) + 1;
		if((pos[i] - l) < (r - pos[i])){
			repn(j, l, pos[i]){
				int op = i - p[j];
				if(op >= 1 && f(pos[op], pos[i], r)) ans++;
			}
		}
		else{
			repn(j, pos[i] + 1, r + 1){
				int op = i - p[j];
				if(op >= 1 && f(pos[op], l, pos[i])) ans++;
			}
		}
		ps.insert(pos[i]);
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
