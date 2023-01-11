#include "Framework.h"
#include "TitleScene.h"

TitleScene::TitleScene()
{
	titleScreen = new Quad(Vector2(WIN_WIDTH, WIN_HEIGHT), Vector2(CENTER_X, CENTER_Y));
	titleScreen->SetTexture(Texture::Add(L"Textures/BG/TitleBG.png"));
	titleScreen->UpdateWorld();

	pressEnter = new PressEnter();


	//
	//1. Press Enter to continue 넣기
	//2. 대략적으로 상단에 리더보드 넣고
	//3. 게임시작과 조작키 메뉴 띄우기
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
