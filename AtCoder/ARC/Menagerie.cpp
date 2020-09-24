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
	string s1;
	cin >> s1;
	rep(i, 2) rep(j, 2){
		//only 4 possibilities, really
		//so guess sheep 1 and sheep 2
		string s = "";
		rep(k, n) s += '?';
		if(i) s[0] = 'S';
		else s[0] = 'W';
		if(j) s[1] = 'S';
		else s[1] = 'W';
		int f = 1;
		rep(k, n){
			int next = (k + 1) % n;
			int last = k - 1;
			if(last == -1) last += n;
			int f1 = (s1[k] == 'o');
			if(s[k] == 'W')  f1 ^= 1;
			if(f1){
				if(s[last] != '?' && s[next] != '?'){
					if(s[last] != s[next]){
						f = 0;
						break;
					}
					continue;
				}
				if(s[last] != '?') s[next] = s[last];
				else if(s[next] != '?') s[last] = s[next];
			}
			else{
				if(s[last] != '?' && s[next] != '?'){
					if(s[last] == s[next]){
						f = 0;
						break;
					}
					continue;
				}
				if(s[last] != '?'){
					if(s[last] == 'S') s[next] = 'W';
					else s[next] = 'S';
				}
				else if(s[next] != '?'){
					if(s[next] == 'S') s[last] = 'W';
					else s[last] = 'S';
				}
			}
		}
		if(f){
			cout << s << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
