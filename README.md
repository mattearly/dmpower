# dmpower-dungeons-and-dragons-5e

dmpower is a terminal-based Dungeons & Dragons 5th edition toolkit intended for Dungeon Masters. Its primary use is to hasten game prep and on the fly assistance. dmpower runs in your terminal window and prompts all available options. I take personal care to make sure everything it presents is accurate and stable. Please raise a ticket if you see something that *might* need addressed.

## Core Features

### 5th Edition Player Characters

- All 12 core PHB + DMG classes fully available. 22 different races including all core subraces. Meticulously programmed level class trees. My custom integrated level up system supports levels 1 to 20 and includes random name suggestions, common stat block options, all alignments, all backgrounds + custom background option, all skills, enough languages to shake a stick at, and all core feats. It also gives average HP for both npcs + pcs(pcs start with max first level HP in most common rule), and it tells you all your spell slots for your current level and spec.
- Save + Load campaigns (which is basically a grouped load of available characters).
- Character Editor for leveling up existing characters, or breaking some of the rules (intended for DM use to grant additional 'things' for the player). The DM only use feature includes: Edit stats (min=1, max=30), give feats, give skills, change name, change alignment.
- Limitations: Character Builder doesn't handle equipment, spell memorization choices, multiclassing, or personality traits. NPC classes (warrior, expert, aristocrat) from the DMG are not included.

### Loot and Randomizers

- Randomized Loot Rollers based on the charts in the DM Guide.
- Spellbook Generator to randomize Wizard Spellbooks.
- All Scrolls generate to spell names of the appropriate level.

## More Various Integrated Tools

- Random Name Generator. Names from [Kisment's list](http://www.dnd.kismetrose.com/pdfs/KismetsFantasyNames.pdf). Custom Editable [config file](data/names.dat).
- XP Calculator.
- Insult Generator. Has clean and dirty mode. Easily adapted to new words by editing the settings file [data/insults-dirty.dat](data/insults-dirty.dat) or [data/insults-clean.dat](data/insults-clean.dat) - just note that if you change the number of words in that file, it must be adjusted in the code as well, you'll find the number of words hardcoded in [src/gen_insult.cpp](src/gen_insult.cpp) (to be improved later to be more adaptable and automatic for varying sizes like the name generator already does).
- Random Encounters. Difficulty Generator that accounts for all party member levels and group size, generates an appropriate Challenge Rating even for the oddest of groups. Seeded from -2 to +2 representing _Very Easy_, _Easy_, _Normal_, _Hard_, _Very Hard_. I'm not sure that this is all that useful yet, I would like to add in mob group generators based on location.
- I threw in some Charts. There always seems to be at least one player interested in using poison. Madness can be useful in many cases (causing scenarios, things for the PC's to deal with, etc).
  - Level Up chart
  - Poison Prices chart
  - Madness chart
  - Diseases chart
  - Player problem resolution flowchart walkthrough (based off of and credits to the creator for the idea [Resolving Basic Behavioral Problems in your Tabletop RPG Group: A Flowchart](https://www.reddit.com/r/rpg/comments/3avp57/resolving_basic_behavioral_problems_in_your/)

## Build Using CMake

### Build & Run on Linux (easy and optimal)

#### Dependencies

- git `git`
- cmake `cmake`
- C++14 `g++`
- boost filesystem `libboost-filesystem-dev`

#### Build and Run

1. `git clone https://github.com/mattearly/dmpower` clone this repo (or go to releases and pick a version, or clone however you are comfortable cloning. I would suggest forking if you are going to work on it and make pull requests.)
2. `cd dmpower/` change directory to where you downloaded the files
3. `make run` use this make command to build the program and run it after the build finishes

Install dependencies if something fails to build, error messages should tell you what you need and it is likely one of the above dependencies.

#### One Liner

Installs dependencies, clones dmpower, configures with cmake, builds into a /build/ dir, runs dmpower.

````sudo apt-get install git cmake g++ libboost-filesystem-dev && git clone https://github.com/mattearly/dmpower.git && cd dmpower && mkdir build && cd build && cmake ../ && make && ./dmpower````

### Run on Windows (easy)

Use [Cygwin](https://www.cygwin.com/), or [WSL](https://msdn.microsoft.com/commandline/wsl/about), or mingw, or Powershell. Pretty much anything you can get the dependencies on it will work with.

- If you are using Cygwin, you will need the packages `gcc-core`, `make`, `libboost-devel`, and of course `git` for the git clone command, then it should work just like the linux build and run above.
- In case of using the Powershell terminal, you will need to activate the ansi color escape with this command:
  - `Set-ItemProperty HKCU:\Console VirtualTerminalLevel -Type DWORD 1`
  - [more discussion on this topic](https://stackoverflow.com/questions/51680709/colored-text-output-in-powershell-console-using-ansi-vt100-codes)
- I have not tested with Visual Studio. Should work but may need some modifications or project setup.

CMake and it should work with Visual Studio

### Run on Mac (easy and probably optimal)

May need homebrew for boost libraries. Use CMake.

#### Some Screenshots

*Screenshots taken on Windows Cygwin64 with green default text and black background. Your experience will vary depending on your terminal settings.*

[screenshots folder](/img/)

## Sources

### Books

- [Player's Handbook](http://dnd.wizards.com/products/tabletop-games/rpg-products/rpg_playershandbook)
- [Dungeon Master's Guide](http://dnd.wizards.com/products/tabletop-games/rpg-products/dungeon-masters-guide)
- [Sword Coast Adventurer's Guide](http://dnd.wizards.com/products/tabletop-games/rpg-products/sc-adventurers-guide)
- [Volo's Guide to Monsters](http://dnd.wizards.com/products/tabletop-games/rpg-products/volos-guide-to-monsters)
- [Wayfinder's Guide to Eberron](https://www.dmsguild.com/product/247882/wayfinders-guide-to-eberron-5e)
- [The Tortle Package](https://www.dmsguild.com/product/221716/Tortle-Package-5e)
- [Elemental Guide of Evil](https://www.dmsguild.com/product/145542/Elemental-Evil-Players-Companion-5e)

### Internet

- [Kismet's Name List](http://www.dnd.kismetrose.com/MyCharacterNameList.html)
- [Resolving Basic Behavioral Problems in your Tabletop RPG Group: A Flowchart](https://www.reddit.com/r/rpg/comments/3avp57/resolving_basic_behavioral_problems_in_your/)

## Notes

### Legal

This project and I are not directly affiliated with Wizards of the Coast or Hasbro.

dmpower is not to be used for any form of profit or sale.

See the [LICENSE](LICENSE) file for more information.

### Development

For rolling release notes and versions, see the [releases](https://github.com/mattearly/dmpower-dungeons-and-dragons-5e/releases) tab in Github.

## Special Thanks

For those getting involved in the project and helping out at times! It does mean a lot. Thanks. -Matt
