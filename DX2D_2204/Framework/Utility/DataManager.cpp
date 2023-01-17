#include "Framework.h"
#include "DataManager.h"

DataManager::DataManager()
{
	//LoadCharacterData();
    LoadMissileData();
}

DataManager::~DataManager()
{
}

void DataManager::LoadCharacterData()
{
    FILE* file;
    fopen_s(&file, "DataTable/CharacterData.csv", "r");

    bool isFirstLine = true;

    while (true)
    {
        char temp[1024];
        fgets(temp, 1024, file);

        if (isFirstLine)
        {
            isFirstLine = false;
            continue;
        }

        if (feof(file))
            return;

        string str = temp;
        Replace(&str, "\n", "");

        vector<string> table = SplitString(str, ",");

        CharacterData data;

        data.key = table[0];

        data.maxHP = stoi(table[17]);
        data.maxMP = stoi(table[18]);
        data.maxSP = stoi(table[19]);

        data.str = stoi(table[20]);
        data.dex = stoi(table[21]);
        data.eng = stoi(table[22]);
        data.via = stoi(table[23]);

        characterDatas[data.key] = data;
    }
}

void DataManager::LoadMissileData()
{
    FILE* file;
    fopen_s(&file, "DataTable/MissileData.csv", "r");

    bool isFirstLine = true;

    while (true)
    {
        char temp[1024];
        fgets(temp, 1024, file);

        if (isFirstLine)
        {
            isFirstLine = false;
            continue;
        }

        if (feof(file))
            return;

        string str = temp;
        Replace(&str, "\n", "");

        vector<string> table = SplitString(str, ",");

        MissileData data;

        data.speed = stof(table[0]);
        data.dmg = stof(table[1]);
        data.filePath.assign(table[2].begin(), table[2].end());
        data.isCircle = stoi(table[3]);
        data.animLength = stoi(table[4]);
        data.boomVFX = table[5];

        missileDatas[data.boomVFX] = data;
    }
}
