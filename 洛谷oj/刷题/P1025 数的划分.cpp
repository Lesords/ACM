#include<iostream>//ac
#include<algorithm>
using namespace std;
int a[10] = {1},ans,n,k;
void dfs(int step,int rest) {//stepΪ����ɵ�������restΪʣ��ֵ
	if(step==k) {//����k��
		if(rest==0) ans++;//ȫ��������
		return;
	}
	//��һ�������Ϊ step+1
	//ʣ�� step+1 -> k ���� k-step ��
	//�ж�ʣ����Ƿ���Թ��� k-step �����ڵ���ǰһ������ֵ
	if(rest/(k-step)<a[step]) return;
	//�� ǰһ������ֵΪ���
	//�� �ж�ʣ���ֵ�Ƿ���Թ��� k-step ���� Ϊ����
	for(int i = a[step];i*(k-step) <= rest;i++) {
		a[step+1] = i;//��¼ step+1 λ�õ�ֵ
		dfs(step+1,rest-i);//����λ�ú�ʣ��ֵ�����ݹ�
	}
}
int main() {
	cin>>n>>k;
	dfs(0,n);
	cout<<ans;
	return 0;
}
