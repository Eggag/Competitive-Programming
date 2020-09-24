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

int ptime[50005][10];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> m >> n;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> ptime[i][j];
		}
	}
	vi ftime(m);
	for(int i = 0; i < n; i++){
		int free = 0;
		for(int j = 0; j < m; j++){
			int start = max(free, ftime[j]);
			ftime[j] = start + ptime[j][i];
			free = ftime[j];
		}
	}
	for(int x : ftime){
		cout << x << " ";
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
