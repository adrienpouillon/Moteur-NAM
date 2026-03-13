#pragma once

namespace nam
{
    struct CollisionInfo
    {
        u32 m_entity1 = -1;
        u32 m_entity2 = -1;

        TransformComponent* m_transform1 = nullptr;
        TransformComponent* m_transform2 = nullptr;

        std::function<void(u32 self, u32 other, const CollisionInfo& collisionInfo)> OnCollision1;
        std::function<void(u32 self, u32 other, const CollisionInfo& collisionInfo)> OnCollision2;

        bool m_noIntersectionPush1 = false;
        bool m_noIntersectionPush2 = false;

        float penetrationDepth = 0.f;
        DirectX::XMFLOAT3 m_normal = {};
        DirectX::XMFLOAT3 m_contactPoint = {};
    };
}
