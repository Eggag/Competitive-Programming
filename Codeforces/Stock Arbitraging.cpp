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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, r;
	cin >> n >> m >> r;
	int c = r;
	int a[n], b[m];
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	sort(a, a + n);
	int buy = r / a[0];
	r -= a[0] * buy;
	sort(b, b + m);
	reverse(b, b + m);
	cout << max(c, r + buy * b[0]) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
