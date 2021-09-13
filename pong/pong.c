// TODO: heading
//

// TODO: clean up - remove unneeded comments
//:i TODOs
// > inline TODOs (do a search 'TODO')
// - copy over play source code files
// - think about is clamp a useful thing to have
// - serve state, play state
// - - serve: ball position is reset
// - - serve: ball stays until key press to start round
// - - play: ball goes off side: set to serve state, reset ball

// NOTES
// - ...

// BUGS

// "" includes: relative to current path
// <> includes: where the compiler looks for headers (-I)
#include <play.h>
#include <utility.h>
#include <ascii.h>
#include <dos.h>
#include <conio.h>

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define SCREEN_W        22
#define SCREEN_H        14
// note: minimum x and y is 1 in turbo C
#define MAX_X           SCREEN_W
#define MAX_Y           SCREEN_H
#define MIN_X           1
#define MIN_Y           1
#define CHAR_PADDLE     10
#define PADDLE_SIZE     3
#define PADDLE_SIZE     3
#define SERVE_COUNTER   3
#define CHAR_BALL       7
#define INITIAL_BALL_Y  (SCREEN_H / 2)
#define INITIAL_BALL_X  (SCREEN_W / 2)


// game data

bool serve = true;


typedef struct
{
    int x;
    int y;
    int dx;
    int dy;
    char ch;
    int fc;
    int bc;
    int score;
} GameObject;


// initialize a struct all at once
GameObject ball = {
    .x = INITIAL_BALL_X,
    .y = INITIAL_BALL_Y,
    .dx = 1, 
    .dy = 1,
    .ch = CHAR_BALL,
    .bc = BLUE,
    .fc = WHITE, 
    .score = 0,
};

GameObject paddle_left = { 
    .x = MIN_X,
    .y = SCREEN_H/2,
    .dx = 0,
    .dy = 0,
    .ch = CHAR_PADDLE,
    .fc = GREEN, 
    .bc = BLUE,
    .score = 0,
};

GameObject paddle_right = { 
    .x = MAX_X, 
    .y = SCREEN_H/2, 
    .dx = 0, 
    .dy = 0,
    .ch = CHAR_PADDLE,
    .fc = RED, 
    .bc = BLUE,
    .score = 0,
};

void KeepObjectInBounds(GameObject * paddle)
{
    clamp(&paddle->y, MIN_Y + 1, MAX_Y - 2);
}

void SetServeState()
{
    serve = true;
        
    ball.x = INITIAL_BALL_X;
    ball.y = INITIAL_BALL_Y;
    ball.dx = 0;
    ball.dy = 0;    
}

void SetPlayState()
{
    serve = false;

    srand((unsigned)time(NULL));
    
    ball.dx = rand() % 1000 < 500 ? 1 : -1;
    ball.dy = rand() % 1000 < 500 ? 1 : -1;
}

bool GetInput(int key)
{
    switch (key) {
        case 'w': 
            --paddle_left.y; 
            break;
        case 's': 
            ++paddle_left.y; 
            break;
        case 'i': 
            --paddle_right.y; 
            break;
        case 'k': 
            ++paddle_right.y; 
            break;
        case ' ':
            if ( serve ) {
                SetPlayState();
            }
            break;
            
        default: break;
    }
 
    KeepObjectInBounds(&paddle_right);
    KeepObjectInBounds(&paddle_left);
    
    return true;
}

void MoveBallToPreviousPosition() 
{
    ball.x -= ball.dx;
    ball.y -= ball.dy;
}


void UpdateGame()
{
    ball.x += ball.dx;  // put it back
    ball.y += ball.dy;  // put it back      
    
    
    if (ball.x == MAX_X + 1) {
        paddle_left.score++;
        play(NOTE_C, 4, 16, 120);
        play(NOTE_F_SHARP, 3, 16, 120);
        SetServeState();
    }

    if (ball.x == MIN_X - 1) {
        paddle_right.score++;
        play(NOTE_C, 4, 16, 120);
        play(NOTE_F_SHARP, 3, 16, 120);
        SetServeState();      
    }
    
    // ball bounces from bottom/top margins
    if ( ball.y == MAX_Y + 1 || ball.y ==  MIN_Y ) {
        MoveBallToPreviousPosition();
        ball.dy = -ball.dy;
    }

    // ball bounce from paddle     
    int hit_ch = getscreench(ball.x, ball.y);
    if (hit_ch == CHAR_PADDLE) {
        MoveBallToPreviousPosition();
        play(NOTE_C, 4, 32, 200); //TODO make shorter sound
        ball.dx = -ball.dx;
    }
}

void DrawGameObject(GameObject * obj)
{
    gotoxy(obj->x, obj->y);
    textcolor(obj->fc);
    textbackground(obj->bg);
    putch(obj->ch);
}

void DrawPaddle(GameObject * paddle)
{
    textcolor(paddle->fc);
    textbackground(paddle->bc);

    for ( int y = paddle->y; y < paddle->y + PADDLE_SIZE; y++ ) {
        gotoxy(paddle->x, y);
        putch(paddle->ch);
    }
}

void PrintScore()
{
    gotoxy (MIN_X, MIN_Y);
    textcolor(GREEN);
    cprintf("GREEN=%d", paddle_left.score); // TODO: player label needed?

	for (int i = 0; i < PADDLE_SIZE*5; i++) {
		cprintf(" ");
	}

    gotoxy(MAX_X - 5, MIN_Y);
    textcolor(RED);
    cprintf("RED=%d", paddle_right.score);
}

void DrawGame()
{
    clrscr();
    
    // TODO: Print... might be better
    DrawGameObject(&ball);
    DrawPaddle(&paddle_left);
    DrawPaddle(&paddle_right);
    PrintScore(); // TODO: consistent naming
}

int main()
{
    setscale(4);
    textmode(C40);
    setcursor(0);
    setscreensize(SCREEN_W, SCREEN_H);
    initdos();
    setbordercolor(BLUE);
    
    int ticks = 0;
    while (1) {
        if ( kbhit() ) {
            GetInput(getch());
        }

        if ( ticks % 5 == 0 ) {
            if (!serve) {
                UpdateGame();
            }
            DrawGame();
        }
        
        refresh();
        ticks++;
    }
    
    return 0;
}
