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

bool sm(pi a, pi b){
	return a.fi * b.se < a.se * b.fi;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(n <= 5000){
		//we can check from each starting location
		pi ans;
		pi bst = {-1, -1};
		rep(i, n){
			int cnt = 0;
			vi vis(30, 0);
			repn(j, i, n){
				if(!vis[s[j] - 'a']) vis[s[j] - 'a'] = 1, cnt++;
				if(bst.fi == -1 || sm(mp(cnt, j - i + 1), bst)){
					ans = mp(i + 1, j + 1);	
					bst = mp(cnt, j - i + 1);
				}
			}
		}
		cout << ans.fi << " " << ans.se << endl;
	}
	else{
		unordered_set<char> pos;
		rep(i, n) pos.insert(s[i]);
		vector<char> ps(all(pos));
		pi ans;
		pi bst = {-1, -1};
		int m = ps.size();
		rep(i, (1 << m)){
			vi gd(30, 0); //the ones we are allowed to use
			rep(j, m) if(i & (1 << j)) gd[ps[j] - 'a'] = 1;
			int len = 0, un = 0;
			vi used(30, 0);
			rep(j, n){
				if(!gd[s[j] - 'a']){
					len = 0;
					un = 0;
					rep(k, 30) used[k] = 0;
				}
				else{
					len++;
					if(!used[s[j] - 'a']) un++, used[s[j] - 'a']++;
					//try to update
					if(bst.fi == -1 || sm(mp(un, len), bst)){
						ans = mp(j + 1 - (len - 1), j + 1);
						bst = mp(un, len);
					}
				}
			}
		}
		cout << ans.fi << " " << ans.se << endl;
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
