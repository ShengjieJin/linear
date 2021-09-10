// seqlist.cpp: 实现文件
//


/*
此文件为顺序表演示的对话框实现文件
此文件为顺序表演示的对话框实现文件
此文件为顺序表演示的对话框实现文件
此文件为顺序表演示的对话框实现文件
此文件为顺序表演示的对话框实现文件
*/


#include "pch.h"
#include "linear.h"
#include "seqlist.h"
#include "afxdialogex.h"
#include<string>
#include<sstream>
// seqlist 对话框

IMPLEMENT_DYNAMIC(seqlist, CDialogEx)

seqlist::seqlist(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	
}

seqlist::~seqlist()
{
}


/*此处为当前对话框的初始化代码*/
void seqlist::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_LIST1, m_list);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0, _T("序号"), 0, 100);
	m_list.InsertColumn(1, _T("值"), 0, 100);
	//若有其他内容需要初始化可在此添加额外代码

}


BEGIN_MESSAGE_MAP(seqlist, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &seqlist::CreateSeqlist)
	ON_BN_CLICKED(IDC_BUTTON2, &seqlist::Push_back)
	ON_BN_CLICKED(IDC_BUTTON3, &seqlist::Inswanted)
	ON_BN_CLICKED(IDC_BUTTON4, &seqlist::Delwanted)
	ON_BN_CLICKED(IDC_BUTTON7, &seqlist::Delwantedpos)
	ON_BN_CLICKED(IDC_BUTTON8, &seqlist::Delallwanted)
	ON_BN_CLICKED(IDC_BUTTON5, &seqlist::Reverse)
	ON_BN_CLICKED(IDC_BUTTON6, &seqlist::Show)
	ON_BN_CLICKED(IDC_BUTTON9, &seqlist::Insafterawanted)
	ON_BN_CLICKED(IDC_BUTTON10, &seqlist::Insafterallwanted)
END_MESSAGE_MAP()


// seqlist 消息处理程序

/*请在此处添加从编辑框控件m_edit中读取数据并创建目标顺序表的代码*/
void seqlist::CreateSeqlist()   //创建顺序表
{
	// TODO: 在此添加控件通知处理程序代码

}

/*请在此处添加在顺序表最后添加元素的代码*/
void seqlist::Push_back()  //添加元素
{
	// TODO: 在此添加控件通知处理程序代码
	
}

/*请在此处添加在顺序表指定位置添加元素的代码*/
void seqlist::Inswanted()   //插入元素
{
	// TODO: 在此添加控件通知处理程序代码
	
}

/*
请在此处添加在顺序表中删除最前面的指定数据的代码
例如  原链表为  1 5 2 5 3 5 4 5
要求删除5
则执行完该段代码后的链表为1 2 5 3 5 4 5
*/
void seqlist::Delwanted()   //删除指定内容
{
	// TODO: 在此添加控件通知处理程序代码
	
}

/*请在此处添加在顺序表中删除指定位置的代码*/
void seqlist::Delwantedpos()    //删除指定位置
{
	// TODO: 在此添加控件通知处理程序代码
	
}

/*
请在此处添加在顺序表中删除所有指定数据的代码
例如  原链表为  1 5 2 5 3 5 4 5
要求删除5
则执行完该段代码后的链表为1 2 3 4
*/
void seqlist::Delallwanted()    //删除所有指定内容
{
	// TODO: 在此添加控件通知处理程序代码


}

/*请在此处添加将顺序表中元素顺序逆置的代码*/
void seqlist::Reverse()    //元素逆置
{
	// TODO: 在此添加控件通知处理程序代码
	
}

/*请在此处添加将顺序表中元素显示在列表控件m_list中的代码*/
void seqlist::Show()    //显示
{
	// TODO: 在此添加控件通知处理程序代码
	

}

/*
请在此处添加在单链表的第一个指定数据后插入指定的元素的代码
例如  原链表为  1 5 2 5 3 5 4 5
要求在5后面插入5
则执行完该段代码后的链表为1 5 5 2 5 3 5 4 5
*/
void seqlist::Insafterawanted()
{
	// TODO: 在此添加控件通知处理程序代码
	
}

/*
请在此处添加在单链表的每一个指定数据后插入指定的元素的代码
例如  原链表为  1 5 2 5 3 5 4 5
要求在5后面插入5
则执行完该段代码后的链表为1 5 5 2 5 5 3 5 5 4 5 5
*/
void seqlist::Insafterallwanted()
{
	// TODO: 在此添加控件通知处理程序代码

}
