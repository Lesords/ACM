#include<iostream>//��ȡ�� ������볤�� 
#include<cstring>//�жϵ�ǰ�ַ�����Ƿ���������ǰ�� 
using namespace std;
const int maxn = 1e7+5;
char a[maxn];
int book[150];
int main() {
	int T;
	ios::sync_with_stdio(false);//���٣�1e7�� 
	while(cin>>T) {
		cin>>a;
		memset(book,-1,sizeof(book));//-1С�ڳ�ʼ���� 
		int len,st,tmp_st,tmp_len;
		len = st = tmp_st = tmp_len = 0;
		for(int i = 0;i < T;i++) {//a[i]�ַ���������ʱ���ǰ��
			if(book[a[i]] < tmp_st) tmp_len++;//��ʱ����++
			else {
				if(tmp_len > len) {
					len = tmp_len;
					st = tmp_st;
				}
				tmp_st = book[a[i]] + 1;//������ʱ��� 
				tmp_len = i - tmp_st + 1;//������ʱ���� 
			}
			book[a[i]] = i;//����a[i]�ַ����ֵ�λ�� 
		}
		if(tmp_len > len) {//���һ���ж� 
			len = tmp_len;
			st = tmp_st;
		} 
		cout<<len<<' '<<st<<' '<<len + st - 1<<endl;
	}
	return 0;
}
