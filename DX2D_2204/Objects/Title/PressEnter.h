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

	void SetActive();
	void SetFunc(CallBack func) { this->func = func; }

private:
	void Control();
	void SetClip();

	void EndAnim();

private:
	CallBack func;
};