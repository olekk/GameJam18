#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <iostream>
#include <string>
#include <sftools/Chronometer.hpp>
#include "PLAYER.h"
#include <fstream>


using namespace std;
using namespace sf;
using namespace sftools;


array<string, H> TileMap;// = Poziom1;

array<string, H> Poziom1;
array<string, H> Poziom2;
array<string, H> Poziom3;
array<string, H> Poziom4;


string ito_string(int n)
{
     string tmp, ret;
     if(n < 0) {
      ret = "-";
      n = -n;
     }
     do {
      tmp += n % 10 + 48;
      n -= n % 10;
     }while(n /= 10);

     for(int i = tmp.size()-1; i >= 0; i--) ret += tmp[i];
     return ret;
}

void mapUpload()
{
    //int lvlcount = 4;
    fstream plik;
    string filename="PoziomN.txt";
    array<string, H> dane;
    int a;
    for(int i=1; i<=4; i++)
    {
        a=0;
        filename[6]=i+48;
        plik.open(filename, ios::in);
        while(!plik.eof())
        {
            getline(plik, dane[a]);
            cout<<a<<endl;
            a++;
        }

        plik.close();

        switch(i)
        {
            case 1: { Poziom1=dane; break;}
            case 2: { Poziom2=dane; break;}
            case 3: { Poziom3=dane; break;}
            case 4: { Poziom4=dane; break;}
        }
    }


}




int main()
{
    mapUpload();

    RenderWindow window(VideoMode(800, 600), "Pazienza");

    Texture niebo;
    niebo.loadFromFile("media/pattern.png");
    Sprite pattern(niebo);

    Font agency;
    Font matura;
    agency.loadFromFile("media/AGENCYB.TTF");
    matura.loadFromFile("media/MATURA.TTF");
    RectangleShape *przycisk = new RectangleShape[4];
    RectangleShape zaslona(Vector2f(800, 600));
    zaslona.setFillColor(Color::Black);
    Text napis[6];
    for(int i=0;i<6;i++)    //wszystkie napisy
    {
        napis[i].setFont(agency);
    }

    for(int i=0;i<4;i++) //prostokaty przyciskow i ich napisy
    {
        przycisk[i].setFillColor(Color::Black);
        przycisk[i].setSize(Vector2f(300, 50));
        przycisk[i].setPosition(250,(i*80)+130 );

        napis[i].setCharacterSize(50);
        napis[i].setPosition(270, (i*80)+120);
    }

    RectangleShape nextprzy(Vector2f(150,75));
    nextprzy.setFillColor(Color::Black);
    nextprzy.setPosition(600,130);
    Text nextnapi;
    nextnapi.setFont(agency);
    nextnapi.setCharacterSize(30);
    nextnapi.setString("Nastepny\npoziom");
    nextnapi.setPosition(610, 130);

    //nie-przyciski
    napis[4].setCharacterSize(80);
    napis[4].setFont(matura);
    napis[5].setCharacterSize(70);
    napis[4].setPosition(235, 10);
    napis[5].setPosition(255, 470);
    napis[5].setColor(Color(237, 28,36));

    napis[4].setString("Pazienza");
    napis[0].setString("Play again");
    napis[1].setString("Resume");
    napis[2].setString("Game Tutorial");
    napis[3].setString("Credits");
    napis[5].setString("Good luck!");

	Texture tileSet;
	tileSet.loadFromFile("media/tileset.png");

	Image ikona;
	ikona.loadFromFile("media/favicon.ico");
	window.setIcon(16, 16, ikona.getPixelsPtr());


    Texture tutor;
    tutor.loadFromFile("media/tutorial.png");
    Sprite tutorial(tutor);
    tutorial.setPosition(0,0);

    Texture winscre;
    winscre.loadFromFile("media/winscreen.png");
    Sprite winscreen(winscre);
    winscreen.setPosition(0,0);

    Texture napisykoncowe;
    napisykoncowe.loadFromFile("media/credits.png");
    Sprite credits(napisykoncowe);
    credits.setPosition(0,0);

	PLAYER Mario(tileSet);      //wyslanie tekstury


	Sprite tile(tileSet);

	SoundBuffer buffer;
	buffer.loadFromFile("media/Jump.ogg");
	Sound sound(buffer);
	sound.setVolume(100);

    Music music;
    music.openFromFile("media/Theme.ogg");
    music.play();
    music.setLoop(1);
    music.setVolume(100);

    Text licznik;
    licznik.setFont(agency);
    licznik.setCharacterSize(50);
    licznik.setPosition(710, 10);
    licznik.setOutlineColor(Color::Black);
    licznik.setOutlineThickness(1);

	Chronometer clock;
	Chronometer zegargry;
        zegargry.pause();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    while (window.isOpen())
    {
        int czasgry = zegargry.getElapsedTime().asSeconds();
        licznik.setString(ito_string(czasgry)+"s");
		float time = clock.getElapsedTime().asMicroseconds();
		clock.reset();
		clock.resume();

		time = time/650;

		if (time > 20) time = 20;

    Event event;
while (window.pollEvent(event))
{
    if (event.type == Event::Closed)
        window.close();
    if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
        window.close();

    if (event.type == Event::KeyPressed && event.key.code == Keyboard::P)
    {
        if(pauza) pauza=false;
        else pauza=true;
        boolcredits=false;
        booltutorial=false;
        boolwinscreen=false;
    }

    if (event.type == Event::KeyPressed && event.key.code == Keyboard::M)
    {
        if(music.getStatus()==2 && sound.getVolume()>0){ music.pause(); sound.setVolume(0); }
        else { music.play(); sound.setVolume(100); }
    }

    if( event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left &&
       przycisk[0].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && pauza) //Graj od nowa
    {
        aktualnyPoziom=1;
        Mario.rect.left=30*16; Mario.rect.top=70*16;
        offsetX = Mario.rect.left-400; offsetY = Mario.rect.top - 408;
        if(pauza) pauza=false;
        else { pauza=true; boolcredits=false; booltutorial=false; boolwinscreen=false;}
        zegargry.reset();
    }

    if( event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left &&
       Keyboard::isKeyPressed(Keyboard::F5) && !pauza) //cheat
    {
        cheat=true;
    }

    if( event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left &&
       przycisk[1].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && pauza) //Kontynuuj
    {
        if(pauza) pauza=false;
        else { pauza=true; boolcredits=false; booltutorial=false; boolwinscreen=false; }
    }

    if( event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left &&
       przycisk[2].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && pauza) //Jak grac
    {
        //Jak grac, wyswietla grafike
        booltutorial=true;
    }

    if( event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left &&
       przycisk[3].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && pauza) //Credits
    {
        //Credits, wyswietla grafike
        boolcredits=true;
    }

    if( event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left &&
       nextprzy.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && pauza) //Credits
    {
        aktualnyPoziom++;

        switch(aktualnyPoziom)
        {
            case 1: { Mario.rect.left=30*16; Mario.rect.top=66*16; break; }
            case 2: { Mario.rect.left=32*16; Mario.rect.top=66*16; break; }
            case 3: { Mario.rect.left=30*16; Mario.rect.top=70*16; break; }
            case 4: { Mario.rect.left=30*16; Mario.rect.top=70*16; break; }
        }
        if(pauza) pauza=false;
        else { pauza=true; boolcredits=false; booltutorial=false; boolwinscreen=false;}
    }
}

pattern.setPosition(-offsetX*0.5, -offsetY*0.5-10);

if(cheat)
{
    cheat=false;
    Mario.rect.left=Mouse::getPosition(window).x;
    Mario.rect.top=Mouse::getPosition(window).y;
    offsetX = Mario.rect.left-400; offsetY = Mario.rect.top - 408;
}

if (Keyboard::isKeyPressed(Keyboard::Left))    Mario.dx=-0.1;

if (Keyboard::isKeyPressed(Keyboard::Right))    Mario.dx=0.1;

if (Keyboard::isKeyPressed(Keyboard::Up))	if (Mario.onGround) { Mario.dy=-0.27; Mario.onGround=false;  sound.play();}
//PAUZA
if(!pauza)
{
     Mario.update(time);
     if(!clock.isRunning()) clock.resume();
     if(!zegargry.isRunning()) zegargry.resume();
}
else
{
    clock.pause();
    zegargry.pause();
}


switch(aktualnyPoziom)
{
    case 1: { TileMap=Poziom1; break; }
    case 2: { TileMap=Poziom2; break; }
    case 3: { TileMap=Poziom3; break; }
    case 4: { TileMap=Poziom4; break; }
    //default: { }  //ekran konca gry
}


if (Mario.rect.left>400 && Mario.rect.left<2000) offsetX = Mario.rect.left-400;    //poruszanie kamer¹
if(Mario.rect.left<=400) offsetX = 0;
if(Mario.rect.left>=2000) offsetX = 1600;
if(Mario.rect.top< 1057 && Mario.rect.top> 400) offsetY = Mario.rect.top - 408;   //z wyjatkiem gdy gracz jest blisko sciany
if(Mario.rect.top>=1057) offsetY = 648;
if(Mario.rect.top<=400) offsetY = -7;



window.clear(Color(107,140,255));

window.draw(pattern);

 for (int i=0; i<H; i++)
     for (int j=0; j<W; j++)
      {
        if (TileMap[i][j]=='P')  tile.setTextureRect( IntRect(143-16*3+1,112,16,16) );

        if (TileMap[i][j]=='k')  tile.setTextureRect( IntRect(143,112,16,16) );

        if (TileMap[i][j]=='c')  tile.setTextureRect( IntRect(143-16,112,16,16) );

        if (TileMap[i][j]=='G')  tile.setTextureRect( IntRect(145,222,222-145,255-222) );   //armaty

        //if (TileMap[i][j]=='t')  tile.setTextureRect( IntRect(0,47,32,95-47) );

        //if (TileMap[i][j]=='g')  tile.setTextureRect( IntRect(0,16*9-5,3*16,16*2+5) );  //górka

        //if (TileMap[i][j]=='d')  tile.setTextureRect( IntRect(0,106,74,127-106) );

        if (TileMap[i][j]=='w')  tile.setTextureRect( IntRect(99,224,140-99,255-224) ); //chmura

        if (TileMap[i][j]=='r')  tile.setTextureRect( IntRect(143-32,112,16,16) );

        if ((TileMap[i][j]==' ') || (TileMap[i][j]=='0')) continue;

        tile.setPosition(j*16-offsetX,i*16 - offsetY) ;
        window.draw(tile);
     }

cout<<aktualnyPoziom<<endl;



window.draw(Mario.sprite);
window.draw(licznik);
if(pauza)
{
    window.draw(zaslona);
    for(int i=0; i<4; i++) window.draw(przycisk[i]);
    for(int i=0; i<6; i++) window.draw(napis[i]);
    window.draw(nextprzy);
    window.draw(nextnapi);
    window.draw(licznik);
}

if(boolcredits && pauza) window.draw(credits);
if(booltutorial && pauza) window.draw(tutorial);
if(boolwinscreen && pauza) { window.draw(winscreen); window.draw(licznik); }

window.display();
}
    return 0;
}
