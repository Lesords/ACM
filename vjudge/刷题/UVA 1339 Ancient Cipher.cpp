#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
char a[105],b[105];
int book_a[30],book_b[30];
int main() {
	while(cin>>a>>b) {
		int len = strlen(a);
		memset(book_a,0,sizeof(book_a));
		memset(book_b,0,sizeof(book_b));
		for(int i = 0;i < len;i++) {
			book_a[a[i]-'A']++;//��¼a������ÿ���ַ����ֵĴ���
			book_b[b[i]-'A']++;//��¼b������ÿ���ַ����ֵĴ���
		}
		sort(book_a,book_a+26);
		sort(book_b,book_b+26);
		int flag = 0;
		//��ab�����������ĳ���ַ����ֵĴ�����һ��
		//�����ͨ��ӳ�䣬ʹ�������ַ������
		for(int i = 0;i < 26;i++) {
			if(book_a[i]!=book_b[i]) {
				flag = 1;
				break;
			}
		}
		flag?cout<<"NO"<<endl:cout<<"YES"<<endl;
	}
	return 0;
}
