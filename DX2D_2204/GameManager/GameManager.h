#pragma once

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Update();
	void Render();

private:
	void Create();
	void Delete();

	void SetScenes();

private:
	Scene* scene;

	float renderFrame = 0;
	const float renderDelay = 0.0069f;
};