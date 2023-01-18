#include "Framework.h"
#include "MainGameScene.h"

MainGameScene::MainGameScene()
{
	player = new Player();
	CAM->SetTarget(player);
}

MainGameScene::~MainGameScene()
{
}

void MainGameScene::Update()
{
	player->Update();
}

void MainGameScene::Render()
{
	//player->Render();
	ZOrder::Get()->Render();
}

void MainGameScene::Active()
{
}

void MainGameScene::LinkVar()
{
}
