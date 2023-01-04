#include "Lable.hpp"
#include "Board.hpp"
#include <map>
#include <raylib.h>


typedef enum 
{
  EMPTY = 0,
  RUNNING,
  WON,
  OVER,
}GameState;

class Game
{
public:
    Board board;
private:
    GameState state;
    const std::map<GameState, std::vector<Lable>> menues =
    {
        {EMPTY, {Lable(0, 0, "click")}},
        {RUNNING, {}},
        {WON, {Lable(0, 0, "You Won!")}},
        {OVER, {Lable(0,0, "Game Over!"), Lable(100, 100, "press `r` to try again")}},
    };
public:
    Game();
    void tick();
    void gameLoop();
private:
    void update();
    void draw() const;
};
