#include "Framework.h"

Actor::Actor()
{
}

Actor::~Actor()
{
}

void Actor::TakeHit(float dmg)
{
	curHP -= dmg;
	if (curHP < 0.1f)
		SetAnim(DEAD);
}

void Actor::SetAnim(State _state)
{
	if (state == _state) return;

	curClip->Stop();
	state = _state;
	curClip = clips[state];
	curClip->Play();
}
