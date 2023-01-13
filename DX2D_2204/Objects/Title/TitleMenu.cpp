#include "Framework.h"

TitleMenu::TitleMenu()
{
	Init();
}

TitleMenu::~TitleMenu()
{
	for (Quad*& obj : options)
		delete obj;

	options.clear();

	delete htp;
	delete darker;
	delete pressEnter;
}

void TitleMenu::Update()
{
	if (!isActive) return;

	//How to Play Èå¸§Á¦¾î
	if (htp->Active())
		pressEnter->Update();
	else
		Control();
}

void TitleMenu::Render()
{
	if (!isActive) return;

	//Options
	for (int i = 0; i < MAX_MENU; i++)
	{
		if (menuNum == i)
			options[i + MAX_MENU]->Render();
		else
			options[i]->Render();
	}

	if (htp->Active())
	{
		//HTP
		darker->Render();
		htp->Render();
		pressEnter->Render();
	}
}

void TitleMenu::Active()
{
	menuNum = 0;
	darker->Active() = false;
	htp->Active() = false;
	pressEnter->Active() = false;

	isActive = true;
}

void TitleMenu::Deactive()
{
	isActive = false;
}

void TitleMenu::Control()
{
	if (KEY_DOWN(VK_DOWN) || KEY_DOWN('S'))
		menuNum++;
	else if (KEY_DOWN(VK_UP) || KEY_DOWN('W'))
		menuNum--;

	if (menuNum < 0)
		menuNum += MAX_MENU;
	else
		menuNum %= MAX_MENU;

	if (KEY_DOWN(VK_RETURN))
	{
		switch (menuNum)
		{
		case 0:
			//Game Start
			StartGame();
			break;

		case 1:
			//HTP
			ShowHTP();
			break;

		case 2:
			//Exit
			ExitGame();
			break;
		}
	}
}

void TitleMenu::StartGame()
{
	SCENE->Set("MainGame");
}

void TitleMenu::ShowHTP()
{
	darker->Active() = true;
	htp->Active() = true;
	pressEnter->SetActive();
}

void TitleMenu::HideHTP()
{
	darker->Active() = false;
	htp->Active() = false;
}

void TitleMenu::ExitGame()
{
	DestroyWindow(hWnd);
}

void TitleMenu::Init()
{
	wstring path = L"Textures/Title/Menu";
	
	options.resize(MAX_MENU * 2);
	for (int i = 0; i < MAX_MENU * 2; i++)
	{
		wstring file = path + to_wstring(i + 1) + L".png";
		options[i] = new Quad(file);
		options[i]->Position() = Vector2(CENTER_X, CENTER_Y - 90.0f - INTERVAL_OPTION * (i % MAX_MENU));
		options[i]->UpdateWorld();
	}

	htp = new Quad(L"Textures/Title/HTP.png");
	htp->Position() = Vector2(CENTER_X, CENTER_Y);
	htp->Active() = false;
	htp->UpdateWorld();

	darker = new Quad(L"Textures/Title/DarkScreen.png");
	darker->Position() = Vector2(CENTER_X, CENTER_Y);
	darker->Active() = false;
	darker->UpdateWorld();

	pressEnter = new PressEnter();
	pressEnter->Position() = {CENTER_X, CENTER_Y - 300.0f };
	pressEnter->SetFunc(bind(&TitleMenu::HideHTP, this));
}