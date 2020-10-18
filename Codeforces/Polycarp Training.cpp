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

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	//looks like we should pick the smallest that satisfies
	rep(i, n){
		int cur = i + 1; //num of prob
		int pos = lb(all(a), cur) - a.begin();
		if(pos == a.size()){
			cout << i << endl;
			return 0;
		}
		a.erase(a.begin() + pos);
	}
	cout << n << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/