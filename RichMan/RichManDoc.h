// RichManDoc.h : CRichManDoc ��Ľӿ�
//


#pragma once


class CRichManDoc : public CDocument
{
protected: // �������л�����
	CRichManDoc();
	DECLARE_DYNCREATE(CRichManDoc)

// ����
public:


// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CRichManDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


