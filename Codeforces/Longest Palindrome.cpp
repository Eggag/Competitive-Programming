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

bool palindrome(string n){
	string n1 = n;
	reverse(all(n1));
	return (n == n1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	map<string, int> cnt;
	rep(i, n) cin >> s[i], cnt[s[i]] = 1;
	//find 'opposites' of each other?
	//all the same size, makes it easy
	map<string, int> vis;
	string l = "", r = "";
	rep(i, n) if(!vis[s[i]]){
		string op = s[i];
		reverse(all(op));
		if(op != s[i] && cnt[op]){
			vis[s[i]] = 1;
			vis[op] = 1;
			l += s[i];
			reverse(all(r));
			r += s[i];
			reverse(all(r));
		}
	}
	//put smth in the center
	rep(i, n) if(!vis[s[i]]){
		if(palindrome(s[i])){
			l += s[i];
			break;
		}
	}
	//reverse(all(r));
	cout << (int)(l.size() + r.size()) << endl;
	cout << l << r << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
