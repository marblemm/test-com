#pragma once
class FastString
{
public:
	FastString(const char* psz);
	~FastString();
	int Length() const;
	int Find(const char* psz) const;

private:
	char* m_psz;
};

