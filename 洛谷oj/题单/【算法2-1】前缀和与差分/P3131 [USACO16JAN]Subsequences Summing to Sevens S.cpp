#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 5e4+10;
int pre[MAXN],last[10];

//ע�������������%7==0,��ô��������%7������һ����ͬ
//�� ������%7������ͬ�����֮��%7==0 ������
//����ֻ��Ҫ�Ҷ�Ӧ������ǰ��������ֵ����

int main() {
	int n,tmp,ans = 0;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>tmp;
		pre[i] = (pre[i-1]+tmp)%7;
		//����%7��ǰ׺��
	}
	for(int i = 1;i <= n;i++) {//��ǰ����������λ��
		last[pre[i]] = i;//Ѱ��pre[i]���������λ��
	}
	for(int i = 1;i <= n;i++) {//����ֱ����ans
		//�ж� ��ǰ������������λ�� - i ��ans�Ĵ�С
		ans = max(ans,last[pre[i]]-i);//pre[i]������
	}
	cout<<ans;
	return 0;
}
