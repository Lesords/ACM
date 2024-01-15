#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 2e4 + 5;
int h[MAXN];
bool cmp(int a,int b) { return a>b; }
int main() {
	int n,b,num = 0,sum = 0;
	cin>>n>>b;
	for(int i = 1;i <= n;i++) cin>>h[i];
	sort(h+1,h+n+1,cmp);//升序
	while(sum<b) {//高度还不够
		num++;//数量++
		sum += h[num];//添加对应的牛的高度
	}
	cout<<num<<endl;
	return 0;
}
