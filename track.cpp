#include <iostream>
#include "raylib.h"

class Track{
private:
    Vector2 position;
    Vector2 size;
    Rectangle trackRect;
public:
    Track(Vector2 pos);
    Track(Vector2 pos, int numberOfTracks);
    void DrawTrack();


    Track::Track(Vector2 pos){
        this->position = pos;
        this->size = {100,20};
        this->trackRect = {position.x, position.y, size.x, size.y};
    }

    Track::Track(Vector2 pos, int numberOfTracks){
        this->position = pos;
        this->size = {100,20};
        for (size_t i = 1; i <= numberOfTracks; i++)
        {
            this->trackRect={position.x + 10 + (100 * i), position.y,size.x,size.y};
        }
    }
        
    };