#pragma once

#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;
using namespace std;


class TextureHolder
{
private:

	map<string, Texture> m_Textures;
	static TextureHolder* m_s_Instance;

public:

	TextureHolder();
	static Texture& GetTexture(string const& filename);
};

