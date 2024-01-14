#include<iostream>//ac
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 5e5+6;

//��⣺������Χ��Ȼ���ж��Ƿ��������������ù鲢����˼��������������

int n,m,last;
ll a[MAXN],b[MAXN],c[MAXN],k;//k��longlong���ͣ�����
void Merge(int l,int mid,int r) {//�ϲ�����[l,mid] [mid+1,r]
    int i = l,j = mid+1;
    for(int k = l;k <= r;k++) {
        if(j>r||(i<=mid&&b[i]<=b[j])) c[k] = b[i++];
        else c[k] = b[j++];
    }
}
ll solve(int l,int r) {//����l-r��������У��ֵ
    if(r>n) r = n;//���ֻ�ܵ�n
    int siz = min(m,(r-l+1)>>1);//�������ȡ���ٶԣ����ܳ���Ҫ��m
    for(int i = last+1;i <= r;i++) b[i] = a[i];//������Ĳ���
    sort(b+last+1,b+r+1);//������Ĳ�������
    Merge(l,last,r);//Ȼ������ϲ�
    ll ans = 0;//����У��ֵ
    for(int i = 0;i < siz;i++) {//c����Ϊ�ϲ���Ľ��������
        ans += (c[r-i]-c[l+i])*(c[r-i]-c[l+i]);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>m>>k;
        for(int i = 1;i <= n;i++) cin>>a[i];
        int l = 1,r = 0,cnt = 0;//lΪ��ǰ����㣬rΪ��һ���ε��յ㣬cntΪ����
        last = 0;//��ʼΪ��
        while(l<=n) {
            int p = 1;
            while(p) {//������ֱ��pΪ0
                ll num = solve(l, r+p);//���� [l,r+p] �����У��ֵ
                if(num<=k) {
                    last = r = min(n,r+p);//����lastΪr��ֵ
                    if(r==n) break;//��������յ㣬�����
                    for(int i = l;i <= r;i++) b[i] = c[i];//�������飨���������飩
                    p <<= 1;
                }
                else p >>= 1;
            }
            cnt++;
            l = r+1;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
