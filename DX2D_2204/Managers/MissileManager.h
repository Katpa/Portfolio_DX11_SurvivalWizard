#pragma once

class MisslieManager : public Singleton<MisslieManager>
{
public:
	MisslieManager();
	~MisslieManager();

	void Update();
	void Render();

	void Fire(string key, Vector2 curPos, Vector2 direction, bool isPlayer = true, float dmgFactor = 0.0f);

	void GetPlayer(Player* player) { this->player = player; }

private:
	void SetMissiles();
	void Collide(Missile* missile);

private:
	map<string, vector<Missile*>> missiles;
	Player* player;
};