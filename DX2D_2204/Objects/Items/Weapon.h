#pragma once

class Weapon : public Equipment
{
private:
	const float defaultCoolTime;

public:
	Weapon(Type type, wstring filePath, float dmg, float coolTime);
	virtual ~Weapon() = 0;

	virtual void Update() = 0;
	virtual void Render() = 0;

	void Fire();

private:
	void SetCoolTime(float factor) { coolTime = defaultCoolTime * factor; }

private:
	float dmg;
	float coolTime;
	float remainTime;

	vector<Missile*> missiles;

	//파티클 넣어야함
};