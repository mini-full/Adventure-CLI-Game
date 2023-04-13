# Adventure

<center> 3210105636 王开炫

</center>

## Desciption

**The Story**

Adventure is a CLI game. The player has to explore a castle, which consists of several levels and many rooms. The task of the player is to find the room where the *princess* is prisoned and take her leave!

There are many types of rooms, and each type has distinct exits. Note that there is a *monster* in one of the rooms, whose exact location is unknown. But once the player meets the monster, the game is over.

The program always shows information about the room into which the player enters: the name of the room, how many exits are there, and the names of all the exits. For example, the player is in the lobby of the castle when the game starts, and the program outputs:

```
Welcome to the lobby. There are 3 exits: east, west and up.
Enter your command:
```

Then the player can input the command `go` followed by the name of the exit that he/she would like to pass through, e.g.,

```
go east
```

Consequently, the player goes into the room to the east. The program gives the information of that room, like what is shown above for the lobby. This process repeats.

During this process, if the player enters a room with a monster, the program shows a message and game over. Likewise, once the player enters the secret room where the princess is, the program shows the conversation between the role and the princess. After that, she is ready to leave with the role. Then the player has to find their way out. The only way to leave the castle is via the lobby.

To simplify the implementation, all the printed messages and the user input are shown in English.

## Specification of the Game

### Available commands

* Go [orientation]: The player move as required, if valid.
* Map: The explored map is shown, “<-” indicates the location of the player.
* Admin: The whole map is shown, including the location of the player, princess and the monster.

Note that the preceding “Go ” can be omitted. The initial letter can be capitalized or not.

### Several Types of Rooms

The game provides 3 types of room, as required.

* Lobby: Only one lobby in the map, it’s where the game starts, and it must be at the southernmost and the middle.
  				The player must leave the castle with the princess from the lobby to win the game.
* Windsor: Nothing special here.
* Dungeon: You will meet a imperial bodyguard here and he will tell you the direction of the monster.

Note that the game guarantee that all the rooms are connected and the rooms are randomly initialized.

## How OOP is used in this homework?

Using an object-oriented paradigm, this program is decomposed into several files to handle.

The object `Player` and `Room` are relatively independent and can interact with each other. The thought of `Composition` is reflected in the program.

Also the idea of `Inheritance` is reflected, considering the `is-a` relationship between `Lobby`, `WIndsor`, `Dungeon` and their parent class, `Room`.

## Test of the game

Note that this program is written and tested in Windows platform, and is generated and maintained using `Visual Studio`.

### Winning the game

```
       d8888      888                            888
      d88888      888                            888
     d88P888      888                            888
    d88P 888  .d88888 888  888  .d88b.  88888b.  888888 888  888 888d888 .d88b.
   d88P  888 d88^ 888 888  888 d8P  Y8b 888 ^88b 888    888  888 888P^  d8P  Y8b
  d88P   888 888  888 Y88  88P 88888888 888  888 888    888  888 888    88888888
 d8888888888 Y88b 888  Y8bd8P  Y8b.     888  888 Y88b.  Y88b 888 888    Y8b.
d88P     888  ^Y88888   Y88P    ^Y8888  888  888  ^Y888  ^Y88888 888     ^Y8888
                     Press any key to start the CLI game!

hello

$LOBBY$
#System#
        Welcome to the lobby.
#System#
        There are 2 exits:
        East    West
#System#
        You cannot do that, try annother command
        Map: get the game_map of the visited place
        Go [orientation]: Move to the next room(if exists)
admin
$ADMIN MAP$
        none            none            none            Windsor P       Dungeon
        none            Windsor         Windsor         Dungeon         Dungeon
        Windsor         Windsor         Windsor M       Windsor         Dungeon
        Dungeon         Windsor         none            Windsor         Windsor
        none            Dungeon         Lobby   <-      Windsor         Dungeon

east

$Windsor$
#System#
        The abandoned Windsor Castle is magnificent but dilapidated.
#System#
        There are 3 exits:
        East    North   West
east

$DUNGEON$
#System#
        Welcome to the Dungeon, you encoutered a lurking friend army
#Friend#
        I just met the monster, I was bitten and is gonna die.
        Remember...the monster is at    North  West
#System#
        There are 2 exits:
        North   West
east
#System#
        You cannot do that, try annother command
        Map: get the game_map of the visited place
        Go [orientation]: Move to the next room(if exists)
east
#System#
        You cannot do that, try annother command
        Map: get the game_map of the visited place
        Go [orientation]: Move to the next room(if exists)
north

$Windsor$
#System#
        The abandoned Windsor Castle is magnificent but dilapidated.
#System#
        There are 3 exits:
        North   South   West
north

$DUNGEON$
#System#
        Welcome to the Dungeon, you encoutered a lurking friend army
#Friend#
        I just met the monster, I was bitten and is gonna die.
        Remember...the monster is at    just West
#System#
        There are 3 exits:
        North   South   West
north

$DUNGEON$
#System#
        Welcome to the Dungeon, you encoutered a lurking friend army
#Friend#
        I just met the monster, I was bitten and is gonna die.
        Remember...the monster is at    South  West
#System#
        There are 3 exits:
        North   South   West
north

$DUNGEON$
#System#
        Welcome to the Dungeon, you encoutered a lurking friend army
#Friend#
        I just met the monster, I was bitten and is gonna die.
        Remember...the monster is at    South  West
#System#
        There are 2 exits:
        South   West
map
$MAP$
                                                                        Dungeon <-
                                                                        Dungeon
                                                                        Dungeon
                                                                        Windsor
                                        Lobby           Windsor         Dungeon

west

                                     ____________
                               _____/            \_
                    __________/  _/          _____ \__
        ______ ____/            /           /     \___\_
      _/      \____           _/          _/             \_
    _/             \____     /          _/    ___          \
   /    _______         \_   |         /  ___/_____-        |
  /   _/       \__        \_ |       _/__/      \_ \__      |
 /  _/            \______     \     /_/           \   \     |
 |_/                _____\__________/              \        |
 /               __/  __/ _/                          \_   /
 |           ___/    /  _/                              \_ |
 |        __/  /    |  /                  ________   \    \|
 |                  | /                   \XXXXXXXXxx_|    |
 |\                 | |                               |     \___
 | |          |     \ |______                         |         \_
 |  \             ___||XXXXX/                ---_     |           \
 |  |         | xxXXX//                     /___-///  |           |
  \ \        /\     |/                 /   |///OX\\\  |           |
  |  ||    _/  |        __---_         |   | \\XX///   \___      \|
  \ //   _/    |     \\\xxxxx \        |   |\_\---       \ \_      \
   |/  _/      |      | //OXX\\\        \                 \  \_     \
  _/ _/        /\     | \\XXX///\                         |\   \    |
 /__/         /  \     \_-----                            | \   |   /
|/ /              |                       \               /  |   \_/
   |             /|                      _|              |  | __/
  /             | |                  \ -                 / _/_/
  |           _/ _/                         _____       |/
  | _       _/  /\\ \               ________/ / |       /_
  |/       /   /  \_ \_          __/_________/ /       /  \______
   \      |   | \_  \- \_          \__________/      _/          \
    \__   |              \___                      _/\_           |
       \__|\_                \___                _/|   \         /
          \__\_______________/   \___         __/  |\          \/
                       \___  |       \_______/     | \___       |
                        /  \_|                     |   \ \_____/
                _______|____/                       \___\__
#Aside#
        You have met the princess!
#Player#
        I must bring her back safely
#System#
        New goal: Go back to the Lobby following the game_map!
$Windsor$
#System#
        The abandoned Windsor Castle is magnificent but dilapidated.
#System#
        There are 2 exits:
        East    South
south

$DUNGEON$
#System#
        Welcome to the Dungeon, you encoutered a lurking friend army
#Friend#
        I just met the monster, I was bitten and is gonna die.
        Remember...the monster is at    South  West
#System#
        There are 4 exits:
        East    North   South   West
south

$Windsor$
#System#
        The abandoned Windsor Castle is magnificent but dilapidated.
#System#
        There are 4 exits:
        East    North   South   West
south

$Windsor$
#System#
        The abandoned Windsor Castle is magnificent but dilapidated.
#System#
        There are 3 exits:
        East    North   South
map
$MAP$
                                                        Windsor         Dungeon
                                                        Dungeon         Dungeon
                                                        Windsor         Dungeon
                                                        Windsor <-      Windsor
                                        Lobby           Windsor         Dungeon

south

$Windsor$
#System#
        The abandoned Windsor Castle is magnificent but dilapidated.
#System#
        There are 3 exits:
        East    North   West
west

\\    / /                   ||   / |  / /
 \\  / /  ___               ||  /  | / / ( )   __
  \\/ / //   ) ) //   / /   || / /||/ / / / //   ) )
   / / //   / / //   / /    ||/ / |  / / / //   / /
  / / ((___/ / ((___( (     |  /  | / / / //   / /

#System#
        You have found the princess and saved the world!
        You win! Press any key to start a new game!
```

### Losing the game

```
       d8888      888                            888
      d88888      888                            888
     d88P888      888                            888
    d88P 888  .d88888 888  888  .d88b.  88888b.  888888 888  888 888d888 .d88b.
   d88P  888 d88^ 888 888  888 d8P  Y8b 888 ^88b 888    888  888 888P^  d8P  Y8b
  d88P   888 888  888 Y88  88P 88888888 888  888 888    888  888 888    88888888
 d8888888888 Y88b 888  Y8bd8P  Y8b.     888  888 Y88b.  Y88b 888 888    Y8b.
d88P     888  ^Y88888   Y88P    ^Y8888  888  888  ^Y888  ^Y88888 888     ^Y8888
                     Press any key to start the CLI game!

d

$LOBBY$
#System#
        Welcome to the lobby.
#System#
        There are 2 exits:
        North   West
#System#
        You cannot do that, try annother command
        Map: get the game_map of the visited place
        Go [orientation]: Move to the next room(if exists)
admin
$ADMIN MAP$
        none            none            Dungeon         Windsor         Dungeon
        none            none            Windsor M       Windsor         none
        none            Dungeon         Windsor P       Windsor         Windsor
        none            Windsor         Windsor         Windsor         Windsor
        none            Windsor         Lobby   <-      none            none

west

$Windsor$
#System#
        The abandoned Windsor Castle is magnificent but dilapidated.
#System#
        There are 2 exits:
        East    North
north

$Windsor$
#System#
        The abandoned Windsor Castle is magnificent but dilapidated.
#System#
        There are 3 exits:
        East    North   South
north

$DUNGEON$
#System#
        Welcome to the Dungeon, you encoutered a lurking friend army
#Friend#
        I just met the monster, I was bitten and is gonna die.
        Remember...the monster is at    North  East
#System#
        There are 2 exits:
        East    South
north
#System#
        You cannot do that, try annother command
        Map: get the game_map of the visited place
        Go [orientation]: Move to the next room(if exists)
east

                                     ____________
                               _____/            \_
                    __________/  _/          _____ \__
        ______ ____/            /           /     \___\_
      _/      \____           _/          _/             \_
    _/             \____     /          _/    ___          \
   /    _______         \_   |         /  ___/_____-        |
  /   _/       \__        \_ |       _/__/      \_ \__      |
 /  _/            \______     \     /_/           \   \     |
 |_/                _____\__________/              \        |
 /               __/  __/ _/                          \_   /
 |           ___/    /  _/                              \_ |
 |        __/  /    |  /                  ________   \    \|
 |                  | /                   \XXXXXXXXxx_|    |
 |\                 | |                               |     \___
 | |          |     \ |______                         |         \_
 |  \             ___||XXXXX/                ---_     |           \
 |  |         | xxXXX//                     /___-///  |           |
  \ \        /\     |/                 /   |///OX\\\  |           |
  |  ||    _/  |        __---_         |   | \\XX///   \___      \|
  \ //   _/    |     \\\xxxxx \        |   |\_\---       \ \_      \
   |/  _/      |      | //OXX\\\        \                 \  \_     \
  _/ _/        /\     | \\XXX///\                         |\   \    |
 /__/         /  \     \_-----                            | \   |   /
|/ /              |                       \               /  |   \_/
   |             /|                      _|              |  | __/
  /             | |                  \ -                 / _/_/
  |           _/ _/                         _____       |/
  | _       _/  /\\ \               ________/ / |       /_
  |/       /   /  \_ \_          __/_________/ /       /  \______
   \      |   | \_  \- \_          \__________/      _/          \
    \__   |              \___                      _/\_           |
       \__|\_                \___                _/|   \         /
          \__\_______________/   \___         __/  |\          \/
                       \___  |       \_______/     | \___       |
                        /  \_|                     |   \ \_____/
                _______|____/                       \___\__
#Aside#
        You have met the princess!
#Player#
        I must bring her back safely
#System#
        New goal: Go back to the Lobby following the game_map!
$Windsor$
#System#
        The abandoned Windsor Castle is magnificent but dilapidated.
#System#
        There are 4 exits:
        East    North   South   West
north

                            ..,,,,,,,,,..
                     .,;88888888888888888888;,.
                   88888888888888888888////888888, .,;88;,
            .,;8/,88888/////88888888888888////8888,88//888,
        .,;8888/,888///8888888888888888888888888888,////8888;,
     .,888888//,8888888888888888@@8a8888888888888888,88/8888888;,
   .,8//8888//,8888///////8888888@@@888888///////8888,88//88888888,
 ,88888///88//,88//88888///88888@@@88888////888888888,/8888888888888
.888888888////,8888888//8///8888@@@@888////88/////888,/;88888888/888
8/8888888/////,8888///88////888@@@@@888///88/88888//8,////8888//888'
8//88888//////,8/8a`  'a8///888@@@@@@88////a`  'a8888,//8///8/88888
8///888888///,8888@@aa@@8//888@@@@S@@@88///@@aa@@88888,/8////88888
88//8888888//,88888///////888@S@@@@SS@@@88/////8888888,8////88888'
88//8888888//,8888/////88@8@SS@@@@@@@S@@@@8888/////888,////88888'
`8/8888//88//,888///8888@@@S@@@@@@@@@@@@@@@S8888////88,///88888'
  8888//8888/,88888888@@@@@@@@@@@@@@@@@@@@@SS@88888888,//88888'
  `888//8888/,8888@8@@@@@@@@@@@@@@@@@@@@@@@@@S@@88888,/////88'
   `888//888/,888@@@SS@@SSs@@@@@@@@@@@@@sSS@@@@@@888,//88//8'
    `888888/  88S@@SS@@@@@Ss` .,,.    'sS@@@S@@@@8'  ///8/8'
      `888/    8SS@@@@SSS@@S.         .S@@SSS@@@@'    //88'
               /`S@@@@@@SSSSSs,     ,sSSSSS@@@@@'
             88//`@@@@@@@@@@@@@Ss,sS@@@@@@@@@@@'/
           8888@@00`@@@@@@@@@@@@@'@@@@@@@@@@@'//88
       888888a8@@@@000aaaaaaaaa00a00aaaaaaa008@88888
    888888a88@@@@@@@@@@000000000000000000@@@8@@888@888
 888888a88@@@8@@@@@@@@@@@00000000000000@@@@@@@@@8@@88@88
888aa8@@@@@@@@@@@@@@0000000000000000000000@@@@@@@@8@@@8888
888@@@@@@@@@@@@@@@00000000000000000000000000000@@@@@@@@@88888
#Player#
        Ohhhh Holly Jesus! It's the monster! If I win him I can find the princess!
#Aside#
        You fight with the monster, but you lose. You are dead. Game over. Press any key to start a new game
```