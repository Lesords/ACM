#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//��⣺����ջ������ά���ϴ���ַ������������һ�����ֵĽ�С�ַ�
//��Ϊ������һ���Ļ���ɾ����֮����󲻻���������
//��ô����ջ��������м�Ϊ �������
//����д�������⣬��Ҫ��ԭ����ջ��ʼ��Ϊ�ϴ�ֵ����ֹ�޸ĵ�0λ�õ�ֵ

const int MAXN = 1e5+5;
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        //vis�жϵ�ǰ�ַ��Ƿ���ջ��
        //last����¼��ǰ�ַ����һ�γ��ֵ�λ��
        vector<int> vis(30,0),last(30,0);
        vector<char> ans(30,'z');//��ʼ��Ϊ�ϴ�ֵ����ֹ�޸ĵ�0λ�õ�ֵ������
        for(int i = 0;i < s.size();i++) {
            last[s[i]-'a'] = i;//��¼����λ��
        }
        int cnt = 0;//��ǰջ��λ��
        for(int i = 0;i < s.size();i++) {
            if(vis[s[i]-'a']) continue;//�Ѽ�¼����������
            //ջ�����ַ�С�ڵ�ǰ�ַ�������ջ�����ַ��ں��滹�г��֣�����
            while(ans[cnt]<s[i]&&last[ans[cnt]-'a']>i) {
                //����ջ���ַ�������������
                vis[ans[cnt--]-'a'] = 0;
            }
            ans[++cnt] = s[i];//��ջ
            vis[s[i]-'a'] = 1;//��ǵ�ǰ�ַ�
        }
        //1-cnt����Ϊ�������
        for(int i = 1;i <= cnt;i++) cout<<ans[i];
        cout<<"\n";
    }
	return 0;
}
