// linklist.cpp: 实现文件
//


/*
此文件为单链表演示的对话框实现文件
此文件为单链表演示的对话框实现文件
此文件为单链表演示的对话框实现文件
此文件为单链表演示的对话框实现文件
此文件为单链表演示的对话框实现文件
*/


#include "pch.h"
#include "linear.h"
#include "linklist.h"
#include "afxdialogex.h"
#include<sstream>
#include<string>
#include<iostream>
using namespace std;
// linklist 对话框

IMPLEMENT_DYNAMIC(linklist, CDialogEx)

linklist::linklist(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
	first = new LinkNode;
}

linklist::~linklist()
{
	delete first;
}

/*此处为当前对话框的初始化代码*/
void linklist::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_LIST1, m_list);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0, _T("序号"), 0, 100);
	m_list.InsertColumn(1, _T("值"), 0, 100);
	//若有其他内容需要初始化可在此添加额外代码

}


BEGIN_MESSAGE_MAP(linklist, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &linklist::CreateLinklist)
	ON_BN_CLICKED(IDC_BUTTON2, &linklist::Push_back)
	ON_BN_CLICKED(IDC_BUTTON3, &linklist::Instowantdpos)
	ON_BN_CLICKED(IDC_BUTTON4, &linklist::Delwanted)
	ON_BN_CLICKED(IDC_BUTTON7, &linklist::Delwantedpos)
	ON_BN_CLICKED(IDC_BUTTON8, &linklist::Delallwanted)
	ON_BN_CLICKED(IDC_BUTTON5, &linklist::Reverse)
	ON_BN_CLICKED(IDC_BUTTON6, &linklist::Show)
	ON_BN_CLICKED(IDC_BUTTON9, &linklist::Insafterawanted)
	ON_BN_CLICKED(IDC_BUTTON10, &linklist::Insafterallwanted)
	ON_BN_CLICKED(IDC_BUTTON11, &linklist::Delrepeat)
END_MESSAGE_MAP()






// linklist 消息处理程序

/*请在此处添加从编辑框控件m_edit中读取数据并创建目标单链表的代码*/
void linklist::CreateLinklist()   //创建单链表
{
	// TODO: 在此添加控件通知处理程序代码
	
	//linklist L;

	LinkNode* current = first;
	if (current->link != NULL) { MessageBox(TEXT("已经初始化！")); return; }
	CString str;
	m_edit.GetWindowText(str);//str接受m_edit的值
	//将str按空格分割，存储到CString类型的动态数组里
	int i = 0;
	CArray<CString, CString>strArray;  //定义一个CString类型的动态数组，用来存取CString类型对象。
	while (str.Find(TEXT(" ")) + 1)//当找不到空格时返回-1，所以这里用它返回值加1来循环
	{
		strArray.Add(str.Left(str.Find(TEXT(" "))));//找到空格的索引，截取空格左边的字符串,并将它添加到strArray动态数组中。
		str.Delete(0, strArray[i].GetLength() + 1);//返回删除空格和其左边的字符串的得到的新字符串。
		i++;
	}
	strArray.Add(str);//最后加上经过最终删除后剩下的字符串；
	i++;
	//将CString动态数组里的数逐个存储到链表中
	for (int j = 0; j < i; j++)
	{
		
		LinkNode* newNode = new LinkNode(_ttoi(strArray[j]));
		if (newNode == NULL) 
		{
			cerr << "存储分配错误" << endl;
			exit(1);
		}
		newNode->link = current->link;
		current->link = newNode;
		current = current->link;

	}


}

/*请在此处添加在单链表最后添加元素的代码*/
void linklist::Push_back()   //添加元素
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_edit.GetWindowText(str);//str接受m_edit的值
	LinkNode* newNode = new LinkNode(_ttoi(str));
	LinkNode* current = first->link;
	while (current->link != NULL)
	{
		current = current->link;
	}
	newNode->link = current->link;
	current->link = newNode;
}

/*请在此处添加在单链表指定位置添加元素的代码*/
void linklist::Instowantdpos()   //插入元素
{
	// TODO: 在此添加控件通知处理程序代码
	//获取选中行的序号num
	CString c_num;
	bool selected = false;
	for (int i = 0; i < m_list.GetItemCount(); i++)
	{
		if (m_list.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			c_num.Format(_T("%d"), i + 1);//序号从1开始计
			selected = true;
			//MessageBox(c_num);
		}
	}
	if (selected == false)
	{
		MessageBox(TEXT("请选中插入行！"));
		return;
	}
	int i_num = _ttoi(c_num);//将序号转化为int型
	int count = 1;
	LinkNode* current = first;
	while (count < i_num)
	{
		current = current->link;
		count++;
	}
	CString str;
	m_edit.GetWindowText(str);//str接受m_edit的值
	LinkNode* newNode = new LinkNode(_ttoi(str));
	newNode->link = current->link;
	current->link = newNode;
}

/*
请在此处添加在单链表中删除最前面的指定数据的代码
例如  原链表为  1 5 2 5 3 5 4 5
要求删除5
则执行完该段代码后的链表为1 2 5 3 5 4 5
*/
void linklist::Delwanted()   //删除指定内容
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_edit.GetWindowText(str);//str接受m_edit的值
	int del = _ttoi(str);//转换为int型并存储
	LinkNode* current = first;
	LinkNode* record = current;
	while (current != NULL)
	{
		if (current->data == del)
		{
			LinkNode* temp = current;
			record->link = temp->link;
			delete temp;
			return;
		}
		record = current;//记录current上次位置
		current = current->link;
	}
	MessageBox(TEXT("不存在该值"));
}

/*请在此处添加在单链表中删除指定位置的代码*/
void linklist::Delwantedpos()   //删除指定位置
{
	// TODO: 在此添加控件通知处理程序代码
	//获取选中行的序号num
	CString c_num;
	bool selected = false;
	for (int i = 0; i < m_list.GetItemCount(); i++)
	{
		if (m_list.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			c_num.Format(_T("%d"), i + 1);//序号从1开始计
			selected = true;
			//MessageBox(c_num);
		}
	}
	if (selected == false)
	{
		MessageBox(TEXT("请选中删除行！"));
		return;
	}
	int i_num = _ttoi(c_num);//将序号转化为int型
	int count = 1;
	LinkNode* current = first;
	LinkNode* record = current;
	while (count <= i_num)
	{
		record = current;
		current = current->link;
		count++;
	}
	/*LinkNode* temp = current;*/
	record->link = current->link;
	delete current;
}

/*请在此处添加在单链表中删除所有指定数据的代码*/
void linklist::Delallwanted()   //删除所有指定内容
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_edit.GetWindowText(str);//str接受m_edit的值
	int del = _ttoi(str);//转换为int型并存储
	int selected = false;
	LinkNode* current = first;
	LinkNode* record = current;
	while (current != NULL)
	{
		if (current->data == del)
		{
			LinkNode* temp = current;
			record->link = temp->link;
			current = record;
			delete temp;
			selected = true;
			
		}
		record = current;//记录current上次位置
		current = current->link;
	}
	if(selected == false)
	MessageBox(TEXT("不存在该值"));
}

/*请在此处添加将单链表中元素顺序逆置的代码*/
void linklist::Reverse()   //元素逆置
{
	// TODO: 在此添加控件通知处理程序代码
	LinkNode* current = first->link;//指向当前位置
	LinkNode* pre = NULL;//指向前一个位置
	while (current != NULL)
	{
		LinkNode* next = current->link;//指向后一个位置
		current->link = pre;
		pre = current;
		current = next;
	}
	first->link = pre;
}


void linklist::Show()   //显示
{/*请在此处添加将单链表中元素显示在列表控件m_list中的代码*/
	// TODO: 在此添加控件通知处理程序代码
	m_list.DeleteAllItems();	//清空所有表项
	CString num, str;
	int i = 1;
	LinkNode* current = first->link;
	while (current != NULL)
	{
		num.Format(TEXT("%d"), i);//序号转换为CString
		str.Format(TEXT("%d"), current->data);//数据转化为CString
		m_list.InsertItem(i - 1, num);
		m_list.SetItemText(i - 1, 1, str);
		current = current->link;
		i++;
	}
}

/*
请在此处添加在单链表的第一个指定数据后插入指定的元素的代码
例如  原链表为  1 5 2 5 3 5 4 5
要求在5后面插入5
则执行完该段代码后的链表为1 5 5 2 5 3 5 4 5
*/
void linklist::Insafterawanted()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_edit.GetWindowText(str);//str接受m_edit的值
	//将str按空格分割，存储到CString类型的动态数组里
	CArray<CString, CString>strArray;  //定义一个CString类型的动态数组，用来存取CString类型对象。
	strArray.Add(str.Left(str.Find(TEXT(" "))));//找到空格的索引，截取空格左边的字符串,并将它添加到strArray动态数组中。
	str.Delete(0, strArray[0].GetLength() + 1);//返回删除空格和其左边的字符串的得到的新字符串。
	strArray.Add(str);//最后加上经过最终删除后剩下的字符串；
	//strArray[0]为指定数据,strArray[1]为插入数据
	int target_num = _ttoi(strArray[0]);
	int insert_num = _ttoi(strArray[1]);
	LinkNode* current = first;
	while (current != NULL)
	{
		if(target_num == current->data)
		{
			break;
		}
		current = current->link;
	}
	if (current == NULL)
	{
		MessageBox(TEXT("内容不存在！"));//异常处理
		return;
	}
	LinkNode* newNode = new LinkNode(insert_num);
	newNode->link = current->link;
	current->link = newNode;
}

/*
请在此处添加在单链表的每一个指定数据后插入指定的元素的代码
例如  原链表为  1 5 2 5 3 5 4 5
要求在5后面插入5
则执行完该段代码后的链表为1 5 5 2 5 5 3 5 5 4 5 5 
*/
void linklist::Insafterallwanted()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_edit.GetWindowText(str);//str接受m_edit的值
	//将str按空格分割，存储到CString类型的动态数组里
	CArray<CString, CString>strArray;  //定义一个CString类型的动态数组，用来存取CString类型对象。
	strArray.Add(str.Left(str.Find(TEXT(" "))));//找到空格的索引，截取空格左边的字符串,并将它添加到strArray动态数组中。
	str.Delete(0, strArray[0].GetLength() + 1);//返回删除空格和其左边的字符串的得到的新字符串。
	strArray.Add(str);//最后加上经过最终删除后剩下的字符串；
	//strArray[0]为指定数据,strArray[1]为插入数据
	int target_num = _ttoi(strArray[0]);
	int insert_num = _ttoi(strArray[1]);
	LinkNode* current = first;
	bool selected = false;//判断是否存在指定数据
	while (current != NULL)
	{
		if (target_num == current->data)
		{
            LinkNode* newNode = new LinkNode(insert_num);
			newNode->link = current->link;
			current->link = newNode;
			selected = true;
		}
		current = current->link;
	}
	if (selected == false)
	{
		MessageBox(TEXT("内容不存在！"));//异常处理
		return;
	}
	
}

/*
请在此处添加将单链表中的重复数据删除的代码
例如  原链表为  1 5 5 2 5 3 6 6 6 2 5 4 5 4 4
则执行完该段代码后的链表为1 5 2 3 6 4
*/
void linklist::Delrepeat()
{
	// TODO: 在此添加控件通知处理程序代码
	LinkNode* q = first->link;
	while (q != NULL)
	{
		LinkNode* p = q;
		while (p->link != NULL)
		{
			if (p->link->data == q->data)
			{
				LinkNode* r = p->link;
				p->link = r->link;
				delete r;
			}
			else
			{
			p = p->link;
			}
		}
		q = q->link;
	}
}
