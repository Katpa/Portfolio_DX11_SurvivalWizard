#pragma once

class Actor : public AnimObject
{
protected:
	enum State
	{
		IDLE_L,
		IDLE_R,
		MOVE_L,
		MOVE_R,
		TAKEHIT_L,
		TAKEHIT_R,
		DEAD
	};

public:
	Actor();
	~Actor();

	virtual void Update() = 0;
	virtual void Render() = 0;

	void TakeHit(float dmg);

	float ReturnDepth() { return bodyCollider->GlobalPosition().y; }
	RectCollider* ReturnCollider() { return bodyCollider; }

protected:
	void SetAnim(State _state);

private:
	virtual void SetClip() = 0;
	virtual void Move() = 0;
	virtual void Attack() = 0;

protected:
	float curHP = 0;
	float maxHP = 0;
	float moveSpeed = 0;
	float curAtkRate = 0;
	float atkRate = 0;

	bool isRight = false;
	Vector2 direction = {};

	State state;

	RectCollider* bodyCollider;

	//DMG 정보는 총알이 갖고 있는걸로하고
};