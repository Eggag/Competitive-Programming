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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int cnt[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	map<int, vi> m;
	set<int> st1;
	int mx = 0;
	rep(i, n) cin >> a[i], m[a[i]].pb(i), mx = max(mx, a[i]), st1.insert(a[i]);
	vi pos(all(st1));
	reverse(all(pos));
	set<int> st;
	st.insert(-1);
	st.insert(n);
	cnt[n] = 1;
	int num = 1;
	int lst = 1;
	int ans = mx + 1;
	int bst = 1;
	rep(j, pos.size()){
		vi cur = m[pos[j]];
		rep(i, cur.size()){
			//remember stuff
			auto it = st.lb(cur[i]);
			auto it1 = it;
			it1--;
			//delete the current one
			num--;
			cnt[(*it - *it1) - 1]--;
			if(!cnt[((*it - *it1) - 1)]) lst--;
			//update the new (left and right)
			if((cur[i] - *it1) > 1){
				num++;
				if(!cnt[(cur[i] - *it1 - 1)]) lst++;
				cnt[(cur[i] - *it1 - 1)]++;
			}
			if((*it - cur[i]) > 1){
				num++;
				if(!cnt[(*it - cur[i] - 1)]) lst++;
				cnt[(*it - cur[i] - 1)]++;
			}
			st.insert(cur[i]);
		}
		if(lst == 1 && num >= bst){
			ans = pos[j];
			if(j != (pos.size() - 1)) ans = pos[j + 1] + 1;
			bst = num;
		}
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
