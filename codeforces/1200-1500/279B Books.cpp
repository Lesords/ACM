#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺��Ԥ����ǰ׺�ͣ����ű�����˵㣬Ȼ������Ҷ˵�
//ȡ�����������������䳤�ȼ�Ϊ��

const int MAXN = 1e5+5;
int a[MAXN], sum[MAXN];
int main() {
    int n,t;
    cin>>n>>t;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int i = 1;i <= n;i++) sum[i] = sum[i-1]+a[i];//ǰ׺��
    int ans = 0;//ǰ׺��Ԥ�����ɿ��ټ��������ڵ���������ʱ��
    for(int i = 1;i <= n;i++) {
        int l = i, r = n;//���ܻ����1��������������Ϊi
        while(l<=r) {
            int mid = (l+r)>>1;
            //i-mid�����ڵ�ʱ��С��t����l+�����ƣ�������r-�����ƣ�
            if(sum[mid]-sum[i-1]<=t) ans = max(ans,mid-i+1), l = mid+1;
            else r = mid-1;//ans������ֵ
        }
    }
    cout<<ans<<"\n";
    return 0;
}
