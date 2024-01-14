#include<iostream>//ac
#include<cmath>
#include<vector>
#include<algorithm>
#define INF 0x3f3f3f3f
#define two(x) (x)*(x)
using namespace std;

//��⣺����ÿ������x�����ܹ����״︲�ǵķ�Χ[l,r]
//��ô����ԭ��Ŀ������ת��Ϊ�����ɸ������У�ѡ�����ٵĵ㣬ʹ�������������ٶ���һ����
//�����䰴��l�Ĵ�С����С���������ñ���pos��¼��һ���״��λ��
//�жϹ��̣����pos>=l[i]��˵�����㵱ǰ���Ҫ��pos��Ҫ����(pos = min(pos,r[i])
//���磺[1,7] [2,5] ���������䣬���ں�һ����˵���״���Ҫ��������һ���������£��������󣬼�Ϊ5
//������Ҫ�����һ���״����λ��Ϊr[i]����������

struct node{
    double l,r;
    friend bool operator < (node a,node b) {
        return a.l < b.l;//��С��������
    }
};
vector<node> v;//������
double get_dis(double d,double y) {
    return sqrt(d*d-y*y);//����ͶӰ��x��ĳ���
}
int main() {
    int n,cas = 0;
    double m;
    while(cin>>n>>m&&n&&m) {
        v.clear();                      //��գ�����
        int flag = 0;                   //����Ƿ��н�
        for(int i = 1;i <= n;i++) {
            double x,y;
            cin>>x>>y;
            if(flag||y>m) {             //��x��ľ�������״�ķ�Χ�����޽⣡����
                flag = 1;continue;
            }
            double dis = get_dis(m,y);  //ͶӰ��x��ĳ���
            node tmp = {x-dis,x+dis};   //���伴ΪxΪ�е㣬��������dis
            v.push_back(tmp);
        }
        if(flag) {                      //�����޽�����������
            cout<<"Case "<<++cas<<": -1\n";
            continue;
        }
        sort(v.begin(),v.end());        //����
        double pos = -INF;              //��ʼ�����Ϊ������
        int ans = 0;
        for(int i = 0;i < v.size();i++) {
            if(pos>=v[i].l) {           //��������
                pos = min(pos,v[i].r);  //����Ϊ��С��λ��
            }
            else ans++, pos = v[i].r;   //�������++������λ��
        }
        cout<<"Case "<<++cas<<": "<<ans<<"\n";
    }
    return 0;
}
