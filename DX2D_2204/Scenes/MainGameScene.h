#pragma once

/// <summary>
/// ���� ���� ��������
/// 1. �ٽ� ��Ʈ
/// 2. �÷��̾� ĳ����
/// 3. ���ʹ� �Ŵ���
/// 4. ������ �Ŵ���
/// 5. �Ҹ� �Ŵ���
/// 6. UI�Ŵ���
/// 7. �� �ڵ������̸� -> ��Ÿ�� �Ŵ��� �ʿ���
/// 8. �� ����ġ�� �ٴڿ� �������� ������Ʈ ���� �Ŵ����� �ʿ��ϴ�
///		-����ġ ����?�� �浹ó�� �������� �׳� ���� �Ÿ� �����ϸ� �����ϴ� �ɷ� ���ڱ�
/// 9. FX�Ŵ���
/// 10. 
/// </summary>

class MainGameScene : public Scene
{
public:
	MainGameScene();
	~MainGameScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void Active() override;

	void LinkVar();


};