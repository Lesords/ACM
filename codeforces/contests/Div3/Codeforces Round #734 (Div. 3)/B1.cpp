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
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//��⣺����ͬһ����ɫ���ܳ�����ͬ�ַ�������ֻ��������ɫ
//��ôҲ����˵ÿ���ַ����ֻ��Ϳ����
//����Լ�¼�����ַ����ִ���
//ͳ��ֻ����1�εģ��ͳ��ִ���1�ε�
//���ִ���1�ε���Ҫ�ֿ�Ϳ��Ҳ����ֻͿ���Σ�����ɫ��
//����ֻ��1�εĿ���������ԣ���ɶ�Ӧ��ϣ�Ȼ��ֱ�Ϳ������ɫ

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int num[30];//��¼�����ַ����ֵĴ���
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        memset(num, 0, sizeof(num));//��ʼ��Ϊ0
        for(int i = 0;i < s.size();i++) {
            int id = s[i]-'a';
            num[id]++;//��¼�����ַ����ִ���
        }
        int one = 0,two = 0;//�ֱ�ͳ�Ƴ���һ�εģ��ͳ���һ�ε�����
        for(int i = 0;i <= 25;i++) {
            if(num[i]==1) one++;
            else if(num[i]>=2) two++;
        }
        //one��������ԣ���ֻ��һ�룬Ȼ���ټ���two��ֵ
        cout<<one/2+two<<"\n";
    }
    return 0;
}
