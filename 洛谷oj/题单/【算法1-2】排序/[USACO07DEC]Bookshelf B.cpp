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
	sort(h+1,h+n+1,cmp);//����
	while(sum<b) {//�߶Ȼ�����
		num++;//����++
		sum += h[num];//��Ӷ�Ӧ��ţ�ĸ߶�
	}
	cout<<num<<endl;
	return 0;
}
