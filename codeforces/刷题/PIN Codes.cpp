#include<iostream>//ac
#include<set>
//�ⷨ1�����������ַ���������޸ģ��ж��Ƿ����غϣ����ݶ��ʱ��
//�ⷨ2���������ֻ��10���ַ����������ַ�����һ��λ�ñ���0~9����
using namespace std;
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		set<string> s;
		cin>>n;
		string a[12];
		for(int i = 1;i <= n;i++) {
			cin>>a[i];
			s.insert(a[i]);
		}
		int ans = 0;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j < i;j++) {//�����ַ����ж��Ƿ���һ�µ�
				if(a[i]==a[j]) {
					ans++;//��С������ÿ���ַ���ֻ��һ���ַ�
					string tmp = a[i];//tmp������ʱ�޸�
					int flag = 0;
					for(int k = 0;k < tmp.size()&&!flag;k++) {
						for(char c = '0';c <= '9';c++) {
							char t = tmp[k];//�����ʼ�ַ�
							tmp[k] = c;
							if(!s.count(tmp)) {//�޸ĳɹ�
								flag = 1;
								a[i] = tmp;//����ԭ�ַ�����
								s.insert(tmp);//�����ڲ������ַ���
								break;
							}
							tmp[k] = t;//�޸�ʧ���軹ԭ
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		for(int i = 1;i <= n;i++)
			cout<<a[i]<<endl;
	}
	return 0;
}
