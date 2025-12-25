
#include <iostream>
#include "raylib.h"
#include "train.cpp"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Train Game - New Engine Test");

    int currentFps = 60;

    // Store the position for the both of the circles
    Vector2 trainTest = {screenWidth/2.0f,screenHeight/2.0f};

    // The speed applied to both circles
    const float speed = 0.001;
    train amtrak = train(trainTest, {200,50}, speed);

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
       
        //amtrak.Move();
        if(amtrak.getPosition().x >= trainTest.x && amtrak.getPosition().y > 99.5f)
            amtrak.SwitchTrackUp();
        if((amtrak.getPosition().y < 100 && amtrak.getAngle() >= 360.0f) || (amtrak.getPosition().x <= trainTest.x))
           amtrak.Move();
        
        if(amtrak.getPosition().x > screenWidth+amtrak.getSize().x/2){
            amtrak.SetPosition(Vector2{0-amtrak.getSize().x/2,trainTest.y});
        }
        BeginDrawing();
            ClearBackground(RAYWHITE);

            // Draw both circles to the screen
            amtrak.DrawTrain();
            std::cout << "Angle: " << amtrak.getAngle() << std::endl;
            std::cout << "Position: (" << amtrak.getPosition().x << "," << amtrak.getPosition().y << ")" << std::endl;
            // Draw the help text
            // Determine what help text to show depending on the current FPS target
            

        EndDrawing();
        
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}