#include<iostream>//ac
using namespace std;
int main() {
	double s,x,dis = 0,swim = 7;
	cin>>s>>x;
	double l = s - x;//��Χ
	double r = s + x;//�ҷ�Χ
	int flag = 0;
	if(l<=0) {//�����ڷ�Χ��
		if(swim<=r) flag = 1;//����֮���ڷ�Χ��
	}
	else while(dis<=r) {
		dis += swim;
		swim *= 0.98;
		if(dis>=l&&dis<=r) {//���ﷶΧʱ
			if(dis+swim<=r) flag = 1;//�β���ȥ
			break;//�ж����ֱ���˳�
		}
	}
	if(flag) cout<<"y"<<endl;//��Σ��
	else cout<<"n"<<endl;
	return 0;
}
