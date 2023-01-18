#include "Framework.h"

MisslieManager::MisslieManager()
{
	SetMissiles();
}

MisslieManager::~MisslieManager()
{
	for (pair<string, vector<Missile*>> p : missiles)
	{
		for (Missile*& missile : missiles[p.first])
			delete missile;

		missiles[p.first].clear();
	}

	missiles.clear();
}

void MisslieManager::Update()
{
	for (pair<string, vector<Missile*>> p : missiles)
	{
		for (Missile* missile : p.second)
		{
			if (!missile->Active()) continue;

			missile->Update();
			Collide(missile);
		}
	}
}

void MisslieManager::Render()
{
	for (pair<string, vector<Missile*>> p : missiles)
	{
		for (Missile* missile : p.second)
		{
			if (!missile->Active()) continue;

			missile->Render();
		}
	}
}

void MisslieManager::Fire(string key, Vector2 curPos, Vector2 direction, bool isPlayer, float dmgFactor)
{
	for (Missile* missile : missiles[key])
	{
		if (missile->Active()) continue;

		missile->Fire(curPos, direction, isPlayer, dmgFactor);
		break;
	}
}

void MisslieManager::SetMissiles()
{
	MissileData data = DataManager::Get()->GetMissileData("FireBall");
	string key = data.boomVFX;

	for(int i = 0; i < 100; i++)
		missiles[key].push_back(new LinearMissile(data));

	//앞으로 여기에 다른 미사일들도 채워나가면 된다
}

void MisslieManager::Collide(Missile* missile)
{
	if (missile->IsPlayer())
	{
		//EnemyManager::Get()->IsCollision(missile);
		return;
	}
	else
	{
		//여긴 플레이어랑 비교해야하는데
		//여기는 나중에 수정해야할 것같다
		// 수정방식
		//1. 범위형 미사일를 위해서 미사일 내부에서 충돌검사를 하고 그 이후에 그 결과 토대로 처리하면 된다
		//2. 지속딜링형(레이저같은ㅇㅇ) 미사일을 위해서 
		//3. 타겟팅형 미사일은 충돌검사가 필요없으니깐 그걸 위해서라도 충돌 검사가 반드시 필수적이지 않게 구조를 만들어야 한다.
		if (!missile->ReturnCollider()->IsCollision(player->ReturnCollider())) return;

		player->TakeHit(missile->ReturnDMG());
		missile->Boom();
	}
}
