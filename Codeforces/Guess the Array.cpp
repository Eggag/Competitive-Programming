#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	//find the first 3 with 3
	//then just proceed normally
	cout << "? 1 2" << endl;
	int a;
	cin >> a;
	cout << "? 2 3" << endl;
	int b;
	cin >> b;
	cout << "? 1 3" << endl;
	int c;
	cin >> c;
	vi ans(n);
	if(a > b){
		int diff = a - b;
		ans[2] = (c - diff) / 2;
		ans[0] = c - ans[2];
	}
	else{
		int diff = b - a;
		ans[0] = (c - diff) / 2;
		ans[2] = c - ans[0];
	}
	ans[1] = a - ans[0];
	repn(i, 3, n){
		cout << "? " << i << " " << i + 1 << endl;
		int d;
		cin >> d;
		ans[i] = d - ans[i - 1];
	}
	cout << "! ";
	rep(i, n) cout << ans[i] << " ";
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
