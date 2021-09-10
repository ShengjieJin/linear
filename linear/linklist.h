#pragma once


// linklist 对话框


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
};
