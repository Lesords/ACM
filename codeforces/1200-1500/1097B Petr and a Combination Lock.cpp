#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺dfs���ɣ�����Ϊ�ӻ��������Ϊ%360��ֵΪ0

int n,a[20],flag;
void dfs(int pos,int val) {
    if(pos==n) {
        //%360Ϊ0����
        if(val%360==0) flag = 1;//����һ�ֿ����Լ���
        return ;
    }
    dfs(pos+1, val+a[pos+1]);
    dfs(pos+1, val-a[pos+1]);
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    dfs(0,0);//dfs
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
