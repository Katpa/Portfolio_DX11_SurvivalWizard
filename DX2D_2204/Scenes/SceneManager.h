#pragma once

class SceneManager : public Singleton<SceneManager>
{
public:
	SceneManager();
	~SceneManager();

	void Update();
	void Render();
	void PreRender();
	void PostRender();

	void Add(string key, Scene* scene);
	void Set(string key);

private:
	map<string, Scene*> scenes;
	Scene* curScene = nullptr;
	string curScenekey;
};