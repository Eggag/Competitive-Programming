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
	int max;
	freopen("hps.in", "r", stdin);
        freopen("hps.out", "w", stdout);
	int n;
	cin >> n;
	vector<pi> games;
	int m[4][4];
	for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
			m[i][j] = 0;
                }
        }
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		m[a][b]++;
	}
	int max1 = m[1][2] + m[2][3] + m[3][1];
	if((m[1][3] + m[3][2] + m[2][1]) > max1){
		max1 = m[1][3] + m[3][2] + m[2][1];
	}
	cout << max1 << endl;
	return 0;
}
