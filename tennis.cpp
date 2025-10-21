#include "raylib.h"
#include <string>
#include <iostream>
using namespace std;



int main(){
	const int width= 1200;
	const int height = 1000;
	
	const char t[]= "MY Window";
	InitWindow(width, height, t);

	// For our two rectangles
	const float l_recStart = 100;
	const float r_recStart = 1100;
	const float rec_width= 20;
	const float rec_height = 300;

	const float middle = 350;	
	
	// For our circle
	const double radius = 15.0;
	const float pos_x = width / 2;
	const float pos_y = height / 2;
	const float move_x = 10;
	const float move_y = 10;
	
	// rectangles	
	Rectangle l_rec = {l_recStart, middle, rec_width, rec_height };
	Rectangle r_rec = {r_recStart, middle, rec_width, rec_height };
	
	// vectors idk	
	Vector2 l_recPos = { l_recStart, middle };
	Vector2 r_recPos = { r_recStart, middle }; 
	Vector2 ballPos = { pos_x, pos_y };
	
	Vector2 ballMovement = { move_x, move_y };	
	Vector2 recMovement = { move_x, move_y };	
		

	SetTargetFPS(60);

	while(!WindowShouldClose()){
	
	// Moving our rectangle
		
	if (IsKeyDown(KEY_UP)) l_rec.y += recMovement.y;
	if (IsKeyDown(KEY_DOWN)) l_rec.y -= recMovement.y;


	BeginDrawing();
		
	DrawRectangleRec(l_rec, RAYWHITE);
	DrawRectangleRec(r_rec, RAYWHITE);

	
	DrawCircleV(ballPos, radius, RAYWHITE);

	EndDrawing();
	
	}

	CloseWindow();

	return 0;
}






