#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;

//��⣻�����е�ţ���ճԲݵ�˳���С��������
//Ȼ����һ�����ȶ��У�ά�� �����ı�ź��������ţ�����Բݵ�ʱ��
//���� �����Բݵ�ʱ�� ��С��������
//Ȼ����������������ţ���ж��ڶѶ����Ƿ��ܹ����㵱ǰţ�Բ�
//���ܣ����½�һ�������������޸ĶѶ���������Ϣ
//���ж�������ά��ÿͷţ�����������
//ע�⣺�����Բݵ�ʱ��Ҳ�ڳԲݣ���һ����ʼ��ʱ�䲻�ܵ��ڽ����Բݵ�ʱ��

const int MAXN = 5e4+5;
struct node{
    int id,x,y;
    friend bool operator < (node a,node b) {
        if(a.x!=b.x) return a.x < b.x;//�Ȱ��ճԲ�ʱ�����򣨴�С���󣡣���
        return a.y < b.y;
    }
}a[MAXN];
struct stall{
    int id, time;
    friend bool operator < (stall a,stall b) {
        return a.time > b.time;//���ȶ��У�����ʱ��С��
    }
};
int pos[MAXN];//��¼ÿͷţ�����������
int main() {
    ios::sync_with_stdio(0);//���٣������ٻ�tle������
    cin.tie(0),cout.tie(0);
    int n,cnt = 0;//cntΪ��ǰ��������
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].x>>a[i].y;
        a[i].id = i;//ţ�ı��
    }
    sort(a+1,a+1+n);//����
    priority_queue<stall> q;
    for(int i = 1;i <= n;i++) {
        if(q.empty()) {//�����ȶ���Ϊ�գ���ֱ�ӽ��µ�����
            stall tmp = {++cnt,a[i].y};
            pos[a[i].id] = cnt;//��¼��ǰţ��������λ��
            q.push(tmp);
        }
        else {
            stall last = q.top();//ȡ�Ѷ�������
            if(a[i].x>last.time) {//���ܰ���������
                //�������������������������Ϣ
                q.pop();//�����ɵ�������Ϣ
                last.time = a[i].y;//�޸Ľ���ʱ��
                pos[a[i].id] = last.id;//��¼��ǰţ��������λ��
                q.push(last);
            }
            else {
                stall tmp = {++cnt,a[i].y};//�����������������µ�����
                pos[a[i].id] = cnt;//��¼��ǰţ��������λ��
                q.push(tmp);
            }
        }
    }
    cout<<cnt<<"\n";//��������
    for(int i = 1;i <= n;i++) {//���ÿ��ţ����������Ϣ
        cout<<pos[i];
        if(i!=n) cout<<"\n";
    }
    return 0;
}
