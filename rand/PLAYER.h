#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;


extern float offsetX, offsetY;


const int H = 80;   //wysokosc mapy
const int W = 150;  //szerokosc

extern array<string, H> Poziom1;
extern array<string, H> Poziom2;
extern array<string, H> Poziom4;
extern array<string, H> Poziom3;
extern array<string, H> TileMap;


extern int aktualnyPoziom;
extern bool cheat;
extern bool booltutorial;
extern bool boolwinscreen;
extern bool boolcredits;
extern bool pauza;


class PLAYER
{

    public:

    float dx , dy;      //predkosc w poziomie i w pionie
    FloatRect rect;     //prostokat (lewo, gora, szerokosc, wysokosc)
    bool onGround;
    Sprite sprite;
    float currentFrame;     //aktualna klatka animacji

        PLAYER(Texture &image)  //konstruktor i referencja na teskture podan¹ w main
        {
            sprite.setTexture(image);
            rect = FloatRect(30*16,66*16,16,16);    //tekstura gracza                                      //SPAWN   (3*16,66*16,16,16)

            dx=dy=0.1;
            currentFrame = 0;       //klatka animacji 0
        }


       void update(float time); //przesuwanie ekranu

       void Collision(int num); //wykrywa kolizje i zmienia predkosc na 0

};
