#include<iostream>//ac
#include<algorithm> 
using namespace std;
int a[1005],b[1005];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	int n;
	while(cin>>n&&n) {
		for(int i = 1;i <= n;i++) cin>>a[i];
		for(int i = 1;i <= n;i++) cin>>b[i];
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		int win = 0,tj,kin,tn,kn;
		tj = kin = 1;
		tn = kn = n;
		while(tj<=tn&&kin<=kn) {
			if(a[tj]>b[kin]) win++,tj++,kin++;
			//�ﾶ������������Ŀ죬���˺���++
			else if(a[tj]<b[kin]) win--,tn--,kin++;
			//�ﾶ������������������ﾶ�Ļ���������
			else {//�ٶ�һ���죬���ж���������
				if(a[tn]>b[kn]) win++,tn--,kn--;
				//�ﾶ������죬����ȥ������
				else if(a[tn]<b[kn]) win--,tn--,kin++;
				//�ﾶ������������������������
				else {
				//һ����Ļ��������ﾶ��������������ĺ����
					if(a[tn]<b[kin]) win--;//�ﾶ���ͼ�
					//�ﾶ�����������������
					tn--,kin++;//����������
				}
			}
		}
		cout<<win*200<<endl;
	}
	return 0;
}
