#include<iostream>//ac
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;

//��⣺̰��
//��¼��ǰ�����Ѿ�ѡ�˵ļ��ϣ������ܺ�
//ÿ�ζ�����ǰ��ֵѡ��ȥ��Ȼ���жϼ��ϵ��ܺ��Ƿ�С��0
//��С��0�Ļ����򽫼�������С����������ֱ�����ϵĺͲ�С��0
//��󼯺ϵ�������Ϊ��
//�������ȶ�������¼�����е���Сֵ������

const int MAXN = 2e5+5;
int a[MAXN];
int main() {
    int n;
    cin>>n;
    ll sum = 0;//���ϵ��ܺ�
    priority_queue<int, vector<int>, greater<int> > q;//��С����
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        q.push(a[i]);//����ǰ�������뼯����
        sum += a[i];//�ۼӺ�
        while(sum<0) {//����С��0
            sum -= q.top();//ɾ����Ӧ����Сֵ
            q.pop();//������ֵ
        }
    }
    cout<<q.size();//����������Ϊ���
    return 0;
}
