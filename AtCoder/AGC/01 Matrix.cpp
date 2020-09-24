#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
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

char ans[1005][1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	pi good;
	int f = 1;
	rep(i, h + 1){
		int tot = a * i + (w - a) * (h - i);
		rep(j, w + 1){
			int tot1 = b * j + (h - b) * (w - j);
			if(tot1 == tot){
				good = mp(i, j);
				f = 0;
				break;
			}
		}
		if(!f) break;
	}
	//now we have the numbers, we just need to make the board
	//so start with rows
	vi need(w, 0);
	rep(i, w){
		if(i < good.se) need[i] = b;
		else need[i] = h - b;
	}
	rep(i, h){
		//we are currently on the i-th row
		int cnt = a; //keep track of how many we can use
		if(i >= good.fi) cnt = w - a; //flip it
		rep(j, w){
			if(cnt && need[j]) ans[i][j] = '1', need[j]--, cnt--;
			else ans[i][j] = '0';
		}
	}
	rep(i, h){
		rep(j, w) cout << ans[i][j];
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
