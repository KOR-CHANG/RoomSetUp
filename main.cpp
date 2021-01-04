#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
struct Person
{
    char name[20];
    int age;
    int roomNum;
    int clone; //0: human, 1: clone
};
struct Room{
    char players[100];
    int count;
};
int main() {
    srand((unsigned int)(time(NULL)));
    struct Person player1 = {"Lee", 20, 0, 0};
    struct Person player2 = {"Kim", 21, 0, 0};
    struct Person player3 = {"Park", 22, 0, 0};
    Room room1 = {"", 0};
    Room room2 = {"", 0};


    strcat_s(room1.players, player1.name);
    player1.roomNum = 1;
    strcat_s(room1.players, player2.name);
    player2.roomNum = 1;
    for (int i = 0; i < 2; i++)
    {
        if(player1.name && player2.name)
        {
            room1.count += 1;
        }
    }
    if (room1.count >= 2)
    {
        strcat_s(room2.players, player3.name);
        player3.roomNum = 2;
        if (rand() % 2 + 1 == 1)
        {
            strcat_s(room2.players, player1.name);
            player1.roomNum = 2;
            player1.clone = 1;
        }else{
            strcat_s(room2.players, player2.name);
            player2.roomNum = 2;
            player2.clone = 1;
        }
    }
    cout << "name: " << player1.name << " roomNum: " << player1.roomNum << " clone: " << player1.clone << endl;
    cout << "name: " << player2.name << " roomNum: " << player2.roomNum << " clone: " << player2.clone << endl;
    cout << "name: " << player3.name << " roomNum: " << player3.roomNum << " clone: " << player3.clone << endl;
    return 0;
}