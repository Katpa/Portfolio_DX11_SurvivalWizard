#pragma once

class Accessary : public Equipment
{
public:
	Accessary(wstring filePath, string key, Buff buff);
	~Accessary();

	Buff ReturnBuff() { return buff; }

private:
	Buff buff;
};