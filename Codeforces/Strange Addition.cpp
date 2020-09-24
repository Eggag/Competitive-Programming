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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int k;
	cin >> k;
	vi d(k);
	rep(i, k) cin >> d[i];
	vi mx;
	rep(i, k){
		vi cnt(3, 0); //have to?
		string nw = to_string(d[i]);
		reverse(all(nw));
		if(nw.size() == 1){
			if(nw[0] != '0') cnt[0] = 1;
		}
		if(nw.size() == 2){
			if(nw[0] != '0') cnt[0] = 1;
			if(nw[1] != '0') cnt[1] = 1;
		}
		if(nw.size() == 2){
			if(nw[0] != '0') cnt[0] = 1;
			if(nw[1] != '0') cnt[1] = 1;
			if(nw[2] != '0') cnt[2] = 1;
		}
		vi ans = {i};
		vi vis(k, 0);
		vis[i] = 1;
		//now we allow one by one
		rep(j, k) if(!vis[j]){
			string cur = to_string(d[j]);
			reverse(all(cur));
			int cnt1 = 0;
			int f = 1;
			rep(m, cur.size()){
				if(!cnt[m] && cur[m] != '0') cnt1++;
				if(cnt[m] && cur[m] != '0') f = 0;
			}
			if(cnt1 <= 1 && f){
				ans.pb(j), vis[j] = 1;
				rep(m, cur.size()) if(!cnt[m] && cur[m] != '0'){
					cnt[m] = 1;
				}
			}
		}
		rep(j, k) if(!vis[j]){
			string cur = to_string(d[j]);
			reverse(all(cur));
			int cnt1 = 0;
			int f = 1;
			rep(m, cur.size()){
				if(!cnt[m] && cur[m] != '0') cnt1++;
				if(cnt[m] && cur[m] != '0') f = 0;
			}
			if(cnt1 <= 2 && f){
				ans.pb(j), vis[j] = 1;
				rep(m, cur.size()) if(!cnt[m] && cur[m] != '0'){
					cnt[m] = 1;
				}
			}
		}
		rep(j, k) if(!vis[j]){
			string cur = to_string(d[j]);
			reverse(all(cur));
			int cnt1 = 0;
			int f = 1;
			rep(m, cur.size()){
				if(!cnt[m] && cur[m] != '0') cnt1++;
				if(cnt[m] && cur[m] != '0') f = 0;
			}
			if(cnt1 <= 3 && f){
				ans.pb(j), vis[j] = 1;
				rep(m, cur.size()) if(!cnt[m] && cur[m] != '0'){
					cnt[m] = 1;
				}
			}
		}
		if(ans.size() > mx.size()) mx = ans;
	}
	cout << mx.size() << endl;
	for(int x : mx) cout << d[x] <<  " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
