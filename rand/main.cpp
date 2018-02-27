#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <iostream>
#include <string>
#include <sftools/Chronometer.hpp>

using namespace sf;
using namespace std;
using namespace sftools;

float offsetX=0, offsetY=0;


const int H = 80;   //wysokosc mapy
const int W = 150;  //szerokosc

String Poziom1[H] = {
"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                       k  kkkkkkkkk                                                                 0",
"0                                                                                k      k                 k                             k            0",
"0                                                                    kkkkkkkkk   k        k                                        k        cccccccc 0",
"0                                                                             k  k                    k       k                k            cccccccc 0",
"0                                                                                k           k    k                        k                kkkkkkkk 0",
"0                                                          kk             kkkkkkkk                                      k                            0",
"0                                                    kk          k    k                                            k                                 0",
"0                                         kkkkkkk                kkkkkk                                                                              0",
"0                                         k                                                                                                          0",
"0                                         k              k           k          k        k      k            k             k         k         k     0",
"0      kkkk   k    k   k   k   k kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk0",
"0         k                      k                                                                                                                   0",
"0   k     k                      k                                                                     kkk   kkk   kkk  kkk     kkkkk  kkk  kkk      0",
"0         k                      k                                                                    k   k k   k k   k k  k    k     k   k k  k     0",
"0        kk                      k                                                                    k     k   k k   k k  k    k     k   k k k      0",
"0         k      k               k                                                                    k  kk k   k k   k k  k    k     k   k kk k     0",
"0 k       k                      k                                                                    k   k k   k k   k k  k    k   k k   k k  k     0",
"0         k   k       k          k                                                                     kkk   kkk   kkk  kkk      kkk   kkk  kkk      0",
"0       k k                      k                                                                                                                   0",
"0         k               k      k                                                                                                                   0",
"0 k       k   k              k   k                                                                                                                   0",
"0             k                  k                                                     0                                                             0",
"0kkkkkkkkkkkkkk                k k                                                     0                                                             0",
"0                         k      k                                                     0                                                             0",
"0                     k          k                                                     0                                                             0",
"0                                k                                                     0                                                             0",
"0           kkkkkk               k                                                     0                                                             0",
"0      k                         k             k                          kkkkkkkkkkk  0                                                             0",
"0                                k   0          k                        k           k 0                                                             0",
"0   k                            k   kkkkkkkkkkkkk                       k           k 0                                                             0",
"0                                k              k                   0000k kkk kkkk    k                                                              0",
"0       k   k    k          k    k             k                    0   k  kk   kk kk  k                                                             0",
"0       kkkkk    kkkkkkkkkkkk                                     00     k k  k     kk k                                                             0",
"0                                      k                         0       k  kk   kkk k k                                                             0",
"0                                kkkkkkk                         0       kkkkkkkk k   k                                                              0",
"0                            k   k      0000000kkkkkkkkkkkkkkkkkk        k k k k k   k                                                               0",
"0        kk   kkk  k       k     k                                      k kkkkkkk   k                                                                0",
"0                  kkkkkkkkk     k                                      k         kk                                                                 0",
"0    k                    k      k                                      k     kkkk                                                                   0",
"0                         k      k                                       kkkkk                                                                       0",
"0                         k      k                                                                                                                   0",
"0  k  kkkkkkkkkkkkkkkkkkkkk      k                                                                                                                   0",
"0                                k                                                                                                                   0",
"0    k                     k     k                                                                                                                   0",
"0    kkkkkkkkkkkkkkkkkkkkkkk     k                                                                                                                   0",
"0                                k                                                                                                                   0",
"0                             k  k                                                                                                                   0",
"0                                k                                                                                                                   0",
"0                         kkk    k                                                                                                                   0",
"0            kkkkkkkkkkkk        k                                                                                                                   0",
"0                       k        k                                                                                                                   0",
"0                       k        k                                                                                                                   0",
"0       kkkkkkkkkkkkk   k        k                                                                                                                   0",
"0                       k        k                                                                                                                   0",
"0             kkkkkkkkkkk        k                                                                                                                   0",
"0                                k                                                                                                                   0",
"0                                k                                                                                                                   0",
"0        k   k                   k                                                                                                                   0",
"0                                k                                                                                                                   0",
"0              kk                k                                                                                                                   0",
"0                                k                                                                                                                   0",
"0                                k                                                                                                                   0",
"0                  kk            k                                                                                                                   0",
"0                                k                                                                                                                   0",
"0                                k                                                                                                                   0",
"0          kkkkk                 k                                                                                                                   0",
"0                                k                                                                                                                   0",
"0                 k  k           k                                                                                                                   0",
"0                                k                                                                                                                   0",
"0                    k           k                                                                                                                   0",
"0                k               k                                                                                                                   0",
"0            k                   k                                                                                                                   0",
"0        k                       k                                                                                                                   0",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"
};

String Poziom2[H] = {   //mapa 150x80
"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                    ccccccccccc                                                                                     0",
"0                                                    ccccccccccc                                                                                     0",
"0                            k         k        k    kkkkkkkkkkk                                          k   k   k   k   k    k    k   k   kkkk     0",
"0                 k    kkkkkkkkkkkkkkkkkkkkkkkk                                                                                                      0",
"0       kk     k   k                                                                                                         kkkk         k          0",
"0                   k                                                                                                       k                        0",
"0    kk             k                                                                                                      k         k               0",
"0              k   k                                                                                                       k                         0",
"0       kk        k                                                                                                        k    k                    0",
"0                             kk          kk     k         k                                              k                k                         0",
"0           k                    kk        kk     k    k    k     k                                                         k                        0",
"0             kkk                         kk     k    k    k     k                         k                                 kkkk     k    k         0",
"0                               kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk  kk                                   k                 0",
"0                       kk                                                                            kk    k                     kk      k          0",
"0                 kk                                                                                                               k                 0",
"0                                                                                                                           kkkkkkkk          k      0",
"0                                                                                                                           k                        0",
"0                                                                                                                       kkkkk                k       0",
"0                                                                                                                   k        k                       0",
"0                                                                                                                           k              k         0",
"0                                                                            k             k           k         k          kkkkk   k              kk0",
"0              k           k              k                                                                                                          0",
"0kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk    k      k      kk        kk           kk          kk         kk         kk           kk        kk      0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                            k       k           k         k         k        k          k         k           k     0",
"0                                                                                                                                                    0",
"0                                                                      k           k         k       k        k        k         k          k        0",
"0                                                                                                                                                    0",
"0                                                  k             k           k          k       k        k        k         k         k         k    0",
"0                                                 kkk                                                                                                0",
"0                                                kk kk      kk        k         k         k      k       k       k        k        k        k        0",
"0                                               kk   kk     kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk0",
"0                                              kk     kk                                                                                             0",
"0                                             kk       kk                                                                                            0",
"0                                            kk         kk                                                                                           0",
"0                                           kk           kk                                                                                          0",
"0                                          kk             kk                                                                                         0",
"0                                         kk               kk                                                                                        0",
"0                                        kk                 kk                                                                                       0",
"0                                       kk                   kk                                                                                      0",
"0                                      kk                     kk                                                                                     0",
"0                                     kk                       kk                                                                                    0",
"0                                    kk       k       k         kk                                                                                   0",
"0                                                                kk                                                                                  0",
"0                               kk     kk                k        kk                                                                                 0",
"0                               kkkkkkk                      kkkkkkk                                                                                 0",
"0                               kkkkkkk            k         kkkkkkk                                                                                 0",
"0                                    kk                      kk                                                                                      0",
"0                                    kk     k                kk                                                                                      0",
"0                                    kk                      kk                                                                                      0",
"0                                    kk           k          kk                                                                                      0",
"0                                    kk                      kk                                                                                      0",
"0                                    kk                  k   kk                                                                                      0",
"0                                    kk                      kk                                                                                      0",
"0                                    kk           kk         kk                                                                                      0",
"0                                    kk                      kk                                                                                      0",
"0                                    kk                      kk                                                                                      0",
"0                                    kk     k                kk                                                                                      0",
"0                                    kk     kkkkkkkkkkkkkkkkkkk                                                                                      0",
"0                                    kk                      kk                                                                                      0",
"0                           kkkkkkkkkkkkk                    kkkkkkkkkkkkkkkkkkkk                                                                    0",
"0                           kkkkkkkkkkk                      kkkkkkkkkkkkkkkkkkkk                                                                    0",
"0                           kk            kk                                   kk                                                                    0",
"0                           kk                kk     k    k    k               kk                                                                    0",
"0                           kk                                                 kk                                                                    0",
"0                           kk                    kkk  kkk  kkk  kk            kk                                                                    0",
"0                           kk                                                 kk                                                                    0",
"0                           kk                                         kk      kk                                                                    0",
"0                           kk                                                 kk                                                                    0",
"0                           kk                                   kk            kk                                                                    0",
"0                           kk                                                 kk                                                                    0",
"0                           kk           kk       kk       kk                  kk                                                                    0",
"0                           kk     kk                                          kk                                                                    0",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"
};

String Poziom4[H] = {
"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0                                                                                                                                                    0",
"0                                                                                         cccccc                                                     0",
"0                                                                                         cccccc                                                     0",
"0                             k      k        k               k                     k     kkkkkk                                                     0",
"0                             kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk                                                                0",
"0                    k                                                                                                                               0",
"0                k                                                                                                                                   0",
"0           k                                                                                                                                        0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0k                                                                                                                                                   0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                   k0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0k                                                                                                                                                   0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0       k                                                                                                                                            0",
"0                                                                                                                                                    0",
"0               k           k        k        k       k      k       k                                                     k                         0",
"0                                                       kkkkkkkkk        k                                                              kkkkkkkkkkkk 0",
"0                                                                          k                                      k         kkk                k     0",
"0                                                                                                                           kk                 k    0",
"0                                                                               k              k      k      k               kk                 k    0",
"0                                                                                    k                                   k  kk  k   k          k     0",
"0                                                                                                                         k kk k    k   k      k     0",
"0                                                                                                                          kkkk     k          k     0",
"0                                                                   k     k      k                                          kk      k       k  k     0",
"0                                                                                                                                   k          k     0",
"0                   k           k     k     k     k     k     k                      k                                                  k  k   k     0",
"0             k                                                                                                                      k         k     0",
"0          k                                                  k                           k                                           k        k     0",
"0                                                                                               k                               kkk k          k     0",
"0      k       k k     k kk     k                       kkkkk      k                                                          kk    k   kkkk   k     0",
"0       k       k       k       k                       k         kk                              kkkkkkkkkkkkkkkkkkkkkkkkkkkk      k          k     0",
"0        k      kkk     k   k  kk                       k          k                              k                                 k          k     0",
"0         k       kk   kk  k  k                         k     k    k                              k                                 k       k  k     0",
"0          k        k k   k kk                          k          k                           kkkk                         kk      k          k     0",
"0           k       kk kkkk                             k   k      k                           k                  k          k      k          k     0",
"0            k                                          k        k k                           k       kkkkk                 k      kk        kk     0",
"0             k       k  kk k                           k          k                        kkkk       k   k              k  k      k          k     0",
"0              kkk  k  kkk k                            kk         k                        k          k   k                 k      k          k     0",
"0                     k  k  kk                          k   k      k                        k       kkkk   kkkk    k         k      k     k    k     0",
"0                      k  kk                            k    k     k                     kkkk       k         k              k      k          k     0",
"0                     k  k kk    k                      k          k                     k          k         k       k      k      kk      k  k     0",
"0                    k k k k                            k          k                     k       kkkk         kkkk           k      k          k     0",
"0                   kk  k  kk                           k      k   k                  kkkk       k               k          kk      k          k     0",
"0           kkkkkkkkkkkkkkkkkkkkkkkkkk      k           k          k                  k          k               k           k      k k        k     0",
"0                                                       k   k      k                  k       kkkk               kkkk    k   k      k          k     0",
"0                                      k         k      k          k               kkkk       k                     kk       k      k    k     k     0",
"0kkkkkkkkkkk         kkkkkkkkkkkk      kkkkkkkkkkk      k          k                          k                     k        kkkk   k          k     0",
"0                               k                       k       k  k                       kkkk                     kkkk        k   k          k     0",
"0              k                k                       k          k                                                   k k      k   k      k   k     0",
"0                               kkkkkkkkkkkkkkkkkkkkkkkkk  k       kkkkkkkkkkkkkk                                      k        k   k          k     0",
"0kkkkkkkkkkkkkkkkkkkkkk                                                               k                                kkkk   k     k         kk     0",
"0                     k     k                                                                                             k         k          k     0",
"0                     k                                       k                                kk                         k                k   k     0",
"0                     kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk          kkkk                  k           kk                   kkkk                 k     0",
"0                                                                                                           k        k       kk         k      k     0",
"0                                                                          kk                               kkkkkkkkkk       k                 k     0",
"0                           k    k           k          k         k                                                          kkkkkkkkkkkkkkkkkkk     0",
"0                     k          k        k        k        k        k           k            k           k            k                             0",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"
};

String Poziom3[H] = {
"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                 kkkkkkkk     kkkk                                                                                                                  0",
"0                                     k                                                                                          kkkkkk              0",
"0                                                                                           kkk       kkkkkk                    k      k             0",
"0                                       kk                                         kkkkk   k   kkk   k      k               kkkk        kk           0",
"0                              kkkk                                               k     k k       kkk        k            kk              k          0",
"0                           kkk   kkk                                            k       k                    k     k      k              k          0",
"0                          k   kkk   k      k            kkkkkkk                k                              k            kkkkkkkkkkkkkk           0",
"0                         k   k                         k       k        kkk   k                               kk                                    0",
"0                        k   k          kk         k kkk         kkkk           k                                kk                 kkkkkkkkkkk      0",
"0                        k   k      kk           k                   k          k                                 kk                          k      0",
"0                        k   k                  k                     k          kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk      kkkkk                k      0",
"0                         k   k            kk   k                     k                                                                       k      0",
"0                          k    kk   k          k                     k                                                          k   k        k      0",
"0                           kkk   kkk            kkkkkkkkkkkkkkkkkkkkk                                                           k            k      0",
"0                              kkkk                                                                                              kk           k      0",
"0                                                                                                                                k    kk      k      0",
"0                                                                                                                                k         kk k      0",
"0                                                                                                                                k            k      0",
"0                                                                                                                                k     kkk    k      0",
"0                                                                                                                                k            k      0",
"0                                                                                                                                k            k      0",
"0                                                                                                                                k   k        k      0",
"0                                                                                                                                k            k      0",
"0                                                                                                                                k            k      0",
"0                                                 kk   kkkkk                                                                     k        k   k      0",
"0                                           kk        k     k                                                                    k            k      0",
"0                                                    k       k     kkk                                                           k            k      0",
"0                       kkkkkkkkkkkkkkkkk            k       k                                                                   kk           k      0",
"0           kkkkkk                                   k       k                                                                   k            k      0",
"0   k                                                k       k             kkkkkk                                                k            k      0",
"0k  k                                                k       k            kk  k  k                                               k        k   k      0",
"0   k                                                k       k           k  k   k  k                                             k            k      0",
"0   k                              kkkkkkkkkkkk      k       k        kkk k      k  k                                            k            k      0",
"0  k                              k    kkk     k      k     k        k  kk         k  k                                          k    k       k      0",
"0                                k   kk   kk     k     kkkkk      kkk  k             kk                                          k            k      0",
"0                                kkkk       k  k   kkkkkkkkkkkkk   kk k               k                                          k            k      0",
"0k        k                      kk           k  kkk    k k    kkk  kk                k                                          k        k   k      0",
"0kkkkkkkkkk                     kk               k      k k      k                   k      kkk                                  k            k      0",
"0             kk             k   k               k      kkk      k                                                               k            k      0",
"0                             kkk                k  k   k k   k  k                                                               k  k         k      0",
"0                  kkk                           k  k   k k   k  k                      k                                        k            k      0",
"0                                       kkkkkk   k  k   k k   k  k  kkkkkk                                                       k            k      0",
"0                    kkk              kk     k   k  k   k k   k  k  k     k                      kkkk                            k        k   k      0",
"0               kkkkkk       kk      k   kkkkk   k  k   k k   k  k  kkkk   k                                                     k            k      0",
"0             kkkk                  kk  kk       k  k   k k   k  k      k    k       kkkkkkkkk                                   k            k      0",
"0            k  kk                 kk   k        k  k    k    k  k       kk    kk kk          kk                                 k    k       k      0",
"0      kk    k   kk               k   k          k  k    kk   k  k        k      k    kkkkk     kkk     kkkkk                    k            k      0",
"0             k    kkkk          k   k           k  k    k    k  k         kkk     kkk     kk      k                             k          k k      0",
"0 kk           k       kkk       k   k           k  k    kk   k  k           kkkkkk          kkk    k                                         k      0",
"0               kkkk      kk     k   k           k  k    k    k  k                              k    k                                        k      0",
"0                   kkk     k    k   k       k   k  k   kkk   k  k                               k    k         kkkkkk       kkkkkkkkkkkkkkkkkk      0",
"0     kk               k     kkkk   k            k  k  k   k  k  k                                k    k                                             0",
"0                       kkk      kkk      k      k  k k     k k  k                                 k    k                                            0",
"0 kk                       kkkkkk                k  kk       kk  k                                  k   k                                            0",
"0                                                kkkk   kkk   kkkk                                   k  k                                            0",
"0    k        k                           kkkk   k  k   k k   k  k                                    k k                                            0",
"0    kkkkkkkkkk     kk                           k  k   k k   k  k                                    kk                                             0",
"0                                 kkkkk           kkk   k k   kkk                                  kkkk                                              0",
"0                                                   k   k k   k                                   kk                                                 0",
"0                        kkkk                       k   k k   k                                                                                      0",
"0                                                   k   k k   k                                                                                      0",
"0                                kkkk               k   k k   k                                                                                      0",
"0                                                   k   k k   k                                                                                      0",
"0                                       k     k     k   k k   k                                                                                      0",
"0                                       kkkkkkk     k   k k   k                                                                                      0",
"0                                                  kkkkkk kkkkkk                                                                                     0",
"0                                 kk              k     k k     k                                                                                    0",
"0                                                kkkkkkkk kkkkkkkk                                                                                   0",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"
};

String TileMap[H];

int aktualnyPoziom =1;


class PLAYER {

public:

float dx , dy;      //predkosc w poziomie i w pionie
FloatRect rect;     //prostokat (lewo, gora, szerokosc, wysokosc)
bool onGround;
Sprite sprite;
float currentFrame;     //aktualna klatka animacji

    PLAYER(Texture &image)  //konstruktor i referencja na teskture podan¹ w main
   {
	sprite.setTexture(image);
	rect = FloatRect(3*16,66*16,16,16);    //tekstura gracza                                      //SPAWN   (3*16,66*16,16,16)

	dx=dy=0.1;
	currentFrame = 0;       //klatka animacji 0
   }


   void update(float time)      //pobrany czas z clock jako mikrosekundy
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


   void Collision(int num)                  //metoda kolizji przyjmujaca 1 lub 0
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
                                                switch(aktualnyPoziom)
                                                {
                                                    case 1: { rect.left=3*16; rect.top=66*16; break; }
                                                    case 2: { rect.left=32*16; rect.top=66*16; break; }
                                                    case 3: { rect.left=10*16; rect.top=70*16; break; }
                                                    case 4: { rect.left=3*16; rect.top=70*16; break; }
                                                }
			                          	 }
			 }

}

};

/*
class ENEMY
{

public:
float dx,dy;
FloatRect rect;
Sprite sprite;
float currentFrame;
bool life;


   void set(Texture &image, int x, int y)       //funkcja startujaca przeciwnika //tekstura i polozenie
   {
	sprite.setTexture(image);
	rect = FloatRect(x,y,16,16);        //polozenie i wielkosc

    dx=0.05;            //automatyczny ruch
	currentFrame = 0;
	life=true;          //mozliwosc zgniecenia
   }

   void update(float time)
   {
	 rect.left += dx * time;        //poruszanie z uwzglednieniem czasu

     Collision();       //ciagle sprawdzanie kolizji


     currentFrame += time * 0.005;      //ciagla animacja
     if (currentFrame > 2) currentFrame -= 2;       //2 klatki animacji

    sprite.setTextureRect(IntRect(18*int(currentFrame),   0, 16,16));
    if (!life) sprite.setTextureRect(IntRect(58, 0, 16,16));            //tesktura przy zgnieceniu (life ==0)


	sprite.setPosition(rect.left - offsetX, rect.top - offsetY);        //poruszanie

   }


   void Collision()
  {

	for (int i = rect.top/16 ; i<(rect.top+rect.height)/16; i++)            //SPRAWDZANIE POLOZENIA NA MAPIE
		for (int j = rect.left/16; j<(rect.left+rect.width)/16; j++)
			 if ((TileMap[i][j]=='P') || (TileMap[i][j]=='0')|| (TileMap[i][j]=='k'))              //kolizja z P lub 0
			                           {
                                                    if (dx>0)
												   { rect.left =  j*16 - rect.width; dx*=-1; }      //zmiana kierunku w lewo
											        else if (dx<0)
												   { rect.left =  j*16 + 16;  dx*=-1; }             //w prawo

										}
  }

};

*/
/*
class Cannon
{
public:
    FloatRect rect;
    Sprite sprite;
    Sprite kula;
    int pociski = 3;


   void set(Texture &image, int x, int y)
   {
	sprite.setTexture(image);
	rect = FloatRect(x,y,16,16);        //polozenie i wielkosc
   }

};
*/


int main()
{
    for(int i=0;i<H;i++) TileMap[i]=Poziom1[i];

    RenderWindow window(VideoMode(800, 600), "SFML works!");

    bool pauza=1;
    Font agency;
    agency.loadFromFile("AGENCYB.TTF");
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
        przycisk[i].setFillColor(Color::Green);
        przycisk[i].setSize(Vector2f(300, 50));
        przycisk[i].setPosition(250,(i*80)+130 );

        napis[i].setCharacterSize(50);
        napis[i].setPosition(270, (i*80)+120);
    }

    RectangleShape nextprzy(Vector2f(150,75));
    nextprzy.setFillColor(Color::Green);
    nextprzy.setPosition(600,130);
    Text nextnapi;
    nextnapi.setFont(agency);
    nextnapi.setCharacterSize(30);
    nextnapi.setString("Nastepny\npoziom");
    nextnapi.setPosition(610, 130);

    //nie-przyciski
    napis[4].setCharacterSize(70);
    napis[5].setCharacterSize(70);
    napis[4].setPosition(260, 10);
    napis[5].setPosition(255, 470);
    napis[5].setColor(Color(237, 28,36));

    napis[4].setString("Nazwa gry");
    napis[0].setString("Graj od nowa");
    napis[1].setString("Kontynuuj");
    napis[2].setString("Jak grac");
    napis[3].setString("Credits");
    napis[5].setString("Powodzenia!");

	Texture tileSet;
	tileSet.loadFromFile("Mario_Tileset.png");

    Texture napisykoncowe;
    napisykoncowe.loadFromFile("creditstemp.png");
    Sprite credits(napisykoncowe);
    credits.setPosition(0,0);
    bool boolcredits=0;

	PLAYER Mario(tileSet);      //wyslanie tekstury


	Sprite tile(tileSet);

	SoundBuffer buffer;
	buffer.loadFromFile("Jump.ogg");
	Sound sound(buffer);
	sound.setVolume(30);

    Music music;
    music.openFromFile("Mario_Theme.ogg");
    music.play();
    music.setLoop(1);
    music.setVolume(50);

    Text licznik;
    licznik.setFont(agency);
    licznik.setCharacterSize(50);
    licznik.setPosition(710, 10);
    licznik.setOutlineColor(Color::Black);
    licznik.setOutlineThickness(1);

	Chronometer clock;
	Chronometer zegargry;
        zegargry.pause();

    while (window.isOpen())
    {
        int czasgry = zegargry.getElapsedTime().asSeconds();
        licznik.setString(to_string(czasgry)+"s");
		float time = clock.getElapsedTime().asMicroseconds();
		clock.reset();
		clock.resume();

		time = time/500;

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
            }

            if (event.type == Event::KeyPressed && event.key.code == Keyboard::M)
            {
                if(music.getStatus()==2 && sound.getVolume()>0){ music.pause(); sound.setVolume(0); }
                else { music.play(); sound.setVolume(30); }
            }

            if( event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left &&
               przycisk[0].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && pauza) //Graj od nowa
            {
                aktualnyPoziom=1;
                Mario.rect.left=12*16; Mario.rect.top=70*16;
                if(pauza) pauza=false;
                else { pauza=true; boolcredits=false; }
                zegargry.reset();
            }

            if( event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left &&
               przycisk[1].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && pauza) //Kontynuuj
            {
                if(pauza) pauza=false;
                else { pauza=true; boolcredits=false; }
            }

            if( event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left &&
               przycisk[2].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && pauza) //Jak grac
            {
                //Jak grac, wyswietla grafike
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
                    case 1: { Mario.rect.left=3*16; Mario.rect.top=66*16; break; }
                    case 2: { Mario.rect.left=32*16; Mario.rect.top=66*16; break; }
                    case 3: { Mario.rect.left=10*16; Mario.rect.top=70*16; break; }
                }
                if(pauza) pauza=false;
                else { pauza=true; boolcredits=false; }
            }
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

        for (int i=0; i<H; i++)
			 for (int j=0; j<W; j++)
			  {
			      if (TileMap[i][j]=='c') {

			      }
			  }

        switch(aktualnyPoziom)
        {
            case 1: { for(int i=0;i<H;i++) { TileMap[i]=Poziom1[i]; } break; }
            case 2: { for(int i=0;i<H;i++) { TileMap[i]=Poziom2[i]; } break; }
            case 3: { for(int i=0;i<H;i++) { TileMap[i]=Poziom3[i]; } break; }
            case 4: { for(int i=0;i<H;i++) { TileMap[i]=Poziom4[i]; } break; }
            //default: { }  //ekran konca gry
        }




		 if (Mario.rect.left>400 && Mario.rect.left<2000) offsetX = Mario.rect.left-400;           //
        if(Mario.rect.top< 1057 && Mario.rect.top> 400) offsetY = Mario.rect.top - 408;



		 window.clear(Color(107,140,255));

		 for (int i=0; i<H; i++)
			 for (int j=0; j<W; j++)
			  {
				if (TileMap[i][j]=='P')  tile.setTextureRect( IntRect(143-16*3,112,16,16) );

				if (TileMap[i][j]=='k')  tile.setTextureRect( IntRect(143,112,16,16) );

   			    if (TileMap[i][j]=='c')  tile.setTextureRect( IntRect(143-16,112,16,16) );

				if (TileMap[i][j]=='t')  tile.setTextureRect( IntRect(0,47,32,95-47) );

				if (TileMap[i][j]=='g')  tile.setTextureRect( IntRect(0,16*9-5,3*16,16*2+5) );

				if (TileMap[i][j]=='G')  tile.setTextureRect( IntRect(145,222,222-145,255-222) );

			    if (TileMap[i][j]=='d')  tile.setTextureRect( IntRect(0,106,74,127-106) );

				if (TileMap[i][j]=='w')  tile.setTextureRect( IntRect(99,224,140-99,255-224) );

				if (TileMap[i][j]=='r')  tile.setTextureRect( IntRect(143-32,112,16,16) );

				if ((TileMap[i][j]==' ') || (TileMap[i][j]=='0')) continue;

  			    tile.setPosition(j*16-offsetX,i*16 - offsetY) ;
		        window.draw(tile);
		     }

        cout<<aktualnyPoziom;
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
		window.display();
    }

    return 0;
}



