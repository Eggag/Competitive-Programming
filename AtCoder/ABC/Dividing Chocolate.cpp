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
	int h, w, k;
	cin >> h >> w >> k;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	int ans1 = 1e9;
	rep(i, (1 << (h - 1))){
		int ans = __builtin_popcount(i);
		vi cnt(h + 2, 0);
		vi gr(h + 2, 0);
		int ind = 0;
		rep(j, h){
			cnt[j] = ind;
			if(i & (1 << j)) ind++;
		}
		int bad = 0;
		rep(j, w){
			rep(l, h) if(s[l][j] == '1') gr[cnt[l]]++;
			rep(l, h) if(gr[l] > k){
				if(!j){
					bad = 1;
					break;
				}
				rep(m, h) gr[m] = 0;
				rep(m, h) if(s[m][j] == '1'){
					//add the current
					gr[cnt[m]]++;
				}
				ans++; //increment answer
				break;
			}
			rep(l, h) if(gr[l] > k){
				bad = 1;
				break;
			}
			if(bad) break;
		}
		if(bad) continue;
		ans1 = min(ans, ans1);
	}
	cout << ans1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
