#include<iostream>//ac
using namespace std;

//��⣺sqrt(i) + sqrt(j) = sqrt(k)
// => i + j + 2 * sqrt(i*j) = k
// => i * j �� n ����Ϊ��ȫƽ��������Ϊ����

// ���� i*j <= n������Ա��� 1 ~ n �����е���ȫƽ����
//ͳ����Щ��ȫƽ����������������

int main() {
	int n,ans = 0;
	cin>>n;
	for(int i = 1;i*i<=n;i++) {//�������е���ȫƽ����
		int k = i*i;//��¼Ϊ��ǰ����ȫƽ����
		for(int j = 1;j*j <= k;j++) {//������һ��������
			if(k%j==0) {//��ͬ����ֻ��һ����Ԫ��
				ans += (j==k/j)?1:2;
			}//��ͬ���ӣ�����λ�ú�����������Ԫ��
		}
	}
	cout<<ans<<endl;
	return 0;
}
