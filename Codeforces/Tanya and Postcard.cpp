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
	map<char, int> m;
	rep(i, t.size()) m[t[i]]++;
	int y = 0, wh = 0;
	vi v((int)(s.size()), 0);
	rep(i, s.size()){
		if(m[s[i]]){
			v[i] = 1;
			m[s[i]]--;
			y++;
		}
	}
	rep(i, s.size()) if(!v[i]){
		if(m[(char)(s[i] + ('a' - 'A'))]){
			m[(char)(s[i] + ('a' - 'A'))]--;
			wh++;
		}
		else if(m[(char)(s[i] - ('a' - 'A'))]){
			m[(char)(s[i] - ('a' - 'A'))]--;
			wh++;
		}
	}
	cout << y << " " << wh << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
