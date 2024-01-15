#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
int a[10];
int main() {
	int n,ans_1=0,ans_2=0;
	ios::sync_with_stdio(false);
	cin>>n;
	char tmp;
	for(int i=1;i<=n;i++) {//数据是规律的，直接判断z n也可 
		cin>>tmp;
		if(tmp=='z') a[1]++;
		else if(tmp=='e') a[2]++;
		else if(tmp=='r') a[3]++;
		else if(tmp=='o') a[4]++;
		else if(tmp=='n') a[5]++;
	}
	ans_1 = min(a[5],min(a[4],a[2]));
	a[5] -= ans_1;
	a[4] -= ans_1;
	a[2] -= ans_1;
	ans_2 = min(min(a[1],a[2]),min(a[3],a[4]));
	for(int i=1;i<=ans_1;i++) {
		if(i!=1) cout<<' ';
		cout<<'1';
	}
	for(int i=1;i<=ans_2;i++) {
		if(ans_1||!ans_1&&i!=1) cout<<' ';
		cout<<'0'; 
	}
	return 0;
}
