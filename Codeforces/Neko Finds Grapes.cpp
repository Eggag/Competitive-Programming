#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	int aodd = 0;
	int aeven = 0;
	rep(i, n){
		if(a[i] % 2 != 0) aodd++;
	}
	aeven = n - aodd;
	int bodd = 0;
	int beven = 0;
	rep(i, m){
		if(b[i] % 2 != 0) bodd++;
	}
	beven = m - bodd;
	cout << min(aeven, bodd) + min(aodd, beven) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
