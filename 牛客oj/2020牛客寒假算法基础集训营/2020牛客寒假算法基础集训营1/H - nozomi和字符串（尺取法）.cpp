#include<iostream>//ac
#include<algorithm>
#include<string>
using namespace std;
int vis[2];//��� 0 �� 1 ������
int main() {
	int n,k;
	string a;
	cin>>n>>k>>a;
	int num = 0,ans = 0;//��ʼ��Ϊ0
	//iΪ�����䣬jΪ������
	for(int i = 0,j = 0;j < a.size();j++) {//jΪ��ǰ�ƶ���ָ��
		vis[a[j]-'0']++;//��ǵ�ǰ���ַ�
		num = max(vis[1],vis[0]);//�����ַ����϶������
		while(j-i+1-num>k) {//��Ҫ��������������kʱ�ƶ�i
			vis[a[i++]-'0']--;
		}//ɾ����ָ��ָ����ַ��ı�ǣ�������i
		ans = max(ans,j-i+1);//���������
	}
	cout<<ans<<endl;
	return 0;
}
