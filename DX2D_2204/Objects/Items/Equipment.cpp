#include "Framework.h"

Equipment::Equipment(wstring filePath, string key)
	:key(key)
{
	icon = new Quad(filePath);
}

void Equipment::Render()
{
	icon->Render();
}

void Equipment::PowerUp(int addLevel)
{
	level += addLevel;
	if (level > 10)
		level = 10;

	SetPower();
}
