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

char a[55][55];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	repn(i, 1, n + 1) repn(j, 1, n + 1) cin >> a[i][j];
	repn(i, 1, n + 1){
		repn(j, 1, n + 1){
			if(a[i][j] == '.' && a[i + 1][j + 1] == '.' && a[i + 1][j - 1] == '.' && a[i + 1][j] == '.' && a[i + 2][j] == '.'){
				a[i][j] = a[i + 1][j] = a[i + 1][j - 1] = a[i + 1][j + 1] = a[i + 2][j] = '#';
			}
		}
	}
	repn(i, 1, n + 1) repn(j, 1, n + 1){
		if(a[i][j] == '.'){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
