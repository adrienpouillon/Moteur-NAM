#pragma once

namespace nam
{
	struct Mesh;

	class ObjParser
	{
	public:
		static bool LoadObj(Mesh* p_target, std::wstring path);
	};
}


