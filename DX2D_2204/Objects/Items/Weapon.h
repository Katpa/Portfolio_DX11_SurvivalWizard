#pragma once

class Weapon : public Equipment
{
private:
	const float defaultCoolTime;

public:
	Weapon(wstring filePath, string key, float dmg, float coolTime, int fireCount);
	virtual ~Weapon() = 0;

	void Update();

	void SetCoolTime(float rate);
	void Fire();

private:
	float dmg;
	float coolTime;
	float curCoolTime;
	int fireCount;

	//vector<Missile*> missiles;

	//파티클 넣어야함
};