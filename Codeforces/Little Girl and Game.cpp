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
	string s;
	cin >> s;
	map<char, int> m;
	rep(i, s.size()) m[s[i]]++;
	if(m.size() == 1){
		cout << "First" << endl;
		return 0;
	}
	if(s.size() % 2 == 0){
		int f = 1;
		for(auto x : m){
			if(x.se & 1){
				f = 0;
				break;
			}
		}
		if(f){
			cout << "First" << endl;
			return 0;
		}
	}
	else{
		int f = 0;
		for(auto x : m) if(x.se & 1) f++;
		if(f == 1){
			cout << "First" << endl;
			return 0;
		}
	}
	if(s.size() % 2 == 0) cout << "Second" << endl;
	else cout << "First" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
