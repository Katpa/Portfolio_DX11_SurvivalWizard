#pragma once

class Player : public Actor
{
private:
	

public:
	Player();
	~Player();

	virtual void Update() override;
	virtual void Render() override;
	void UIRender();

private:
	void Control();

	virtual void SetClip() override;

	virtual void Move() override;
	virtual void Attack() override;

private:
	///
	/// 1. �κ��丮
	/// 2. ui
	/// 3. ��� ��Ʈ�ѷ�
	/// 4. ų��
	///
};