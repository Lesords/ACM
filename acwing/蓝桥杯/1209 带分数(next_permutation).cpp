#include<iostream>//ac
#include<algorithm>
using namespace std;
int a[10],ans,n;
int get_val(int left,int right) {//����ָ����Χ�ڵ�ֵ
	int ans = 0;
	for(int i = left;i <= right;i++) ans = ans*10+a[i];
	return ans;
}
int main() {
	cin>>n;
	for(int i = 1;i <= 9;i++) a[i] = i;//next_permutation�����򣬹ʳ�ʼ������
	do {
		int flag = 0;
		for(int i = 1;i <= 7;i++) {//��һ����
			for(int j = i+1;j <= 8;j++) {//�ڶ�����
				int A = get_val(1,i);
				int B = get_val(i+1,j);
				int C = get_val(j+1,9);//������������ֵ
				if(n*C==A*C+B) {//�ж��Ƿ���������
					flag = 1;ans++;break;
				}
			}
			if(flag) break;//��������������
		}
	} while(next_permutation(a+1,a+10));//������һ������
	cout<<ans<<endl;
	return 0;
}
