#pragma once
class IFastString
{
public:
	virtual void Delete() = 0;
	virtual int Length() const = 0;
	virtual int Find(const char* psz) const = 0;
};


extern "C" __declspec(dllimport) IFastString * CreateFastString(const char* psz);


class FastString : public IFastString
{
public:
	FastString(const char* psz);
	~FastString();
	void Delete();
	int Length() const;
	int Find(const char* psz) const;

private:
	char* m_psz;
	const int m_cch;
};