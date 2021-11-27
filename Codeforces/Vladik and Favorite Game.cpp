#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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
const int mxN = 105;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const char dz[4] = {'D', 'U', 'R', 'L'};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
pi ff = mp(1, 1), ff1 = mp(1, 1);
char s[mxN][mxN];
pair<pi, char> pr[mxN][mxN];
int vis[mxN][mxN];

bool valid(int x, int y){
	return x >= 1 && y >= 1 && x <= n && y <= m;
}

pi ask(char d){
	cout << d << endl;
	int x, y;
	cin >> x >> y;
	if(x == -1) exit(0);
	if(x == ff1.fi && y == ff1.se) exit(0);
	return mp(x, y);
}

int main(){
	cin >> n >> m;
	repn(i, 1, n + 1) repn(j, 1, m + 1){
		cin >> s[i][j];
		if(s[i][j] == 'F') ff = mp(i, j), ff1 = ff;
	}
	pi pos = mp(1, 1);
	int swapLR = 0, swapUD = 0;
	if(n == 1){
		pos = ask('R');
		if(pos.se == 1) swapLR = 1;
		else pos = ask('L');
		while(s[pos.fi][pos.se] != 'F'){
			if(swapLR) pos = ask('L');
			else pos = ask('R');
		}
		return 0;
	}
	if(m == 1){
		pos = ask('D');
		if(pos.fi == 1) swapUD = 1;
		else pos = ask('U');
		while(s[pos.fi][pos.se] != 'F'){
			if(swapUD) pos = ask('U');
			else pos = ask('D');
		}
		return 0;
	}
	if(valid(1, 2) && (s[1][2] == '.' || s[1][2] == 'F')){
		pos = ask('R');
		if(pos.se == 1) swapLR = 1;
		else pos = ask('L');
		while(s[2][pos.se] != '.' && s[2][pos.se] != 'F'){
			if(swapLR) pos = ask('L');
			else pos = ask('R');
		}
		pos = ask('D');
		if(pos.fi == 1) swapUD = 1;
	}
	else if(valid(2, 1) && (s[2][1] == '.' || s[2][1] == 'F')){
		pos = ask('D');
		if(pos.fi == 1) swapUD = 1;
		else pos = ask('U');
		while(s[pos.fi][2] != '.' && s[pos.fi][2] != 'F'){
			if(swapUD) pos = ask('U');
			else pos = ask('D');
		}
		pos = ask('R');
		if(pos.se == 1) swapLR = 1;
	}
	else assert(0);
	queue<pi> q;
	q.push(pos);
	pr[pos.fi][pos.se] = mp(mp(0, 0), '.');
	vis[pos.fi][pos.se] = 1;
	while(!q.empty()){
		pi nw = q.front();
		q.pop();
		rep(i, 4){
			int x = nw.fi + dx[i], y = nw.se + dy[i];
			if(valid(x, y) && !vis[x][y] && s[x][y] != '*'){
				pr[x][y] = mp(nw, dz[i]);
				vis[x][y] = 1;
				q.push(mp(x, y));
			}
		}
	}
	string res = "";
	while(pr[ff.fi][ff.se].se != '.'){
		res += pr[ff.fi][ff.se].se;
		ff = pr[ff.fi][ff.se].fi;
	}
	reverse(all(res));
	rep(i, res.size()){
		if(swapLR){
			if(res[i] == 'L') res[i] = 'R';
			else if(res[i] == 'R') res[i] = 'L';
		}
		if(swapUD){
			if(res[i] == 'U') res[i] = 'D';
			else if(res[i] == 'D') res[i] = 'U';
		}
		pos = ask(res[i]);
	}
	assert(pos == ff1);
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
