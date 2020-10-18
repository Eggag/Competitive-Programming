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
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	int mx = n;
	//each one can 'catch' one of 2 or 3
	vi proc2, proc3; //we put the 2s and 3s that need catching here
	vector<pi> ans;
	rep(i, n) if(a[i]){
		if(a[i] == 2){
			if(proc3.size()){
				int cur = proc3[(int)(proc3.size()) - 1];
				ans.pb({i + 1, cur});
				ans.pb({i + 1, mx});
				proc2.pb(mx);
				proc3.pop_back();
				mx--;
			}
			else{
				proc2.pb(mx);
				ans.pb({i + 1, mx});
				mx--;
			}
		}
		if(a[i] == 1){
			if(proc2.size()){
				int cur = proc2[(int)(proc2.size()) - 1];	
				ans.pb({i + 1, cur});
				proc2.pop_back();
			}
			else if(proc3.size()){
				int cur = proc3[(int)(proc3.size()) - 1];	
				ans.pb({i + 1, cur});
				ans.pb({i + 1, mx});
				proc3.pop_back();
				mx--;
			}
			else{
				ans.pb({i + 1, mx});
				mx--;
			}
		}
		if(a[i] == 3){
			if(proc3.size()){
				int cur = proc3[(int)(proc3.size()) - 1];	
				ans.pb({i + 1, cur});
				ans.pb({i + 1, mx});
				proc3.pop_back();
				proc3.pb(mx);
				mx--;
			}
			else{
				proc3.pb(mx);
				ans.pb({i + 1, mx});
				mx--;
			}
		}
		if(mx < 0){
			cout << -1 << endl;
			return 0;
		}
	}
	if(proc2.size() || proc3.size()){
		cout << -1 << endl;
		return 0;
	}
	cout << (int)ans.size() << endl;
	vi cnt(n + 1, 0);
	vi cnt1(n + 1, 0);
	for(pi x : ans){
		cnt[x.fi]++;
		if(cnt[x.fi] > 2){
			cout << -1 << endl;
			return 0;
		}
		cnt1[x.se]++;
		if(cnt1[x.se] > 2){
			cout << -1 << endl;
			return 0;
		}
	}
	for(pi x : ans) cout << (n + 1 - x.se) << " " << x.fi << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
