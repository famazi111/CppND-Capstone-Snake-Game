#ifndef RENDERER_LEVEL2_H
#define RENDERER_LEVEL2_H

#include "SDL.h"
#include "renderer.h"
#include "snake.h"
#include <vector>

class ObstacleRenderer : public Renderer {
public:
  ObstacleRenderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
      : Renderer(screen_width, screen_height, grid_width, grid_height) {

    obstacle1.w = grid_width;
    obstacle1.h = screen_height;
    obstacle1.x = 0;
    obstacle1.y = 0;

    obstacle2.w = screen_width;
    obstacle2.h = grid_width;
    obstacle2.x = 0;
    obstacle2.y = 0;

    obstacle3.w = grid_width;
    obstacle3.h = screen_height;
    obstacle3.x = screen_width - grid_width;
    obstacle3.y = 0;

    obstacle4.w = screen_height;
    obstacle4.h = grid_width;
    obstacle4.x = 0;
    obstacle4.y = screen_height - grid_height;
  }

  void Render(Snake const snake, SDL_Point const &food);
  bool collision(Snake);
  bool ObstacleCell(int, int);
};

#endif