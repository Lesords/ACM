#include<iostream>//ac
#include<cstdio>
using namespace std;
double a[70][10];
int main() {
	int n;
	double sum = 0,ans = 0;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= 8;j++) cin>>a[i][j];
		if(a[i][1]==0||a[i][1]==1) {//Ϊ��ѡ����ѡʱ
			sum+=a[i][2];//��ѧ��
			a[i][9] = a[i][3]*a[i][4]+a[i][5]*a[i][6]+a[i][7]*a[i][8];
			double tmp = a[i][9];//��������
			if(tmp - (int)a[i][9]>=0.5) a[i][9] = (int)tmp+1;
			else a[i][9] = (int)tmp;//��Ҫ������
		}
	}
	//cout<<sum<<endl;
	for(int i = 1;i <= n;i++) {
		if(a[i][1]==0||a[i][1]==1) {//Ϊ��ѡ����ѡʱ
			//cout<<a[i][9]<<' '<<a[i][2]<<endl;
			//cout<<a[i][9]*a[i][2]/sum<<endl;
			ans += a[i][9]*a[i][2]/sum;//a[i][9]Ϊ���Ƴɼ�
		}
	}
	printf("%.2f\n",ans);
	return 0;
}
