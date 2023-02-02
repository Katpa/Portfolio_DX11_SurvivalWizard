#include "Framework.h"

Accessory::Accessory(wstring filePath, string key, Buff buff)
	:Equipment(filePath, key), buff(buff)
{
}

Accessory::~Accessory()
{
}

void Accessory::SetPower()
{
	//AccessoryData data = ataManager::Get()->LoadAccessoryData(key, level);
}
