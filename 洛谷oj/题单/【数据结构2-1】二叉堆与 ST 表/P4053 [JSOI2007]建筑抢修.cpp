#include<iostream>//ac
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;

//��⣺����ֱ��̰�ģ���Ҫ��¼��ʷ����ʱ�䣡����
//�����ݰ����޶�ʱ���С��������
//Ȼ���ж�ÿ��������ǰʱ��+����ʱ���Ƿ��㹻����С���޶�ʱ��
//�����㣬��ֱ�Ӹ��»���ʱ��ʹ𰸣���������ʱ����������
//�������㣬������ʷ����ʱ���У�Ѱ��һ���ȵ�ǰ����ʱ���ģ����У����뵱ǰʱ���滻
//Ҳ����˵������ǰ�����㣬��iλ�ò����㣬��ôǰi��ֻ��i-1�����޸�
//��ô���ǿ��Խ�i-1���޸���ʱ�価����С������
//����ǰ��i-1���޶�ʱ�䶼�ȵ�ǰʱ��С��Ҳ����˵��ǰ�涼�������������Ҵ�����ʷ����ʱ����ڵ�ǰ����ʱ��
//��ô�滻�ɵ�ǰ����ʱ��϶��������i���޶�ʱ��
//����ѧ�Ƕ�˼�������£�
//sum[i-1] < T[i-1] < T[i] , max(a[1...(i-1)]) > a[i]
//sum[i-1] - max(a[1...(i-1)]) + a[i] < T[i-1] < T[i]
//sumΪǰ׺�ͣ�TΪ�޶�ʱ�䣬aΪ����ʱ��

const int MAXN = 15e4+5;
struct node{
    ll cost,time;
    friend bool operator < (node a,node b) {
        return a.time < b.time;//ʱ���С��������
    }
}a[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].cost>>a[i].time;
    }
    sort(a+1,a+1+n);//����
    priority_queue<int>q;
    int ans = 0;
    ll nowt = 0;//��ǰ���ѵ���ʱ��
    for(int i = 1;i <= n;i++) {
        if(nowt+a[i].cost<a[i].time) {//��������
            ans++;
            nowt += a[i].cost;//����ʱ��
            q.push(a[i].cost);//��¼��ʷʱ��
        }
        else {
            int tmp = q.top();
            if(tmp>a[i].cost) {//��������ʷ����ʱ��ȵ�ǰ����ʱ���
                nowt -= tmp;//ɾ���ϴ�ֵ
                nowt += a[i].cost;//�����Сֵ
                q.pop();//���ڲ���Ҫpop������
                q.push(a[i].cost);//�滻�ɵ�ǰ����ʱ��
            }
        }
    }
    cout<<ans;
    return 0;
}
