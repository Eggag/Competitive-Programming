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

void solve(){
	int n;
	cin >> n;
	map<string, int> m;
	vector<string> s(n);
	rep(i, n){
		cin >> s[i];
		m[s[i]]++;
	}
	int cnt = 0;
	rep(i, n) if(m[s[i]] > 1){
		//try to add, then subtract
		rep(j, s.size()){
			char cur = s[i][j] + 1;
			int f = 1;
			while(cur <= '9'){
				string s1 = s[i];
				s1[j] = cur;
				if(!m[s1]){
					m[s[i]]--;
					m[s1]++;
					s[i] = s1;
					cnt++;
					f = 0;
					break;
				}
				cur++;
			}
			if(!f) break;
			cur = s[i][j] - 1;
			f = 1;
			while(cur >= '0'){
				string s1 = s[i];
				s1[j] = cur;
				if(!m[s1]){
					m[s[i]]--;
					m[s1]++;
					s[i] = s1;
					cnt++;
					f = 0;
					break;
				}
				cur--;
			}
			if(!f) break;
		}
	}
	cout << cnt << endl;
	rep(i, n) cout << s[i] << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
