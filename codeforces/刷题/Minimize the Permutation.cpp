#include<iostream>//ac
#include<algorithm>
using namespace std;

//���⣺��n-1������֮��ÿ��λ��ֻ�ܲ���һ�Σ�������ֵ�����С������
//��⣺ȷ��һ����ַpos������Ѱ�� δȷ������ �ڵ���С����
//�����ƶ��� δȷ������ ������ˣ�����pos����С���ִ����������˶��Ѳ�������
//�����С����Ϊ��ǰλ����pos++

int a[105];
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i = 1;i <= n;i++) cin>>a[i];
		int pos = 1;
		while(pos <= n) {
			int in = min_element(a+pos,a+n+1) - a;//��Сֵ�±�
			if(pos == in) {//��Сλ��Ϊ��ǰλ��
				pos++;continue;
			}
			int t = a[in];//��ʱ�洢��Сֵ
			for(int i = in;i >= pos + 1;i--) a[i] = a[i-1];//������������
			a[pos] = t;//��������ֵ
			pos = in;//����λ�ã���ǰλ�û��ɲ�����
		}
		for(int i = 1;i <= n;i++)
			cout<<a[i]<<' ';
		cout<<endl;
	}
	return 0;
}
