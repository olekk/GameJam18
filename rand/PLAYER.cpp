#include <SFML/Graphics.hpp>
#include "PLAYER.h"
#include <iostream>

using namespace std;
using namespace sf;

float offsetX=0;
float offsetY=0;


array<string, H> Poziom1 = {
"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                       k  kkkkkkkkk                                                                 0",
"0                                                                                k      k                 k                             k            0",
"0                                                                    kkkkkkkkk   k        k                                        k        cccccccc 0",
"0                                                                             k  k                    k       k                k            cccccccc 0",
"0                                                                                k           k    k                        k                kkkkkkkk 0",
"0                                                          kk             kkkkkkkk                                 k    k                            0",
"0                                                    kk          k    k                                                                              0",
"0                                         kkkkkkk                kkkkkk                                                                              0",
"0                                         k                                                                                                          0",
"0                                         k              k           k          k        k      k            k             k         k         k     0",
"0       kkk   k    k   k   k   k kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk0",
"0         k                      k                                                                                                                   0",
"0   k     k                      k                                                                     kkk   kkk   kkk  kkk     kkkkk  kkk  kkk      0",
"0         k                      k                                                                    k   k k   k k   k k  k    k     k   k k  k     0",
"0         k                      k                                                                    k     k   k k   k k  k    k     k   k k k      0",
"0       k k      k               k                                                                    k  kk k   k k   k k  k    k     k   k kk k     0",
"0         k           k          k                                                                    k   k k   k k   k k  k    k   k k   k k  k     0",
"0   k     k               k      k                                                                     kkk   kkk   kkk  kkk      kkk   kkk  kkk      0",
"0         k                      k                                                                                                                   0",
"0         k                      k                                                                                                                   0",
"0    k    k   k              k   k                                                                                                                   0",
"0             k                  k                                                     0                                                             0",
"0kkkkkkkkkkkkkk                  k                                                     0                                                             0",
"0                         k      k                                                     0                                                             0",
"0                     k          k                                                     0                                                             0",
"0                                k                                                     0                                                             0",
"0           kkkkkk               k                                                     0                                                             0",
"0      k                         k        G    k                          rrrrrrrrrrr  0                                                             0",
"0                                k   0          k                        r           r 0                                                             0",
"0   k                            k   kkkkkkkkkkkkk                       r           r 0                                                             0",
"0                                k              k                   0000r rrr rrrr    r                                                              0",
"0       k   k    k          k    k             k                    0   r  rr   rr rr  r                                                             0",
"0       kkkkk    kkkkkkkkkkkk                                     00     r r  r     rr r                                                             0",
"0                                      k                         0       r  rr   rrr r r                                                             0",
"0                                kkkkkkk                         0       rrrrrrrr r   r                                                              0",
"0                            k   k      0000000kkkkkkkkkkkkkkkkkk        r r r r r   r                                                               0",
"0        kk   kkk  k             k                                      r rrrrrrr   r                                                                0",
"0                  kkkkkkkkk     k                                      r         rr                                                                 0",
"0    k                    k      k                                      r     rrrr                                                                   0",
"0                         k      k                                       rrrrr                                                                       0",
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
"0     kkkkkkkkkkkkk     k        k                                                                                                                   0",
"0                       k        k                                                                                                                   0",
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
"0            k                   k       G                                                                                                           0",
"0        k                       k                                                                                                                   0",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"
};

array<string, H> Poziom2 = {   //mapa 150x80
"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                    ccccccccccc                                                                             G       0",
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
"0                       kk                                                                            kk    k                      k      k          0",
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
"0                                    kk     kkkkkkkkkkkkkkkkkkk       G                                                                              0",
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
"0                           kk                                   kkk           kk                                                                    0",
"0                           kk                                                 kk                                                                    0",
"0             G             kk           kk       kk       kk                  kk                                                                    0",
"0                           kk     kk                                          kk                                                                    0",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"
};

array<string, H> Poziom4 = {
"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0                                                                                                                                                    0",
"0                                      k   k kkkkk k     k        kkk    kkkk  k   k kkkkk   kk                                                      0",
"0                                      k   k k     k     k        k  k  k    k kk  k k       kk                                                      0",
"0                                      k   k kkk   k     k        k   k k    k k k k kkk     kk                                                      0",
"0                                      k k k k     k     k        k  k  k    k k  kk k                                                               0",
"0                                       k k  kkkkk kkkkk kkkkk    kkk    kkkk  k   k kkkkk   kk                                                      0",
"0                                                                                                                                                    0",
"0                                                                                       cccccccc                                                     0",
"0                                                                                       cccccccc                                                     0",
"0                           kkk      k        k               k                         kkkkkkkk                                                     0",
"0                   kkk       kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk                                                                0",
"0                                                                                                                                                    0",
"0                                          000000000000000000000000000000000000000000000000000000000000                                              0",
"0               kkk                        0                                                          0                                              0",
"0                                          0                                                          0                                              0",
"0                                                                               k00000000000000k      0                                              0",
"0            kkk                                       k00000000000000000k      0                     0                                              0",
"0                                                      0                        0                     0                                              0",
"0                 kkkkkkkkkkkkkkk                      0                        0              k0000000                                              0",
"0                                  kkkkk                                        0                                                                    0",
"0                                  kkkkk                                        0                                                                    0",
"0                                       000k000000000000000k     k      000000000  000000000000k                                                     0",
"0                                          0                     0                 0                                                                 0",
"0                                          00000000000000000000000000000000000000000000000000000000000kkkk   kkkkkkk                                 0",
"0                                                                                                                                                    0",
"0                                                                                                                        kkkk                        0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                               kk                   0",
"0                                                                                k     k                                                             0",
"0                                                                               kk     kk              k                                             0",
"0                                        k                                     kkk     kkk                   k                     k                 0",
"0                                        kkkkkkkkkkkkkkkkkkkk    kkkkkkkkkkkkkkkkk     kkkkkkkkkkkkkkk       kkkkkkkkkkkkkkkkkkkkkkk                 0",
"0                                     k                                                                                                              0",
"0                                  k                                                                                                                 0",
"0                                   k                                                                                                                0",
"0                                    k        k                                                                                                      0",
"0                                    kkkkkkkkkk   kkk                k                                                                          G    0",
"0                                                       kkkkkkkkk        k                                                                           0",
"0                                                                                                                 k                            kkkkkk0",
"0                                                                          k             k                                                     k     0",
"0              kkk    kkkkkkkkkkkkkkkk                                      kkkkk              k      k      k      k                          k     0",
"0                                    k                                                k                                  k                     k     0",
"0                                    k   k                                                                                   k        k   k    k     0",
"0           k                        k              k                                                                         k     k          k     0",
"0           k                 kk     k         k       k            kkkkkkkkkkkkkk                                                  k          k     0",
"0           kk                k      k                                                                                              k          k     0",
"0           k                 k      k                  kkkkk      k                                                          kk    k   kkkk   k     0",
"0           k     k           k   k  k                  k         kk                              kkkkkkkkkkkkkkkkkkkkkkkkkkkk      k          k     0",
"0           k                 k      k                  k          k                              k                                 k          k     0",
"0           k           k     k      k                  k     k    k                              k                                 k       k  k     0",
"0           k                 kk     k                  k          k                           kkkk                         kk      k          k     0",
"0           k                 k      k                  k   k      k                           k                  k          k      k          k     0",
"0           k                 k      k                  k        k k                           k       kkkkk                 k      k         kk     0",
"0                             k      k                  k          k                        kkkk       k   k              k  k      k          k     0",
"0           kkkkkkkkkkkkkkkkkkkk     k                  kk         k                        k          k   k                 k      k          k     0",
"0           k                        k                  k   k      k                        k       kkkk   kkkk    k         k      k     k    k     0",
"0           k                        k                  k          k                     kkkk       k         k              k      k          k     0",
"0           k      kkkkkkkkkkkkkkkkkkk                  k          k                     k          k         k       k      k      kk      k  k     0",
"0           k                                           k    k     k                     k       kkkk         kkkk           k      k          k     0",
"0           k                                           k          k                  kkkk       k               k          kk      k          k     0",
"0           kkkkkkkkkkkkkkkkkkkkkkkkkk      k           k          k                  k          k               k           k      k k        k     0",
"0                                                       k          k                  k       kkkk               kkkk    k   k      k          k     0",
"0                                      k         k      k     k    k               kkkk       k                     kk       k      k    k     k     0",
"0kkkkkkkkkkk         kkkkkkkkkkkk      kkkkkkkkkkk      k          k                          k                     k        kkkk   k          k     0",
"0                               k                       k          k                       kkkk                     kkkk        k   k          k     0",
"0              k                k                       k          k                                                   k k      k   k      k   k     0",
"0                               kkkkkkkkkkkkkkkkkkkkkkkkk  k       kkkkkkkkkkkkkk                                      k        k   k          k     0",
"0kkkkkkkkkkkkkkkkkkkkkk                                                               k                                kkkk   k     k         kk     0",
"0                     k     k                                                                                             k         k          k     0",
"0                     k                                       k                                kk                         k                k   k     0",
"0                     kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk         kkkkk                  k           kk        G          kkkk                 k     0",
"0                                                                                                           k        k       kk         k      k     0",
"0                                                                          kk                               kkkkkkkkkk       k                 k     0",
"0       G                   k    k           k          k        k                                                           kkkkkkkkkkkkkkkkkkk     0",
"0                     k          k        k        k        k        k           k            k           k            k                             0",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"
};

array<string, H> Poziom3 = {
"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                                                                                                                                                    0",
"0                 cccccccc                                                                                                                           0",
"0                 cccccccc                                                                                                                           0",
"0                 kkkkkkkk     kkkk                                                                                                                  0",
"0                                     k                                                                                          kkkkkk              0",
"0                                                                                           kkk       kkkkkk                    k      k             0",
"0                                       kk                                         kkkkk   k   kkk   k      k               kkkk        kk           0",
"0                              kkkk                                               k     k k       kkk        k            kk              k          0",
"0                           kkk   kkk                                            k       k                    k            k              k          0",
"0                          k   kkk          k            kkkkkkk                k                              k            kkkkkkkkkkkkkk           0",
"0                         k   k                         k       k        kkk   k                               kk                                    0",
"0                        k   k                     kkkkk         kkkk           k            G                   kk                 kkkkkkkkkkk      0",
"0                        k   k                   kk                  k          k                                 kk                          k      0",
"0                        k   k                  k                     k          kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk      kkkkk                k      0",
"0                         k   k                 k                     k                                                                       k      0",
"0                          k   kkk              k                     k                                                         kk   k        k      0",
"0                           kkk   kkk            kkkkkkkkkkkkkkkkkkkkk                                                           k            k      0",
"0                              kkkk                                                                                              kk           k      0",
"0                                                                                                                                k    kk      k      0",
"0                                                                                                                                k            k      0",
"0                                                                                                                                k            k      0",
"0                                                                                                                                k     kkk    k      0",
"0                                                                                                                                k            k      0",
"0                                                                                                                                k            k      0",
"0                                                                                                                                k   k        k      0",
"0                                                                                                                                k            k      0",
"0                                                                                                                                k            k      0",
"0                                                 kk   kkkkk                                                                     k     k      k      0",
"0                                           kk        k     k                                                                    k            k      0",
"0                                                    k       k     kkk                                                           k            k      0",
"0                     kkkkkkkkkkkkkkkkkkk            k       k                                                                   k            k      0",
"0          kkkkkkk                                   k       k                                                                   k    k       k      0",
"0   k                                                k       k             kkkkkk                                                k            k      0",
"0k  k                                                k       k            kk  k  k                                               k        k   k      0",
"0   k                                                k       k           k  k   k  k                                             k            k      0",
"0   k                              kkkkkkkkkkkk      k       k        kkk k      k  k                                            k            k      0",
"0  k                              k    kkk     k      k     k        k  kk         k  k                                          k            k      0",
"0                                k   kk   kk     k     kkkkk      kkk  k             kk                                          k           kk      0",
"0                                kkkk       k  k   kkkkkkkkkkkkk   kk k               k                                          k            k      0",
"0k        k                      kk           k  kkk    k k    kkk  kk                k                                          k            k      0",
"0kkkkkkkkkk                     kk               k      k k      k                   k      kkk                                  k            k      0",
"0             kk             k   k               k      kkk      k                                                               k           kk      0",
"0                             kkk                k  k   k k   k  k                                                               k            k      0",
"0                  kkk                           k  k   k k   k  k                      k                                        k    k       k      0",
"0                                       kkkkkk   k  k   k k   k  k  kkkkkk                                                       k            k      0",
"0                    kkk              kk     k   k  k   k k   k  k  k     k                      kkkk                            k            k      0",
"0               kkkkkk       kk      k   kkkkk   k  k   k k   k  k  kkkk   k                                                     k            k      0",
"0             kkkk                  kk  kk       k  k   k k   k  k      k    k       kkkkkkkkk                                   k      k     k      0",
"0            k  kk                 kk   k        k  k    k    k  k       kk    kk kk          kk                                 k            k      0",
"0      kk    k   kk               k   k          k  k    kk   k  k        k      k    kkkkk     kkk     kkkkk                    k            k      0",
"0             k    kkkk          k   k           k  k    k    k  k         kkk     kkk     kk      k                             k          k k      0",
"0 kk           k       kkk       k   k           k  k    kk   k  k           kkkkkk          kkk    k                                         k      0",
"0               kkkk      kk     k   k           k  k    k    k  k                              k    k                                        k      0",
"0                   kkk     k    k   k       k   k  k   kkk   k  k                               k    k         kkkkkk       kkkkkkkkkkkkkkkkkk      0",
"0     kk               k     kkkk   k            k  k  k   k  k  k                                k    k                                             0",
"0                       kkk      kkk      k      k  k k     k k  k                                 k    k                                            0",
"0 kk                       kkkkkk                k  kk       kk  k                                  k   k                                            0",
"0                                                kkkk   kkk   kkkk                                   k  k0                                           0",
"0    k        k                           kkkk   k  k   k k   k  k                                    k k0                                           0",
"0    kkkkkkkkkk     kk                           k  k   k k   k  k                                    kk 0                                           0",
"0                                 kkkkk           kkk   k k   kkk                                  kkkk   0                                          0",
"0                                                   k   k k   k                                   kk      0                                          0",
"0                        kkkk                       k   k k   k                                           0                                          0",
"0                                                   k   k k   k                                            0                                         0",
"0                                kkkk               k   k k   k                                            0                                         0",
"0                                                   k   k k   k                                            0                                         0",
"0                                       k     k     k   k k   k                                             0                                        0",
"0                                       kkkkkkk     k   k k   k                                             0                                        0",
"0                                                  kkkkkk kkkkkk                                            0                                        0",
"0                                 kk              k     k k     k    G                                 G     0                                       0",
"0                                                kkkkkkkk kkkkkkkk                                           0                                       0",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"
};


array<string, H> TileMap = Poziom1;

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
