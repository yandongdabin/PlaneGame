// GameDoc.h : CGameDoc ��Ľӿ�
//


#pragma once


class CGameDoc : public CDocument
{
protected: // �������л�����
	CGameDoc();
	DECLARE_DYNCREATE(CGameDoc)

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
	virtual ~CGameDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


