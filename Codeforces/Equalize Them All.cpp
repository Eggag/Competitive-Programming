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
#define ar array
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
	map<int, int> cnt;
	int mx = 0, bst = -1;
	rep(i, n){
		cin >> a[i];
		cnt[a[i]]++;
		if(cnt[a[i]] > mx){
			mx = cnt[a[i]];
			bst = a[i];
		}
	}
	int ind = -1;
	rep(i, n) if(a[i] == bst) ind = i;
	assert(ind != -1);
	int l = ind;
	vector<ar<int, 3>> ans;
	while(l > 0){
		if(a[l] != a[l - 1]){
			if(a[l] > a[l - 1]){
				ans.pb({1, l - 1, l});
			}
			else ans.pb({2, l - 1, l});
			a[l - 1] = a[l];
		}
		l--;
	}
	int r = ind;
	while(r < (n - 1)){
		if(a[r] != a[r + 1]){
			if(a[r] > a[r + 1]){
				ans.pb({1, r + 1, r});
			}
			else ans.pb({2, r + 1, r});
			a[r + 1] = a[r];
		}
		r++;
	}
	cout << ans.size() << endl;
	rep(i, ans.size()) cout << ans[i][0] << " " << ans[i][1] + 1 << " " << ans[i][2] + 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
