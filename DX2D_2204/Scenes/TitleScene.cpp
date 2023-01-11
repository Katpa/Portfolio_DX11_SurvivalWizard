#include "Framework.h"
#include "TitleScene.h"

TitleScene::TitleScene()
{
	titleScreen = new Quad(Vector2(WIN_WIDTH, WIN_HEIGHT), Vector2(CENTER_X, CENTER_Y));
	titleScreen->SetTexture(Texture::Add(L"Textures/BG/TitleBG.png"));
	titleScreen->UpdateWorld();

	pressEnter = new PressEnter();


	//
	//1. Press Enter to continue �ֱ�
	//2. �뷫������ ��ܿ� �������� �ְ�
	//3. ���ӽ��۰� ����Ű �޴� ����
}

TitleScene::~TitleScene()
{
	delete titleScreen;
	delete pressEnter;
}

void TitleScene::Update()
{
	pressEnter->Update();
}

void TitleScene::Render()
{
	titleScreen->Render();
}
