#include "game_client/include/main.h"
#include "game_client/include/GameClient.h"

int main() {
  //TODO Add a gameInit method
  auto client = game_client::GameClient();

  //TODO Add game loop here
  /*
   * Handle input
   * Send to server
   * Wait for logic from server
   * Update objects
   * Draw screen
   * Play sounds
   */

  //TODO Remove debug calls below

  client.UpdatePhysics();
  client.DrawGraphics();
  //To here
}