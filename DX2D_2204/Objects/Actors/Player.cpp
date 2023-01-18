#include "Framework.h"

Player::Player()
{
	SetClip();
	Scale() *= 2.0f;
	moveSpeed = 250.0f;
	//MISSILE->GetPlayer(this);

	ZOrder::Get()->Insert(this);
}

Player::~Player()
{
}

void Player::Update()
{
	Control();
	Attack();
	AnimObject::Update();
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

	if (direction.Length() == 0)
	{
		if (!isRight)
			SetAnim(IDLE_L);
		else
			SetAnim(IDLE_R);
	}
	else
	{
		if (!isRight)
			SetAnim(MOVE_L);
		else
			SetAnim(MOVE_R);
	}

	//ESC			메뉴 출력 및 일시정지
	//Tab			인벤토리 오픈/클로즈
	//SpaceBar		확인
}

void Player::SetClip()
{
	wstring filePath = L"Textures/Character/ChikBoy_idle.png";
	Texture* texture = Texture::Add(filePath);
	Vector2 frameSize = texture->GetSize() / Vector2(2, 6);

	vector<Frame*> frames;
	for (int i = 0; i < 6; i++)
	{
		frames.push_back(new Frame(filePath, 0, frameSize.y * i, frameSize.x, frameSize.y));
	}
	clips[IDLE_L] = new Clip(frames, Clip::LOOP, 0.15f);
	curClip = clips[IDLE_L];

	frames.clear();
	for (int i = 0; i < 6; i++)
	{
		frames.push_back(new Frame(filePath, frameSize.x, frameSize.y * i, frameSize.x, frameSize.y));
	}
	clips[IDLE_R] = new Clip(frames, Clip::LOOP, 0.15f);

	filePath = L"Textures/Character/ChikBoy_run.png";
	texture = Texture::Add(filePath);
	frameSize = texture->GetSize() / Vector2(2, 10);

	frames.clear();
	for (int i = 0; i < 10; i++)
	{
		frames.push_back(new Frame(filePath, 0, frameSize.y * i, frameSize.x, frameSize.y));
	}
	clips[MOVE_L] = new Clip(frames, Clip::LOOP, 0.15f);

	frames.clear();
	for (int i = 0; i < 10; i++)
	{
		frames.push_back(new Frame(filePath, frameSize.x, frameSize.y * i, frameSize.x, frameSize.y));
	}
	clips[MOVE_R] = new Clip(frames, Clip::LOOP, 0.15f);
}

void Player::Move()
{
	direction = { 0, 0 };

	if (KEY_PRESS(VK_LEFT) || KEY_PRESS('A'))
	{
		direction.x--;

		isRight = false;
	}
	else if (KEY_PRESS(VK_RIGHT) || KEY_PRESS('D'))
	{
		direction.x++;

		isRight = true;
	}

	if (KEY_PRESS(VK_UP) || KEY_PRESS('W'))
	{
		direction.y++;
	}
	else if (KEY_PRESS(VK_DOWN) || KEY_PRESS('S'))
	{
		direction.y--;
	}
	
	direction = direction.Normalized();
	
	Position() += direction * moveSpeed * DELTA;
}

void Player::Attack()
{
}