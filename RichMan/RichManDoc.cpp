// RichManDoc.cpp : CRichManDoc 类的实现
//

#include "stdafx.h"
#include "RichMan.h"

#include "RichManDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRichManDoc

IMPLEMENT_DYNCREATE(CRichManDoc, CDocument)

BEGIN_MESSAGE_MAP(CRichManDoc, CDocument)
END_MESSAGE_MAP()


// CRichManDoc 构造/析构

CRichManDoc::CRichManDoc()
{
	// TODO: 在此添加一次性构造代码

}

CRichManDoc::~CRichManDoc()
{
}

BOOL CRichManDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CRichManDoc 序列化

void CRichManDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CRichManDoc 诊断

#ifdef _DEBUG
void CRichManDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRichManDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRichManDoc 命令
