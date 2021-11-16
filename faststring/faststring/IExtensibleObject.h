#pragma once
class IExtensibleObject
{
public:
	virtual void* Dynamic_Cast(const char* pszType) = 0;
	virtual void Delete() = 0;
};

class IFastString : public IExtensibleObject
{
public:
	virtual int Length() const = 0;
	virtual int Find(const char* psz) const = 0;
};

class IPersistentObject : public IExtensibleObject
{
public:
	virtual bool Load(const char* pszFileName) = 0;
	virtual bool Save(const char* pszFileName) = 0;
};

extern "C" __declspec(dllimport) IFastString * CreateFastString(const char* psz);

void f()
{
	IFastString* pfs = 0;
	IPersistentObject* ppo = 0;
	pfs = CreateFastString("hello world");
	if (pfs)
	{
		ppo = (IPersistentObject*)pfs->Dynamic_Cast("IPersistentObject");
		if (!ppo)
		{
			pfs->Delete();
		}
		else
		{
			ppo->Save("d:\\test.txt");
			ppo->Delete();
		}
	}
}

class FastString : public IFastString
	, public IPersistentObject
{
public:
	FastString(const char* psz);
	~FastString();
	void* Dynamic_Cast(const char* pszType);
	void Delete();
	int Length() const;
	int Find(const char* psz) const;

	bool Load(const char* pszFileName);
	bool Save(const char* pszFileName);
private:
	char* m_psz;
	const int m_cch;
};

