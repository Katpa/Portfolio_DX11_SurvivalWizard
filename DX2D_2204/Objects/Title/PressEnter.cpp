#include "Framework.h"

PressEnter::PressEnter() : AnimObject()
{
    isActive = false;
    func = NULL;
    SetClip();
}

PressEnter::~PressEnter()
{
}

void PressEnter::Update()
{
    if (!isActive || curClip == nullptr) return;

	Control();
}

void PressEnter::Control()
{
	if (KEY_DOWN(VK_RETURN))
	{
        curClip->Stop();
        curClip = clips[END];
        curClip->Play();
        if (func != nullptr)
            func();
	}

    curClip->Update();
    UpdateWorld();
}

void PressEnter::SetClip()
{
    wstring file = L"Textures/Text/PressEnter.png";
    Texture* texture = Texture::Add(file);
    Vector2 cutSize = texture->GetSize() / Vector2(11, 2);
    vector<Frame*> frames;

    for (int i = 0; i < 11; i++)
    {
        frames.push_back(new Frame(file, cutSize.x * i, 0, cutSize.x, cutSize.y));
    }
    clips[LOOP] = new Clip(frames, Clip::LOOP, 0.05f);
    curClip = clips[LOOP];

    frames.clear();

    for (int i = 0; i < 4; i++)
    {
        frames.push_back(new Frame(file, cutSize.x * i, cutSize.y, cutSize.x, cutSize.y));
    }
    clips[END] = new Clip(frames, Clip::END, 0.05f);
    clips[END]->SetEvent(1.0f, bind(&PressEnter::EndAnim, this));
}

void PressEnter::SetActive()
{
    if (isActive) return;

    isActive = true;
    curClip->Stop();
    curClip = clips[LOOP];
    curClip->Play();
}

void PressEnter::EndAnim()
{
    isActive = false;
}