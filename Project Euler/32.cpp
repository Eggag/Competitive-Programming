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

bool check(int a, int b){
	string s = to_string(a);
	string s1 = to_string(b);
	string s2 = to_string((int)(a * b));
	vi cnt(10, 0);
	int tot = 0;
	rep(i, s.size()) cnt[s[i] - '0']++, tot++;
	rep(i, s1.size()) cnt[s1[i] - '0']++, tot++;
	rep(i, s2.size()) cnt[s2[i] - '0']++, tot++;
	repn(i, 1, 10) if(cnt[i] != 1) return 0;
	if(cnt[0]) return 0;
	assert(tot == 9);
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	set<int> st;
	repn(i, 1, 10001) repn(j, 1, 10001){
		if(check(i, j)) st.insert(i * j);
	}
	int ans = 0;
	for(int num : st) ans += num;
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
