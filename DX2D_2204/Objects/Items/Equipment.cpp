#include "Framework.h"

Equipment::Equipment(Type type, wstring filePath)
	:type(type), image(new Quad(filePath)), icon(new Quad(filePath))
{
	icon->Scale() *= 0.5f;
}
