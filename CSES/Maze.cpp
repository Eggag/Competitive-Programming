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
#define x1 qwertyuiop
#define y1 asdfghjkl
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[505][505][2];
int w, h;

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i <= h && j <= w);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> w >> h;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	swap(x1, y1);
	swap(x2, y2);
	vector<string> s(2 * h + 1);
	rep(i, 2 * h + 1) cin >> s[i];
	set<pair<int, pair<int, pi>>> q;
	rep(i, h + 1) rep(j, w + 1) dp[i][j][0] = dp[i][j][1] = 1e9;
	dp[x1][y1][0] = 0;
	dp[x1][y1][1] = 0;
	q.insert(mp(0, mp(0, mp(x1, y1))));
	q.insert(mp(0, mp(1, mp(x1, y1))));
	while(!q.empty()){
		pair<int, pair<int, pi>> cur2 = *q.begin();
		pair<int, pi> cur1 = cur2.se;
		int cur = cur1.fi;
		int x = cur1.se.fi, y = cur1.se.se;
		q.erase(q.begin());
		if(valid(x + 1, y) && ((cur && s[x * 2 + 1][2 * y] == 'b') || (!cur && s[x * 2 + 1][2 * y] == 'w'))){
			if(dp[x + 1][y][cur ^ 1] > (dp[x][y][cur] + 1)){
				q.erase(mp(dp[x + 1][y][cur ^ 1], mp(cur ^ 1, mp(x + 1, y))));
				dp[x + 1][y][cur ^ 1] = dp[x][y][cur] + 1;
				q.insert(mp(dp[x + 1][y][cur ^ 1], mp(cur ^ 1, mp(x + 1, y))));
			}
		}
		if(valid(x - 1, y) && ((cur && s[(x * 2) - 1][2 * y] == 'b') || (!cur && s[(x * 2) - 1][2 * y] == 'w'))){
			if(dp[x - 1][y][cur ^ 1] > (dp[x][y][cur] + 1)){
				q.erase(mp(dp[x - 1][y][cur ^ 1], mp(cur ^ 1, mp(x - 1, y))));
				dp[x - 1][y][cur ^ 1] = dp[x][y][cur] + 1;
				q.insert(mp(dp[x - 1][y][cur ^ 1], mp(cur ^ 1, mp(x - 1, y))));
			}
		}
		if(valid(x, y + 1) && ((cur && s[x * 2][y] == 'b') || (!cur && s[x * 2][y] == 'w'))){
			if(dp[x][y + 1][cur ^ 1] > (dp[x][y][cur] + 1)){
				q.erase(mp(dp[x][y + 1][cur ^ 1], mp(cur ^ 1, mp(x, y + 1))));
				dp[x][y + 1][cur ^ 1] = dp[x][y][cur] + 1;
				q.insert(mp(dp[x][y + 1][cur ^ 1], mp(cur ^ 1, mp(x, y + 1))));
			}
		}
		if(valid(x, y - 1) && ((cur && s[x * 2][y - 1] == 'b') || (!cur && s[x * 2][y - 1] == 'w'))){
			if(dp[x][y - 1][cur ^ 1] > (dp[x][y][cur] + 1)){
				q.erase(mp(dp[x][y - 1][cur ^ 1], mp(cur ^ 1, mp(x, y - 1))));
				dp[x][y - 1][cur ^ 1] = dp[x][y][cur] + 1;
				q.insert(mp(dp[x][y - 1][cur ^ 1], mp(cur ^ 1, mp(x, y - 1))));
			}
		}
		if(valid(x - 1, y + 1) && ((cur && s[(x * 2) - 1][(2 * y) + 1] == 'b') || (!cur && s[(x * 2) - 1][(2 * y) + 1] == 'w'))){
			if(dp[x - 1][y + 1][cur ^ 1] > (dp[x][y][cur] + 1)){
				q.erase(mp(dp[x - 1][y + 1][cur ^ 1], mp(cur ^ 1, mp(x - 1, y + 1))));
				dp[x - 1][y + 1][cur ^ 1] = dp[x][y][cur] + 1;
				q.insert(mp(dp[x - 1][y + 1][cur ^ 1], mp(cur ^ 1, mp(x - 1, y + 1))));
			}
		}
		if(valid(x + 1, y - 1) && ((cur && s[x * 2 + 1][(2 * y) - 1] == 'b') || (!cur && s[x * 2 + 1][(2 * y) - 1] == 'w'))){
			if(dp[x + 1][y - 1][cur ^ 1] > (dp[x][y][cur] + 1)){
				q.erase(mp(dp[x + 1][y - 1][cur ^ 1], mp(cur ^ 1, mp(x + 1, y - 1))));
				dp[x + 1][y - 1][cur ^ 1] = dp[x][y][cur] + 1;
				q.insert(mp(dp[x + 1][y - 1][cur ^ 1], mp(cur ^ 1, mp(x + 1, y - 1))));
			}
		}
	}
	cout << min(dp[x2][y2][0], dp[x2][y2][1]) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
