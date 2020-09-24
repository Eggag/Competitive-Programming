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
	pi ans;
	pi bst = {-1, -1};
	repn(j, 1, 27){
		int cnt = 0, l = 0;
		vi vis(30, 0);
		rep(i, n){
			if(!vis[s[i] - 'a']) cnt++;
			vis[s[i] - 'a']++;		
			while(cnt > j){
				vis[s[l] - 'a']--;
				if(!vis[s[l] - 'a']) cnt--;
				l++;
			}
			if(bst.fi == -1 || sm(mp(cnt, i - l + 1), bst)){
				ans = mp(l + 1, i + 1);
				bst = mp(cnt, i - l + 1);
			}
		}
	}
	cout << ans.fi << " " << ans.se << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
