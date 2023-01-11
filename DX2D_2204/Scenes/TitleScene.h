#pragma once

class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	Quad* titleScreen;
	PressEnter* pressEnter;

};