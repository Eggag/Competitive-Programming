#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define pf push_front
#define f first
#define s second

bool a[2005][2005];

int X, Y, L, R, N, M;

struct node{
	int y, x, l, r;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	cin >> N >> M >> Y >> X >> L >> R;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			char r;
			cin >> r;
			if(r == '*'){
				a[i][j] = 1;
			}
		}
	}
	deque<node> q;
	int ans = 0;
	q.pb(node{Y, X, 0, 0});
	while(!q.empty()){
		node t = q.front();
		q.pop_front();
		if(a[t.y][t.x] || t.x < 1 || t.y < 1 || t.x > M || t.y > N || t.l > L || t.r > R){
			continue;
		}
		a[t.y][t.x] = 1;
		ans++;
		q.pf(node{t.y + 1, t.x, t.l, t.r});
		q.pf(node{t.y - 1, t.x, t.l, t.r});
		q.pb(node{t.y, t.x - 1, t.l + 1, t.r});
		q.pb(node{t.y, t.x + 1, t.l, t.r + 1});
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
