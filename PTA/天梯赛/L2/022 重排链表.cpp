#include<iostream>//ac
#include<cstdio>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
const int MAXN = 1e6+1;//�������stringռ�õ��ڴ�С�����߶����Թ�
//��string�Ļ���ֱ�������ַ������Ҫ��printf
struct node{
    int name,val;//��¼��ǰ��ַ��ֵ
};
int data[MAXN],nextt[MAXN],vis[MAXN];//dataΪ��ǰ�ڵ��ֵ��nexttΪ��ǰ�ڵ����һ����ַ
//vis�жϵ�ǰ��ַ�Ƿ���ֵ
vector<node> link;
int main() {
    int head,n;
    scanf("%d%d",&head,&n);
    for(int i = 1;i <= n;i++) {
        int a,b,val;
        scanf("%d%d%d",&a,&val,&b);
        vis[a] = 1;//a��ַ��ֵ
        data[a] = val;//���½ڵ��ֵ
        nextt[a] = b;//���µ�ǰ�ڵ����һ����ַ
    }
    while(vis[head]) {//��ǰ��ַ��ֵ
        link.push_back(node{head,data[head]});//��¼��ַ��ֵ
        head = nextt[head];//�Ƶ���һ��λ��
    }
    int l = 0,r = link.size()-1,flag = 0;//flag�жϵ�ǰ�Ƿ�Ϊ��һ������ģ�1����
    //ֻҪ���ǵ�һ������ģ�����Ҫ�������ַһ�Σ�Ϊ��һ���������һ����ַ��
    //������ÿ��ֻ��Ҫ��� ��ǰ��ַ �� ֵ ����
    while(l<=r) {//����l==r�����������
        if(l==r) {
            //����flag�жϵĶ���Ҫ�س�����Ϊ��һ�е� ��һ����ַ
            if(flag) printf("%05d\n",link[l].name);//ע�� %05d
            printf("%05d %d ",link[l].name,link[l].val);
            l++,r--;//����Ҫ������
            //l==rʱû�и��£�����һֱ��ӣ�ֱ���ڴ泬�ޣ�����д��֮��Ϊtle������
        }
        else {//����˫ָ���˼�룬�������
            if(flag) printf("%05d\n",link[r].name);//�ȴ��С
            printf("%05d %d ",link[r].name,link[r].val);
            flag = 1;
            if(flag) printf("%05d\n",link[l].name);
            printf("%05d %d ",link[l].name,link[l].val);
            r--,l++;
        }
    }
    printf("-1");//���һ�е���һ����ַһ��Ϊ -1
    return 0;
}
