#pragma once

//
//Externe dependence
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string>
#include <chrono>
#include <wrl.h>
#include <comdef.h>
#include <fstream>

#include <windows.h>
#include <d3dcommon.h>
#include <d3d12.h>
#include <DirectXMath.h>
#include <DirectXCollision.h>

#pragma comment(lib,"d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")
#pragma comment(lib, "dxgi.lib")

#include "Common/d3dUtil.h"
#include "Common/UploadBuffer.h"
#include "Common/MathHelper.h"
#include "Common/d3dx12.h"

#include <FrameworkCore.h>

#include <nam_engine/TransformComponent.h>

using namespace DirectX;
using Microsoft::WRL::ComPtr;

#include "Light.h"
#include "LightManager.h"

#include "Constants.h"
#include "Vertex.h"
#include "DataShader.h"
#include "ConstantBuffersDatas.h"
#include "CubeFace.h"
#include "InputLayout.h"
#include "ObjParser.h"
#include "Shader.h"
#include "RootSignatureName.h"

#include "ParticleManager.h"
#include "RenderItemManager.h"
#include "DescriptoHeapsWrapper.h"
#include "RootSignature.h"
#include "PipelineStateBuilder.h"
#include "PsoManager.h"
#include "TextureManager.h"
#include "RenderManager.h"
#include "CommandManager.h"
#include "RenderWrapper.h"
#include "ARenderItem.h"
#include "SwapChainManager.h"

#include "Mesh.h"
#include "Sprite.h"
#include "Text.h"








