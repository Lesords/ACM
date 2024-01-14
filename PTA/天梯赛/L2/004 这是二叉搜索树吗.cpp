#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//��⣺����ԭ�������������ԣ����������н��С�����������н��󣨰������ڣ�
//���ھ�����ԣ����������н��󣨰������ڣ������������н��С
//���Կ������ж��Ƿ�����ԭ������������Ȼ�����ж��Ƿ����㾵�����������
//����ÿ�ε��ж϶��ԣ�����whileѰ���������յ����������㣬���ߵĲ�ֵΪ1�ų����������޽�

const int MAXN = 1e3+5;
int n,a[MAXN],isMirror;
vector<int> ans;
void solve(int root,int tail) {
    int i = root+1,j = tail;
    if(isMirror) {//�����С
        while(i<=tail&&a[i]>=a[root]) i++;
        while(j>root&&a[j]<a[root]) j--;
    }
    else {//��С�Ҵ�
        while(i<=tail&&a[i]<a[root]) i++;
        while(j>root&&a[j]>=a[root]) j--;
    }
    if(i-j!=1) return;
    solve(root+1,j);
    solve(i,tail);
    ans.push_back(a[root]);
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    solve(1,n);
    if(ans.size()!=n) {
        ans.clear();
        isMirror = true;
        solve(1,n);
    }
    if(ans.size()!=n)  cout<<"NO\n";
    else {
        cout<<"YES\n";
        for(int i =  0;i < (int)ans.size();i++) {
            if(i!=0) cout<<" ";
            cout<<ans[i];
        }
    }
    return 0;
}
