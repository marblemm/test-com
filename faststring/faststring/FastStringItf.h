#pragma once
class __declspec(dllexport)  FastStringItf
{
public:
	FastStringItf(const char* psz);
	~FastStringItf();
	int Length() const;
	int Find(const char* psz) const;
private:
	class FastString;
	FastString* m_pThis;

};

