#include<iostream>//ac
#include<string>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 2e5 + 5;
int num[28],pos[28][MAXN];
//num�����Ӧ�ַ�����
//pos[i][j]��ʾΪ i �ַ��ĵ� j ����λ��
int main() {
	int n,k;
	int ans = INF;//��ʼ��Ϊ���޴�����С��
	string a;
	cin>>n>>k>>a;
	for(int i = 0;i < a.size();i++) {//�����ַ���a
		int tmp = a[i]-'a';
		num[tmp]++;//��ǰ�ַ�����++
		pos[tmp][num[tmp]] = i;//��¼λ��
		//tmp�ַ��ĵ�num[tmp]����λ��Ϊi
		if(num[tmp]>=k) {//�����ﵽ��׼ʱ
			int dis = i - pos[tmp][num[tmp]-k+1] + 1;
			//��ǰλ�� - ����k-1����λ�� + 1
			//disΪ����k��tmp�ַ��ĳ���
			ans = min(ans,dis);//������Сֵ
		}
	}
	cout<<(ans==INF?(-1):ans);
	return 0;
}
