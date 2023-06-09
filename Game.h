#ifndef __GAME_H__
#define __GAME_H__

const int SIZE = 5;
const int MAX_ROOM = 20;

void welcome(int i);
void draw_princess();
void draw_monster();
void play();


const char WELCOME[] =
"       d8888      888                            888                            \n\
      d88888      888                            888                             \n\
     d88P888      888                            888                             \n\
    d88P 888  .d88888 888  888  .d88b.  88888b.  888888 888  888 888d888 .d88b.  \n\
   d88P  888 d88^ 888 888  888 d8P  Y8b 888 ^88b 888    888  888 888P^  d8P  Y8b \n\
  d88P   888 888  888 Y88  88P 88888888 888  888 888    888  888 888    88888888 \n\
 d8888888888 Y88b 888  Y8bd8P  Y8b.     888  888 Y88b.  Y88b 888 888    Y8b.     \n\
d88P     888  ^Y88888   Y88P    ^Y8888  888  888  ^Y888  ^Y88888 888     ^Y8888  \n\
                     Press any key to start the CLI game!\n";

const char PRINCESS[] =
"                                     ____________\n\
                               _____/            \\_\n\
                    __________/  _/          _____ \\__\n\
        ______ ____/            /           /     \\___\\_\n\
      _/      \\____           _/          _/             \\_\n\
    _/             \\____     /          _/    ___          \\\n\
   /    _______         \\_   |         /  ___/_____-        |\n\
  /   _/       \\__        \\_ |       _/__/      \\_ \\__      |\n\
 /  _/            \\______     \\     /_/           \\   \\     |\n\
 |_/                _____\\__________/              \\        |\n\
 /               __/  __/ _/                          \\_   /\n\
 |           ___/    /  _/                              \\_ |\n\
 |        __/  /    |  /                  ________   \\    \\|\n\
 |                  | /                   \\XXXXXXXXxx_|    |\n\
 |\\                 | |                               |     \\___\n\
 | |          |     \\ |______                         |         \\_\n\
 |  \\             ___||XXXXX/                ---_     |           \\\n\
 |  |         | xxXXX//                     /___-///  |           |\n\
  \\ \\        /\\     |/                 /   |///OX\\\\\\  |           |\n\
  |  ||    _/  |        __---_         |   | \\\\XX///   \\___      \\|\n\
  \\ //   _/    |     \\\\\\xxxxx \\        |   |\\_\\---       \\ \\_      \\\n\
   |/  _/      |      | //OXX\\\\\\        \\                 \\  \\_     \\\n\
  _/ _/        /\\     | \\\\XXX///\\                         |\\   \\    |\n\
 /__/         /  \\     \\_-----                            | \\   |   /\n\
|/ /              |                       \\               /  |   \\_/\n\
   |             /|                      _|              |  | __/\n\
  /             | |                  \\ -                 / _/_/\n\
  |           _/ _/                         _____       |/\n\
  | _       _/  /\\\\ \\               ________/ / |       /_\n\
  |/       /   /  \\_ \\_          __/_________/ /       /  \\______\n\
   \\      |   | \\_  \\- \\_          \\__________/      _/          \\\n\
    \\__   |              \\___                      _/\\_           |\n\
       \\__|\\_                \\___                _/|   \\         /\n\
          \\__\\_______________/   \\___         __/  |\\          \\/\n\
                       \\___  |       \\_______/     | \\___       |\n\
                        /  \\_|                     |   \\ \\_____/\n\
                _______|____/                       \\___\\__";

const char MONSTER[] =
"                            ..,,,,,,,,,.. \n\
                     .,;88888888888888888888;,. \n\
                   88888888888888888888////888888, .,;88;, \n\
            .,;8/,88888/////88888888888888////8888,88//888, \n\
        .,;8888/,888///8888888888888888888888888888,////8888;, \n\
     .,888888//,8888888888888888@@8a8888888888888888,88/8888888;, \n\
   .,8//8888//,8888///////8888888@@@888888///////8888,88//88888888, \n\
 ,88888///88//,88//88888///88888@@@88888////888888888,/8888888888888 \n\
.888888888////,8888888//8///8888@@@@888////88/////888,/;88888888/888 \n\
8/8888888/////,8888///88////888@@@@@888///88/88888//8,////8888//888' \n\
8//88888//////,8/8a`  'a8///888@@@@@@88////a`  'a8888,//8///8/88888 \n\
8///888888///,8888@@aa@@8//888@@@@S@@@88///@@aa@@88888,/8////88888 \n\
88//8888888//,88888///////888@S@@@@SS@@@88/////8888888,8////88888' \n\
88//8888888//,8888/////88@8@SS@@@@@@@S@@@@8888/////888,////88888' \n\
`8/8888//88//,888///8888@@@S@@@@@@@@@@@@@@@S8888////88,///88888' \n\
  8888//8888/,88888888@@@@@@@@@@@@@@@@@@@@@SS@88888888,//88888' \n\
  `888//8888/,8888@8@@@@@@@@@@@@@@@@@@@@@@@@@S@@88888,/////88' \n\
   `888//888/,888@@@SS@@SSs@@@@@@@@@@@@@sSS@@@@@@888,//88//8' \n\
    `888888/  88S@@SS@@@@@Ss` .,,.    'sS@@@S@@@@8'  ///8/8' \n\
      `888/    8SS@@@@SSS@@S.         .S@@SSS@@@@'    //88' \n\
               /`S@@@@@@SSSSSs,     ,sSSSSS@@@@@' \n\
             88//`@@@@@@@@@@@@@Ss,sS@@@@@@@@@@@'/ \n\
           8888@@00`@@@@@@@@@@@@@'@@@@@@@@@@@'//88 \n\
       888888a8@@@@000aaaaaaaaa00a00aaaaaaa008@88888 \n\
    888888a88@@@@@@@@@@000000000000000000@@@8@@888@888 \n\
 888888a88@@@8@@@@@@@@@@@00000000000000@@@@@@@@@8@@88@88 \n\
888aa8@@@@@@@@@@@@@@0000000000000000000000@@@@@@@@8@@@8888 \n\
888@@@@@@@@@@@@@@@00000000000000000000000000000@@@@@@@@@88888";

const char WIN[] =
"\\\\    / /                   ||   / |  / /            \n\
 \\\\  / /  ___               ||  /  | / / ( )   __    \n\
  \\\\/ / //   ) ) //   / /   || / /||/ / / / //   ) ) \n\
   / / //   / / //   / /    ||/ / |  / / / //   / /  \n\
  / / ((___/ / ((___( (     |  /  | / / / //   / /   \n";

#endif
