#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+5;
int pre[MAXN],suf[MAXN],a[MAXN];
//pre[i]����1-iΪ��β�� k�� ƽ̨���Էŵĵ㣬ȡ���ֵ
//suf[i]����i-nΪ���� k�� ƽ̨���Էŵĵ㣬ȡ���ֵ
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k,tmp;
        cin>>n>>k;
        for(int i = 1;i <= n;i++) cin>>a[i];
        sort(a+1,a+1+n);//��������
        for(int i = 1;i <= n;i++) cin>>tmp;//y�������ã�����
        int pos = 1;//��ʼ��Ϊ1
        for(int i = 1;i <= n;i++) {//��ǰ�����ж�ǰ׺��ֵ
            while(a[i]-a[pos]>k) pos++;//���ܳ���k��
            pre[i] = i-pos+1;//posΪ��㣬iΪ�ҵ�
            if(i>1) pre[i] = max(pre[i],pre[i-1]);//��Ϊ��ʼ��
        }
        pos = n;
        for(int i = n;i >= 1;i--) {//�Ӻ�ǰ�жϺ�׺��ֵ
            while(a[pos]-a[i]>k) pos--;//���ܳ���k��
            suf[i] = pos-i+1;//posΪ�ҵ㣬iΪ���
            if(i<n) suf[i] = max(suf[i],suf[i+1]);//��Ϊ�յ�
        }
        int ans = 0;//��ʼ�����Ϊ0
        //�������е㣬���� ǰk+��k ����ֵ����һ���ʼ��pre��suf����
        for(int i = 1;i <= n;i++) ans = max(ans,pre[i]+suf[i+1]),pre[i]=suf[i]=0;
        cout<<ans<<endl;
    }
	return 0;
}
