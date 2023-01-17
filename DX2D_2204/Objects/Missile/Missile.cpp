#include "Framework.h"

Missile::Missile(MissileData data)
	:speed(data.speed), dmg(data.dmg), boomVFX(data.boomVFX)
{
	isActive = false;
	SetAnim(data.filePath, data.animLength, data.isCircle);
}

Missile::Missile(float speed, float dmg, wstring filePath, bool isCircle, int animLength, string boomVFX)
	:AnimObject(), speed(speed), dmg(dmg), boomVFX(boomVFX)
{
	isActive = false;
	SetAnim(filePath, animLength, isCircle);
}

void Missile::Update()
{
	Move();
	AnimObject::Update();
}

void Missile::Render()
{
	AnimObject::Render();
}

void Missile::SetCollider(Vector2 size, bool isCircle)
{
	if (isCircle)
		collider = new CircleCollider((size.x + size.y) / 2);
	else
		collider = new RectCollider(size);

	collider->SetParent(this);
}

void Missile::LifeTimer()
{
	lifeTime += DELTA;

	if (lifeTime > MISSILE_LIFE)
	{
		lifeTime -= MISSILE_LIFE;
		Boom();
	}
}
