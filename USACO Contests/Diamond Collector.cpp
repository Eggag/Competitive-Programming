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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int a[n];
	rep(i, n){
		cin >> a[i];
	}
	sort(a, a + n);
	int ans = 0;
	rep(i, n){
		int tmp = 1;
		repn(j, i + 1, n){
			if(a[j] - a[i] <= k){
				tmp++;
			}
			else break;
		}
		ans = max(ans, tmp);
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
