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

int p[105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for(int i = a; i < b; i++){
		p[i] = 1;
	}
	for(int i = c; i < d; i++){
		p[i] = 1;
	}
	int ans = 0;
	for(int i = 0; i < 105; i++){
		if(p[i]) ans++;
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
