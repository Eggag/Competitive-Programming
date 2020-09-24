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

int pos[100005];
int score[100005];

void solve(){
	int n;
	cin >> n;
	vi p(n);
	rep(i, n) cin >> p[i], pos[p[i]] = i, score[i] = 1;
	int mx = 1;
	multiset<int> sc;
	rep(i, n) sc.insert(1);
	set<int> st;
	rep(i, n) st.insert(i);
	repn(i, 1, n + 1){
		auto it = sc.end();
		it--;
		mx = *it;
		if(score[pos[i]] < mx){
			cout << "No" << endl;
			return;
		}
		auto nxt1 = st.lb(pos[i]);
		nxt1++;
		if(nxt1 != st.end()){
			int nxt = *nxt1;
			sc.erase(sc.find(score[nxt]));
			score[nxt] += score[pos[i]];
			sc.erase(sc.find(score[pos[i]]));
			st.erase(st.find(pos[i]));
			sc.insert(score[nxt]);
		}
		else{
			st.erase(st.find(pos[i]));
			sc.erase(sc.find(score[pos[i]]));
		}
		score[pos[i]] = 0;
		//for(int x : sc) cout << x << " ";
		//cout << endl;
	}
	cout << "Yes" << endl;
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
