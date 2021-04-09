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
#define ar array

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

bool cmp(ar<int, 3> a, ar<int, 3> b){
	if(a[0] != b[0]) return a[0] > b[0];
	return a[2] < b[2];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	int cur = 1, ind = 0;
	vector<pi> p(n);
	multiset<ar<int, 3>, decltype(cmp)*> q(cmp);
	set<int> st;
	repn(i, 1, n){
		if(a[i] == a[i - 1]) cur++;
		else{
			p[ind] = mp(cur, a[i - 1]);
			st.insert(ind);
			q.insert(ar<int, 3>{cur, a[i - 1], ind++});
			cur = 1;
		}
	}
	p[ind] = mp(cur, a[n - 1]);
	st.insert(ind);
	q.insert(ar<int, 3>{cur, a[n - 1], ind++});
	int cnt = 0;
	while(!q.empty()){
		ar<int, 3> cr = *q.begin();
		q.erase(q.begin());
		if(st.find(cr[2]) == st.end()) continue;
		cnt++;
		st.erase(st.find(cr[2]));
		if(q.empty()) break;
		auto fs = st.lb(cr[2]);
		if(fs != st.end() && fs != st.begin()){
			int x = *fs;
			int y = *(--fs);
			if(p[x].se == p[y].se){
				st.erase(fs);
				p[x].fi += p[y].fi;
				q.insert(ar<int, 3>{p[x].fi, p[x].se, x});
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
