#include "Framework.h"
#include "TitleScene.h"

TitleScene::TitleScene()
{
	titleScreen = new Quad(Vector2(WIN_WIDTH, WIN_HEIGHT), Vector2(CENTER_X, CENTER_Y));
	titleScreen->SetTexture(Texture::Add(L"Textures/BG/TitleBG.png"));
	titleScreen->UpdateWorld();

	menu = new TitleMenu();

	pressEnter = new PressEnter();
	pressEnter->Position() = Vector2(CENTER_X, 200);
	pressEnter->SetActive();
	pressEnter->SetFunc(bind(&TitleScene::ShowMenu, this));

	titleLogo = new Quad(Vector2(WIN_WIDTH, WIN_HEIGHT), Vector2(CENTER_X, CENTER_Y));
	titleLogo->SetTexture(Texture::Add(L"Textures/Text/TitleLogo.png"));
	titleLogo->UpdateWorld();

	//�������� �߰� ����غ���
}

TitleScene::~TitleScene()
{
	delete titleScreen;
	delete pressEnter;
	delete titleLogo;
	delete menu;
}

void TitleScene::Update()
{
	if (pressEnter->Active())
		pressEnter->Update();
	else
		menu->Update();
}

void TitleScene::Render()
{
	titleScreen->Render();
	titleLogo->Render();

	if (pressEnter->Active())
		pressEnter->Render();
	else
		menu->Render();
	
}

void TitleScene::Active()
{
	CAM->SetTarget(nullptr);
	CAM->Position() = Vector2(CENTER_X, CENTER_Y);
	menu->Deactive();
}

void TitleScene::ShowMenu()
{
	menu->Active();
}
