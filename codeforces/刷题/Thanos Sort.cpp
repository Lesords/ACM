#include<iostream>//ac
#include<algorithm>
using namespace std;
int a[20],ans = 1;//��ʼ��Ϊ1���϶�����һ����
void binal_search(int l,int r) {//���ֲ���
	if(l>=r) return;//��������
	int mid = (l+r)/2;
	int tmp = 1;
	for(int i = l;i < r;i++) {//�����Ƿ��������
		if(a[i]<=a[i+1]) tmp++;
		else {tmp = 1;break;}//��һ�������϶�����
	}
	ans = max(ans,tmp);//�����������
	if(tmp!=1) return;//�ҵ������ֱ�ӷ��أ������ݹ�ֵ��С��
	binal_search(l,mid);//��ݹ�
	binal_search(mid+1,r);//�ҵݹ�
}
int main() {
	int n;cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	binal_search(1,n);//���ֲ����ж�
	cout<<ans<<endl;
	return 0;
}
