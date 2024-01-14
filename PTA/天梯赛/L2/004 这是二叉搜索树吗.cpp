#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//题解：对于原二叉搜索树而言，左子树所有结点小，右子树所有结点大（包括等于）
//对于镜像而言，左子树所有结点大（包括等于），右子树所有结点小
//所以可以先判断是否满足原二叉搜索树，然后再判断是否满足镜像二叉搜索树
//对于每次的判断而言，可以while寻找左子树终点和右子树起点，两者的差值为1才成立，否则无解

const int MAXN = 1e3+5;
int n,a[MAXN],isMirror;
vector<int> ans;
void solve(int root,int tail) {
    int i = root+1,j = tail;
    if(isMirror) {//左大右小
        while(i<=tail&&a[i]>=a[root]) i++;
        while(j>root&&a[j]<a[root]) j--;
    }
    else {//左小右大
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
