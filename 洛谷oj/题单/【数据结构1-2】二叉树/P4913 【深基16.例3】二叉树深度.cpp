#include<iostream>//ac
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

//��⣺vector��ͼ��Ȼ����bfs������ȼ���

const int MAXN = 1e6+5;
struct node{
    int dot,dep;
    friend bool operator < (node a,node b) {
        if(a.dep!=b.dep) return a.dep > b.dep;//�������С��
        return a.dot > b.dot;
    }
};
vector<int> g[MAXN];                    //��ͼ
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int a,b;
        cin>>a>>b;
        g[i].push_back(a);              //����
        g[i].push_back(b);
    }
    int rt = 1,dep = 0;                 //���״̬
    priority_queue<node> q;
    q.push({rt,0});                     //��������
    while(!q.empty()) {
        node tmp = q.top();
        q.pop();
        for(int i = 0;i < g[tmp.dot].size();i++) {//��������ָ���
            int now = g[tmp.dot][i];
            dep = max(dep,tmp.dep+1);   //�������
            q.push({now,tmp.dep+1});    //�ӽڵ����
        }
    }
    cout<<dep;
    return 0;
}
