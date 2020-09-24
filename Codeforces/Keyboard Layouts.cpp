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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

unordered_map<char, char> m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s, s1;
	cin >> s >> s1;
	string s2;
	cin >> s2;
	rep(i, s.size()){
		m[s[i]] = s1[i];
	}
	rep(i, s2.size()){
		if(s2[i] >= '0' && s2[i] <= '9') cout << s2[i];
		else{
			if(s2[i] >= 'a' && s2[i] <= 'z') cout << m[s2[i]];
			else{
				char ans = m[s2[i] + 32];
				char ans1 = ans - 32;
				cout << ans1;	
			}
		}
	}
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
