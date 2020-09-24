#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	for(int i = 1; i < 6; i++){
		for(int a = 1; a < 6; a++){
			int s;
			cin >> s;
			if(s == 1){
				cout << abs(3 - a) + abs(3 - i)<< endl;
				return 0;
			}
		}
	}
}
