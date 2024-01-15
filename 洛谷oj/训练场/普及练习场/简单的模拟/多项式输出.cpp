#include<iostream>//ac
#include<cmath>
using namespace std;
int main() {
	int n,tmp,sign;
	cin>>n;
	for(int i = n;i >= 0;i--) {//总共n+1个数据
		cin>>tmp;
		if(!tmp) continue;//0跳过 
		sign = (tmp>=0)?1:0;//1为+，0为-
		tmp = abs(tmp);
		if(!sign) cout<<'-';//负号无限制
		else if(i!=n) cout<<'+';//第一项无需正号
		if(tmp>1) cout<<tmp;
		else if(!i) cout<<tmp;//常数项才输出1
		if(i) {//非常数项
			if(i>1) cout<<"x^"<<i;
			else cout<<'x';//最小项
		}
	}
	cout<<endl;
	return 0;
}
