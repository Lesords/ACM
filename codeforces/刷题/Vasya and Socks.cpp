#include<iostream>//ac
using namespace std;
int main() {
	int n,m,cnt = 0;
	cin>>n>>m;
	while(n--) {//袜子数量--
		cnt++;
		if(!(cnt%m)) n++;//到达指定时间，袜子++
	}
	cout<<cnt<<endl;
	return 0;
} 
