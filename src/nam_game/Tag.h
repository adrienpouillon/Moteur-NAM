#pragma once

enum class Tag : int
{
	_None,
	_Player,
	_Enemy,
	_Shot,
	_Obstacle,
	_Collectible,
	_Floor,
	_Rail,
	_RailGenerator,
	_Camera,
	_CountTag
};

enum class Textures : size
{
	_Yellow,
	_Rainbow,
	_Stone,

	_Crepit,
	_Tuile,
	_Heart,
	_Grass,
};

enum class TagScene : size
{
	_No,
	_MainMenu,
	_UI,
	_Scene,
	_Pause
};

