#include "Framework.h"

UpDownButton::UpDownButton(wstring file1, wstring file2)
{
	up = new Quad(file1);
	up->SetParent(this);
	down = new Quad(file2);
	down->SetParent(this);
	curImage = up;

	collider = new RectCollider(up->Size());
	collider->SetParent(this);
}

UpDownButton::~UpDownButton()
{
	delete up;
	delete down;
	delete collider;
}

void UpDownButton::Update()
{
	if (!isActive) return;

	//1. key_down�̸� �̹����� �ٲ��
	//2. key_up�� �� ����� �Լ��� ����Ǿ� �Ѵ�
	//3. �׿� ���ÿ� �̹����� up���� �ٲ����Ѵ�
	//4. �׸��� ����Ű�� ������ ��ư�� �۵��ؾ��Ѵ�

	if ((KEY_DOWN(VK_LBUTTON) && collider->IsPointCollision(mousePos)) ||
		 KEY_DOWN(hotKey))
	{
		SetDown();
	}

	if ((KEY_UP(VK_LBUTTON) && collider->IsPointCollision(mousePos)) ||
		 KEY_UP(hotKey))
	{
		if (Event != nullptr)
			Event();

		SetUp();
	}

	UpdateWorld();
	curImage->UpdateWorld();
	collider->UpdateWorld();
}

void UpDownButton::Render()
{
	if (!isActive) return;

	curImage->Render();

	if (false)
		collider->Render();
}

void UpDownButton::SetDown()
{
	isDown = true;

	curImage = down;
}

void UpDownButton::SetUp()
{
	isDown = false;

	curImage = up;
}
