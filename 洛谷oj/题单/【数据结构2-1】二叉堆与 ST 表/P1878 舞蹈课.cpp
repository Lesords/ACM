#include<iostream>//ac
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;

//��⣺�Ƚ��������ڵ����ζ��������
//Ȼ��ÿ��ѡ������׵�ֵ��Ȼ����ѡ�е���
//���Ž���ǰѡ�е���������Ѱ�ҿ������ڵ��ˣ�ȥ����ǰλ�ú󣬼������ڣ�

const int MAXN = 2e5+5;
struct node{
    int cha,x,y;
    friend bool operator < (node a,node b) {
        if(a.cha!=b.cha) return a.cha > b.cha;//�ȸ��ݲ��С��������
        return a.x > b.x;//Ȼ�������Сֵx����С�ﵽ����
    }
};
int a[MAXN],ansA[MAXN],ansB[MAXN],in[MAXN];//inΪ��ǰλ���Ƿ�ѡ��
char gen[MAXN];//��¼�Ա�
priority_queue<node> q;//���ȶ���
int main() {
    int n,num = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>gen[i];
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        if(i!=1&&gen[i]!=gen[i-1]) {//���ڵ��������
            q.push({abs(a[i]-a[i-1]), i-1,i});//���Сλ�ã��ϴ�λ��
        }
    }
    while(!q.empty()) {//��Ϊ�գ����������
        int x = q.top().x;
        int y = q.top().y;
        q.pop();//�ǵó���
        if(in[x]||in[y]) continue;//����һ����ѡ�У�������
        num++;//����++
        ansA[num] = x;
        ansB[num] = y;//��¼��Ӧλ��
        in[x] = in[y] = 1;//���Ϊ��ѡ��
        while(x>=1&&in[x]) x--;//x����Ѱ�ҵ�һ��δ��ѡ�е���
        while(y<=n&&in[y]) y++;//y����Ѱ�ҵ�һ��δ��ѡ�е���
        if(x<1||y>n) continue;//Խ�磬������
        //�ж��Ա��Ƿ�ͬ������
        if(gen[x]!=gen[y]) q.push({abs(a[x]-a[y]),x,y});//�������
    }
    cout<<num<<"\n";
    for(int i = 1;i <= num;i++) {
        cout<<ansA[i]<<" "<<ansB[i]<<"\n";
    }
    return 0;
}
