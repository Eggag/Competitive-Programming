#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	int lucky[12] = {4, 7, 47, 74, 444, 447, 474, 477, 744, 747, 774, 777};
	for(int i = 0; i < 12; i++){
		if(n % lucky[i] == 0){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
