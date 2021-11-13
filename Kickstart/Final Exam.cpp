#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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

void solve(){
	int n, m;
	cin >> n >> m;
	vector<pair<ll, ll>> p(n);
	vector<ll> s(m);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	rep(i, m) cin >> s[i];
	set<ll> st;
	map<ll, ll> ff;
	rep(i, n) st.insert(p[i].fi), ff[p[i].fi] = p[i].se;
	rep(i, m){
		auto it = st.lb(s[i]);
		ll d = 1e18, d1 = 1e18;
		if(it != st.end()) d = *it - s[i];
		if(it != st.begin()){
			it--;
			if(ff[*it] >= s[i]){
				cout << s[i];
				if(s[i] + 1 <= ff[*it]){
					st.insert(s[i] + 1);
					ff[s[i] + 1] = ff[*it];
				}
				ff[*it] = s[i] - 1;
				if(s[i] - 1 < *it){
					ff[*it] = 0;
					st.erase(it);
				}
				else ff[*it] = s[i] - 1;
			}
			else{
				d1 = s[i] - ff[*it];
				if(d1 <= d){
					cout << ff[*it];
					if(--ff[*it] < *it){
						ff[*it] = 0;
						st.erase(it);
					}
				}
				else{
					auto it1 = it;
					it1++;
					cout << *it1;
					if(((ll)(*it1) + 1) <= ff[*it1]){
						st.insert((ll)(*it1) + 1);
						ff[(ll)(*it1) + 1] = ff[*it1];
					}
					ff[*it1] = 0;
					st.erase(it1);
				}
			}
		}
		else{
			assert(it != st.end());
			cout << *it;
			if(((ll)(*it) + 1) <= ff[*it]){
				st.insert((ll)(*it) + 1);
				ff[(ll)(*it) + 1] = ff[*it];
			}
			ff[*it] = 0;
			st.erase(it);
		}
		if(i != (m - 1)) cout << " ";
		else cout << '\n';
	}
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
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
