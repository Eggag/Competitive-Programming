#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
const int MAXN = 15000000;

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int p[(MAXN + 1)];
int v[(MAXN + 1)];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int a[n];
	rep(i, n) cin >> a[i];
	int g = a[0];
	repn(i, 1, n) g = gcd(g, a[i]);
	rep(i, n) a[i] /= g;
	memset(p, 0, sizeof(p));
	rep(i, n) p[a[i]]++;
	int mx = 0;
	memset(v, 0, sizeof(v));
	repn(i, 2, MAXN) if(!v[i]){
		int cnt = 0;
		for(int j = i; j <= MAXN; j += i) cnt += p[j], v[j] = 1;
		mx = max(mx, cnt);
	}
	if(!mx) cout << "-1" << endl;
	else cout << n - mx << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
