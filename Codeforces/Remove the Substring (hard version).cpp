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
	string s, t;
	cin >> s >> t;
	int ind = (int)t.size() - 1;
	vi cl((int)t.size());
	for(int i = s.size() - 1; i >= 0; i--){
		if(s[i] == t[ind]){
			cl[ind] = i;
			ind--;
			if(ind == -1) break;
		}
	}
	int ans = cl[0];
	ind = 0;
	rep(i, s.size()){
		if(s[i] == t[ind]){
			ind++;
			if(ind < ((int)(t.size())) && i < cl[ind]){
				int cur = (int)s.size() - (i + 1 + ((int)s.size() - cl[ind]));
				ans = max(ans, cur);

			}
			else{
				ans = max(ans, (int)s.size() - (i + 1));
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
