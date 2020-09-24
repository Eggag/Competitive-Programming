#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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

bool cmp(array<int, 4> a, array<int, 4> b){
	return a[0] < b[0];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<array<int, 4>> p(n);
	rep(i, n) cin >> p[i][0] >> p[i][1] >> p[i][2] >> p[i][3];
	sort(all(p), cmp);
	repn(i, 1, n){
		if(max(p[i - 1][1], p[i - 1][3]) > max(p[i][1], p[i][3])){
			cout << p[i - 1][0] << " " << min(p[i - 1][1], p[i - 1][3]) << " ";
			cout << p[i][0] << " " << max(p[i][1], p[i][3]) << endl;
		}
		else{
			cout << p[i - 1][0] << " " << max(p[i - 1][1], p[i - 1][3]) << " ";
			cout << p[i][0] << " " << min(p[i][1], p[i][3]) << endl;
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
