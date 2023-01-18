#include "Framework.h"

Accessary::Accessary(wstring filePath, string key, Buff buff)
	:Equipment(filePath, key), buff(buff)
{
}

Accessary::~Accessary()
{
}
