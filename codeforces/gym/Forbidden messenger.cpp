#include<iostream>//ac
#include<cmath>//c++14������cmath��c++11Ҳ��(algorithm)
using namespace std;
int main() {
	double x,a,b;//a��д��ʱ�䣬b�Ƿ���ʱ��
	int ans = 0;//��ʼ�����Ϊ0
	cin>>x>>a>>b;
	double minute = x*60;//������
	if(minute>=a+b) {//ʱ�乻�����������Ϊ0
		ans++,minute -= a+b;//��һ����Ϣ
		ans += floor(minute/(a<b?b:a));
	}
	//�������ʱ���д��������ڵ�һ�η���ʱ����д�ڶ���Ϣ
	//���Եڶ��μ��Ժ�ֻ��Ҫ�жϷ���ʱ�䣨b������
	
	//���д��ʱ��ȷ���ʱ�䳤(����ʱ��Ҳд)
	//��ڶ��� д�ͷ� ��ʱ��Ϊ a+b - b(�۳���һ�η���ʱ��)
	//���Եڶ��μ��Ժ�ֻ��Ҫ�ж�д��ʱ�䣨a������
	cout<<ans;
	return 0;
}
