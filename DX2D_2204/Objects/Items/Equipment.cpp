#include "Framework.h"

Equipment::Equipment(wstring filePath, string key)
	:key(key)
{
	Texture* texture = Texture::Add(filePath);
	Vector2 cutSize = texture->GetSize() / Vector2(EQUIPMENT_MAX_LEVEL, 1);

	for (int i = 0; i < EQUIPMENT_MAX_LEVEL; i++)
	{
		icon[i] = new Frame(filePath, cutSize.x * i, 0, cutSize.x, cutSize.y);
	}
}

void Equipment::Render()
{
	icon[level - 1]->Render();
}