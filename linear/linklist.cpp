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
// linklist 对话框

IMPLEMENT_DYNAMIC(linklist, CDialogEx)

linklist::linklist(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
	
}

linklist::~linklist()
{
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

}

/*请在此处添加在单链表最后添加元素的代码*/
void linklist::Push_back()   //添加元素
{
	// TODO: 在此添加控件通知处理程序代码
	
}

/*请在此处添加在单链表指定位置添加元素的代码*/
void linklist::Instowantdpos()   //插入元素
{
	// TODO: 在此添加控件通知处理程序代码
	
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
	
}

/*请在此处添加在单链表中删除指定位置的代码*/
void linklist::Delwantedpos()   //删除指定位置
{
	// TODO: 在此添加控件通知处理程序代码
	
}

/*请在此处添加在单链表中删除所有指定数据的代码*/
void linklist::Delallwanted()   //删除所有指定内容
{
	// TODO: 在此添加控件通知处理程序代码
	
}

/*请在此处添加将单链表中元素顺序逆置的代码*/
void linklist::Reverse()   //元素逆置
{
	// TODO: 在此添加控件通知处理程序代码
	
}


void linklist::Show()   //显示
{/*请在此处添加将单链表中元素显示在列表控件m_list中的代码*/
	// TODO: 在此添加控件通知处理程序代码
	
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

}

/*
请在此处添加将单链表中的重复数据删除的代码
例如  原链表为  1 5 5 2 5 3 6 6 6 2 5 4 5 4 4
则执行完该段代码后的链表为1 5 2 3 6 4
*/
void linklist::Delrepeat()
{
	// TODO: 在此添加控件通知处理程序代码
	
}
