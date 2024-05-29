#include "raylib.h"
#include "util/util.h"

int main(void)
{
	InitWindow(800, 600, "Cross-platform raylib template");

	SetWindowState(FLAG_WINDOW_RESIZABLE);

	SetTargetFPS(60);

	// Image raylibImg = LoadImage("../res/raylib.png");
	Texture2D raylibTex = LoadTexture("../res/raylib.png");

	exampleFunction();

	while(!WindowShouldClose()) {
		int width = GetRenderWidth();
		int height = GetRenderHeight();

BeginDrawing();

	ClearBackground(RAYWHITE);

	DrawTexture(raylibTex, (width - raylibTex.width) / 2, (height - raylibTex.height) / 2, WHITE);

	DrawFPS(0, 0);

EndDrawing();

	}

	CloseWindow();

	return 0;
}