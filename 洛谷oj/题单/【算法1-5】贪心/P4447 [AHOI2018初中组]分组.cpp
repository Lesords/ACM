#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺̰��+����
//���Ƚ����ж�Ա����ʵ��ֵ��С��������
//Ȼ������������ѡ������ʵ��飬���û�ҵ������½�һ����
//���ö����������飬����ж���鶼������������Խ�����Խ�ţ������������С���ܸ�С

const int MAXN = 1e5+5;
int a[MAXN],q[MAXN],siz[MAXN];//q��¼ ���� ��ǰ���ʵ��ֵ��siz��¼��ǰ��Ĵ�С
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+1+n);//��С��������
    int top = 0;
    for(int i = 1;i <= n;i++) {
        int pos = lower_bound(q+1,q+top+1,a[i])-q;//Ѱ�ҵ�һ������������λ��
        while(pos+1<=top&&q[pos+1]==a[i]) pos++;//�����������Ҳ���㣬��ѡ�������
        if(q[pos]==a[i]) siz[pos]++,q[pos]++;//��ǰ����������������������Ϣ��q���1��Ҫ����
        else q[++top] = a[i]+1,siz[top] = 1;//�½�һ����
        //��һ����Ҫ��ֵ��Ϊ��ǰֵ+1������
    }
    int ans = INF;
    for(int i = 1;i <= top;i++) {//ȡ��С���ȼ�Ϊ���
        ans = min(ans, siz[i]);
    }
    cout<<ans;
    return 0;
}
