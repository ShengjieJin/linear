#pragma once


// linklist 对话框

class LinkNode//结点类定义
{
	friend class linklist;
public:
	LinkNode(LinkNode* ptr = NULL) :link(ptr) {}//仅初始化指针
	LinkNode(const int& item, LinkNode* ptr = NULL) :data(item), link(ptr) {}//初始化数据与指针
private:
	int data;//数据元素域
	LinkNode* link;//链指针域
};


class linklist : public CDialogEx
{
	DECLARE_DYNAMIC(linklist)

public:
	linklist(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~linklist();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	CListCtrl m_list;
	afx_msg void CreateLinklist();
	afx_msg void Push_back();
	afx_msg void Instowantdpos();
	afx_msg void Delwanted();
	afx_msg void Delwantedpos();
	afx_msg void Delallwanted();
	afx_msg void Reverse();
	afx_msg void Show();
	afx_msg void Insafterawanted();
	afx_msg void Insafterallwanted();
	afx_msg void Delrepeat();

protected:
	LinkNode* first = new LinkNode;//头指针
};
