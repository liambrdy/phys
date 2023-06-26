#include <stdio.h>

#include <raylib.h>

void DrawEditorGrid(size_t w, size_t h)
{
    size_t verticalLines = 70;
    for (size_t i = 0; i < verticalLines+1; i++) {
        Color lineColor = GetColor(0x99999922);
        if (i % 2 == 0) lineColor.a = 0x44;
        size_t scale = w / verticalLines;
        DrawLine(0, i*scale, w, i*scale, lineColor);
        DrawLine(i*scale, 0, i*scale, h, lineColor);
    }
}

int main()
{
    size_t screenWidth = 1280, screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Phys");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        PollInputEvents();

        BeginDrawing();
        ClearBackground(BLACK);

        DrawEditorGrid(screenWidth, screenHeight);

        char buffer[256];
        snprintf(buffer, 256, "Frame Time: %f\n", GetFrameTime());
        DrawText(buffer, 2, 0, 25, GRAY);

        EndDrawing();
    }

    return 0;
}