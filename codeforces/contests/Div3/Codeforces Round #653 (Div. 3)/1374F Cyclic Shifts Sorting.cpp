#include<iostream>//ac
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//���⣺������n^2����ʹ�������򣬲���Ϊ����Ϊ���ķ�Χ�ڣ����һλ��ǰ��ʣ�����
//��⣺�����������е������Ϊ0����ÿ�β�������ʹ�����-2������λ��С����ǰ��λ��
//���Ե������Ϊ������ʱ���н⣬ֻ��Ҫ�������򼴿�
//�������Ϊż����ʱ���ж��Ƿ���������ֵ��ͬ����������λ��Ҳ���н�(����+1)
//�����޽�


const int MAXN = 505;
int a[MAXN];
vector<int> ans;
vector<pair<int,int>> pos;//pai�Ȱ�fi���������ٰ�se��������
void change(int i) {//�ƶ�������iΪ������м�λ��
    int tmp = a[i+1];
    a[i+1] = a[i],a[i] = a[i-1];
    a[i-1] = tmp;
}
int main() {
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        pos.clear(),ans.clear();//��ʼ��
        for(int i = 1;i <= n;i++) cin>>a[i],pos.push_back({a[i],i});
        sort(pos.begin(),pos.end());//�����ж�ÿ����Ӧ�ô���λ��
        for(int i = 0;i < pos.size();i++) {
            a[pos[i].se] = i+1;//����С���1��ʼ�����1
        }//se�������ԭ�����ݵ��±�
        int num = 0;//���������
        for(int i = 1;i <= n;i++) {
            for(int j = i+1;j <= n;j++) num += a[i]>a[j];
        }
        if(num&1) {//�����Ϊ����ʱ
            for(int i = 0;i < pos.size()-1;i++) {
                if(pos[i].fi==pos[i+1].fi) {//�ƶ�����ֵӦ����λ��
                    swap(a[pos[i].se],a[pos[i+1].se]);
                    break;
                }
            }
        }
        for(int i = 1;i <= n-2;i++) {//������ǰn-2������λ��
            int tmp = INF,index;
            for(int j = i;j <= n;j++) {//����Сֵ
                if(a[j]<tmp) tmp = a[j],index = j;
            }
            if(index==i) continue;//index��ʾҪ�ƶ���ǰ�����
            while(index-2>=i) {//���ܳ���iλ��
                ans.push_back(index-2);//ans������������һ�����ֵ��±꣡����
                change(index-1);//�����м��޸�
                index -= 2;//�ƶ���ǰ����λ��
            }
            if(index!=i) {//�������iλ�ã���ԭ�ر任����
                ans.push_back(index-1),ans.push_back(index-1);
                change(index),change(index);
            }
        }
        int flag = 0;
        for(int i = 1;i <= 3;i++) {//���������������ֻ�����ֿ���
            if(is_sorted(a+1,a+1+n)) {//�������������
                flag = 1;break;
            }
            ans.push_back(n-2);//�����ʼλ��
            change(n-1);
        }
        if(!flag) {
            cout<<"-1"<<endl;continue;
        }
        cout<<ans.size()<<endl;
        for(int i = 0;i < ans.size();i++) {
            if(i!=0) cout<<' ';
            cout<<ans[i];
        }
        cout<<endl
    }
	return 0;
}
