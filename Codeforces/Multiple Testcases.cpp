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

vi ans[200005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vi m(n);
	map<int, vi> cnt; //store all of them
	rep(i, n) cin >> m[i], cnt[m[i]].pb(i);
	vi c(k);
	rep(i, k) cin >> c[i];
	//process from the back because idk
	//ugh why do i always need a set
	//shld i do this now though? its late :(
	int ind = 0;
	multiset<pi> st; //keep the number used + index
	st.insert(mp(0, 0));
	for(int i = k; i >= 1; i--){
		while(cnt[i].size() > 0){
			pi bst = *st.begin();
			st.erase(st.begin());
			//now try to fill it up as much as we can
			int pos = c[i - 1] - bst.fi;
			if(pos == 0){
				//need a new one oops
				ind++;
				st.insert(bst);
				st.insert(mp(0, ind));
				continue;
			}
			else{
				int num = 0;
				while(pos-- && cnt[i].size()){
					ans[bst.se].pb(cnt[i].back());
					cnt[i].pop_back();
					num++;
				}
				st.insert(mp(bst.fi + num, bst.se));
			}
		}
	}
	cout << ind + 1 << endl;
	rep(i, ind + 1){
		cout << ans[i].size() << " ";
		rep(j, ans[i].size()) cout << m[ans[i][j]] << " ";
		cout << endl;
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
