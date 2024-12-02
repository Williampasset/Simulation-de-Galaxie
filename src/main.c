#include "config.h"
#include "physics.h"
#include "display.h"

int main() {
    bool startPlay = false;

    Galaxy galaxy;
    initGalaxy(&galaxy, NUM_BODIES, (float[]){0, 0});

    // Galaxy galaxy2;
    // initGalaxy(&galaxy2, NUM_BODIES, (float[]){-10, -10});

    // Initialisation de la fenêtre raylib
    InitWindow(GRID_WIDTH, GRID_HEIGHT, "Galaxie");

    SetTargetFPS(60);

    Image logo = LoadImage("logo.png");

    SetWindowIcon(logo);

    Texture2D texture = LoadTextureFromImage(logo);

    UnloadImage(logo);

    ClearBackground(DARKBLUE);

    Camera2D camera = { 0 };
    float zoom = 1.0f;

    camera.offset = (Vector2){ (float)GRID_WIDTH / 2, (float)GRID_HEIGHT / 2 };
    camera.rotation = 0.0f;
    camera.target = (Vector2){ 0.0f, 0.0f };
    camera.zoom = zoom;

    while (!WindowShouldClose()) {

        if(IsKeyDown(KEY_ENTER) && !startPlay){
            startPlay = true;
        }

        if(startPlay){

            //Zoom de la caméra
            float mouseWheel = GetMouseWheelMove();
            if (mouseWheel != 0.0f) {
                camera.zoom += mouseWheel * 0.1f;
            }

            //Limitation du zoom
            if (camera.zoom < 0.1f) camera.zoom = 0.1f;
            if (camera.zoom > 2.0f) camera.zoom = 2.0f;

            //Déplacement de la caméra
            if (IsKeyDown(KEY_RIGHT)) camera.offset.x -= 5 / camera.zoom;
            if (IsKeyDown(KEY_LEFT)) camera.offset.x += 5 / camera.zoom;
            if (IsKeyDown(KEY_DOWN)) camera.offset.y -= 5 / camera.zoom;
            if (IsKeyDown(KEY_UP)) camera.offset.y += 5 / camera.zoom;

            applyForces(galaxy.bodies, &galaxy.n);
            // applyForces(galaxy2.bodies, &galaxy2.n);

            for (int i = 0; i < galaxy.n; i++) {
                updateBody(&galaxy.bodies[i]);
                // updateBody(&galaxy2.bodies[i]);
            }

            BeginDrawing();

                BeginMode2D(camera);
            
                    displayGrid(galaxy.bodies, galaxy.n, GRID_WIDTH, GRID_HEIGHT, SPACE_LIMIT, WHITE);
                    // displayGrid(galaxy2.bodies, galaxy2.n, GRID_WIDTH, GRID_HEIGHT, SPACE_LIMIT, GREEN);
            
                EndMode2D();

            EndDrawing();

        }
        else{
            BeginDrawing();
            ClearBackground(DARKBLUE);
            DrawTexture(texture, GRID_WIDTH / 2 - texture.width / 2, GRID_HEIGHT / 3 - texture.height / 2, WHITE);
            EndDrawing();
        }
        
    }

    UnloadTexture(texture);
    CloseWindow();

    for (int i = 0; i < galaxy.n; i++) {
	    freeBody(&galaxy.bodies[i]);
        // freeBody(&galaxy2.bodies[i]);
	}

	freeGalaxy(&galaxy);
    // freeGalaxy(&galaxy2);

    return 0;
}
