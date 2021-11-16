#pragma once
class IFastString
{
public:
	virtual int Length() const = 0;
	virtual int Find(const char* psz) const = 0;
};

class FastString : public IFastString
{
public:
	FastString(const char* psz);
	~FastString();
	int Length() const;
	int Find(const char* psz) const;

private:
	char* m_psz;
	const int m_cch;
};

extern "C" IFastString * CreateFastString(const char* psz);
