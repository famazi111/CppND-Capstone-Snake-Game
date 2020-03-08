#include "obstaclerenderer.h"
#include <iostream>
#include <string>

void ObstacleRenderer::Render(Snake const snake, SDL_Point const &food) {

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render Obstacle 1
  SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 0, 0);
  SDL_RenderFillRect(sdl_renderer, &obstacle1);

  // Render Obstacle 2
  SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 0, 0);
  SDL_RenderFillRect(sdl_renderer, &obstacle2);

  // Render Obstacle 3
  SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 0, 0);
  SDL_RenderFillRect(sdl_renderer, &obstacle3);

  // Render Obstacle 4
  SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 0, 0);
  SDL_RenderFillRect(sdl_renderer, &obstacle4);
  // Render food
  RenderFood(food);

  // Render snake's body
  RenderBody(snake);

  // Render snake's head
  RenderHead(snake);

  SDL_UpdateWindowSurface(sdl_window);

  SDL_RenderPresent(sdl_renderer);
}

bool ObstacleRenderer::collision(Snake snake) {

  if ((block.w * static_cast<int>(snake.head_x) > obstacle1.x &&
       block.w * static_cast<int>(snake.head_x) <
           (obstacle1.x + obstacle1.w)) &&
      (block.h * static_cast<int>(snake.head_y) > obstacle1.y &&
       block.h * static_cast<int>(snake.head_y) <
           (obstacle1.y + obstacle1.h))) {
    return true;
  }

  if ((block.w * static_cast<int>(snake.head_x) > obstacle2.x &&
       block.w * static_cast<int>(snake.head_x) <
           (obstacle2.x + obstacle2.w)) &&
      (block.h * static_cast<int>(snake.head_y) > obstacle2.y &&
       block.h * static_cast<int>(snake.head_y) <
           (obstacle2.y + obstacle2.h))) {
    return true;
  }

  if ((block.w * static_cast<int>(snake.head_x) > obstacle3.x &&
       block.w * static_cast<int>(snake.head_x) <
           (obstacle3.x + obstacle3.w)) &&
      (block.h * static_cast<int>(snake.head_y) > obstacle3.y &&
       block.h * static_cast<int>(snake.head_y) <
           (obstacle3.y + obstacle3.h))) {
    return true;
  }

  if ((block.w * static_cast<int>(snake.head_x) > obstacle4.x &&
       block.w * static_cast<int>(snake.head_x) <
           (obstacle4.x + obstacle4.w)) &&
      (block.h * static_cast<int>(snake.head_y) > obstacle4.y &&
       block.h * static_cast<int>(snake.head_y) <
           (obstacle4.y + obstacle4.h))) {
    return true;
  }

  return false;
}

bool ObstacleRenderer::ObstacleCell(int x, int y) {

  if ((block.w * x >= obstacle1.x &&
       block.w * x <= (obstacle1.x + obstacle1.w)) &&
      (block.h * y >= obstacle1.y &&
       block.h * y <= (obstacle1.y + obstacle1.h))) {
    return true;
  }

  if ((block.w * x >= obstacle2.x &&
       block.w * x <= (obstacle2.x + obstacle2.w)) &&
      (block.h * y >= obstacle2.y &&
       block.h * y <= (obstacle2.y + obstacle2.h))) {
    return true;
  }

  if ((block.w * x >= obstacle3.x &&
       block.w * x <= (obstacle3.x + obstacle3.w)) &&
      (block.h * y >= obstacle3.y &&
       block.h * y <= (obstacle3.y + obstacle3.h))) {
    return true;
  }

  if ((block.w * x >= obstacle4.x &&
       block.w * x <= (obstacle4.x + obstacle4.w)) &&
      (block.h * y >= obstacle4.y &&
       block.h * y <= (obstacle4.y + obstacle4.h))) {
    return true;
  }

  return false;
}