#include<iostream>//ac
#include<cstring>
#include<string>
using namespace std;

//��⣺���ж������ַ��Ƿ�����������Ȼ���ж��ַ��Ƿ���ֹ�
//�����ж��Ƿ��ǳ�ʼλ�û�ĩ��λ�ã���Ӧ�����ַ�
//���������м�λ���������ַ������㣬�����ַ�δ����

int vis[30];//��¼�ѳ��ֵ��ַ�
int main() {
	int t,flag,pos;
	string s,ans;
	cin>>t;
	while(t--) {
		memset(vis,0,sizeof(vis));//��ʼ��
		flag = 0,pos = 0;
		cin>>s;
		ans = s[0],vis[s[0]-'a'] = 1;//�ȱ����һ���ַ�
		for(int i = 1;i < s.size();i++) {
			//���ж������ַ��Ƿ����㣬ע��Խ��
			if(pos>0&&ans[pos-1]==s[i]) pos--;
			else if(pos+1<ans.size()&&ans[pos+1]==s[i]) pos++;
			else if(vis[s[i]-'a']) {//�ַ��ѳ��ֵ������Ա�
				flag = 1;break;//��ʱ�޷����ɶ�Ӧ����
			}//��ʼλ�ú�ĩ��λ�ÿ��Զ�Ӧ�����ַ�
			else if(!pos) ans = s[i]+ans,vis[s[i]-'a'] = 1;
			else if(pos+1==ans.size()) //ע���ƶ�pos������
				ans += s[i],vis[s[i]-'a'] = 1,pos++;
			else {//�����м��������ַ��������㣬���ַ�δ����
				flag = 1;break;
			}
		}
		for(char i = 'a';i <= 'z';i++) {//����ʣ���ַ�
			if(!vis[i-'a']) ans += i;
		}
		if(flag) cout<<"NO\n";
		else cout<<"YES\n"<<ans<<'\n';
	}
	return 0;
}
