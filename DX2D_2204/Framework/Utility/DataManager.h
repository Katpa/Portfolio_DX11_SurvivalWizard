#pragma once

struct CharacterData
{
	string key;

	UINT maxHP;
	UINT maxMP;
	UINT maxSP;

	UINT str;
	UINT dex;
	UINT eng;
	UINT via;
};

struct MissileData
{
	float speed;
	float dmg;
	wstring filePath;
	bool isCircle;
	int animLength;
	string boomVFX;
};

class DataManager : public Singleton<DataManager>
{
public:
	DataManager();
	~DataManager();

	CharacterData GetCharacterData(string key) { return characterDatas[key]; }
	MissileData GetMissileData(string key) { return missileDatas[key]; }

private:
	void LoadCharacterData();
	void LoadMissileData();

private:
	map<string, CharacterData> characterDatas;
	map<string, MissileData> missileDatas;
};