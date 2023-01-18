#include "Framework.h"

Weapon::Weapon(wstring filePath, string key, float dmg, float coolTime, int fireCount)
	:Equipment(filePath, key), dmg(dmg), defaultCoolTime(coolTime), fireCount(fireCount)
{
}

void Weapon::Update()
{
	curCoolTime -= DELTA;
	if (curCoolTime < 0)
	{
		curCoolTime += coolTime;
		//Fire();
	}
}

void Weapon::SetCoolTime(float rate)
{
	coolTime = defaultCoolTime * (1.0f - rate);
	curCoolTime = 0;
}

void Weapon::Fire()
{
	for (int i = 0; i < fireCount; i++)
	{
		//MISSILE->Fire(key, dmgFactor);
		//목표 위치
	}

}
