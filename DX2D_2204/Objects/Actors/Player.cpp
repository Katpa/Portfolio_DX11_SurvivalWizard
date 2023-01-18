#include "Framework.h"

Player::Player()
{
	SetClip();
	MISSILE->GetPlayer(this);
}

Player::~Player()
{
}

void Player::Update()
{
	Control();
}

void Player::Render()
{
	AnimObject::Render();
}

void Player::UIRender()
{
}

void Player::Control()
{
	Move();
}

void Player::SetClip()
{
	wstring filePath = L"Textures/Character/ChikBoy_idle.png";
	Texture* texture = Texture::Add(filePath);
	Vector2 frameSize = texture->GetSize() / Vector2(1, 6);

	vector<Frame*> frames;
	for (int i = 0; i < 6; i++)
	{
		frames.push_back(new Frame(filePath, 0, frameSize.y * i, frameSize.x, frameSize.y));
	}
	clips[0] = new Clip(frames);
	curClip = clips[0];
	curClip->Play();
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
