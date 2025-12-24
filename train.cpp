#include <iostream>
#include "raylib.h"
#define TURN_SPEED 0.01f
#define SPEED 0.01f
class train
{
private:
    Vector2 position;
    Vector2 size;
    float speed;
    std::string id;
    float angle = 360.0f;
    Rectangle trainRect;
public:
    train(Vector2 pos, Vector2 size, float spd);
    train();
    train(Vector2 pos, float spd);

    void SwitchTrackUp();
    void DrawTrain();
    void Move();
    void Turn(float angle);

    float getAngle();
    void setAngle(float angle);
    Vector2 getPosition();
    Vector2 getSize();
    void SetPosition(float x, float y);
    void SetPosition(Vector2 pos);
    ~train();
};

train::train(Vector2 pos, Vector2 size, float spd)
{
    this->position = pos;
    this->size = size;
    this->speed = spd;
    this->trainRect = {this->position.x, this->position.y, size.x, size.y};
}

train::train(Vector2 pos, float spd){
    this->position = pos;
    this->size = {100,50};
    this->speed = spd;
    this->trainRect = {pos.x, pos.y, 100, 50};
}

train::train()
{
    this->position = {0,0};
    this->size = {100,50};
    this->speed = 0.1f;
}

void train::DrawTrain(){
    DrawRectanglePro(this->trainRect, {this->size.x/2, this->size.y/2}, this->angle, BLUE);    
    //DrawRectangleRec({this->position.x, this->position.y, this->size.x, this->size.y}, RED);
}


void train::SwitchTrackUp(){
    if(this->angle >= 315.0f && this->trainRect.y > 200){
        this->angle -= TURN_SPEED;
    }
    if(this->angle <= 315.0f && this->trainRect.y > 100){
        this->trainRect.y -= SPEED;
        this->trainRect.x += SPEED;
    }
    if(this->trainRect.y <= 100 && this->angle < 360.0f){
        std::cout << "Third condtion met" << std::endl;
        this->angle += TURN_SPEED;
    }
}


void train::Move(){
    this->trainRect.x += SPEED;
}

void train::Turn(float angle){
    this->angle += angle;
}

Vector2 train::getPosition(){
    return {this->trainRect.x, this->trainRect.y};
}

void train::SetPosition(Vector2 pos){
    this->trainRect.x = pos.x;
    this->trainRect.y = pos.y;
}

void train::SetPosition(float x, float y){
    this->trainRect = {x,y};
}

float train::getAngle(){
    return this->angle;
}

void train::setAngle(float angle){
    this->angle = angle;
}

Vector2 train::getSize(){
    return this->size;
}

train::~train()
{
}
