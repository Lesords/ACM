#include<iostream>//ac
#include<algorithm>
using namespace std;

//���⣺��ʼ��a���յ�b���и�����c�����㸲�ǵķ�ΧΪr����û���Ĵ�С
//��⣺�ܹ�������������������ۼ���
//ȫ����������ĩ���ڣ���������Ұ�����������

int main() {
	int t,a,b,s,r;
	cin>>t;
	while(t--) {
		cin>>a>>b>>s>>r;
		int minn = min(a,b);
		int maxx = max(a,b);
		int s_l = s - r;
		int s_r = s + r;
		if(s_r>=maxx&&s_l<=minn) cout<<"0"<<endl;//ȫ����
		else if(minn<=s_l&&s_r<=maxx) //����ĩ����
			cout<<maxx-s_r+s_l-minn<<endl;
		else if(minn<=s_l&&s_l<=maxx) //�����
			cout<<s_l-minn<<endl;
		else if(minn<=s_r&&s_r<=maxx) //�Ұ���
			cout<<maxx-s_r<<endl;
		else cout<<maxx-minn<<endl;
	}
	return 0;
}
