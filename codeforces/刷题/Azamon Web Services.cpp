#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//����:���������ַ���a,b���ж�a���ڽ����ַ����Ƿ����С��b��
//���:��ǰ�ַ�����ɨ��Ѱ��һ���Ͽ����ֵС�ַ���Ȼ�󽻻�

string a,b;
int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>a>>b;
		int len = a.size() - 1;
		for(int i = 0;i <= len;i++) {
			int equal = i;
			for(int j = i + 1;j <= len;j++) {//�������ҵ�������ַ�
				if(a[j] <= a[equal]&&a[j] != a[i]) {
					equal = j;
				}
			}
			/*Ҳ��ֱ�ӴӺ��濪ʼ����
			for(int j = len;j > i;j--) {
				if(a[j] < a[equal]) {
					equal = j;
				}
			}
			*/
			if(equal != i) {//���ھͽ���
				swap(a[i],a[equal]);
				break;
			}
		}
		if(a<b) cout<<a<<endl;
		else cout<<"---"<<endl;
	}
	return 0;
}
