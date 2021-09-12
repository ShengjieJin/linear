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
	delete[] data;
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

	//  DDX_Text(pDX, IDC_EDIT1, m_edit_v);
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
	if (last != -1) { MessageBox(TEXT("已经初始化！")); return; }
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


	//将CString动态数组里的数逐个存储到顺序表中
	for(int j = 0; j < i; j++)
	{
		last++;
        data[last] = _ttoi(strArray[j]);//转换为int型并存储
	}

    
	//num.Format(TEXT("%d"), last + 1);//序号转换为CString
	//m_list.InsertItem(last, num);
	//m_list.SetItemText(last, 1, str);
}

/*请在此处添加在顺序表最后添加元素的代码*/
void seqlist::Push_back()  //添加元素
{
	// TODO: 在此添加控件通知处理程序代码
	last++;
	CString str;
	m_edit.GetWindowText(str);//str接受m_edit的值
	data[last] = _ttoi(str);//转换为int型并存储
	//num.Format(TEXT("%d"), last + 1);//序号转换为CString
	//m_list.InsertItem(last, num);
	//m_list.SetItemText(last, 1, str);
}

/*请在此处添加在顺序表指定位置添加元素的代码*/
void seqlist::Inswanted()   //插入元素
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
	 if(selected == false)
			{
				MessageBox(TEXT("请选中插入行！"));
				return;
			}

	int i_num = _ttoi(c_num);//将序号转化为int型
	
	for (int i = last; i >= i_num - 1; i--)
	{
		data[i + 1] = data[i];//依次后移
	}
	CString str;
	m_edit.GetWindowText(str);//str接受m_edit的值
	data[i_num - 1] = _ttoi(str);//新值覆盖指定位置
	last++;
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
	CString str;
	m_edit.GetWindowText(str);//str接受m_edit的值
	int del = _ttoi(str);//转换为int型并存储
	int i = 0;
	for (; i <= last; i++)//搜索目标数据位置
	{
		if (data[i] == del) break;
	}
	if (i > last)
	{
		MessageBox(TEXT("该值不存在！"));
		return;
	}
	for (int j = i; j < last; j++)
	{
		data[j] = data[j + 1];
	}
	last--;
}

/*请在此处添加在顺序表中删除指定位置的代码*/
void seqlist::Delwantedpos()    //删除指定位置
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

	for (int i = i_num - 1; i < last; i++)
	{
		data[i] = data[i + 1];//依次前移
	}
	last--;
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
	CString str;
	m_edit.GetWindowText(str);//str接受m_edit的值
	int del = _ttoi(str);


	int i = 0, t = 0;
	int* n = new int[maxSize];//用于存储目标删除数据位置
	for (; i <= last; i++)//搜索目标删除数据位置
	{
		if (data[i] == del) { n[t] = i; t++; }
	}
	if (t == 0)
	{
		MessageBox(TEXT("目标删除数据不存在！"));
		return;
	}

	while (t > 0)
	{
		for (int j = n[t - 1]; j < last; j++)
		{
			data[j] = data[j + 1];//依次前移
		}
		last--;
		t--;
	}

}

/*请在此处添加将顺序表中元素顺序逆置的代码*/
void seqlist::Reverse()    //元素逆置
{
	// TODO: 在此添加控件通知处理程序代码
	int* newData =  new int[maxSize];
	for (int i = 0; i <= last; i++)
	{
		newData[i] = data[last - i];//逐一赋值
	}
	int* temp = data;
	data = newData;//改变指向
	delete[] temp;
}

/*请在此处添加将顺序表中元素显示在列表控件m_list中的代码*/
void seqlist::Show()    //显示
{
	// TODO: 在此添加控件通知处理程序代码
	m_list.DeleteAllItems();	//清空所有表项
	CString num, str;
	for (int i = 1; i <= last + 1; i++)
	{
		str.Format(TEXT("%d"), data[i - 1]);//数据转化为CString
		num.Format(TEXT("%d"), i);//序号转换为CString
		m_list.InsertItem(i - 1, num);
		m_list.SetItemText(i - 1, 1, str);
	}
	
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

	int i = 0;
	for (; i <= last; i++)//搜索目标数据位置
	{
		if (data[i] == target_num) break;
	}
	if (i > last)
	{
		MessageBox(TEXT("目标数据不存在！"));
		return;
	}

	if (last == maxSize - 1) return;
	for (int j = last; j > i; j--)
	{
		data[j + 1] = data[j];//依次后移
	}
	data[i + 1] = insert_num;
	last++;
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

	int i = 0, t = 0;
	int* n = new int[maxSize];//用于存储目标数据位置
	for (; i <= last; i++)//搜索目标数据位置
	{
		if (data[i] == target_num) { n[t] = i; t++; }
	}
	if (t == 0)
	{
		MessageBox(TEXT("目标数据不存在！"));
		return;
	}

	if (last == maxSize - 1) return;//表满
	while (t > 0)
	{
		for (int j = last; j >= n[t-1]; j--)
		{
			data[j + 1] = data[j];//依次后移
		}
		data[n[t - 1] + 1] = insert_num;
	last++;
	t--;
	}
	
}
