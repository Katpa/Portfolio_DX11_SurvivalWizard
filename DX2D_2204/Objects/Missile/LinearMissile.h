#pragma once

class LinearMissile : public Missile
{
public:
	LinearMissile(MissileData data);
	LinearMissile(float speed, float dmg, wstring filePath, bool isCircle, int animLength, string boomVFX);
	~LinearMissile();

	virtual void Update() override;
	virtual void Render() override;

	virtual void Fire(Vector2 curPos, Vector2 direction, bool isPlayer, float dmgFactor = 0.0f) override;
	virtual void Boom() override;

private:
	virtual void SetAnim(wstring filePath, int animLength, bool isCircle) override;
	virtual void Move() override;
};