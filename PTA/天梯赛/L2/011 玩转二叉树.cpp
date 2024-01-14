#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 33;

//��⣺ֱ�����������������ǰ�����������ʱ�򽻻����Ҷ��ӵı��
//Ȼ������bfs����������

int a[MAXN], b[MAXN],tree[MAXN],l[MAXN],r[MAXN],cnt;
void solve(int rt,int left,int right,int L,int R) {
    //rtΪ��ǰ���ڵ㣬left��rightΪ��������ķ�Χ��L��RΪǰ������ķ�Χ
    tree[rt] = b[L];//���ڵ�
    int pos = 0;//��¼���ڵ��λ��
    for(int i = left;i <= right;i++) {//Ѱ�Ҹ��ڵ������������λ��
        if(a[i]==b[L]) {
            pos = i;break;
        }
    }
    int Lnum = pos-left;//����������������
    int Rnum = right-pos;//����������������
    if(pos>left) {//�����������
        ++cnt;
        r[rt] = cnt;//���������������
        solve(cnt,left,pos-1,L+1,L+Lnum);//�����ݹ�
    }
    if(pos<right) {//�����������
        ++cnt;
        l[rt] = cnt;//���������������
        solve(cnt,pos+1,right,R-Rnum+1,R);//�����ݹ�
    }
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++) cin>>b[i];
    cnt = 1;//��ʼ��
    solve(1,1,n,1,n);
    queue<int> q;
    int flag = 0;
    q.push(1);//��ʼ�����
    while(!q.empty()) {//bfs�����α���
        int now = q.front();
        q.pop();
        if(flag) cout<<" ";
        else flag = 1;
        cout<<tree[now];
        if(l[now]) q.push(l[now]);//����������
        if(r[now]) q.push(r[now]);//������Ҷ���
    }
    return 0;
}
