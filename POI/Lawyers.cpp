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

bool cmp(array<int, 3> a, array<int, 3> b){
	if(a[0] != b[0]) return a[0] < b[0];
	return a[1] > b[1];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<array<int, 3>> p;
	vi a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i], p.pb({a[i], 1, i}), p.pb({b[i], 0, i});
	//make k = 1 a special case
	if(k == 1){
		int bst = 0;
		int ans = -1;
		rep(i, n){
			if(bst < (b[i] - a[i])){
				bst = b[i] - a[i];
				ans = i + 1;
			}
		}
		assert(ans != -1);
		cout << bst << endl;
		cout << ans << endl;
		return 0;
	}
	sort(all(p), cmp);
	multiset<pi> cur;
	int mx = 0;
	rep(i, p.size()){
		if(p[i][1]){
			while(cur.size()){
				pi nw = *cur.begin();
				if(nw.fi <= p[i][0]) cur.erase(cur.begin());
				else break;
			}
			while(cur.size() > (k - 1)) cur.erase(cur.begin());
			if(cur.size() == (k - 1)){
				pi nw = *cur.begin();
				mx = max(mx, min(b[p[i][2]], nw.fi) - p[i][0]);
			}
			cur.insert(mp(b[p[i][2]], p[i][2]));
		}
		else{
			auto it = cur.find(mp(p[i][0], p[i][1]));
			if(it != cur.end()) cur.erase(it);
		}
	}	
	cur.clear();
	int bst = mx;
	mx = 0;
	rep(i, p.size()){
		if(p[i][1]){
			while(cur.size()){
				pi nw = *cur.begin();
				if(nw.fi <= p[i][0]) cur.erase(cur.begin());
				else break;
			}
			while(cur.size() > (k - 1)) cur.erase(cur.begin());
			if(cur.size() == (k - 1)){
				pi nw = *cur.begin();
				int res = min(b[p[i][2]], nw.fi) - p[i][0];
				if(res == bst){
					//we add all the indices and we're good
					cout << bst << endl;
					vi ans = {p[i][2] + 1};
					while(cur.size()){
						pi nw = *cur.begin();
						cur.erase(cur.begin());
						ans.pb(nw.se + 1);
					}
					for(int x : ans) cout << x << " ";
					cout << endl;
					return 0;
				}
			}
			cur.insert(mp(b[p[i][2]], p[i][2]));
		}
		else{
			auto it = cur.find(mp(p[i][0], p[i][1]));
			if(it != cur.end()) cur.erase(it);
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
