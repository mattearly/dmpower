### Contributing to Dungeon Master Power, what you need to know

 - Go by the official D&D books and rules in general. Some homebrew may be added, but only in small doses in only where it can be taken as a suggestion and not as a set rule (such as the name generator).

#### The source code

 - Many sections in lists of code (but not all) are layed out alphabetically, try to preserve the order if it seems like everything else is in order.
 
 - When adding new variables to [characters.h](src/characters.h):
    - The [characters.cpp](src/characters.cpp) should initilize them in the default constructor to `0`.
    - The dumpCharacter & retrieveCharacter functions in [campaign.cpp](src/campaign.cpp) must be updated.
      - These functions run in a very specific sequential order, which is the same order they are in the character header file.
      - All older saves will no longer work after these functions are updated, and the notes on the release update **must** reflect this. Use an older version of the program to open your older files. (I plan to make some sort of fail safe in the future so people cannot try to load bad saves, like a version tag at the top of the save.)
    - The print* functions in [character_print.cpp](src/character_print.cpp) must be updated.

- Its probably also worth noting that this was one of my first C++ projects I started when I was just learning to program, so some of the ways I did things may seem strange to developers who have been in the game for a long time. I'm hear to learn if there is a better way and I'm always looking to scale better, however at this point I am also taking into account the time involved in any major refactor as things are working as they are for now.

#### Documenting code

- Use [doxygen](http://www.doxygen.nl/manual/docblocks.html) to make the documentation from the code, all new code should have doxygen comments, old code will be updated slowly (or so we can all hope).

#### Response time for issues and pull requests

- It depends on how busy I am and if I am currently working on this or something else. Expect somewhere between same day and up to one week.

#### if you have contributed

- Feel free to add yourself to the [contributors file](CONTRIBUTORS.md) along with notes about what you did to halp out.

