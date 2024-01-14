#include<iostream>//ac
#include<queue>
#include<set>
#include<utility>
#include<algorithm>
#define INF 0x3f3f3f3f
#define pii pair<int,int>
using namespace std;
struct node{
    int a[3],step;
    friend bool operator < (node a,node b) {
        return a.step > b.step;//���ȴ����ٵ�
    }
};
int c[3];//��¼�������ӵ�����
bool check(node val) {
    sort(val.a,val.a+3);//����������
    //����С��Ϊ�գ�����������ֵ��ͬ��Ϊ��������
    if(val.a[0]==0&&val.a[1]==val.a[2]) return 1;
    return 0;
}
int main() {
    while(cin>>c[0]>>c[1]>>c[2]&&c[0]+c[1]+c[2]) {
        priority_queue<node> q;
        set<pii > st;//����������ӵ������ɣ���Ϊ���������ǹ̶���
        node tmp = {c[0],0,0,0};//��ʼ��ֻ�е�һ����ˮ
        q.push(tmp);
        int ans = INF;
        while(!q.empty()) {
            node tmp = q.top();q.pop();
            pii vis = {tmp.a[0],tmp.a[1]};
            if(st.count(vis)) continue;//�����ѱ�ǵ�
            else st.insert(vis);
            if(check(tmp)) {//��������������´�
                ans = tmp.step;break;
            }
            for(int i = 0;i < 3;i++) {//i����ˮ����j����
                for(int j = 0;j < 3;j++) {//�ܹ��������򣨵�ˮ��
                    if(i==j||tmp.a[i]==0) continue;//��ͬ�Ļ���iûˮ������
                    node now = tmp;
                    int sum = now.a[i]+now.a[j];//�ܺ�
                    now.a[j] = min(sum,c[j]);//���ܳ���j������������
                    now.a[i] = sum-now.a[j];//iΪʣ�µ�
                    now.step++;//����++
                    q.push(now);
                }
            }
        }
        if(ans==INF) cout<<"NO\n";//�޽��ʱ��
        else cout<<ans<<"\n";
    }
    return 0;
}
