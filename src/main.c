#include "config.h"
#include "physics.h"
#include "display.h"

int main(int argc, char *argv[]) {

    srand( time( NULL ) );

    int numBodies = NUM_BODIES;
    float spaceLimit = SPACE_LIMIT;

    if (argc > 1) {
        if (argc >= 2) {
            numBodies = atoi(argv[1]);
            if (numBodies <= 0 || numBodies > 1000) {
                printf("Le nombre de corps de la galaxie doit être compris entre 1 et 1000.\n");
                return EXIT_FAILURE;
            }
        }
        if (argc >= 3) {
            spaceLimit = atof(argv[2]);
            if (spaceLimit <= 0 || spaceLimit > 1000) {
                printf("La limite de l'espace doit être compris entre 1 et 1000.\n");
                return EXIT_FAILURE;
            }
        }
    }

    bool startPlay = false;

    Galaxy galaxy;
    initGalaxy(&galaxy, numBodies, (float[]){ 0, 0, 0 }, spaceLimit);


    // Initialisation de la fenêtre raylib
    InitWindow(GRID_WIDTH, GRID_HEIGHT, "Galaxie 3D");
    SetTargetFPS(60);

    Image logo = LoadImage("logo.png");
    SetWindowIcon(logo);
    Texture2D texture = LoadTextureFromImage(logo);
    UnloadImage(logo);

    ClearBackground(DARKBLUE);

    Camera camera;
    camera.position = (Vector3){ 0.0f, 50.0f, 100.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };

    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_ENTER) && !startPlay) {
            startPlay = true;
        }

        if (startPlay) {
            // Contrôles de la caméra
            if (IsKeyDown(KEY_UP)) camera.position.z -= 5.0f;
            if (IsKeyDown(KEY_DOWN)) camera.position.z += 5.0f;
            if (IsKeyDown(KEY_LEFT)) camera.position.x -= 5.0f;
            if (IsKeyDown(KEY_RIGHT)) camera.position.x += 5.0f;

            if (IsKeyDown(KEY_P)) camera.position.y += 5.0f;
            if (IsKeyDown(KEY_M)) camera.position.y -= 5.0f;

            // Zoom caméra
            float mouseWheel = GetMouseWheelMove();
            if (mouseWheel != 0) {
                camera.fovy += mouseWheel * 2.0f;
                if (camera.fovy < 10.0f) camera.fovy = 10.0f;
                if (camera.fovy > 120.0f) camera.fovy = 120.0f;
            }

            applyForces(galaxy.bodies, &galaxy.n);

            for (int i = 0; i < galaxy.n; i++) {
                updateBody(&galaxy.bodies[i]);
            }

            BeginDrawing();
                BeginMode3D(camera);
                    displayGrid(galaxy.bodies, galaxy.n, spaceLimit, WHITE);
                EndMode3D();
            EndDrawing();
        } else {
            BeginDrawing();
            ClearBackground(DARKBLUE);
            DrawTexture(texture, GRID_WIDTH / 2 - texture.width / 2, GRID_HEIGHT / 3 - texture.height / 2, WHITE);
            DrawText("Appuyez sur ENTREE pour commencer", GRID_WIDTH / 2 - MeasureText("Appuyez sur ENTREE pour commencer", 20) / 2, GRID_HEIGHT / 2, 20, WHITE);
            EndDrawing();
        }
    }

    UnloadTexture(texture);
    CloseWindow();
    freeGalaxy(&galaxy);

    return EXIT_SUCCESS;
}
