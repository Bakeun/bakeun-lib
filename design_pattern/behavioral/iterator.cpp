#include "iostream"
#include "string"
#include <stdlib.h>
using namespace std;

/*
    encapsulate the traversal of collection classes
    behind the interface “first..next..isDone”
*/

int global_release_order = 1;
class Game
{
private:
    string game_name;
    int play_time;
    int release_order;
public:
    Game(string game_name){
        this->game_name = game_name;
        this->play_time = 0;
        this->release_order = global_release_order++;
    }
    void play_game(int play_time){
        this->play_time += play_time;
    }
    void print_info(void){
        cout << "===== " << this->game_name << " =====" << endl;
        cout << "release_order: " << this->release_order << endl;
        cout << "play_time: " << this->play_time << endl;
        cout << endl;
    }
};

class GameLibrary
{
private:
    Game* my_games[10];
    int owned_games;
    int index_interator;
public:
    GameLibrary(){
        this->owned_games = 0;
        this->index_interator = 0;
    }
    void first(){
        this->index_interator = 0;
    }
    void next(){
        if(index_interator < owned_games){
            this->index_interator++;
        }
    }
    bool is_done(){
        return (index_interator >= owned_games);
    }
    Game* current_game(){
        if(is_done()){ return my_games[owned_games-1]; }
        return my_games[index_interator];
    }
    void buy_the_game(Game* new_game){
        owned_games++;
        my_games[owned_games-1] = new_game;
    }
};

int main(int argc, char** argv)
{
    Game* FF  = new Game("Final Fantasy 6");
    Game* DMC = new Game("Devil May Cry");
    Game* USP = new Game("Ultra Street Fighter 4");
    Game* BH  = new Game("BioHazad 7");
    Game* AC  = new Game("Batman: Arkham City");

    GameLibrary my_lib;
    my_lib.buy_the_game(AC);
    my_lib.buy_the_game(DMC);
    my_lib.buy_the_game(USP);

    my_lib.first();
    srand(time(0));
    while(!my_lib.is_done()){
        Game* current = my_lib.current_game();
        current->play_game(rand()%(rand()%100));
        current->print_info();
        my_lib.next();
    }

    return 0;
}

/* result
===== Batman: Arkham City =====
release_order: 5
play_time: 20

===== Devil May Cry =====
release_order: 2
play_time: 53

===== Ultra Street Fighter 4 =====
release_order: 3
play_time: 13

*/
