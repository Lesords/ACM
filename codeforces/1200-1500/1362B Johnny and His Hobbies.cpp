#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//��⣺�������ݷ�Χֻ��1024������ֱ�ӱ���ƥ�� [1,1024)��Χ���Ƿ���ֵ���㼴��

const int MAXN = 1030;
int a[MAXN],vis[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,ans = -1;//��ʼ��ansΪ-1
        cin>>n;
        memset(vis, 0, sizeof(vis));//����
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            vis[a[i]]++;//��ǳ��ֵ�����
        }
        for(int i = 1;i < 1024;i++) {//������1024������
            int sum = 0;//ͳ�Ƴ��ֵ���������
            for(int j = 1;j <= n;j++) {//�������е���
                if(vis[a[j]^i]) sum++;
                //���Ľ��Ψһ�������жϼ���Ľ���Ƿ���ּ���
            }
            if(sum==n) {//��n����ʾ�ҵ����
                ans = i;break;
            }
        }
        if(ans!=-1) cout<<ans<<"\n";//��Ϊ-1���ҵ����
        else cout<<ans<<"\n";
    }
    return 0;
}
