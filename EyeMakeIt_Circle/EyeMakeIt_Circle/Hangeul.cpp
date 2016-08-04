#include "stdafx.h"
#include "Hangeul.h"

const int BASE_CODE = 0xac00;		// 기초음성(가)
const int LIMIT_MIN = 0xac00;		// 음성범위 MIN(가)
const int LIMIT_MAX = 0xd7a3;		// 음성범위 MAX

// 음성 테이블
wchar_t SOUND_TABLE[68] =
{
	/* 초성 19자 0 ~ 18 */
	_T('ㄱ'), _T('ㄲ'), _T('ㄴ'), _T('ㄷ'), _T('ㄸ'),
	_T('ㄹ'), _T('ㅁ'), _T('ㅂ'), _T('ㅃ'), _T('ㅅ'),
	_T('ㅆ'), _T('ㅇ'), _T('ㅈ'), _T('ㅉ'), _T('ㅊ'),
	_T('ㅋ'), _T('ㅌ'), _T('ㅍ'), _T('ㅎ'),
	/* 중성 21자 19 ~ 39 */
	_T('ㅏ'), _T('ㅐ'), _T('ㅑ'), _T('ㅒ'), _T('ㅓ'),
	_T('ㅔ'), _T('ㅕ'), _T('ㅖ'), _T('ㅗ'), _T('ㅘ'),
	_T('ㅙ'), _T('ㅚ'), _T('ㅛ'), _T('ㅜ'), _T('ㅝ'),
	_T('ㅞ'), _T('ㅟ'), _T('ㅠ'), _T('ㅡ'), _T('ㅢ'),
	_T('ㅣ'),
	/* 종성 28자 40 ~ 67 */
	_T(' '), _T('ㄱ'), _T('ㄲ'), _T('ㄳ'), _T('ㄴ'),
	_T('ㄵ'), _T('ㄶ'), _T('ㄷ'), _T('ㄹ'), _T('ㄺ'),
	_T('ㄻ'), _T('ㄼ'), _T('ㄽ'), _T('ㄾ'), _T('ㄿ'),
	_T('ㅀ'), _T('ㅁ'), _T('ㅂ'), _T('ㅄ'), _T('ㅅ'),
	_T('ㅆ'), _T('ㅇ'), _T('ㅈ'), _T('ㅊ'), _T('ㅋ'),
	_T('ㅌ'), _T('ㅍ'), _T('ㅎ')
};


// 초성 합성 테이블
int MIXED_CHO_CONSON[14][3] =
{
	//{ 0, 0, 15 }, // ㄱ,ㄱ,ㅋ
	//{ 15, 0, 1 }, // ㅋ,ㄱ,ㄲ
	//{ 1, 0, 0 }, // ㄲ,ㄱ,ㄱ
	//
	//{ 3, 3, 16 }, // ㄷ,ㄷ,ㅌ
	//{ 16, 3, 4 }, // ㅌ,ㄷ,ㄸ
	//{ 4, 3, 3 }, // ㄸ,ㄷ,ㄷ
	//
	//{ 7, 7, 17 }, // ㅂ,ㅂ,ㅍ
	//{ 17, 7, 8 }, // ㅍ,ㅂ,ㅃ
	//{ 8, 7, 7 }, // ㅃ,ㅂ,ㅂ
	//
	//{ 9, 9, 10 }, // ㅅ,ㅅ,ㅆ
	//{ 10, 9, 9 }, // ㅆ,ㅅ,ㅅ
	//
	//{ 12, 12, 14 }, // ㅈ,ㅈ,ㅊ
	//{ 14, 12, 13 }, // ㅊ,ㅈ,ㅉ
	//{ 13, 12, 12 }  // ㅉ,ㅈ,ㅈ
};

// 초성,중성 모음 합성 테이블
int MIXED_VOWEL[5][3] = //[21][3]
{
	//{ 19, 19, 21 },	// ㅏ,ㅏ,ㅑ
	//{ 21, 19, 19 },	// ㅑ,ㅏ,ㅏ

	//{ 19, 39, 20 },	// ㅏ,ㅣ,ㅐ
	//{ 21, 39, 22 },	// ㅑ,ㅣ,ㅒ

	//{ 23, 23, 25 },	// ㅓ,ㅓ,ㅕ
	//{ 25, 23, 23 },	// ㅕ,ㅓ,ㅓ

	//{ 23, 39, 24 },	// ㅓ,ㅣ,ㅔ
	//{ 25, 39, 26 },	// ㅕ,ㅣ,ㅖ

	//{ 27, 27, 31 },	// ㅗ,ㅗ,ㅛ
	//{ 31, 27, 27 },	// ㅛ,ㅗ,ㅗ
	//{ 39, 40, 19 },	// l, ·, ㅏ
	//{ 27, 19, 28 },	// ㅗ,ㅏ,ㅘ
	//{ 27, 20, 29 },	// ㅗ,ㅐ,ㅙ

	//{ 27, 39, 30 },	// ㅗ,ㅣ,ㅚ

	//{ 32, 32, 36 },	// ㅜ,ㅜ,ㅠ
	//{ 36, 32, 32 },	// ㅠ,ㅜ,ㅜ

	//{ 32, 23, 33 },	// ㅜ,ㅓ,ㅝ
	//{ 32, 24, 34 },	// ㅜ,ㅔ,ㅞ

	//{ 32, 39, 35 },	// ㅜ,ㅣ,ㅟ

	//{ 39, 39, 37 },	// ㅣ,ㅣ,ㅡ
	//{ 37, 39, 38 },	// ㅡ,ㅣ,ㅢ
	//{ 38, 39, 39 }	// ㅢ,ㅣ,ㅣ
};

// 종성 합성 테이블
int MIXED_JONG_CONSON[11][3] = //[22][3]
{
	//{ 41, 41, 64 }, // ㄱ,ㄱ,ㅋ
	//{ 64, 41, 42 }, // ㅋ,ㄱ,ㄲ
	//{ 42, 41, 41 }, // ㄲ,ㄱ,ㄱ

	{ 41, 59, 43 }, // ㄱ,ㅅ,ㄳ

	{ 44, 62, 45 }, // ㄴ,ㅈ,ㄵ
	{ 45, 66, 46 }, // ㄴ,ㅎ,ㄶ

	//{ 47, 47, 65 }, // ㄷ,ㄷ,ㅌ
	//{ 65, 47, 47 }, // ㅌ,ㄷ,ㄷ

	{ 48, 41, 49 }, // ㄹ,ㄱ,ㄺ
	{ 48, 56, 50 }, // ㄹ,ㅁ,ㄻ

	{ 48, 57, 51 }, // ㄹ,ㅂ,ㄼ
	{ 51, 57, 54 }, // ㄼ,ㅂ,ㄿ

	{ 48, 59, 52 }, // ㄹ,ㅅ,ㄽ
	{ 48, 47, 53 }, // ㄹ,ㄷ,ㄾ	
	{ 48, 67, 55 }, // ㄹ,ㅎ,ㅀ

	//{ 57, 57, 66 }, // ㅂ,ㅂ,ㅍ
	//{ 66, 57, 57 }, // ㅍ,ㅂ,ㅂ

	{ 57, 59, 58 }, // ㅂ,ㅅ,ㅄ

	//{ 59, 59, 60 }, // ㅅ,ㅅ,ㅆ
	//{ 60, 59, 59 }, // ㅆ,ㅅ,ㅅ
	//
	//{ 62, 62, 63 }, // ㅈ,ㅈ,ㅊ
	//{ 63, 62, 62 }  // ㅊ,ㅈ,ㅈ
};

// 종성 분해 테이블
int DIVIDE_JONG_CONSON[13][3] =
{
	{ 41, 41, 42 }, // ㄱ,ㄱ,ㄲ
	{ 41, 59, 43 }, // ㄱ,ㅅ,ㄳ
	{ 44, 62, 45 }, // ㄴ,ㅈ,ㄵ
	{ 44, 67, 46 }, // ㄴ,ㅎ,ㄶ
	{ 48, 41, 49 }, // ㄹ,ㄱ,ㄺ
	{ 48, 56, 50 }, // ㄹ,ㅁ,ㄻ
	{ 48, 57, 51 }, // ㄹ,ㅂ,ㄼ
	{ 48, 66, 54 }, // ㄹ,ㅍ,ㄿ
	{ 48, 59, 52 }, // ㄹ,ㅅ,ㄽ
	{ 48, 65, 53 }, // ㄹ,ㅌ,ㄾ	
	{ 48, 67, 55 }, // ㄹ,ㅎ,ㅀ
	{ 57, 59, 58 }, // ㅂ,ㅅ,ㅄ
	{ 59, 59, 60 }  // ㅅ,ㅅ,ㅆ
};

Hangeul::Hangeul()
{
	Clear();
}

Hangeul::~Hangeul()
{
}



void Hangeul::Clear()
{
	nowState = HS_FIRST;
	completeText = _T("");
	ingWord = NULL;
	completeWord = NULL;
}

wchar_t Hangeul::SetHangeulCode(int nKeyCode)
{
	completeWord = NULL;

	// 특수키 입력
	if (nKeyCode < 0)
	{
		nowState = HS_FIRST;

		if (nKeyCode == KEY_CODE_SPACE) // 띄어쓰기
		{
			if (ingWord != NULL)
				completeText += ingWord;
			else
				completeText += _T(' ');

			ingWord = NULL;
		}
		else if (nKeyCode == KEY_CODE_ENTER) // 내려쓰기
		{
			if (ingWord != NULL)
				completeText += ingWord;

			completeText += _T("\r\n");

			ingWord = NULL;
		}
		else if (nKeyCode == KEY_CODE_BACKSPACE) // 지우기
		{
			if (ingWord == NULL)
			{
				if (completeText.GetLength() > 0)
				{
					if (completeText.Right(1) == _T("\n"))
						completeText = completeText.Left(completeText.GetLength() - 2);
					else
						completeText = completeText.Left(completeText.GetLength() - 1);
				}
			}
			else
			{
				nowState = DownGradeIngWordStatus(ingWord);
			}
		}

		return completeWord;
	}



	switch (nowState)
	{
	case HS_FIRST:
		// 초성
		now_Phonemez[0] = nKeyCode;
		ingWord = SOUND_TABLE[now_Phonemez[0]];
		nowState = nKeyCode > 18 ? HS_FIRST_C : HS_FIRST_V;
		break;

	case HS_FIRST_C:
		// 모음 + 모음
		if (nKeyCode > 18)	// 모음
		{
			if (MixVowel(&now_Phonemez[0], nKeyCode) == FALSE)
			{
				completeWord = SOUND_TABLE[now_Phonemez[0]];
				now_Phonemez[0] = nKeyCode;
			}
		}
		else				// 자음
		{
			completeWord = SOUND_TABLE[now_Phonemez[0]];
			now_Phonemez[0] = nKeyCode;
			nowState = HS_FIRST_V;
		}
		break;

	case HS_FIRST_V:
		// 자음 + 자음
		if (nKeyCode > 18)	// 모음
		{
			now_Phonemez[1] = nKeyCode;
			nowState = HS_MIDDLE_STATE;
		}
		else				// 자음
		{
			if (!MixInitial(nKeyCode))
			{
				completeWord = SOUND_TABLE[now_Phonemez[0]];
				now_Phonemez[0] = nKeyCode;
				nowState = HS_FIRST_V;
			}
		}
		break;

	case HS_MIDDLE_STATE:
		// 초성 + 모음 + 모음
		if (nKeyCode > 18)
		{
			if (MixVowel(&now_Phonemez[1], nKeyCode) == FALSE)
			{
				completeWord = CombineHangle(1);
				now_Phonemez[0] = nKeyCode;
				nowState = HS_FIRST_C;
			}
		}
		else
		{
			int jungCode = ToFinal(nKeyCode);

			if (jungCode > 0)
			{
				now_Phonemez[2] = jungCode;
				nowState = HS_END_STATE;
			}
			else
			{
				completeWord = CombineHangle(1);
				now_Phonemez[0] = nKeyCode;
				nowState = HS_FIRST;
			}
		}
		break;

	case HS_END:
		// 초성 + 중성 + 종성
		if (nKeyCode > 18)
		{
			completeWord = CombineHangle(1);
			now_Phonemez[0] = nKeyCode;
			nowState = HS_FIRST;
		}
		else
		{
			int jungCode = ToFinal(nKeyCode);
			if (jungCode > 0)
			{
				now_Phonemez[2] = jungCode;
				nowState = HS_END_STATE;
			}
			else
			{
				completeWord = CombineHangle(1);
				now_Phonemez[0] = nKeyCode;
				nowState = HS_FIRST;
			}
		}
		break;

	case HS_END_STATE:
		// 초성 + 중성 + 자음(종) + 자음(종)
		if (nKeyCode > 18)
		{
			completeWord = CombineHangle(1);

			now_Phonemez[0] = ToInitial(now_Phonemez[2]);
			now_Phonemez[1] = nKeyCode;
			nowState = HS_MIDDLE_STATE;
		}
		else
		{
			int jungCode = ToFinal(nKeyCode);
			if (jungCode > 0)
			{
				nowState = HS_END_EXCEPTION;

				if (!MixFinal(jungCode))
				{
					completeWord = CombineHangle(2);
					now_Phonemez[0] = nKeyCode;
					nowState = HS_FIRST_V;
				}
			}
			else
			{
				completeWord = CombineHangle(2);
				now_Phonemez[0] = nKeyCode;
				nowState = HS_FIRST_V;
			}
		}
		break;

	case HS_END_EXCEPTION:
		// 초성 + 중성 + 종성(곁자음)
		if (nKeyCode > 18)
		{
			DecomposeConsonant();
			now_Phonemez[1] = nKeyCode;
			nowState = HS_MIDDLE_STATE;
		}
		else
		{
			int jungCode = ToFinal(nKeyCode);
			if (jungCode > 0)
			{
				nowState = HS_END_EXCEPTION;

				if (!MixFinal(jungCode))
				{
					completeWord = CombineHangle(2);
					now_Phonemez[0] = nKeyCode;
					nowState = HS_FIRST_V;
				}
			}
			else
			{
				completeWord = CombineHangle(2);
				now_Phonemez[0] = nKeyCode;
				nowState = HS_FIRST_V;
			}
		}
		break;
	}

	// 현재 보이는 글자상태
	CombineIngWord(nowState);

	// 완성 문자열 만들기
	if (completeWord != NULL)
		completeText += TCHAR(completeWord);

	return completeWord;
}

// 초성으로 변환
int Hangeul::ToInitial(int nKeyCode)
{
	switch (nKeyCode)
	{
	case 41: return 0;	// ㄱ
	case 42: return 1;	// ㄲ
	case 44: return 2;	// ㄴ
	case 47: return 3;	// ㄷ
	case 48: return 5;	// ㄹ
	case 56: return 6;	// ㅁ
	case 57: return 7;	// ㅂ
	case 59: return 9;	// ㅅ
	case 60: return 10;	// ㅆ
	case 61: return 11;	// ㅇ
	case 62: return 12;	// ㅈ
	case 63: return 14;	// ㅊ
	case 64: return 15;	// ㅋ
	case 65: return 16;	// ㅌ
	case 66: return 17;	// ㅍ
	case 67: return 18;	// ㅎ
	}
	return -1;
}

// 종성으로 변환
int Hangeul::ToFinal(int nKeyCode)
{
	switch (nKeyCode)
	{
	case 0: return 41;	// ㄱ
	case 1: return 42;	// ㄲ
	case 2: return 44;	// ㄴ
	case 3: return 47;	// ㄷ
	case 5: return 48;	// ㄹ
	case 6: return 56;	// ㅁ
	case 7: return 57;	// ㅂ
	case 9: return 59;	// ㅅ
	case 10: return 60;	// ㅆ
	case 11: return 61;	// ㅇ
	case 12: return 62;	// ㅈ
	case 14: return 63;	// ㅊ
	case 15: return 64;	// ㅋ
	case 16: return 65;	// ㅌ
	case 17: return 66;	// ㅍ
	case 18: return 67;	// ㅎ
	}
	return -1;
}

// 자음분해
void Hangeul::DecomposeConsonant()
{
	int i = 0;
	if (now_Phonemez[3] > 40 || now_Phonemez[4] > 40)
	{
		do
		{
			if (DIVIDE_JONG_CONSON[i][2] == now_Phonemez[2])
			{
				now_Phonemez[3] = DIVIDE_JONG_CONSON[i][0];
				now_Phonemez[4] = DIVIDE_JONG_CONSON[i][1];

				completeWord = CombineHangle(3);
				now_Phonemez[0] = ToInitial(now_Phonemez[4]);
				return;
			}
		} while (++i< 13);
	}

	completeWord = CombineHangle(1);
	now_Phonemez[0] = ToInitial(now_Phonemez[2]);
}


// 초성합성
BOOL Hangeul::MixInitial(int nKeyCode)
{/*
 if (nKeyCode >= 19)
 return FALSE;

 int i = 0;
 do
 {
 if (MIXED_CHO_CONSON[i][0] == now_Phonemez[0] && MIXED_CHO_CONSON[i][1] == nKeyCode)
 {
 now_Phonemez[0] = MIXED_CHO_CONSON[i][2];
 return TRUE;
 }
 } while (++i < 14);
 */
	return FALSE;
}

// 종성합성
BOOL Hangeul::MixFinal(int nKeyCode)
{
	if (nKeyCode <= 40) return FALSE;

	int i = 0;
	do
	{
		if (MIXED_JONG_CONSON[i][0] == now_Phonemez[2] && MIXED_JONG_CONSON[i][1] == nKeyCode)
		{
			now_Phonemez[3] = now_Phonemez[2];
			now_Phonemez[4] = nKeyCode;
			now_Phonemez[2] = MIXED_JONG_CONSON[i][2];

			return TRUE;
		}
	} while (++i < 22);

	return FALSE;
}

// 모음합성
BOOL Hangeul::MixVowel(int * currentCode, int inputCode)
{
	int i = 0;
	do
	{
		if (MIXED_VOWEL[i][0] == *currentCode && MIXED_VOWEL[i][1] == inputCode)
		{
			*currentCode = MIXED_VOWEL[i][2];
			return TRUE;
		}
	} while (++i< 21);

	return FALSE;
}

// 한글조합
wchar_t Hangeul::CombineHangle(int cho, int jung, int jong)
{
	// 초성 * 21 * 28 + (중성 - 19) * 28 + (종성 - 40) + BASE_CODE;
	return BASE_CODE - 572 + jong + cho * 588 + jung * 28;
}

wchar_t Hangeul::CombineHangle(int status)
{
	switch (status)
	{
		//초성 + 중성
	case 1: return CombineHangle(now_Phonemez[0], now_Phonemez[1], 40);

		//초성 + 중성 + 종성
	case 2: return CombineHangle(now_Phonemez[0], now_Phonemez[1], now_Phonemez[2]);

		//초성 + 중성 + 곁자음01
	case 3: return CombineHangle(now_Phonemez[0], now_Phonemez[1], now_Phonemez[3]);
	}
	return ' ';
}

void Hangeul::CombineIngWord(int status)
{
	switch (nowState)
	{
	case HS_FIRST:
	case HS_FIRST_V:
	case HS_FIRST_C:
		ingWord = SOUND_TABLE[now_Phonemez[0]];
		break;

	case HS_MIDDLE_STATE:
	case HS_END:
		ingWord = CombineHangle(1);
		break;

	case HS_END_STATE:
	case HS_END_EXCEPTION:
		ingWord = CombineHangle(2);
		break;
	}
}

int Hangeul::DownGradeIngWordStatus(wchar_t word)
{
	int iWord = word;

	//초성만 있는 경우
	if (iWord < LIMIT_MIN || iWord > LIMIT_MAX)
	{
		ingWord = NULL;

		return HS_FIRST;
	}

	//문자코드 체계
	//iWord = firstWord * (21*28)
	//		+ middleWord * 28
	//		+ lastWord * 27
	//		+ BASE_CODE;
	//
	int totalWord = iWord - BASE_CODE;
	int iFirstWord = totalWord / 28 / 21;	//초성
	int iMiddleWord = totalWord / 28 % 21;	//중성
	int iLastWord = totalWord % 28;		//종성

	now_Phonemez[0] = iFirstWord; //초성저장

	if (iLastWord == 0)	//종성이 없는 경우
	{
		ingWord = SOUND_TABLE[now_Phonemez[0]];

		return HS_FIRST_V;
	}

	now_Phonemez[1] = iMiddleWord + 19; //중성저장

	iLastWord += 40;

	for (int i = 0; i < 13; i++)
	{
		if (iLastWord == DIVIDE_JONG_CONSON[i][2])
		{
			ingWord = CombineHangle(3);
			now_Phonemez[2] = DIVIDE_JONG_CONSON[i][0]; // 종성저장
			return HS_END_EXCEPTION;
		}
	}

	ingWord = CombineHangle(1);

	return HS_MIDDLE_STATE;
}

