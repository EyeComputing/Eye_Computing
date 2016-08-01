#pragma once
class Hangeul
{
public:
	Hangeul();
	~Hangeul();

public:
	wchar_t SetHangeulCode(int code);
	wchar_t ingWord;
	
	CString completeText;
	
private:
	wchar_t completeWord;
	int nowState;

};

