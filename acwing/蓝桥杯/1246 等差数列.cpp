#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e6+5;
int a[MAXN];
int gcd(int a,int b) {//�������Լ��
	return b?gcd(b,a%b):a;//����д��������a��bΪ0�������
}
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+1+n);//����
	int step = a[2]-a[1];//��һ������
	for(int i = 3;i <= n;i++) {
		step = gcd(step,a[i]-a[i-1]);//ȡ��ֵ֮������Լ��
	}
	if(step==0) {//Ϊ0��ʾȫһ�£���Ϊ�Ȳ�����
		cout<<n<<endl;
		return 0;
	}
	cout<<(a[n]-a[1])/step+1;//�ܲ�ֵ/����+1 Ϊ��������
	return 0;
}
