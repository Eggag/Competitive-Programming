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
	int n, q;
	cin >> n >> q;
	vi a(n);
	set<int> st;
	multiset<int> mlt;
	rep(i, n) cin >> a[i], st.insert(a[i]);
	sort(all(a));
	repn(i, 1, n) mlt.insert(a[i] - a[i - 1]);
	int r = a[n - 1], l = a[0];
	rep(i, q + 1){
		if(mlt.size()){
			auto it = --mlt.end();
			int mx = *it;
			cout << r - l - mx << '\n';
		}
		else cout << 0 << '\n';
		if(i == q) continue;
		int t;
		cin >> t;
		if(t == 0){
			int x;
			cin >> x;
			if(*st.begin() == x){
				auto it = st.begin();
				it++;
				if(it != st.end()){
					auto it2 = mlt.find(*it - *st.begin());
					if(it2 != mlt.end()) mlt.erase(it2);
				}
			}
			else{
				auto it = st.lb(x);
				it--;
				if(mlt.find(x - *it) != mlt.end()) mlt.erase(mlt.find(x - *it));
				auto it1 = it;
				it1++;
				it1++;
				if(it1 != st.end()){
					auto it2 = mlt.find(*it1 - x);
					if(it2 != mlt.end()) mlt.erase(it2);
					mlt.insert(*it1 - *it);
				}
			}
			auto it = st.find(x);
			if(it != st.end()) st.erase(it);
		}
		else{
			int x;
			cin >> x;
			if(st.size()){
				auto it = st.lb(x);
				if(it != st.end()){
					mlt.insert(*it - x);
					if(it != st.begin()){
						auto it1 = it;
						it1--;
						mlt.insert(x - *it1);
						auto it2 = mlt.find(*it - *it1);
						if(it2 != mlt.end()) mlt.erase(it2);
					}
				}
				else{
					if(it != st.begin()){
						it--;
						mlt.insert(x - *it);
					}		
				}
			}
			st.insert(x);
		}
		if(st.size()){
			l = *st.begin();
			r = *(--st.end());
		}
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
