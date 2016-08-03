#pragma once

#define		KEY_CODE_SPACE			-1		// 띄어쓰기
#define		KEY_CODE_ENTER			-2		// 내려쓰기
#define		KEY_CODE_BACKSPACE		-3		// 지우기

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

	int nowState;			// 조합 상태
	int now_Phonemez[5];	// 초성,중성,종성,곁자음1,곁자음2


	// 변환 
	int			ToInitial(int nKeyCode);	// 초성으로
	int			ToFinal(int nKeyCode);		// 종성으로


	// 분해 
	void		DecomposeConsonant();		// 자음분해


	// 합성 
	BOOL		MixInitial(int nKeyCode);	// 초성합성
	BOOL		MixFinal(int nKeyCode);		// 종성합성

	BOOL		MixVowel(int * nCurCode, int nInCode);	// 모음합성


	// 조합(한글완성) 
	wchar_t		CombineHangle(int cho, int jung, int jong);
	wchar_t		CombineHangle(int status);
	void		CombineIngWord(int status);

	int			DownGradeIngWordStatus(wchar_t word);	//조합 문자 상태 낮추기

};

