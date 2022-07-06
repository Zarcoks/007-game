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

void game_start(){
    srand((unsigned int) time(0)); // permet random number

    cout << "\n\nFINE, lets start !" << endl;

    const int nb_possibilities = 3;
    string possibilites[nb_possibilities];
    possibilites[0] = "shield"; possibilites[1] = "bullet"; possibilites[2] = "shoot";
    string resp("");
    
    bool retry = true;
    while (retry){
        cout << "Please choose your action (\"shield\", \"bullet\", \"shoot\")" << endl;
        cout << "--> ";
        getline(cin, resp);
        while(!(in(resp, possibilites, nb_possibilities))){ // tant que resp n'est pas dans le tableau des possibilites
            cout << "That's not a good answer !" << endl << "retry --> ";
            getline(cin, resp);
        }
    }
}

void preview(){
    cout << "Hey, welcome to my program !" << endl;
    cout << "Do you know what 007 game is ?" << endl;
    cout << "You have 3 choices : you choose between \"bullet reload\", \"shield\", and \"shoot\" " << endl;
    cout << "At beginning, you have 0 bullets, this is why you have to reload one." << endl;
    cout << "Your goal is to shoot you ennemy, when he is not wearing a shield, and same for your ennemy !" << endl;
    cout << "When you have 10 bullets, then you can shoot a mega bullet that will kill your ennemy, you can't so shield every round !" << endl;
    cout << "Is it good ? Let's play with the IA ^^" << endl;
    cout << "Are you ready?" << endl;
    cout << "--> ";
    string unsusefull_variable("");
    getline(cin, unsusefull_variable);

    game_start();
}


int main() {
    preview();
}
