#pragma once

namespace nam
{
    enum class LightType : u32
    {
        _Directionnal,
        _Point,
        _Spot,
    };

    class Light
    {
    public:
        LightType m_type = LightType::_Directionnal;
        DirectX::XMFLOAT3 m_color = { 1, 1, 1 };

        DirectX::XMFLOAT3 m_direction = { 0, 0, 0 };
        int m_id = -1;

        DirectX::XMFLOAT3 m_position = { 0, 0, 0 };
        float pad2 = 0;

        float m_range = 0;
        float m_beginAngleRad = 0;
        float m_endAngleRad = 0;
        float m_intensity = 0;

    public: 
        void SetToDirectionalLight(float intensity, const DirectX::XMFLOAT3& direction, const DirectX::XMFLOAT3& color);
        void SetToPointLight(float intensity, const DirectX::XMFLOAT3& position, float range, const DirectX::XMFLOAT3& color);
        void SetToSpotLight(float intensity, const DirectX::XMFLOAT3& position, float range, const DirectX::XMFLOAT3& direction, float beginAngleRad, float endAngleRad, const DirectX::XMFLOAT3& color);
      
        void SetPosition(const DirectX::XMFLOAT3& pos);
        void SetIntensity(float intensity);
        void SetColor(const DirectX::XMFLOAT3& color);

        //DO NOT USE IN GAMEPLAY
        void SetByTransform(TransformComponent& transform);

    private:
        void Reset();
    };
}
