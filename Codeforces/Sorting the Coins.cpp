#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi p(n);
	rep(i, n) cin >> p[i], p[i]--;
	vi vis(n, 0); //to track what we put in
	cout << 1 << " "; //it is always 1 for the 1st one
	int prev = n;
	int last = 0;
	rep(i, n){
		//we put it in and check from it onwards???
		//1 is the min
		vis[p[i]] = 1;
		int suf = 0;
		suf = last;
		if(prev <= 0){
			cout << 1 << " ";
			continue;
		}
		//now check if that changed
		if(p[i] == prev - 1){
			int next = prev - 1;
			while(next >= 0 && vis[next]) suf++, prev--, next--;
		}
		last = suf;
		int ans = i + 1; //the cur without the suffix
		cout << (ans - suf) + 1 << " ";
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
