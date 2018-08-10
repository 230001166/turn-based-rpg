#ifndef RENDERER_H
#define RENDERER_H
#include "tileMap.h"
#include "Entity.h"

class Renderer
{
    public:
        Renderer();
        virtual ~Renderer();

        void render (tileMap tilemap, Entity player, int playerX, int playerY);

    protected:

    private:
};

#endif // RENDERER_H
