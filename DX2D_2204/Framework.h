﻿#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN

#define TEX_SCALE_MULTI 1.5f

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define CENTER_X (WIN_WIDTH * 0.5f)
#define CENTER_Y (WIN_HEIGHT * 0.5f)

#define DEVICE Device::Get()->GetDevice()
#define DC Device::Get()->GetDeviceContext()

#define KEY_DOWN(k) Keyboard::Get()->Down(k)
#define KEY_UP(k) Keyboard::Get()->Up(k)
#define KEY_PRESS(k) Keyboard::Get()->Press(k)

#define DELTA Timer::Get()->GetElapsedTime()

#define CAM Environment::Get()->GetMainCamera()

#define FX EffectManager::Get()
#define SFX Audio::Get()

#define SCENE SceneManager::Get()

#define SLOT_SIZE 29.0f

#define LERP(s, e, t) (s + (e - s)*t)

#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <algorithm>

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "dxguid.lib")

//ImGui
#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>

#include <dirent/dirent.h>
#include <ImGuiFileDialog.h>
#include <ImGuiFileDialogConfig.h>

#pragma comment(lib, "ImGui.lib")

//DirectXTex
#include <DirectXTex/DirectXTex.h>

#pragma comment(lib, "DirectXTex.lib")

//FMOD
#include <FMOD/fmod.hpp>

#pragma comment(lib, "fmod_vc.lib")

//DirectWirte
#include <d2d1_2.h>
#include <dwrite.h>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")

using namespace std;
using namespace DirectX;

typedef XMFLOAT4 Float4;
typedef XMFLOAT3 Float3;
typedef XMFLOAT2 Float2;
typedef XMMATRIX Matrix;

typedef function<void()> CallBack;
typedef function<void(int)> CallBackInt;

//Framework Header
#include "Framework/Math/Vector2.h"
#include "Framework/Math/Transform.h"
#include "Framework/Math/Math.h"

using namespace GameMath;

#include "Framework/Utility/Singleton.h"
#include "Framework/Utility/BinaryReader.h"
#include "Framework/Utility/BinaryWriter.h"
#include "Framework/Utility/Keyboard.h"
#include "Framework/Utility/Timer.h"
#include "Framework/Utility/Xml.h"
#include "Framework/Utility/Utility.h"
#include "Framework/Utility/Audio.h"
#include "Framework/Utility/Font.h"
#include "Framework/Utility/DataManager.h"
#include "Framework/Utility/ZOder.h"

using namespace Utility;

#include "Framework/System/Device.h"

#include "Framework/Shader/Shader.h"
#include "Framework/Shader/VertexShader.h"
#include "Framework/Shader/PixelShader.h"

#include "Framework/Buffer/VertexLayouts.h"
#include "Framework/Buffer/VertexBuffer.h"
#include "Framework/Buffer/IndexBuffer.h"
#include "Framework/Buffer/ConstBuffer.h"
#include "Framework/Buffer/GlobalBuffer.h"

#include "Framework/Render/Texture.h"
#include "Framework/Render/Frame.h"
#include "Framework/Render/Clip.h"
#include "Framework/Render/RenderTarget.h"

#include "Framework/Collision/Collider.h"
#include "Framework/Collision/CircleCollider.h"
#include "Framework/Collision/RectCollider.h"
#include "Framework/Collision/LineCollider.h"
#include "Framework/Collision/IsometricCollider.h"

#include "Framework/Environment/Camera.h"
#include "Framework/Environment/Environment.h"

#include "Algorithm/Node.h"
#include "Algorithm/Heap.h"
#include "Algorithm/AStar.h"
#include "Algorithm/AStarPlus.h"

//Object Header
#include "Objects/Basic/GameObject.h"
#include "Objects/Basic/Quad.h"
#include "Objects/Basic/Isometric.h"
#include "Objects/Basic/AnimObject.h"
#include "Objects/Basic/Effect.h"
#include "Objects/Basic/EffectManager.h"
#include "Objects/Basic/ProgressBar.h"
#include "Objects/Basic/Button.h"
#include "Objects/Basic/IButton.h"
#include "Objects/Basic/UpDownButton.h"
#include "Objects/Basic/InstancingTileMap.h"
#include "Objects/Basic/ImageFont.h"
#include "Objects/Actors/Actor.h"

#include "Objects/Title/PressEnter.h"
#include "Objects/Title/TitleMenu.h"

#include "Objects/items/Equipment.h"
#include "Objects/Items/Weapon.h"

#include "Objects/Actors/Player.h"

//Scene
#include "Scenes/Scene.h"
#include "Scenes/SceneManager.h"
#include "GameManager/GameManager.h"

extern HWND hWnd;
extern Vector2 mousePos;