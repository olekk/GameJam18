#include <SFML/Graphics.hpp>
#include "PLAYER.h"
#include <iostream>

using namespace std;
using namespace sf;

float offsetX=0;
float offsetY=0;


int aktualnyPoziom =1;
bool cheat=0;
bool booltutorial=0;
bool boolwinscreen=0;
bool boolcredits=0;
bool pauza=1;



void PLAYER::update(float time)      //pobrany czas z clock jako mikrosekundy
{

    rect.left += dx * time;    //wspolrzedne lewej sciany tesktury playera
    Collision(0);                  //wylaczenie zatrzymania gracza


    if (!onGround) dy=dy+0.0005*time;      //skok
    rect.top += dy*time;                               //skok
    onGround=false;                                   //opadanie
    Collision(1);                  //wlaczenie zatrzymania


    currentFrame += time * 0.005;
    if (currentFrame > 3) currentFrame -= 3;       //3 powtarzajace sie klatki


    if (dx>0) sprite.setTextureRect(IntRect(112+31*int(currentFrame),144,16,16));        //animacja przy ruchu w prawo
    if (dx<0) sprite.setTextureRect(IntRect(112+31*int(currentFrame)+16,144,-16,16));    //animacja przy ruchu w lewo


    sprite.setPosition(rect.left - offsetX, rect.top - offsetY);               //ustawianie pozycji

    dx=0;              //zerownie predkosci
}


void PLAYER::Collision(int num)                  //metoda kolizji przyjmujaca 1 lub 0
{

	for (int i = rect.top/16 ; i<(rect.top+rect.height)/16; i++)        //wspolrzedne na mapie x
		for (int j = rect.left/16; j<(rect.left+rect.width)/16; j++)        // y
			 {
				 if ((TileMap[i][j]=='P') || (TileMap[i][j]=='k') || (TileMap[i][j]=='0') || (TileMap[i][j]=='r') || (TileMap[i][j]=='t'))
				                         {        //przy ktorych obiektach ma reagowac ^
												   if (dy>0 && num==1)  //przy spadaniu
												   { rect.top =   i*16 -  rect.height;  dy=0;   onGround=true; }
											       if (dy<0 && num==1)      //porusza sie w gore przy w³¹czonej kolizji - uderzenie od do³u
												   { rect.top = i*16 + 16;   dy=0;}
												   if (dx>0 && num==0)      //zatrzymanie w poziomie przy ruchu w prawo
												   { rect.left =  j*16 -  rect.width; }
											       if (dx<0 && num==0)      //w poziomie w lewo
												   { rect.left =  j*16 +16;}
										 }

				 if (TileMap[i][j]=='c') {
                                                ++aktualnyPoziom;
                                                if(aktualnyPoziom>5) aktualnyPoziom=1;
                                                switch(aktualnyPoziom)
                                                {
                                                    case 1: { rect.left=30*16; rect.top=66*16; break; }
                                                    case 2: { rect.left=32*16; rect.top=66*16; break; }
                                                    case 3: { rect.left=30*16; rect.top=70*16; break; }
                                                    case 4: { rect.left=15*16; rect.top=70*16; break; }
                                                    case 5: { boolwinscreen=true; pauza=true;}
                                                }
                                                offsetX = rect.left-400; offsetY = rect.top - 408;
			                          	 }
			 }

}
