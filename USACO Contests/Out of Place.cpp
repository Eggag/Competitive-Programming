#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	freopen("outofplace.in", "r", stdin);
        freopen("outofplace.out", "w", stdout);
	int n;
	cin >> n;
	int a[n];
	int b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	int g = 0;
	sort(b, b + n);
	for(int i = 0; i < n; i++){
		if(a[i] != b[i]){
			g++;
		}
	}
	cout << g - 1 << endl;
	return 0;
}
