#pragma once

struct Buff
{
public:
	float dmgIncrease = 0;
	float atkSpeed = 0;
	float moveSpeed = 0;
	float maxHP = 0;
	float healPerSecond = 0;
	float expGainRate = 0;
	float itemGainRange = 0;

public:
	Buff operator+(Buff buff)
	{
		Buff tmp;
		tmp.dmgIncrease = dmgIncrease + buff.dmgIncrease;
		tmp.atkSpeed = atkSpeed + buff.atkSpeed;
		tmp.moveSpeed = moveSpeed + buff.moveSpeed;
		tmp.maxHP = maxHP + buff.maxHP;
		tmp.healPerSecond = healPerSecond + buff.healPerSecond;
		tmp.expGainRate = expGainRate + buff.expGainRate;

		return tmp;
	}

};

class Equipment
{
public:
	Equipment(wstring filePath, string key);
	virtual ~Equipment() = 0;

	void Render();

protected:
	vector<Frame*> icon;
	string key;
	int level = 1;
};