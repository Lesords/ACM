#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 5e3+5;
int main() {
    int n;
    while(cin>>n&&n) {
        int tmp,ans = 0;
        priority_queue<int,vector<int>,greater<int> > q;
        for(int i = 1;i <= n;i++) {
            cin>>tmp;
            q.push(tmp);
        }
        while(!q.empty()) {//���ȶ���
            int t1 = q.top();q.pop();
            int t2 = q.top();q.pop();
            ans += t1+t2;//ÿ��ȡ������Сֵ���
            if(!q.empty()) q.push(t1+t2);//�����л���ֵ�������
        }
        cout<<ans<<"\n";
    }
    return 0;
}
