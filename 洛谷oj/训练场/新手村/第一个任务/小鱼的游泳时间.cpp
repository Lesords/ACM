#include<iostream>//ac
using namespace std;
int main() {
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int minu = c*60+d - (a*60 + b);//统一转成 分钟 计算
	cout<<minu/60<<' '<<minu%60<<endl;
	return 0;
}
