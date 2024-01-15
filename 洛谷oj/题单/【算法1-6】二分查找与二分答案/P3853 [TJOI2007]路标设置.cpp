#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e7+5;
bool mark[MAXN];//bool��ʱ�̣�������¼�Ѿ�����·���λ��
int len,n,k,tmp;
bool check(int mid) {//mid����С���տ�ָ����ֵ
    int last = 0,num = 0;//last����һ��·���λ�ã�numΪ���õ�·������
    for(int i = 1;i < len;i++) {//��һ�������һ������·�꣬����
        if(mark[i]) last = i;//�ѷ��ù���
        else if(i-last==mid) last = i,num++;//�������mid������·��
    }
    return num <= k;//���õ�·���Ƿ�С����ĿҪ��
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>len>>n>>k;
    for(int i = 1;i <= n;i++) cin>>tmp,mark[tmp]++;
    int l = 0,r = len,ans;
    while(l<=r) {//����
        int mid = (l+r)/2;
        if(check(mid)) ans = mid,r = mid-1;//����ȡС
        else l = mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
