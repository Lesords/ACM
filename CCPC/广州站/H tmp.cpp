#include<iostream>//±©Á¦
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
#define ll long long
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAXN = 2e5+5;
const int MOD = 998244353;
const int N = 100;
int main() {
	int a, b, c;
	while(cin >> a>> b>>c) {
		for(int i = 1;i <= N;i++) {
			for(int j = 1;j <= N;j++) {
				for(int k = 1;k <= N ;k++) {
					int val1 = i%j;
					int val2 = j%k;
					int val3 = k%i;
					
					/*
					if(a>=b&& a>=c) {
						if(i!=a) continue;
					}
					if(b>=a&&b>=c) {
						if(j!=b) continue;
					}
					if(c>=a&&c>=b) {
						if(k!=c) continue;
					}
					
					*/
					if(val1==a&&val2==b&&val3==c) {
						cout << i << " "<< j << " " << k << "\n";
					}
				}
			}
		}
		cout <<"------------\n";
	}

	return 0;
}
