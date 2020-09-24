#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

char g[15][15];
int tx, ty, sx, sy, rx, ry;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("buckets.in", "r", stdin);
	freopen("buckets.out", "w", stdout);
	rep(i, 10){
		rep(j, 10){
			cin >> g[i][j];
			if(g[i][j] == 'B') tx = i, ty = j;
			if(g[i][j] == 'L') sx = i, sy = j;
			if(g[i][j] == 'R') rx = i, ry = j;
		}
	}	
	int ans = abs(tx - sx) + abs(ty - sy) - 1;
	if(((sx == tx && sx == rx) && ((ry < ty && ry > sy) || (ry < ty && ry > sy))) || ((sy == ty && sy == ry) && ((rx < tx && rx > sx) || (rx < tx && rx > sx)))){
                ans += 2;
        }
	cout << ans << endl;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
