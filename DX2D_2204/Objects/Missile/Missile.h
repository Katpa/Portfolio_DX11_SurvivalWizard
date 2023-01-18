#pragma once

#define MISSILE_LIFE 5.0f

class Missile : public AnimObject
{
public:
	Missile(MissileData data);
	Missile(float speed, float dmg, wstring filePath, bool isCircle, int animLength, string boomVFX);
	virtual ~Missile() = 0;

	virtual void Update();
	virtual void Render();

	virtual void Fire(Vector2 curPos, Vector2 direction, bool isPlayer, float dmgFactor = 0.0f) = 0;
	virtual void Boom() = 0;

	float ReturnDMG() { return dmg * (1.0f + dmgFactor); }
	bool IsPlayer() { return isPlayer; }
	Collider* ReturnCollider() { return collider; }

protected:
	void SetCollider(Vector2 size, bool isCircle);

private:
	virtual void SetAnim(wstring filePath, int animLength, bool isCircle) {};
	virtual void Move() = 0;

	void LifeTimer();
	
protected:
	bool isPlayer = false;
	float speed;
	float dmg;
	float dmgFactor;
	Vector2 direction;
	Collider* collider;

	float lifeTime;

	string boomVFX;

	//터질떄의 파티클 넣어야함
};