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

pi prime(int n){
	for(int i = 2; (i * i) <= n; i++){
		if(n % i == 0) return mp(i, n / i);
	}
}
void solve(){
	int n1, l;
	cin >> n1 >> l;
	vi a(l);
	rep(i, l) cin >> a[i];
	pi one = prime(a[0]);
	vi ans(l + 1);
	int cnt = 0;
	rep(i, 2){
		if(!i){
			ans[0] = one.fi;
			ans[1] = one.se;
			if(a[1] % ans[1]) continue;
			ans[2] = a[1] / ans[1];
		}
		else{
			if(cnt) break;
			ans[0] = one.se;
			ans[1] = one.fi;
			if(a[1] % ans[1]) continue;
			ans[2] = a[1] / ans[1];
		}
		int f = 1;
		repn(j, 3, l + 1){
			ans[j] = a[j - 1] / ans[j - 1];
			if(a[j - 1] % ans[j - 1]){
				f = 0;
				break;
			}
		}
		if(!f) continue;
		cnt++;
	}
	set<int> st;
	rep(i, l + 1) st.insert(ans[i]);
	vi p(all(st));
	map<int, char> m;
	assert((int)p.size() == 26);
	rep(i, p.size()) m[p[i]] = 'A' + i;
	string ret = "";
	rep(i, ans.size()) ret += m[ans[i]];
	cout << ret << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
		solve();
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
