// RichManDoc.cpp : CRichManDoc ���ʵ��
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


// CRichManDoc ����/����

CRichManDoc::CRichManDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CRichManDoc::~CRichManDoc()
{
}

BOOL CRichManDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CRichManDoc ���л�

void CRichManDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CRichManDoc ���

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


// CRichManDoc ����
