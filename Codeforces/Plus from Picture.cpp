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

char g[505][505];
int v[505][505];

void no(){
	cout << "NO" << endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int h, w;
	cin >> h >> w;
	rep(i, 505) rep(j, 505) g[i][j] = 'q', v[i][j] = 0;
	rep(i, h) rep(j, w){
		cin >> g[i][j];
	}
	int plus = 0;
	rep(i, h) rep(j, w){
		if(g[i][j] == '*'){
			if(g[i + 1][j] == '*' && g[i - 1][j] == '*' && g[i][j + 1] == '*' && g[i][j - 1] == '*'){
				if(plus) no();
				int a = i, b = j;
				while(g[a][b] != '.' && a < h){
					v[a][b] = 1;
					a++;
				}
				a = i, b = j;
				while(a >= 0 && g[a][b] != '.'){
					v[a][b] = 1;
					a--;
				}
				a = i, b = j;
				while(g[a][b] != '.' && b < w){
					v[a][b] = 1;
					b++;
				}
				a = i, b = j;
				while(b >= 0 && g[a][b] != '.'){
					v[a][b] = 1;
					b--;
				}
				plus = 1;
			}
		}
	}
	rep(i, h) rep(j, w) if(!v[i][j] && g[i][j] == '*') no();
	if(plus) cout << "YES" << endl;
	else no();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
