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

vi g[30];

int fnd(int ch, int r){
	if(!g[ch].size()) return 0;
	if(r < 0) return 0;
	auto it = lb(all(g[ch]), r);
	if(it == g[ch].begin()){
		if(*it > r) return 0;
		else return 1;
	}
	if(it == g[ch].end()) it--;
	if(*it > r && it != g[ch].begin()) it--;
	return (it - g[ch].begin()) + 1;
}

int cnt(char x, int l, int r){
	int nm = x - 'a';
	return fnd(nm, r) - fnd(nm, l - 1);
}

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	rep(i, 30) g[i].clear();
	rep(i, s.size()) g[s[i] - 'a'].pb(i); 
	int t = 0;
	while((1 << t) < n) t++;
	int res = 1e9;
	rep(i, (1 << t) + 1){
		//if i is 0, we take left, else, we take right
		int l = 0, r = n - 1;
		int ans = 0;
		rep(j, t + 1){
			int mid = (l + r) / 2;
			if(i & (1 << j)){
				if(r == l) mid = r;
				ans += (mid - l + 1) - cnt((char)('a' + j), l, mid);
				l = mid + 1;
			}
			else{
				mid++;
				if(r == l) mid = l;
				ans += (r - mid + 1) - cnt((char)('a' + j), mid, r);
				r = mid - 1;
			}
		}
		res = min(res, ans);
	}
	cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
