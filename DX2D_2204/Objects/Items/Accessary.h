#pragma once

class Accessory : public Equipment
{
public:
	Accessory(wstring filePath, string key, Buff buff);
	~Accessory();

	Buff ReturnBuff() { return buff; }

private:
	virtual void SetPower() override;

private:
	Buff buff;
};