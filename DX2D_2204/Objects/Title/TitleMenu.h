#pragma once

class TitleMenu
{
private:
	const int MAX_MENU = 3;
	const float INTERVAL_OPTION = 70.0f;

public:
	TitleMenu();
	~TitleMenu();

	void Update();
	void Render();
	void Active();

private:
	void Control();

	void StartGame();
	void ShowHTP();
	void HideHTP();
	void ExitGame();

	void Init();

private:
	//num + MAX_MENU = State: selected
	vector<Quad*> options;
	int menuNum = 0;

	Quad* htp;
	Quad* darker;
	PressEnter* pressEnter;

	bool isActive = false;
};