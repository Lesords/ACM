#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;

//��⣺����ֱ����̰�ķ����
//����ƥ��������ǲ�ֵС�ڵ���1
//���Կ��Խ�������Ů������Ӧ��С��������
//ÿ������ѡ����С��Ů��
//���Ӧ���������Ķ�����Ϊ���

int a[105],b[105],vis[105];
int main() {
    int n,m,ans = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    cin>>m;
    for(int i = 1;i <= m;i++) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);//����
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {//Ѱ�Ҷ�Ӧ��Ů��
            if(vis[j]) continue;//�����ѱ�ǵģ�����ӵģ�
            if(abs(a[i]-b[j])<=1) {//��������
                ans++;
                vis[j] = 1;//���
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
