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

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

char g[55][55];
char b[4] = {'B', 'A', 'C', 'D'};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int a[4];
	cin >> a[0] >> a[1] >> a[2] >> a[3] ;
	rep(i, 4) a[i]--;
	rep(i, 4){
		char cur = b[i];
		repn(j, (i * 12), ((i + 1) * 12)) rep(k, 50){
			g[j][k] = cur;
		}
	}
	rep(i, 4){
		char cur = ('A' + (3 - i));
		for(int j = i * 12 + 1; j < ((i + 1) * 12); j += 2) rep(k, 50){
			if(!a[3 - i]) break;
			if((j + k) & 1) a[3 - i]--, g[j][k] = cur;
		}
	}
	cout << "48 50" << endl;
	rep(i, 48){
		rep(j, 50) cout << g[i][j];
		cout << endl;
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
