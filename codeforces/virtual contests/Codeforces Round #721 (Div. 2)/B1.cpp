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

//��⣺ͳ��0�����������0������Ϊż������Ϊ1��ض���BOBӮ��������ALICEӮ
//����ż�������ʱ������ԭ�ַ���Ϊ���Ĵ�
//����ALICEѡ��һ��0֮��BOBѡ��0��Ӧ��λ�ã�����λ�ã�
//��ֻʣ�������0��ʱ�򣬵�ALICEѡ��һ��0֮��BOB����ֱ�ӷ�ת�ַ���
//ʹ��ALICE����ѡһ��0����ôBOB��Ӯ��
//��Ϊ���������ʱ��ALICE�޸����м��0
//��ô����ʣ���ż��0��˵��BOBΪ���֣�������ALICEӮ
//ע�⣺��Ҫ����0������Ϊ1�����

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        int zero = 0,n;
        cin>>n>>s;
        for(int i = 0;i < s.size();i++) {
            if(s[i]=='0') zero++;
        }
        if(zero%2==0||zero==1) {
            cout<<"BOB\n";
        }
        else cout<<"ALICE\n";
    }
	return 0;
}
