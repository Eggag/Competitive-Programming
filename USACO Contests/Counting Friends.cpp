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
	freopen("fcount.in", "r", stdin);
	freopen("fcount.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n + 1);
	rep(i, n + 1) cin >> a[i];
	vi ans;
	rep(i, n + 1){
		multiset<int> st;
		int tot = 0, mx = 0;
		rep(j, n + 1) if(i != j && a[j]) st.insert(a[j]), tot += a[j], mx = max(mx, a[j]);
		int f = 1;
		if(tot & 1) f = 0;
		if(mx > (n - 1)) f = 0;
		rep(j, n + 1) if(i != j && a[j]){
			if(a[j] > n) f = 0;
		}
		if(!f) continue;
		while(st.size()){
			if((int)st.size() == 1 && (*st.begin()) != 0){
				f = 0;
				break;
			}
			if(*(--st.end()) > (int)(st.size() - 1)){
				f = 0;
				break;
			}
			int b = *st.begin();
			if(((int)st.size() - 1) < b){
				f = 0;
				break;
			}
			vi p;
			while(b--){
				int nm = *(--st.end());	
				nm--;
				if(nm) p.pb(nm);
				st.erase(--st.end());
			}
			st.erase(st.begin());
			rep(j, p.size()) st.insert(p[j]);
		}	
		if(f) ans.pb(i + 1);
	}
	cout << (int)ans.size() << endl;
	for(int x : ans) cout << x << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
