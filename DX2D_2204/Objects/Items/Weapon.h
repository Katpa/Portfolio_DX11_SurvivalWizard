#pragma once

struct CoolTime
{
public:
	CoolTime(float defaultTime)
		:defaultTime(defaultTime)
	{
		fixedTime = defaultTime;
	}

	void Set(float rate)
	{
		fixedTime = defaultTime * (1.0f - rate);
	}

	const float defaultTime;
	float fixedTime = 0;
	float curTime = 0;
};

struct Gun
{
public:
	Gun(float defaultRate)
		:defaultRate(defaultRate)
	{

	}

	void SetCount(int cnt)
	{
		totalCount = cnt;
	}

	int totalCount;
	int curCount;
	const float defaultRate;
	float curRate;
};

class Weapon : public Equipment
{
public:
	Weapon(wstring filePath, string key, float dmg, float coolTime, float fireRate, int fireCount);
	virtual ~Weapon() = 0;

	void Update();

	void SetCoolTime(float rate) { coolTime.Set(rate); }
	void Fire();

private:
	virtual void SetPower() override;

private:
	bool isFire = false;

	float dmg;

	CoolTime coolTime;
	Gun gun;

	//vector<Missile*> missiles;

	//파티클 넣어야함
};