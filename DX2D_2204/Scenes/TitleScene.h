#pragma once

class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();

	virtual void Update() override;
	virtual void Render() override;

	virtual void Active() override;

private:
	Quad* titleScreen;
	Quad* titleLogo;
	PressEnter* pressEnter;

	TitleMenu* menu;
};