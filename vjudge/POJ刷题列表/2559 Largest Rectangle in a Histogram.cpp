#include<iostream>//ac
#include<algorithm>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
using namespace std;

//��⣺����ջ
//����ջ��¼�߶ȴ�С����ĵ�
//����ǰ��߶ȴ���ջ��ʱ��ֱ����ջ
//���򵯳�ջ���ĵ�
//ÿ�ε���ջ����ʱ��˳������Ӧ��ľ��δ�С
//Ȼ���ۼӺ�Ŀ�Ⱥϲ�����ǰ��Ŀ�ȣ�����

const int MAXN = 1e5+5;
ll a[MAXN],w[MAXN],que[MAXN];//a��¼��Ӧ��ĸ߶ȣ�w��¼��Ӧ��Ŀ��
//queΪ����ջ��¼��Ӧ��x����
int main() {
    fast;
    int n;
    while(cin>>n&&n) {
        int top = 0;
        ll ans = 0;
        for(int i = 1;i <= n;i++) cin>>a[i];
        a[n+1] = 0;//�����һ���㣬���ڼ���ǰ�����е㣨��ֹջ��Ϊ�գ�
        for(int i = 1;i <= n+1;i++) {
            //��ǰ����ջ����ֱ����ջ������¼��Ӧ��ȼ���
            if(a[i]>a[que[top]]) que[++top] = i,w[i] = 1;
            else {
                int width = 0;//��ǰ������С���ۼƿ��
                //�����ǰ��С��ջ�����򵯳����������Ӧ���δ�С
                while(a[i]<a[que[top]]) {
                    int now = que[top--];//��¼ջ���ĵ㣬������
                    width += w[now];//�ۼƿ��
                    ans = max(ans, width*a[now]);//����ջ���ĵ��Ӧ�ľ��δ�С
                }
                w[i] = width+1;//ǰ�����е����ĵ�Ŀ�ȣ��ۼƵ���ǰλ��
                que[++top] = i;//��ջ
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
