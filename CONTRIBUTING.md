# Contributing to Dungeon Master Power

## what you need to know

- Go by the official D&D rules in general. Some homebrew may be added, but only in small doses in only where it can be taken as a suggestion and not as a set rule (such as the name generator).

### The source code

1. Many sections in lists of code (but not all) are layed out alphabetically, try to preserve the order if it seems like everything else is in order.
2. When adding new variables to [characters.h](src/characters.h) (this might be made easier by binary saves at some point - will test in later versions):
    - The [characters.cpp](src/characters.cpp) should initilize them in the default constructor to `0`.
    - The dumpCharacter & retrieveCharacter functions in [campaign.cpp](src/campaign.cpp) must be updated.
    - These functions run in a very specific sequential order, which is the same order they are in the character header file.
    - All older saves will no longer work after these functions are updated, and the notes on the release update **must** reflect this. Use an older version of the program to open your older files.
    - The print* functions in [character_print.cpp](src/character_print.cpp) must be updated.
3. Its probably also worth noting that this was one of my first C++ projects I started when I was just learning to program. I'm here to learn if there is a better way and I'm always looking to scale better, however at this point I am also taking into account the time involved in any major refactor to keep all current features displayed to the user in a fully functional state.

### Documenting code

- Use [doxygen](http://www.doxygen.nl/manual/docblocks.html) if you feel like it. Old code doesn't all have it.

### Response time for issues and pull requests

- It depends on how busy I am and if I am currently working on this or something else. Expect somewhere between one day to one week.

### If you have contributed

- Thanks. You have earned a pat on the back. *pat pat pat*. Consider that debt paid. You have also earned one Matt Cool Point, which is redeemable at your local Matt outlet.
