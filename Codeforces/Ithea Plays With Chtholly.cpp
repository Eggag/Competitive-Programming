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
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, c;
	cin >> n >> m >> c;
	int mx = 0, mn = 1e9, mx1 = 0;
	vi ans, ans1;
	int bo = (c + 1) / 2;
	rep(i, m){
		int p;
		cin >> p;
		if(p <= bo){
			if(p >= mx){
				cout << (int)(ans.size()) + 1 << endl;
				ans.pb(p), mx = max(mx, p);
			}
			else{
				auto it = ub(all(ans), p);
				assert(it != ans.end());
				int ind = (int)(it - ans.begin());
				cout << ind + 1 << endl;
				if(ind == (int)(ans.size() - 1) && ans[ind] == mx) mx = p;
				ans[ind] = p;
			}
		}
		else{
			if(p <= mn){
				cout << n - (int)(ans1.size()) << endl;
				ans1.pb(p), mn = min(mn, p);
				mx1 = max(mx1, p);
			}
			else{
				int l = 0, r = (int)(ans1.size()) - 1;
				while(l < r){
					int mid = (l + r + 1) / 2;
					if(ans1[mid] > p) l = mid;
					else r = mid - 1;
				}
				cout << n - l << endl;
				if(!l && ans1[l] == mx1) mx1 = p;
				ans1[l] = p;
			}
		}
		if((int)(ans.size() + ans1.size()) == n) return 0;
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
