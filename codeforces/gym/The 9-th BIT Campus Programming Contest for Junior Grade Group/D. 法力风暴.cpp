#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺�������Ƿ���INF�����
//ֻ�����е�R��B����Ҫ���ѷ���������ô���Ӧ��R����BΪ0����һ��ΪINF����
//���򣬽����ﰴ����r��С���������ٰ���b��С��������
//�������е�������ڵ�ǰ��i���������
//���㵱ǰ��r�ض�����ǰ���r������������b����ȡ��Сֵ��b
//��Ϊr�����ˣ�ǰ��С��b�϶�Ҳ���㣬����ÿ�ζ���Ҫȡ��С��b
//��ô���ڵ�ǰ��ǰi��������ԣ�ȡ(b-1)�Ͳ�������ǰ�������
//������ȡ��һ��r���������ֵ����(r-1)������Ҳ�Ͳ���������һ������
//�����´�Ϊ ans = max(ans, (min_b-1) + (next_r-1))
//ע�����min_bΪ0�Ļ���ֹͣ���´𰸣���Ϊ�����(r-1)������ǰ������
//��������㣬Ҳ�����ǰһ�����µ�ֵ��

const int MAXN = 5e3+5;
struct node{
    int a,b;
    friend bool operator < (node x,node y) {
        if(x.a==y.a) return x.b < y.b;
        return x.a < y.a;//��a��b
    }
}val[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,zero_a = 0, zero_b = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            int a,b;
            cin>>a>>b;
            if(a==0) zero_a = 1;
            if(b==0) zero_b = 1;
            val[i] = {a,b};
        }
        if(!zero_a||!zero_b) {//�����һ��û��0����ʾ��INF�����
            cout<<"INF\n";
        }
        else {
            sort(val+1,val+1+n);
            int ans = 0,tmp = INF;
            for(int i = 1;i <= n;i++) {
                if(val[i].b==0) break;
                tmp = min(tmp, val[i].b);//ȡ��С��b
                //��ȡ��һ����r����a��
                ans = max(ans, val[i+1].a-1+tmp-1);//�������� -2
//                cout<<i<<" "<<tmp<<" "<<ans<<"\n";
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
/*
2
6
0 100
50 50
60 60
100 0
150 50
1000 0
4
0 1
0 100
99 5
100 0
*/
