#include <capd/capdlib.h>
#include <raylib.h>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - input keys");
    capd::DMap pendulum(
        "time:t;"
        "var:x,y;"
        "par:w,h;"
        "fun:y-h,-x+w;"
    );

    pendulum.setParameter("w", screenWidth / 2.0f);
    pendulum.setParameter("h", screenHeight / 2.0f);

    uint32_t order = 10;
    capd::DOdeSolver solver{pendulum, order};

    solver.setStep(0.03);

    capd::DVector u{screenWidth / 2.0f, screenHeight / 2.0f};
    double t = 0.0;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        u = solver(t, u);

        if (IsKeyDown(KEY_RIGHT)) u[0] += 2.0f;
        if (IsKeyDown(KEY_LEFT)) u[0] -= 2.0f;
        if (IsKeyDown(KEY_UP)) u[1] -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) u[1] += 2.0f;

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
            DrawCircleV((Vector2) {
                (float)u[0],
                (float)u[1]
            }, 50, MAROON);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
