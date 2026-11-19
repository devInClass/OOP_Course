#include <vector>
#include "raylib.h"
#include "Actor.h"


int main(void)
{
    InitWindow(800, 400, "My First Raylib Window");
    SetTargetFPS(60);
	Color bgColor = Color{ 200, 206, 135, 255 }; // grayish green color
	float radius = 20.0f;

 //   Actor player1(0.0f + radius * 1, 0.0f + radius * 1, radius);
	//Actor player2(0.0f + radius * 3, 0.0f + radius * 3, radius);
	//Actor player3(0.0f + radius * 5, 0.0f + radius * 5, radius);
	//Actor player4(0.0f + radius * 7, 0.0f + radius * 7, radius);

	std::vector<Actor> actors{10};

	for (int i = 0; i < actors.size(); i++) {
		actors[i] = Actor(0.0f + radius * (2 * i + 1), 0.0f + radius * (2 * i + 1), radius);
	}

	float speed = 200.0f; // units per second

    while (!WindowShouldClose())
    {
		float deltaTime = GetFrameTime();
		//player1.Update(deltaTime);

		for (Actor& actor : actors) {
			actor.Update(deltaTime, speed);
		}

        BeginDrawing();
            ClearBackground(bgColor);
			for (Actor& actor : actors) {
				actor.Draw();
			}
        EndDrawing();
    }

    CloseWindow();
    return 0;
}