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
	int n = s.size(), n1 = t.size();
	map<string, int> pos;
	rep(i, n) repn(j, i, n){
		string cur = s.substr(i, j - i + 1);
		string cur1 = cur;
		reverse(all(cur1));
		pos[cur] = i;
		pos[cur1] = i;
		rep(k, cur.size()){
			rotate(cur.begin(), cur.begin() + 1, cur.end());
			rotate(cur1.begin(), cur1.begin() + 1, cur1.end());
			pos[cur] = i;
			pos[cur1] = i;
		}
	}
	//start with larger so that we can just exit if we can find it
	for(int len = n1; len >= 1; len--){
		rep(i, n1 - len + 1){
			string nw = t.substr(i, len);
			if(pos[nw]){
				cout << len << endl;
				cout << pos[nw] << " " << i << endl;
				return 0;
			}
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
