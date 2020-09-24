#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
const int inf = 1e9;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, h;
	cin >> n >> h >> m;
	int a[n];
	rep(i, n) a[i] = inf;
	rep(i, m){
		int l, r, c;
		cin >> l >> r >> c;
		repn(j, l - 1, r){
			a[j] = min(a[j], c);
		}
	}
	rep(i, n) if(a[i] == inf) a[i] = h;
	int ans = 0;
	rep(i, n){
		ans += a[i] * a[i];
	}
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
