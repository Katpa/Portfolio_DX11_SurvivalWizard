#pragma once

/// <summary>
/// 메인 게임 씬에서는
/// 1. 핵심 파트
/// 2. 플레이어 캐릭터
/// 3. 에너미 매니저
/// 4. 아이템 매니저
/// 5. 불릿 매니저
/// 6. UI매니저
/// 7. 맵 자동생성이면 -> 맵타일 매니저 필요함
/// 8. 아 경험치랑 바닥에 떨어지는 오브젝트 관련 매니저도 필요하다
///		-경험치 스톤?은 충돌처리 하지말고 그냥 일정 거리 접근하면 습득하는 걸로 하자구
/// 9. FX매니저
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