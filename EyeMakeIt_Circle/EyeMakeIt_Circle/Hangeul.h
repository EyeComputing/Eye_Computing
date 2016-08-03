#pragma once

#define		KEY_CODE_SPACE			-1		// ����
#define		KEY_CODE_ENTER			-2		// ��������
#define		KEY_CODE_BACKSPACE		-3		// �����

class Hangeul
{
public:
	Hangeul();
	~Hangeul();

public:
	void	Clear();
	wchar_t SetHangeulCode(int code);
	wchar_t ingWord;
	CString completeText;

private:
	enum HAN_STATUS
	{
		HS_FIRST = 0,
		HS_FIRST_V,
		HS_FIRST_C,
		HS_MIDDLE_STATE,
		HS_END,
		HS_END_STATE,
		HS_END_EXCEPTION
	};

	wchar_t completeWord;

	int nowState;			// ���� ����
	int now_Phonemez[5];	// �ʼ�,�߼�,����,������1,������2


	// ��ȯ 
	int			ToInitial(int nKeyCode);	// �ʼ�����
	int			ToFinal(int nKeyCode);		// ��������


	// ���� 
	void		DecomposeConsonant();		// ��������


	// �ռ� 
	BOOL		MixInitial(int nKeyCode);	// �ʼ��ռ�
	BOOL		MixFinal(int nKeyCode);		// �����ռ�

	BOOL		MixVowel(int * nCurCode, int nInCode);	// �����ռ�


	// ����(�ѱۿϼ�) 
	wchar_t		CombineHangle(int cho, int jung, int jong);
	wchar_t		CombineHangle(int status);
	void		CombineIngWord(int status);

	int			DownGradeIngWordStatus(wchar_t word);	//���� ���� ���� ���߱�

};

