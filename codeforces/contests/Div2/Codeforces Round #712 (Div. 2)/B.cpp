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
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 3e5+5;

//��⣺����ִ��һ��ǰ׺ת�������������ڵ�0��1����������ȵ�
//���Կ�������ǰ׺������¼1��0������
//Ȼ��Ӻ���ǰ��ʼ�жϣ�ÿ�β����Ļ���Ӧ�Ĳ�����++
//��ôǰ���ֵ��Ϊ (a[i]+op)%2 (��0��1������ģ2)

int n, one[MAXN], zero[MAXN];//one��zero��¼��Ӧ1��0��ǰ׺��
string s,ed;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>s>>ed;
        if(s==ed) {//�Ѿ���ͬ����ֱ�����YES
            cout<<"YES\n";
            continue;
        }
        for(int i = 0;i < n;i++) one[i] = zero[i] = 0;//��ʼ��Ϊ0
        for(int i = 0;i < n;i++) {//��¼��Ӧ��ǰ׺��
            if(s[i]=='0') zero[i] = zero[i-1]+1,one[i] = one[i-1];
            else one[i] = one[i-1]+1, zero[i] = zero[i-1];
        }
        int cnt_op = 0,flag = 0;//cnt_oΪ��������flag�ж��Ƿ��޽�
        for(int i = n-1;i >= 0;i--) {
            int a = s[i]-'0';
            int b = ed[i]-'0';//�ַ�תΪ����
            a = (a+cnt_op)%2;//a��Ӧȡֵ��b���䣨��aת��b������b���䣩
            if(a!=b) {//����ȣ���ִ�в���
                if(zero[i]==one[i]) {//ǰ׺����������ȿ�ִ�в���
                    cnt_op++;
                }
                else {//�����޽�
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
	return 0;
}
