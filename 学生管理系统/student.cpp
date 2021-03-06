/*学生链表类
student.cpp*/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "student.h"
#define wuli current->info.wl
#define xiandai current->info.xd
#define tiyu current->info.ty
using namespace std;
int flag=0;
void list::showt()//显示表头
{
	cout << "序号" << "\t" << "姓名" << "\t" << "幸运日" << "\t";
	cout << "生日" << "\t\t" << "线代" << "\t" << "体育" << "\t" << "物理" << "\t" << endl;
}
void list::destory()//销毁链表，释放内存
{
	student *p;
	while(head)
	{
		p=head->next;
		delete head;
		head=p;
	}
}
void list::singleshow(student *current)
{
	cout << current->info.num << "\t" << current->info.name << "\t" << current->info.xyr << "\t";
	cout << current->info.sr << "\t" << current->info.xd << "\t" << current->info.ty << "\t" << current->info.wl << "\t" << endl;
}
student* list::search()
{
	int i,flag=0;
	cout << "请输入你想查找的序号\n";
	cin >> i;
	student *current=head;
	current=current->next;
	showt();
	while(current!=NULL)
	{
		if(current->info.num==i)
		{
			flag=1;
		}
		if(flag==1)
		{
			singleshow(current);
			cout << "是否要选择该生 输入1选择 其他跳过\n";
			cin >> flag;
			if(flag==1)
			{
				return current;
				break;
			}
			else
			{
				flag=0;
			}
		}
		current=current->next;
	}
	if(flag==0)
	{
		cout << "没有该生\n";
		return NULL;
	}
}
void list::search_()//搜索显示信息
{
	int i=0;
	student *p=head;
	p=p->next;
	int num_;
	cout << "请输入序号" << endl;
	cin >> num_;
	while(p!=NULL)
	{
		if(p->info.num==num_)
		{
			singleshow(p);
			i++;
		}
		p=p->next;
	}
	if(i==0) cout << "没有找到该序号\n";
}
void list::remove(student *p)//删除某个节点
{
	if(p!=NULL)
	{
		if(p->next=NULL)
		{
			p->pre->next=NULL;
			delete(p);
		}
		else
		{
			p->pre->next=p->next;
			p->next->pre=p->pre;
			delete(p);
		}
	}
	else
		cout << "本次未删除\n";
}
void list::show() //显示函数
{
	int i=0;
	student *current=head;
	current=current->next;//跳过头节点
	showt();
	while(current!=NULL)
	{
		cout << current->info.num << "\t" << current->info.name << "\t" << current->info.xyr << "\t";
		cout << current->info.sr << "\t" << current->info.xd << "\t" << current->info.ty << "\t" << current->info.wl << "\t" << endl;
		current=current->next;
		i++;
	}
	if(i==0) cout << "没有学生" << endl;
}
void list::singleinput(student *p)//输入单个人的信息
{
	if(p!=NULL)
	{
		cout << "请输入序号:";
		cin >> p->info.num;
		cout << "请输入姓名:";
		cin >> p->info.name;
		cout << "请输入幸运日:";
		cin >> p->info.xyr;
		cout << "请输入生日:";
		cin >> p->info.sr;
		cout << "请输入线代:";
		cin >> p->info.xd;
		cout << "请输入体育:";
		cin >> p->info.ty;
		cout << "请输入物理:";
		cin >> p->info.wl;
		cout << "输入成功" << endl;
	}
}
void list::insert()//输入函数
{
	student *p,*q=head;
	while(q->next!=NULL)//找到尾部插入
	{
		q=q->next;
	}
	p=(student*)new(student);
	singleinput(p);
	q->next=p;
	p->next=NULL;
	p->pre=q;
}
void list::modify(student *p)//修改信息
{
	singleinput(p);
}
void list::scorefalse()//显示出不及格的人
{
	student *current=head;
	current=current->next;
	while(current!=NULL)
	{
		if(xiandai<60||wuli<60||tiyu<60)
		{
			cout << "姓名:" << current->info.name << endl;
			if(xiandai<60)
			{
				//cout << current->info.name << endl;
				cout << "科目: 线代" << "\t";
				cout << "分数: " << xiandai << endl;
			}
			if(wuli<60)
			{
				//cout << current->info.name << endl;
				cout << "科目: 物理" << "\t";
				cout << "分数: " << wuli << endl;
			}
			if(tiyu<60)
			{
				//cout << current->info.name << endl;
				cout << "科目: 体育" << "\t";
				cout << "分数: " << tiyu << endl;
			}
		}
		current=current->next;
	}
}
void list::percent()//显示总体百分比
{
	student *current=head;
	int i=0,bjg=0,exc=0,lh=0;
	current=current->next;
	while(current!=NULL)
	{
		i++;
		float aver=(wuli+xiandai+tiyu)/3.0;
		if(aver<60) bjg++;
		else if(aver<80) lh++;
		else exc++;
		current=current->next;
	}
	cout << "所有学生中\n平均分<60有\t\t" << bjg << "名\t" << "占:" << float(bjg)/i*100 << "%" << endl;
	cout << "60<平均分<80有\t\t" << lh << "名\t" << "占:" << float(lh)/i*100 << "%" << endl;
	cout << "平均分>80有\t\t" << exc << "名\t" << "占:" << float(exc)/i*100 << "%" << endl;
}
void list::singlepercent()//显示单科百分百
{
	student *current=head;
	int i=0;
	int phy_bjg=0,phy_lh=0,phy_exc=0;
	int line_bjg=0,line_lh=0,line_exc=0;
	int exer_bjg=0,exer_lh=0,exer_exc=0;
	current=current->next;
	while(current!=NULL)
	{
		if(wuli<60) phy_bjg++;
		else if(wuli<80) phy_lh++;
		else phy_exc++;
		if(xiandai<60) line_bjg++;
		else if(xiandai<80) line_lh++;
		else line_exc++;
		if(tiyu<60) exer_bjg++;
		else if(tiyu<80) exer_lh++;
		else exer_exc++;
		i++;
		current=current->next;
	}
	cout << "物理:\n" << "不及格有(<60)\t\t" << phy_bjg << "名\t" << "占" << float(phy_bjg)/i*100 << "%" << endl;
	cout << "良好有(<80)\t\t" << phy_lh << "名\t" << "占" << float(phy_lh)/i*100 << "%" << endl;
	cout << "优秀有(>80)\t\t" << phy_exc << "名\t" << "占" << float(phy_exc)/i*100 << "%" << endl;
	cout << "线代:\n" << "不及格有(<60)\t\t" << line_bjg << "名\t" << "占" << float(line_bjg)/i*100 << "%" << endl;
	cout << "良好有(<80)\t\t" << line_lh << "名\t" << "占" << float(line_lh)/i*100 << "%" << endl;
	cout << "优秀有(>80)\t\t" << line_exc << "名\t" << "占" << float(line_exc)/i*100 << "%" << endl;
	cout << "体育:\n" << "不及格有(<60)\t\t" << exer_bjg << "名\t" << "占" << float(exer_bjg)/i*100 << "%" << endl;
	cout << "良好有(<80)\t\t" << exer_lh << "名\t" << "占" << float(exer_lh)/i*100 << "%" << endl;
	cout << "优秀有(>80)\t\t" << exer_exc << "名\t" << "占" << float(exer_exc)/i*100 << "%" << endl;
}
void list::txtsavefile()//导出到文件
{
	int i=0;
	ofstream stu;
	student *current=head;
	current=current->next;
	if(flag==0)
	{
		cout << "系统检测到危险操作\n输入y跳过打开文件\n";
		char w;
		cin >> w;
		if(w!='y')
		{
			openfile();
		}
	}
	stu.open("学生数据.txt");
	if(!stu.is_open())
	{
		cout << "文件打开失败" << endl;
		exit(EXIT_FAILURE);
	}
	while(current!=NULL)
	{
		stu << current->info.num << "\t" << current->info.name << "\t" << current->info.xyr << "\t";
		stu << current->info.sr << "\t" << current->info.xd << "\t" << current->info.ty << "\t" << current->info.wl << "\t" << endl;
		i++;
		current=current->next;
	}
	cout << "成功导出" << i << "条数据" << endl;
	stu.close();
}
void list::savefile()//保存到二进制文件
{
	int i=0;
	ofstream stu_;
	student *current=head;
	current=current->next;
	if(flag==0)
	{
		cout << "系统检测到危险操作\n输入y跳过打开文件\n";
		char w;
		cin >> w;
		if(w!='y')
		{
			openfile();
		}
	}
	stu_.open("学生数据.bin",ios::binary|ios::out);
	if(!stu_.is_open())
	{
		cout << "文件打开失败" << endl;
		exit(EXIT_FAILURE);
	}
	while(current!=NULL)
	{
		stu_.write((char *) &(current->info),sizeof (current->info));
		i++;
		current=current->next;
	}
	stu_.close();
	cout << "成功保存" << i << "条数据" << endl;
}
void list::openfile()//打开二进制文件
{
	int i=0;
	student *p=head,*q;
	ifstream stu_;
	stu_.open("学生数据.bin",ios::binary|ios::in);
	if(!stu_.is_open())
	{
		cout << "文件打开失败" << endl;
		exit(EXIT_FAILURE);
	}
	stu_.seekg(0,ios::end);
	int end_=stu_.tellg();
	stu_.seekg(0,ios::beg);
	while(stu_.tellg()!=end_)
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		q=(student *)new student;
		stu_.read((char *) &(q->info),sizeof (q->info));
		i++;
		flag=1;
		p->next=q;
		q->next=NULL;
		q->pre=p;
	}
	cout << "成功读取" << i << "条数据" << endl;
}
