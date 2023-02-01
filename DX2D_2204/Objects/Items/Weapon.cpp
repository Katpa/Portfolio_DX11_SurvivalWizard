#include "Framework.h"

Weapon::Weapon(wstring filePath, string key, float dmg, float coolTime, float fireRate, int fireCount)
	:Equipment(filePath, key), dmg(dmg), coolTime(CoolTime(coolTime)), gun(Gun(fireRate))
{
	gun.totalCount = fireCount;
}

void Weapon::Update()
{
	coolTime.curTime -= DELTA;
	if (coolTime.curTime < 0)
	{
		coolTime.curTime += coolTime.fixedTime;
		isFire = true;
	}

	if (isFire)
	{
		Fire();
	}
}

void Weapon::Fire()
{
}