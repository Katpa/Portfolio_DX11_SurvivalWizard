#pragma once

class Equipment
{
public:
	enum Type
	{
		WEAPON = 0,
		ARMOR = 1
	};

public:
	Equipment(Type type, wstring filePath);
	virtual ~Equipment() = 0;



protected:
	Type type;
	Quad* image;
	Quad* icon;
};