#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
char s[10][10];
int n,m,ans,vis[10];
void dfs(int now,int num) {//nowΪ��ǰ�У�numΪ��ǰ�Ѱڷŵ�����
    if(now>n+1) return;//n+1�в�Ϊ�����㣡����
    if(num==m) {//��������
        ans++;return;
    }
    for(int i = 1;i <= n;i++) {//������ǰ�е�������
        if(vis[i]||s[now][i]=='.') continue;//��ǰ���ѷŹ�����Ϊ��
        vis[i] = 1;//���
        dfs(now+1,num+1);
        vis[i] = 0;//����ȡ�����
    }
    dfs(now+1,num);//��ǰ�����������򣬿�ֱ���Ƶ���һ��
}
int main() {
    while(cin>>n>>m) {
        if(n==-1&&m==-1) break;
        for(int i = 1;i <= n;i++) cin>>s[i]+1;
        memset(vis,0,sizeof(vis));//��ʼ��
        ans = 0;//��ʼ��Ϊ0
        dfs(1,0);
        cout<<ans<<'\n';
    }
    return 0;
}
