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

	//������ ���⿡ �ٸ� �̻��ϵ鵵 ä�������� �ȴ�
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
		//���� �÷��̾�� ���ؾ��ϴµ�
		//����� ���߿� �����ؾ��� �Ͱ���
		// �������
		//1. ������ �̻��ϸ� ���ؼ� �̻��� ���ο��� �浹�˻縦 �ϰ� �� ���Ŀ� �� ��� ���� ó���ϸ� �ȴ�
		//2. ���ӵ�����(��������������) �̻����� ���ؼ� 
		//3. Ÿ������ �̻����� �浹�˻簡 �ʿ�����ϱ� �װ� ���ؼ��� �浹 �˻簡 �ݵ�� �ʼ������� �ʰ� ������ ������ �Ѵ�.
		if (!missile->ReturnCollider()->IsCollision(player->ReturnCollider())) return;

		player->TakeHit(missile->ReturnDMG());
		missile->Boom();
	}
}
