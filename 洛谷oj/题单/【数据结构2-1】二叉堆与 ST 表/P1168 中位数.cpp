#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;

//��⣺�Զ������k��Ҳ������λ��
//�ϰ벿��ΪС���ѣ���С��������
//�°벿��Ϊ����ѣ��Ӵ�С����
//�����ѵ�֮��Ĵ�С��ܳ���1
//��ѯ��ʱ����������ϴ�ĶѵĶѶ�����

priority_queue<int> down;//����� �°벿�֣��Ӵ�С
priority_queue<int, vector<int>, greater<int> > up;//С���� �ϰ벿�֣���С����
void Insert(int tmp) {
    //С����Ϊ�գ����ߵ�ǰֵ����С���ѵĶѶ��������С����
    if(up.empty()||tmp>up.top()) up.push(tmp);
    else down.push(tmp);//�����������
    //�����ѵĴ�С��Ҫ�����жϣ�������else������
    //������һ���ѵĶѶ����뵱ǰ����
    if(down.size()>up.size()+1) up.push(down.top()),down.pop();
    if(up.size()>down.size()+1) down.push(up.top()),up.pop();
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int tmp;
        cin>>tmp;
        Insert(tmp);//��Ӳ���
        if(i&1) {//��������Ҫ��ѯ
            //�����ϴ�Ķѣ�ȡ�Ѷ�
            cout<<(up.size()>down.size()?up.top():down.top())<<"\n";
        }
    }
    return 0;
}
