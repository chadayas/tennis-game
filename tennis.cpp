#include "raylib.h"
#include <string>
#include <iostream>
using namespace std;

struct leftRectangle {
	Vector2 position;
	Vector2 size;
};


struct rightRectangle {
	Vector2 position;
	Vector2 size; 
};

struct Ball {
	Vector2 position;
	Vector2 size; 
	float radius;
	bool begin;
};


// Window size

	const int width= 1200;
	const int height = 1000;
	
	const char t[]= "MY Window";

	// For our two rectangles
	const float l_recStart = 100;
	const float r_recStart = 1100;
	const float rec_width= 20;
	const float rec_height = 300;

	const float middle = 350;	
	
	// For our circle
	float radius = 15.0;
	const float pos_x = width / 2;
	const float pos_y = height / 2;
	const float move_x = 5;
	const float move_y = 5;
	
	// name for our structs
	
	leftRectangle l_rec;
	leftRectangle r_rec;
	Ball ball;
	
	// movement vectors

	Vector2 ballMovement = { move_x, move_y };	
	Vector2 recMovement = { move_x, move_y };	



	void PlayerMovement(){
		if (IsKeyDown(KEY_UP)) l_rec.position.y -= recMovement.y;
		if (IsKeyDown(KEY_DOWN)) l_rec.position.y += recMovement.y;
	}
	void ComputerMovement();

	
	
	void BallMovement(){
		if (IsKeyPressed(KEY_P)){
			ball.position.x += 2 * ballMovement.x;
			ball.position.y +=  ballMovement.y;

		}			
	}

int main(){


	InitWindow(width, height, t);
	
		// vectors
	
	l_rec.position = Vector2{ l_recStart, middle };
	r_rec.position = Vector2{ r_recStart, middle }; 

	l_rec.size = Vector2{rec_width, rec_height};
	r_rec.size = Vector2{rec_width, rec_height};
	
 	ball.position = Vector2{ pos_x, pos_y };
	ball.radius = radius;	
		

	SetTargetFPS(60);


	while(!WindowShouldClose()){
	
		// Moving our rectangle
		// Right now our rectangle streches when key is pressed
		// when instead we want a static rectangle
	
		// move the circle 
		
		ClearBackground(BLACK);

		BeginDrawing();
			
		PlayerMovement();
		
		BallMovement();

		DrawRectangleV(l_rec.position, l_rec.size, RAYWHITE);
		DrawRectangleV(r_rec.position, r_rec.size, RAYWHITE);

	
		DrawCircleV(ball.position, ball.radius, RAYWHITE);

		EndDrawing();
	
	}

	CloseWindow();

	return 0;
}






