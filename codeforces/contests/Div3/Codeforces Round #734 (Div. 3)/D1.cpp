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

//��⣺���ڴ�ֱ�ڷź�ˮƽ�ڷ����������������
//���Կ��Լ���ˮƽ�ڷŵ�������Χ����
//�������Ϊ��������ô������һ�еú���ڷţ�m/2����
//�������Ϊ��������ô������һ����Ҫ��ֱ�ڷţ�n/2��������Ӧˮƽ����Ϊ n*m/2 -(n/2) ��
//��Ϊ���˴�ֱ�ڷţ�ʣ�඼��ˮƽ�ڷţ�����

//�۳�һ�еİڷ�������ʣ��Ĵ�ֱ�ڷ�����һ��ҪΪ2�ı���
//������Ӧ�ĸ߶Ȳ��ܴ�ֱ�ڷ�


const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n,m,k;
        cin>>n>>m>>k;
        int min_h = n%2?m/2:0;//���ٵ�ˮƽ�ڷ�����
        int max_h = n*m/2 - (m%2?n/2:0);//����ˮƽ�ڷ�����
        //ˮƽ������Ҫ�ڷ�Χ�ڣ�����ʣ��������Ϊ2�ı���������
        if(min_h<=k&&k<=max_h&&(k-min_h)%2==0) {
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}
