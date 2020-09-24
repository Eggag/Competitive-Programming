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
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	vi cnt(30, 0);
	rep(i, s.size()) cnt[s[i] - 'a']++;
	rep(i, t.size()) cnt[t[i] - 'a']--;
	rep(i, 30) if(cnt[i]){
		cout << -1 << endl;
		return 0;
	}
	vi ans;
	rep(i, n) if(s[i] != t[i]){
		int st = -1;
		repn(j, i + 1, n){
			if(s[j] == t[i]){
				st = j;
				break;
			}
		}
		assert(st != -1);
		for(int j = st; j > i; j--){
			swap(s[j], s[j - 1]);
			ans.pb(j - 1);
		}
	}
	cout << ans.size() << endl;
	for(int x : ans) cout << x + 1 << " ";
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
