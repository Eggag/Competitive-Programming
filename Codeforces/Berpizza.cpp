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
	int q;
	cin >> q;
	set<pi> st, st1;
	int id = 1;
	rep(i, q){
		int t;
		cin >> t;
		if(t == 1){
			int m;
			cin >> m;
			st.insert(mp(m, id));
			st1.insert(mp(id, m));
			id++;
		}
		else if(t == 2){
			pi cr = *st1.begin();
			cout << cr.fi << " ";
			st1.erase(st1.begin());
			st.erase(st.find(mp(cr.se, cr.fi)));
		}
		else{
			pi cr = *(--st.end());
			auto it = st.lb({cr.fi, 0});
			cr = *it;
			cout << cr.se << " ";
			st.erase(it);
			st1.erase(st1.find(mp(cr.se, cr.fi)));
		}
	}
	cout << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
