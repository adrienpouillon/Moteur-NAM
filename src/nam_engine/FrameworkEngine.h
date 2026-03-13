#pragma once

//lib

#ifdef _DEBUG
#pragma comment(lib, "../nam_core/x64/Debug/nam_core.lib")
#pragma comment(lib, "../nam_render/x64/Debug/nam_render.lib")
#else
#pragma comment(lib, "../nam_core/x64/Release/nam_core.lib")
#pragma comment(lib, "../nam_render/x64/Release/nam_render.lib")
#endif

//
//Externe dependence
#include <iostream>
#include <cstdint>
#include <cassert>
#include <vector>
#include <bitset>
#include <limits>
#include <chrono>
#include <limits>
#include <windows.h>
#include <optional>
#include <FrameworkCore.h>
#include <FrameworkRender.h>

#include <RenderManager.h>
#include <TextureManager.h>
#include <ParticleManager.h>

#include <DirectXMath.h>
#include "Common/MathHelper.h"
#include <DirectXCollision.h>

//
//Interne dependence

#include "Input.h"
#include "Mesh.h"
#include "Sprite.h"
#include "Text.h"
#include "Light.h"
#include "Entity.h"

#include "TransformComponent.h"
#include "Transform2DComponent.h"
#include "BehaviorComponent.h"
#include "ButtonComponent.h"
#include "CameraComponent.h"
#include "MeshRendererComponent.h"
#include "SpriteRendererComponent.h"
#include "TextRendererComponent.h"
#include "LightComponent.h"
#include "ParticleEmitersComponent.h"
#include "StateMachineComponent.h"
#include "BoxColliderComponent.h"
#include "SphereColliderComponent.h"
#include "PhysicComponent.h"

#include "CollisionInfo.h"
#include "SpatialHash.h"
#include "EcsConfig.h"
#include "Utils.h"
#include "ISystem.h"
#include "ISparseSet.h"
#include "IView.h"

#include "RenderSystem.h"
#include "PhysicSystem.h"
#include "StateMachineSystem.h"
#include "LightManagerSystem.h"
#include "BehaviorSystem.h"
#include "CameraManagerSystem.h"
#include "ColliderSystem.h"
#include "ParticleSystem.h"
#include "UISystem.h"

#include "ViewId.h"
#include "ComponentId.h"
#include "SystemId.h"
#include "GameObject.h"
#include "LightManager.h"
#include "EntityManager.h"
#include "SparseSet.h"

#include "LoadingScreen.h"

#include "Ecs.h"
#include "View.h"
#include "Scene.h"
#include "SceneManager.h"
#include "App.h"
#include "Make.h"

#include "CaveGeneratorParams.h"
#include "CaveGenerator.h"
#include "CaveSectionParams.h"
#include "CaveTubeSection.h"
#include "CaveSections.h"




