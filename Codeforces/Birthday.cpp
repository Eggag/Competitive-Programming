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
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	vi a1;
	vi a2;
	for(int i = 0; i < n; i++){
		if(i % 2 == 0) a2.pb(a[i]);
		if(i % 2 != 0) a1.pb(a[i]);
	}
	for(int i = 0; i < a1.size(); i++){
		cout << a1[i] << " ";
	}
	reverse(all(a2));
	for(int i = 0; i < a2.size(); i++){
		cout << a2[i];
		if(i != a2.size() - 1) cout << " ";
	}
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
