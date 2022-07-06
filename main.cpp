#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

bool in(string elt, string tab[], int len){

    for (int i=0; i<len; i++){
        if (tab[i] == elt){
            return true;
        }
    }
    return false;
}

int result(string player, string ia){
    if (player == "shoot"){
        if (ia == "shoot") {cout << "That's draw !" << endl; return 11;} // case 1-1
        if (ia == "shield") {cout << "Your bullet has been blocked !" << endl; return 0;} // case 0-0
        if (ia == "bullet") {cout << "You killed IA !" << endl; return 10;} // case 1-0 (player win)
    }
    else if (player == "shield"){
        if (ia == "shoot") {cout << "IA bullet has been blocked !" << endl; return 00;} // case 0-0
        if (ia == "shield") {cout << "Nothing passed..." << endl; return 00;} // case 0-0
        if (ia == "bullet") {cout << "IA got 1 bullet !" << endl; return 003;} // case 0-0 with +1 IA bul
    }
    else if (player == "bullet"){
        if (ia == "shoot") {cout << "IA killed you !" << endl; return 01;} // case 0-1 (IA win)
        if (ia == "shield") {cout << "You got 1 bullet !" << endl; return 002;} // case 0-0 with +1 player bul
        if (ia == "bullet") {cout << "You and IA got 1 bullet !" << endl; return 004;} // case 0-0 with +1 IA bul and +1 player bul
    }
    return 8;
}

void game_start(){
    srand((unsigned int) time(0)); // permet random number
    cout << "\n\nFINE, lets start !" << endl;

    const int nb_possibilities = 3;
    string possibilites[nb_possibilities];
    possibilites[0] = "shield"; possibilites[1] = "bullet"; possibilites[2] = "shoot";
    string resp("");
    string ia_choice("");

    int player_bullets = 0;
    int ia_bullets = 0;
    
    bool retry = true;

    while(retry) {
        cout << "\n\n-- you have " << player_bullets << " bullets --" << endl;
        cout << "\nPlease choose your action (\"shield\", \"bullet\", \"shoot\")" << endl;
        cout << "--> ";
        getline(cin, resp);

        // security :
        while(!(in(resp, possibilites, nb_possibilities)) || (player_bullets <= 0 && resp == "shoot")){ // tant que resp n'est pas dans le tableau des possibilites
            cout << "That's not a good answer !" << endl << "retry --> ";
            getline(cin, resp);
        }

        // IA choice:
        ia_choice = "bullet";
        if(ia_bullets > 0) {
            ia_choice = possibilites[rand()%3];  // random choice max 2 
        }
        cout << "\nIA plays " << ia_choice << endl;


        // get the results:
        int results = result(resp, ia_choice);

        // exploit the results:
        switch (results)
        {
        case 11: // no winner
            retry = false;
            break;
        case 0: // game continue
            break;
        case 10:
            retry = false; // player win
            break;
        case 3: // IA get bullet
            ia_bullets += 1;
            break;
        case 1: // IA win
            retry = false;
            break;
        case 002: // player get bullet
            player_bullets += 1;
            break;
        case 004: // player and IA get bullet
            player_bullets += 1;
            ia_bullets += 1;
            break;
        
        default: // error case
            cout << "SWITCH ERROR";
            retry = false;
            break;
        }

        // case if bullets are >= 10 (win)
        if (player_bullets >= 10){cout << "You have 10 bullets, and decied to shoot a mega ball on IA... You won !" << endl; retry=false;}
        else if (ia_bullets >= 10){cout << "IA have 10 bullets, and decied to shoot a mega ball on you... You lose !" << endl; retry=false;}

    }
}

void preview(){
    cout << "\nHey, welcome to my program !" << endl;
    cout << "\nDo you know what 007 game is ?" << endl;
    cout << "\nYou have 3 choices : you choose between \"bullet reload\", \"shield\", and \"shoot\" " << endl;
    cout << "\nAt beginning, you have 0 bullets, this is why you have to reload one." << endl;
    cout << "\nYour goal is to shoot you ennemy, when he is not wearing a shield, and same for your ennemy !" << endl;
    cout << "\nWhen you have 10 bullets, then you can shoot a mega bullet that will kill your ennemy, you can't so shield every round !" << endl;
    cout << "\nIs it good ? Let's play with the IA ^^" << endl;
    cout << "\n\nAre you ready?" << endl;
    cout << "--> ";
    string unsusefull_variable("");
    getline(cin, unsusefull_variable);

    game_start();
}


int main() {
    preview();
}