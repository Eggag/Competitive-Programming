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

#ifdef LOCAL
clock_t timer = clock();
#endif

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);
	int x, y;
	cin >> x >> y;
	int ans = 0;
	int by = 1;
	int dir = 1;
	while(true){
		if((dir == 1 && x <= y && y <= x + by) || (dir == -1 && x >= y && x - by <= y)){
			ans += abs(x - y);
			cout << ans << endl;
			break;
		}
		else{
			ans += by * 2;
			by *= 2;
			dir *= -1;
		}
	}
#ifdef LOCAL
        cout << "Total Time: " << (double)(clock() - timer) / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
