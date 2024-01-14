#include<iostream>//ac
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
    int val,step;
    friend bool operator < (node a,node b) {
        return a.step > b.step;//�����ٵ�����
    }
};
int n,m,val[5];//val��¼��ǰ��������λ�õ�ֵ
bool check(int val) {//�ж�val�Ƿ�Ϊ����
    for(int i = 2;i*i <= val;i++) {
        if(val%i==0) return 1;
    }
    return 0;
}
int main() {
    set<int> prime;
    for(int i = 1000;i <= 9999;i++) {//��ɸ��λ������������
        if(check(i)) continue;
        prime.insert(i);
    }
    int t;cin>>t;
    while(t--) {
        cin>>n>>m;
        set<int> vis;//vis�жϵ�ǰ���Ƿ�����
        priority_queue<node> q;
        node tmp;
        tmp = {n,0};//��ʼ���
        q.push(tmp);
        int flag = 0;
        while(!q.empty()) {
            tmp = q.top();q.pop();
            if(vis.count(tmp.val)) continue;//�����Ѿ�������
            else vis.insert(tmp.val);//������
            if(tmp.val==m) {//��������ʱ
                cout<<tmp.step<<"\n";
                flag = 1;break;
            }
            int ttt = tmp.val,pos = 1;
            while(ttt) {
                val[pos++] = ttt%10;
                ttt /= 10;
            }//val�������λ���ϵ�ֵ��1Ϊ��λ��4Ϊ��λ
            for(int i = 0;i <= 9;i++) {//�滻��ֵΪ0~9
                int wei = 1;//wei��ʾ��Ӧ�滻λ�õ�ֵ
                for(int j = 1;j <= 4;j++) {//4��λ������滻
                    //��jλ��ֵ�滻Ϊ i
                    int tval = tmp.val - val[j]*wei + i*wei;
                    wei *= 10;
                    if(prime.count(tval)==0) continue;//��Ϊ����������
                    if(tval<1000) continue;//��Ϊ��λ��������
                    if(vis.count(tval)) continue;//�Ѿ�����������
                    node tt = {tval,tmp.step+1};
                    q.push(tt);//���
                }
            }
        }
        if(!flag) cout<<"Impossible\n";//�޽�
    }
    return 0;
}
