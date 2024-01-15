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

//��⣺���仯����������ÿ��״̬���Բ�������������
//ÿ��λ��Ҫô����ǰ����Ҫô���䣬��������-1�ķ�������
//����״̬�ĺͼ�Ϊ��ǰλ�ò��������������ܺͣ�������ʼ����������

const int MAXN = 1e3+5;
const int MOD = 1e9+7;
int dp[MAXN][MAXN][2],n,k;
//�ݹ�ᱬջ
int solve(int pos,int val,int dir) {
    //posΪλ�ã�valΪ˥�����ڣ�dirΪ����1Ϊ���ң�0Ϊ����
    if(val==1) {//����Ϊ1���޷�����˥����
        return 1;//����ֻ��һ��
    }
    if(dp[pos][val][dir]!=-1) {//��λ�õ�״̬�Ѿ�������ˣ�ֱ�ӷ���
        return dp[pos][val][dir];
    }
    int ans = 2;//��ʼ��Ϊ�������Լ�������
    if(dir==1) {//�����ƶ�
        if(pos<n) {//ǰ�滹�ܼ����ߵ�
            ans += solve(pos+1,val,dir) - 1;//�۳�һ�������
        }
        ans %= MOD;//ȡģ
        if(pos>1) {//��߿����ߵģ����Է����
            ans += solve(pos-1,val-1,1-dir) - 1;//�۳�һ�����Ƶ�
        }
        ans %= MOD;//ȡģ
        dp[pos][val][dir] = ans;//��¼��ǰ״̬�Ĵ�
    }
    else {//�����ƶ�
        if(pos>1) {//��߿��Լ����ƶ�
            ans += solve(pos-1,val,dir) - 1;//��۳�һ�������
        }
        ans %= MOD;//ȡģ
        if(pos<n) {//�ұ߿����ƶ����ɷ���
            ans += solve(pos+1,val-1,1-dir) - 1;//�۳�һ�����Ƶ�
        }
        ans %= MOD;//ȡģ
        dp[pos][val][dir] = ans;//��¼��ǰ״̬�Ĵ�
    }
    return ans;
}
int main() {
//  ����64λ��cf32λ

//	int size=126<<20;//256MB
//    char*p=(char*)malloc(size)+size;
//    __asm__ __volatile__("movq %0, %%rsp\n" :: "r"(p));//64bit

	int __size__ = 126<<20;
	char *__p__ = (char *)malloc(__size__)+__size__;
	__asm__("movl %0,%%esp\n"::"r"(__p__));//32bit

    int t;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        memset(dp,-1,sizeof(dp));//��ʼ��Ϊ-1
        cout<<solve(1,k,1)<<"\n";
    }
    exit(0);
	return 0;
}
