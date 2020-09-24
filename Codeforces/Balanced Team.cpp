#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int a[n + 1];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}	
	sort(a, a + n);
	a[n] = 2e9;
	int ans = 0;
	int r = 0;
	for(int i = 0; i < n; i++){
		while(a[r] <= a[i] + 5) r++;
		ans = max(ans, r - i);
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
