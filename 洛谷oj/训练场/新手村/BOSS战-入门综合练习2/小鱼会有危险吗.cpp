#include<iostream>//ac
using namespace std;
int main() {
	double s,x,dis = 0,swim = 7;
	cin>>s>>x;
	double l = s - x;//左范围
	double r = s + x;//右范围
	int flag = 0;
	if(l<=0) {//起点就在范围内
		if(swim<=r) flag = 1;//游了之后还在范围内
	}
	else while(dis<=r) {
		dis += swim;
		swim *= 0.98;
		if(dis>=l&&dis<=r) {//到达范围时
			if(dis+swim<=r) flag = 1;//游不出去
			break;//判断完就直接退出
		}
	}
	if(flag) cout<<"y"<<endl;//有危险
	else cout<<"n"<<endl;
	return 0;
}
