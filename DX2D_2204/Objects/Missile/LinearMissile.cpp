#include "Framework.h"

LinearMissile::LinearMissile(MissileData data)
	:Missile(data)
{
}

LinearMissile::LinearMissile(float speed, float dmg, wstring filePath, bool isCircle, int animLength, string boomVFX)
	:Missile(speed, dmg, filePath, isCircle, animLength, boomVFX)
{
}

LinearMissile::~LinearMissile()
{
	delete collider;
}

void LinearMissile::Fire(Vector2 curPos, Vector2 direction, bool isPlayer, float dmgFactor = 0.0f)
{
	localPosition = curPos;
	this->direction = direction;
	this->isPlayer = isPlayer;
	this->dmgFactor = dmgFactor;
	isActive = true;
}

void LinearMissile::Boom()
{
	isActive = false;
	lifeTime = 0;
	FX->Play(boomVFX, GlobalPosition());
}

void LinearMissile::SetAnim(wstring filePath, int animLength, bool isCircle)
{
	Texture* texture = Texture::Add(filePath);
	Vector2 frameSize = texture->GetSize() / Vector2(animLength, 1);
	
	vector<Frame*> frames;
	for (int i = 0; i < animLength; i++)
	{
		frames.push_back(new Frame(filePath, frameSize.x * i, 0, frameSize.x, frameSize.y));
	}
	clips[0] = new Clip(frames);
	curClip = clips[0];

	SetCollider(frameSize, isCircle);
}

void LinearMissile::Move()
{
	Position() += direction * speed;
	Rotation().x = acos(direction.x);
}