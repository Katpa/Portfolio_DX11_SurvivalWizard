#include "Framework.h"

Weapon::Weapon(Type type, wstring filePath, float dmg, float coolTime)
	:Equipment(type, filePath), dmg(dmg), defaultCoolTime(coolTime)
{
}

void Weapon::Fire()
{
	remainTime -= DELTA;
	if (remainTime < 0)
	{
		remainTime = coolTime;
		//for (Missile* missile : missiles)
		//{
		//	if (missile->Active()) continue;
		//
		//	missile->Fire();
		//  break;
		//}
	}

}
