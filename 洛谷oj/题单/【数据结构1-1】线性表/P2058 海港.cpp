#include<iostream>//ac
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

//��⣺����ά��24Сʱ�����еĳ˿ͣ�������ά��24Сʱ�ڵ���Ĵ�������
//Ȼ����map��¼��Ӧ�����ĳ�������������Ӧ�޸�ans

const int TIME = 86400;//24Сʱ��Ӧ����
struct node{//���浽��ʱ��͹���
    int time,nation;
};
queue<node> q;//ά��24Сʱ��Χ�ڵ����г˿�
map<int,int> num;//��¼��Ӧ����������
int main() {
    int n,ans = 0;//ans����ά����ǰ�Ĺ�����
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//����
    cin>>n;
    for(int i = 1;i <= n;i++) {//n����
        int tmp,arrive,siz;
        cin>>arrive>>siz;//����ʱ�������
        for(int j = 1;j <= siz;j++) {//��ǰ����������
            cin>>tmp,q.push(node{arrive,tmp});//�����������
            if(num[tmp]==0) ans++;//��������µĹ�������ans++
            num[tmp]++;//ÿ���˵Ĺ�������Ҫ��¼������
        }
        while(arrive-q.front().time>=TIME) {//ȥ�����׳���24Сʱ�Ĵ�Ա
            if(--num[q.front().nation]==0) --ans;//ȥ��֮���޴˹�������ʱ��ans--
            q.pop();//������
        }
        cout<<ans<<endl;
    }
    return 0;
}
