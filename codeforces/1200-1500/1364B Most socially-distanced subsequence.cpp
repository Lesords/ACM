#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//��⣺������Ϊһ�Σ���������Ϊ����������м�ĵ��ʡ�ԣ������յ㲻ʡ�ԣ�

const int MAXN = 1e5+5;
int p[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> ans;
        for(int i = 1;i <= n;i++) cin>>p[i];
        for(int i = 1;i <= n;i++) {
            //���β�Ϊ���򣬻�Ϊ�����յ㣬����ӵ�ans��
            if(i==1||i==n||p[i-1]<p[i]!=p[i]<p[i+1]) ans.push_back(p[i]);
        }
        cout<<ans.size()<<"\n";
        for(int i = 0;i < ans.size();i++) {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
