#include<iostream>//ac
using namespace std;
int main() {
	int n,m,black = 0,color = 0;
	char tmp;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j<= m; j++) {
			cin>>tmp;
			if(tmp=='W'||tmp=='B'||tmp=='G') black++;
			else color++;
		}
	}
	if(black&&!color) cout<<"#Black&White"<<endl;
	else cout<<"#Color"<<endl;
	return 0;
}
