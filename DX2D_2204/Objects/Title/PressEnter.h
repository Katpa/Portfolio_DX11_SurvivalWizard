#pragma once

class PressEnter : public AnimObject
{
private:
	enum State
	{
		LOOP = 0,
		END = 1
	};

public:
	PressEnter();
	~PressEnter();

	void Update();
	
private:
	void Control();
	void SetClip();

	void SetActive();
	void EndAnim();
};