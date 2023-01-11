#include "Framework.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	curScene = nullptr;
	for (pair<string, Scene*> scene : scenes)
	{
		delete scene.second;
	}

	scenes.clear();
}

void SceneManager::Update()
{
	if (!curScene) return;

	curScene->Update();
}

void SceneManager::Render()
{
	if (!curScene) return;

	curScene->Render();
}

void SceneManager::PreRender()
{
	if (!curScene) return;

	curScene->PreRender();
}

void SceneManager::PostRender()
{
	if (!curScene) return;

	curScene->PostRender();
}

void SceneManager::Add(string key, Scene* scene)
{
	if (scenes.count(key) > 0) return;

	scenes[key] = scene;
}

void SceneManager::Set(string key)
{
	if (scenes.count(key) == 0) return;

	curScene = scenes[key];
}
