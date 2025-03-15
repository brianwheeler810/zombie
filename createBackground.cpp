#include "ZombieArena.h"

int createBackground(VertexArray& rVA, IntRect arena) {
	srand(time(0));
	const int TILE_SIZE = 50;
	const int TILE_TYPES = 3;
	const int VERTS_IN_QUAD = 4;
	int worldWidth = arena.width / TILE_SIZE;
	int worldHeight = arena.height / TILE_SIZE;
	rVA.setPrimitiveType(Quads);
	rVA.resize(worldWidth * worldHeight * VERTS_IN_QUAD);

	int current_Vertex = 0;
	for (int w = 0; w < worldWidth; w++) {
		for (int h = 0; h < worldHeight; h++) {
			rVA[current_Vertex + 0].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE);
			rVA[current_Vertex + 1].position = Vector2f(w * TILE_SIZE  + TILE_SIZE, h * TILE_SIZE);
			rVA[current_Vertex + 2].position = Vector2f(w * TILE_SIZE  + TILE_SIZE, h * TILE_SIZE + TILE_SIZE);
			rVA[current_Vertex + 3].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE + TILE_SIZE);

			if (h == 0 || h == worldHeight - 1 || w == 0 || w == worldWidth - 1) {
				rVA[current_Vertex + 0].texCoords = Vector2f(0, 0 + TILE_TYPES * TILE_SIZE);
				rVA[current_Vertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + TILE_TYPES * TILE_SIZE);
				rVA[current_Vertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + TILE_TYPES * TILE_SIZE);
				rVA[current_Vertex + 3].texCoords = Vector2f(0, TILE_SIZE + TILE_TYPES * TILE_SIZE);
			}
			else {
				int mOrG = rand() % TILE_TYPES;
				int verticalOffset = mOrG * TILE_SIZE;
				rVA[current_Vertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);
				rVA[current_Vertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);
				rVA[current_Vertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
				rVA[current_Vertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);
			}

			current_Vertex += VERTS_IN_QUAD;
		}
	}

	return TILE_SIZE;
}