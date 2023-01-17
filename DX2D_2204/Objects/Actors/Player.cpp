#include "Framework.h"

Player::Player()
{

	MISSILE->GetPlayer(this);
}

Player::~Player()
{
}

void Player::Update()
{
}

void Player::Render()
{
}

void Player::UIRender()
{
}

void Player::Control()
{
}

void Player::SetClip()
{
}

void Player::Move()
{
	if (KEY_PRESS(VK_LEFT) || KEY_PRESS('A'))
	{
		direction.x = -moveSpeed;

		isRight = false;
	}
	else if (KEY_PRESS(VK_RIGHT) || KEY_PRESS('D'))
	{
		direction.x = moveSpeed;

		isRight = true;
	}

	if (KEY_PRESS(VK_UP) || KEY_PRESS('W'))
	{
		direction.y = moveSpeed;
	}
	else if (KEY_PRESS(VK_DOWN) || KEY_PRESS('S'))
	{
		direction.y = -moveSpeed;
	}
	
	direction = direction.Normalized();
	
	Position() += direction * DELTA;
}

void Player::Attack()
{
}
