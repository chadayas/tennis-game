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

struct TopBorder {
	Vector2 position;
	Vector2 size;
};

struct BottomBorder {
	Vector2 position;
	Vector2 size;
};

// Window size

	const int screen_width= 1200;
	const int screen_height = 1000;
	
	const char t[]= "Tennis Game";
	const char start[] = "Welcome";
	const char press[] = "Press SPACE to start";
	
	// For our two rectangles
	const float l_recStart = 100;
	const float r_recStart = 1100;
	const float rec_width= 20;
	const float rec_height = 300;

	const float middle = 350;	
	
	// For our circle
	float radius = 15.0;
	const float center_x = screen_width / 2;
	const float center_y = screen_height / 2;
	const float move_x = 5;
	const float move_y = 5;
	int fontSize = 15;
	
	bool moveBall = false;


	// name for our structs
	
	leftRectangle l_rec;
	leftRectangle r_rec;
	Ball ball;
	TopBorder top_border;
	BottomBorder bottom_border;
	
	// movement vectors

	Vector2 ballMovement = { move_x, move_y };	
	Vector2 recMovement = { move_x, move_y };	

	void StartScreen(){
		
		DrawText(start, center_x, center_y, fontSize, RAYWHITE);
	}

	void PlayerMovement(){
		if (IsKeyDown(KEY_UP)) l_rec.position.y -= recMovement.y;
		if (IsKeyDown(KEY_DOWN)) l_rec.position.y += recMovement.y;
	}
	void ComputerMovement(){


	}

	
	
	void BallMovement(){
	  	ball.position.x +=- 2 * ballMovement.x;
		ball.position.y +=  ballMovement.y;
	
	}


int main(){


	InitWindow(screen_width, screen_height, t);
	
	// rectangles, ball, and border init
	
	l_rec.position = Vector2{ l_recStart, middle };
	r_rec.position = Vector2{ r_recStart, middle }; 

	l_rec.size = Vector2{rec_width, rec_height};
	r_rec.size = Vector2{rec_width, rec_height};
	
	bottom_border.position = Vector2{1,screen_height - 20};
	bottom_border.size = Vector2{screen_width, rec_width};	
	
	top_border.position = Vector2{1,1};
	top_border.size = Vector2{screen_width, rec_width};

 	ball.position = Vector2{ center_x, center_y};
	ball.radius = radius;	
		

	SetTargetFPS(60);


	while(!WindowShouldClose()){
		
		ClearBackground(BLACK);
  	
		Rectangle player_rec = {l_rec.position.x, l_rec.position.y
			,l_rec.size.x, l_rec.size.y };
		
		Rectangle computer_rec = {r_rec.position.x, r_rec.position.y
			, r_rec.size.x, r_rec.size.y };
		
		Rectangle topBorder = {top_border.position.x, top_border.position.y
			,top_border.size.x, top_border.size.y };
		
		Rectangle bottomBorder = {bottom_border.position.x, bottom_border.position.y
			,bottom_border.size.x, bottom_border.size.y };




		// move the circle 
		
		if (IsKeyPressed(KEY_SPACE)) moveBall = true;
		else if (IsKeyPressed(KEY_P)) moveBall = false;

		if (moveBall){
			ball.position.x +=- 2 * ballMovement.x;
			ball.position.y +=  ballMovement.y;

			r_rec.position.y += ballMovement.y;
		}
	
			// Ball collision logic
		
		if (CheckCollisionCircleRec(ball.position, ball.radius, player_rec))  
			ballMovement.x *= -1;
		
		if (CheckCollisionCircleRec(ball.position, ball.radius, topBorder))
			ballMovement.y *= -1;
	
		if (CheckCollisionCircleRec(ball.position, ball.radius, bottomBorder))
			ballMovement.y *= -1;
		if (CheckCollisionCircleRec(ball.position, ball.radius, computer_rec))  
			ballMovement.x *= -1;
		


		//if (CheckCollisionRecs(bottomBorder, computer_rec) ||
		//CheckCollisionRecs(topBorder, computer_rec))
		//	r_rec.position.y *= -1;	
		
		
		BeginDrawing();

		PlayerMovement();
		

		DrawRectangleV(l_rec.position, l_rec.size, RAYWHITE);
		DrawRectangleV(r_rec.position, r_rec.size, RAYWHITE);
	
		// top and bottom borders
		
		DrawRectangleV(top_border.position, top_border.size,RAYWHITE);
		DrawRectangleV(bottom_border.position, bottom_border.size,RAYWHITE);
		
		DrawCircleV(ball.position, ball.radius, RAYWHITE);

		EndDrawing();
	
	}

	CloseWindow();

	return 0;
}






