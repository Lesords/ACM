#include<iostream>//ac
#include<utility>
#include<algorithm>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//��⣺����������ö��ÿ��λ�õ�״̬
//0��ʾ��ǰΪ��
//1��ʾ��ǰ��һ��1*1��������ռ��
//2��ʾ��ǰ����(x,y)����һ������(x,y+1)��1*2�ĳ�����ռ�ã�ˮƽ�ڷ�
//3��ʾ��ǰ����(x,y)����һ������(x+1,y)��1*2�ĳ�����ռ�ã���ֱ�ڷ�
//����ʼλ(1,1)��ʼö�٣�����h+1�м�Ϊ��������

int ans,num[25][25],h,w,a,b;
pii getN(int x,int y) {//��ȡ��һ��λ��
    if(y==w) return {x+1,1};//�����ǰλ������ĩ�������Ƶ���һ��
    return {x,y+1};//�������Ƽ���
}
void dfs(int x,int y,int cnta,int cntb) {//(x,y)Ϊ��ǰ���꣬cnta,cntb�ֱ�Ϊa,b��ʣ������
    if(cnta<0||cntb<0) return;//С��0����������������
    if(x>h) return (void) ans++;//������������ۼӣ�voidС����
    pii nxt = getN(x,y);//��ȡ��һ��λ�õ�����
    if(num[x][y-1]==2||num[x-1][y]==3) {//����ǰλ�ñ���һ�������ռ���ˣ���������䣬��������
        return dfs(nxt.fi,nxt.se,cnta,cntb);
    }
    num[nxt.fi][nxt.se] = 1;//����1*1�ĸ���
    dfs(nxt.fi,nxt.se,cnta,cntb-1);//cntb����-1
    num[nxt.fi][nxt.se] = 0;//����
    if(y<w&&num[x-1][y+1]!=3) {//ˮƽ���ã����ұߵ���һ�����ô�ֱ����
        num[x][y] = 2;//ˮƽ����
        dfs(nxt.fi,nxt.se,cnta-1,cntb);//cnta������-1
        num[x][y] = 0;//����
    }
    if(x<h) {//��һ�в�Խ�缴��
        num[x][y] = 3;//��ֱ����
        dfs(nxt.fi,nxt.se,cnta-1,cntb);//cnta������-1
        num[x][y] = 0;//����
    }
}
int main() {
    cin>>h>>w>>a>>b;
    dfs(1,1,a,b);
    cout<<ans;//������
    return 0;
}
