#include<iostream>//ac
#include<string>
#include<algorithm>
#define ll long long
using namespace std;//���ݷ�Χ�е��

//��⣺��Ŀֻ��Ҫ���һ��ֵΪtrue���ɣ�����

ll dp[100];//dp[i]��ʾiλ��Ϊtrue������
int main() {
    int n;
    cin>>n;
    dp[0] = 1;//��ʼλ��ֻ��һ����ֻ�ܶ�Ӧ��ֵ��
    for(int i = 1;i <= n;i++) {
        string tmp;
        cin>>tmp;
        if(tmp=="AND") {//��Ϊand����ǰ����һ������Ϊtrue
            dp[i] = dp[i-1];
        }
        else dp[i] = dp[i-1]+(1ll<<i);
        //����ֻ��Ҫ���һ��Ϊtrue������OR������
        //��ǰλ��Ϊtrue�Ļ�����ǰ�� 0-(n-1) ��ֵ����Ϊ����ֵ
        //��ǰλ��Ϊfalse�Ļ�������һ������Ϊtrue
    }
    cout<<dp[n];
    return 0;
}
