#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h> 
using namespace std;

#define KEY_UP 119
#define KEY_DOWN 115
#define KEY_LEFT 97
#define KEY_RIGHT 100

struct character_t
{
    string name;
    string role;
    int hp;
};

struct item_t
{
    string name;
    string type;
    int armorBuffeffect;
    int attackBuffeffect;
};


int main(){
    /*
    RULES
    1. lane (able)
    2. ambush (able || random find enemy 15%)
    3. puddle (able || random find item 10%)
    4. tree (disable)
    5. stone (disable)
    6. waters (able || random find item 10%)
    RULES TILE
    1. true jika ada di 1, 2, 3, 6
    DESAIN DATA
    MATRIKS LINGKUNGAN
    POSISI KARAKTER
    */

    character_t character[] = {
        {
            "Alu",
            "Fighter",
            1200
        }, 
        {
            "Eudo",
            "Mage",
            800
        },
        {
            "Mino",
            "Tank",
            1700
        },
        {
            "Miya",
            "Marksman",
            1000
        },
        {
            "Ling",
            "Assassin",
            900
        },
    };

    item_t item[] = {
        {
            "Tameng",
            "Armor",
            200,
            5
        }, 
        {
            "Kujang",
            "Attack",
            5,
            125
        },
        {
            "Zirah",
            "Armor",
            500,
            10
        },
        {
            "Keling",
            "Attack",
            0,
            75,
        },
        {
            "Trisula",
            "Attack",
            10,
            250
        },
    };

    int panjangMap = 10;    //x
    int lebarMap = 10;      //y
    
    int koorCharY = 0;
    int koorCharX = 0;
    
    cout << "u spawn at (" << koorCharY << ", " << koorCharX << ")" << endl
    << "use w,a,s,d to move" << endl;
    
    int map[lebarMap][panjangMap] = {
        {1,1,1,1,1,2,2,1,6,4},
        {4,4,4,1,2,2,2,6,6,4},
        {4,4,2,1,1,5,6,6,6,4},
        {1,1,1,1,6,6,6,6,2,2},
        {5,5,5,1,6,6,1,1,5,5},
        {5,5,2,1,1,1,1,1,4,4},
        {4,4,2,2,2,1,1,2,2,2},
        {4,5,1,1,1,1,2,2,2,4},
        {4,4,6,6,6,1,1,3,3,3},
        {1,1,1,5,5,2,3,3,3,3},
        {1,1,5,5,5,5,2,3,3,3},
    };
    
    int arrowKey = 0;
    while (1){
        
        // Input arrow key
        cout << "input arrow key :";
        arrowKey = (getch()); 
        cout << endl;
        
        // Bergerak ke atas
        if (arrowKey == 119 && (map[koorCharY-1][koorCharX] == 1 || map[koorCharY-1][koorCharX] == 4) && koorCharY >= 0){
            koorCharY = koorCharY-1;
        }
        // Bergerak ke bawah
        if (arrowKey == 115 && (map[koorCharY+1][koorCharX] == 1 || map[koorCharY+1][koorCharX] == 4) && koorCharY < lebarMap){
            koorCharY = koorCharY+1;
        }
        // Bergerak ke kiri
        if (arrowKey == 97 && (map[koorCharY][koorCharX-1] == 1 || map[koorCharY][koorCharX-1] == 4) && koorCharY >= 0){
            koorCharX = koorCharX-1;
        }
        // Bergerak ke kanan
        if (arrowKey == 100 && (map[koorCharY][koorCharX+1] == 1 || map[koorCharY][koorCharX+1] == 4) && koorCharY < panjangMap){
            koorCharX = koorCharX+1;
        }
        // Render
        for(int y=0; y<lebarMap; y++){
            for(int x=0; x<panjangMap; x++){
                if (koorCharX == x && koorCharY == y){
                    cout << 0 << " ";
                }
                else {
                    cout << map[y][x] << " ";
                }
            }
            cout << endl;
        }
        //Random trap and enemy
        int characterPosition=map[koorCharY][koorCharX];
        if (characterPosition==2)
        {
            int probabilityFindEnemy;
            srand (time(NULL));
            probabilityFindEnemy = rand() %15;

            if (probabilityFindEnemy<3)
            {
                cout << "u find the enemy" << endl
                << "ready to fight bruh !!" << endl;
            }
        }
        if (characterPosition==3 || characterPosition==6)
        {
            int probabilityFoundItem;
            srand (time(NULL));
            probabilityFoundItem = rand() %10;

            if (probabilityFoundItem<3)
            {
                cout << "u found item" << endl
                << "item will automatically saved" << endl;
            }
        }
    }
    return 0;
}
