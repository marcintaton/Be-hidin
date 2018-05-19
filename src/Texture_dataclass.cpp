#include "Texture_dataclass.h"

std::map<std::string, std::vector<std::string>> Texture_dataclass::paths = {

    {"map_tiles", {"assets/wall.png", "assets/platform.png", "assets/sky.png"}},
    {"player_idle",
     {"assets/player/Idle__000.png", "assets/player/Idle__001.png",
      "assets/player/Idle__002.png", "assets/player/Idle__003.png",
      "assets/player/Idle__004.png", "assets/player/Idle__005.png",
      "assets/player/Idle__006.png", "assets/player/Idle__007.png",
      "assets/player/Idle__008.png", "assets/player/Idle__009.png"}},
    {"player_run",
     {"assets/player/Run__000.png", "assets/player/Run__001.png",
      "assets/player/Run__002.png", "assets/player/Run__003.png",
      "assets/player/Run__004.png", "assets/player/Run__005.png",
      "assets/player/Run__006.png", "assets/player/Run__007.png",
      "assets/player/Run__008.png", "assets/player/Run__009.png"}}

};
