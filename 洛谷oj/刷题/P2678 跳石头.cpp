#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 5e4+10;
int len,n,m,a[MAXN];//len�������
bool check(int mid) {//�ж�mid�Ƿ����
	//posΪ��ǰλ�ã�nextΪ����Ŀ��λ��
	int pos = 0,next = 1,num = 0;//numΪ�ƶ���ʯͷ����
	//���Ҫ����n+1��ʯͷ��λ��(���һ��ʯͷ)
	while(pos<n+1) {//�����û�е������һ��ʯͷ
		while(a[next]-a[pos]<mid) {//�ж�
			if(next>n+1) return 0;//nextԽ��(��û����������)
			next++;//next������һ��������Ҫ����һ��ʯͷ
			num++;
			if(num>m) return 0;//�ƶ���ʯͷ��������
		}
		pos = next++;//��ǰλ�ø���Ϊnext,next�����
	}
	return 1;
}
int main() {
	cin>>len>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	a[n+1] = len;//��ʼ��Ϊ�㣬���һ��(n+1)Ϊlen
	int l = 1,r = len;
	while(l<=r) {//���ֲ���
		int mid = (l+r)/2;
		if(check(mid)) l = mid+1;//Ҳ���ڴ���ansά��
		else r = mid-1;
	}
	cout<<r<<endl;//rΪ���Ľ������Ϊl����
	//rҪô���䣬Ҫô����(����Ϊ������)
	return 0;
}
