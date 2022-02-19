#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
#define debug2(x, y) debug(x), debug(y)
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
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	set<int> st;
	rep(i, n - 2){
		if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c'){
			st.insert(i);
		}
	}
	rep(i, q){
		int ind;
		char c;
		cin >> ind >> c;
		ind--;
		s[ind] = c;
		repn(j, max(0, ind - 2), ind + 1){
			if(j + 2 >= n) break;
			if(s[j] == 'a' && s[j + 1] == 'b' && s[j + 2] == 'c') st.insert(j);
			else if(st.find(j) != st.end()) st.erase(st.find(j));
		}
		cout << (int)(st.size()) << '\n';
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
