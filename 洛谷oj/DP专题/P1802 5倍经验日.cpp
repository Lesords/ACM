#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e3+5;
int dp[MAXN],win[MAXN],lose[MAXN],use[MAXN];
//dp[i]:����i��ҩ����õľ���
int main() {
    int n,x;
    cin>>n>>x;
    for(int i = 1;i <= n;i++)
        cin>>lose[i]>>win[i]>>use[i];
    for(int i = 1;i <= n;i++) {//��������ҩ
        for(int j = x;j >= use[i];j--) {//����Ӯ�����
            dp[j] = max(dp[j-use[i]]+win[i],dp[j]+lose[i]);
            //Ӯ����use[i],�䲻����
        }
        //�϶�������
        for(int j = use[i]-1;j >= 0;j--) dp[j] += lose[i];
    }
    cout<<dp[x]*5LL<<endl;//longlong������
    return 0;
}
