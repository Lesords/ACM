#include<iostream>//ac
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

//��⣺̰��+���ȶ���
//�����������ȶ��зֱ�洢����ͻ��ڵķ羰�������
//������Ŀ��Ҫ�����Ϲ�������������Ϊk��
//��ôҲ����˵������ȥ�ι۵�����������Ҫk��
//��ô���Էֳ����������
//����ѡ�����磬��һ��Ҫѡ������
//�������ڵ�����ι۲���Ӱ�죬�������ڵ�ȫ������ιۣ�����

const int MAXN = 1e5+5;
double a[MAXN],b[MAXN];
int main() {
    int n,m,t,k;
    cin>>n>>m>>t>>k;
    priority_queue<double> indoor,outdoor;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        indoor.push(a[i]);
    }
    for(int i = 1;i <= m;i++) {
        cin>>b[i];
        outdoor.push(b[i]);//0.8
    }
    double ans = 0;
    for(int i = 1;i <= t;i++) {//�ܹ�t��
        double in = indoor.top();
        double out = outdoor.top();
        if(i+k<=t) {//���첻һ����Ҫ����ȥ
            if(in>=out) {//���ڵļ�ֵ����
                ans += in;
                indoor.pop();//�����ɵģ�����µ�
                indoor.push(in*0.6);
                k--;//���ڵģ�����ȥ
            }
            else {
                ans += out;
                outdoor.pop();//�����ɵģ�����µ�
                outdoor.push(out*0.6);
            }
        }
        else {//��������ȥ
            k--;
            if(in>=out*0.8) {//�������Ҫ��0.8������
                ans += in;
                indoor.pop();//�����ɵģ�����µ�
                indoor.push(in*0.6);
            }
            else {
                ans += out*0.8;
                outdoor.pop();//�����ɵģ�����µ�
                outdoor.push(out*0.6);//����ָ�ԭ�ۣ�����ֻ��Ҫ*0.6
            }
        }
    }
    printf("%.2f",ans);
    return 0;
}
