#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	while(q--){
		int n, m;
		cin >> n >> m;
		vector<string> s(n);
		rep(i, n) cin >> s[i];
		vi cnt(n, 0), cnt1(m, 0);
		vi cnt2(n, 0), cnt3(m, 0);
		rep(i, n) rep(j, m){
			if(s[i][j] == '*') cnt[i]++, cnt2[i]++;
		}
		rep(i, m) rep(j, n){
			if(s[j][i] == '*') cnt1[i]++, cnt3[i]++;
		}
		vi v, v1;
		sort(all(cnt1));
		reverse(all(cnt1));
		int cur = cnt1[0];
		rep(i, m) if(cnt3[i] == cur) v.pb(i);
		sort(all(cnt));
		reverse(all(cnt));
		int cur1 = cnt[0];
		rep(i, n) if(cnt2[i] == cur1) v1.pb(i);
		int ans = (n - cnt[0]) + (m - cnt1[0]);
		int f = 1;
		if(ans == 0){
			cout << 0 << endl;
		}
		else{
			rep(i, v1.size()){
				if(!f) break;
				rep(j, v.size()){
					if(s[v1[i]][v[j]] == '.'){
						ans--;
						f = 0;
						break;
					}
				}
			}
			cout << ans << endl;
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
