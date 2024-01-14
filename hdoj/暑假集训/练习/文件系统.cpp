#include<iostream>
#include<string>
using namespace std;
struct fil {
	string name;
	fil * next;//同级文件 
};
struct dir {
	string name;
	dir * next;//同级文件夹
	dir * up;//上一级文件夹 
	dir * dirhead;//子文件夹 
	fil * filhead;//子文件 
};
dir *head,*nowhead;
dir *searchdir(string name) {
	dir *tmp=nowhead->dirhead->next;
	while(tmp) {
		if(tmp->name==name) return tmp;
		tmp=tmp->next;
	}
	return NULL;
}
fil *searchfil(string name) {
	fil *tmp=nowhead->filhead->next;
	while(tmp) {
		if(tmp->name==name) return tmp;
		tmp=tmp->next;
	}
	return NULL;
}
void init() {//初始化
	head=new dir;//new 不需要头文件 
	head->dirhead=new dir;
	head->filhead=new fil;
	head->next=NULL;
	head->up=head;
	nowhead=head;
	nowhead->dirhead->next=NULL;
	nowhead->filhead->next=NULL; 
} 
int main() {
	string op,name;
	init();
	while(cin>>op>>name) {
		if(op=="CD") {//更改目录位置 
			if(name=="..") {
				nowhead=nowhead->up;
				cout<<"success"<<endl;
			}
			else if(name=="\\") {
				nowhead=head;
				cout<<"success"<<endl;
			}
			else {
				dir *p=searchdir(name);
				if(!p) {
					cout<<"no such directory"<<endl;
				}
				else {
					nowhead=p;
					cout<<"success"<<endl;
				}
			}
		}
		else if(op=="MD"){//建立子文件夹 
			if(name==".."||name=="\\") {
				cout<<"directory already exist"<<endl;
			}
			else {
				dir *p;
				p=searchdir(name);
				if(!p) {
					dir *q=new dir;
					q->name=name;
					q->filhead=new fil;
					q->dirhead=new dir;
					q->filhead->next=NULL;
					q->dirhead->next=NULL;
					q->up=nowhead;
					q->next=nowhead->dirhead->next;//在next中间加入子文件夹 
					nowhead->dirhead->next=q;
					cout<<"success"<<endl;
				}
				else cout<<"directory already exist"<<endl;
			}
		}
		else if(op=="RD") {//删除子文件夹 
			dir *p=searchdir(name);
			if(!p||p->dirhead->next) {
				cout<<"can not delete the directory"<<endl;
			} 
			else {
				dir *q=nowhead->dirhead;//dirhead为子文件夹 
				while(q) {
					if(q->next==p) {//q->next为同类子文件夹 
						q->next=p->next;
						delete p;//delete不需要头文件 
						cout<<"success"<<endl;
						break;
					}
					q=q->next;
				}
			}
		}
		else if(op=="CREATE") {//建立文件 
			fil *p=searchfil(name);
			if(!p) {
				p=new fil;//重新申请内存 
				p->name=name;
				p->next=nowhead->filhead->next;//next中间加入文件 
				nowhead->filhead->next=p;
				cout<<"success"<<endl;
			}
			else cout<<"file already exist"<<endl;
		}
		else if(op=="DELETE") {//删除文件 
			fil *p=searchfil(name);
			if(!p) {
				cout<<"no such file"<<endl;
			}
			else {
				fil *q;
				q=nowhead->filhead;
				while(q) {
					if(q->next==p) {
						q->next=p->next;//p->next为被删除的文件后的指针 
						delete p;
						break;
					}
					q=q->next;
				}
				cout<<"success"<<endl;
			}
		}
	}
	return 0;
} 
