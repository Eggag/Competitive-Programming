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

#ifdef LOCAL
clock_t t = clock();
#endif

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if(m % n != 0){
		cout << "-1" << endl;
		return 0;
	}
	if(m == n){
		cout << "0" << endl;
		return 0;
	}
	int a = m / n;
	int ans = 0;
	while(a % 2 == 0){
		ans++;
		a /= 2;
	}
	while(a % 3 == 0){
		ans++;
		a /= 3;
	}
	if(a != 1){
		cout << "-1" << endl;
		return 0;
	}
	cout << ans << endl;
#ifdef LOCAL
        cout << "Total Time: " << (double)(clock() - t) / CLOCKS_PER_SEC << endl;
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
