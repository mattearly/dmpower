# dmpower-dungeons-and-dragons-5e

Dungeon Master Power (dmpower) is a terminal-based D&D5e toolkit intended for Dungeon Masters to aid in game prep and/or on the fly assistance.

All you have to do is run it in your terminal and all options will be prompted by my custom menu system, which is built to be uncrashable by bad input.

## Features

### 5th Edition Characters

- 12 classes with meticulously programmed level class trees, level 1 to 20, random name generator, 4 common starting stat options, 22 races (+ additional subraces), 9 alignments, 25 backgrounds + custom backgrounds supported, 18 skills, 20 languages, 42 feats, calculates average hit points, calculates spell slots, and much more.
- Save, Load, and Export. Save/load a list of characters based on a unique campaign name.
- Character Editor for DMs. Edit stats (min=1, max=30), give feats, give skills, give levels, change name, change alignment.
- Limitations: Character Builder doesn't handle equipment, spell choices (only a chart of your spell slots), multiclassing, or personality traits. Also the weaker NPC classes from the DM guide (such as warrior, expert, etc) are not included.

### LOOT GENERATION

- Loot rollers for single mob or a treasure horde (charts in the DM Guide).
- Spellbook Generator. Generates a spellbook of randomly chosen Wizard spells. Also tells you how many pages are being used in the spellbook. Excellent for NPC wizards or players that like the idea of having random spells.
- All scroll loot is pregenerated int a spell name so the DM actually knows what scroll is found (something the charts in the DM guide lacks).

### MORE VARIOUS TOOLS

- Name Generator. 7732 names from [Kisment's list](http://www.dnd.kismetrose.com/pdfs/KismetsFantasyNames.pdf) with randomized selection. Edit the file [data/names.dat](data/names.dat) to add/remove names. The code that handles it automatically adjusts based on the number of lines in the file. Be sure to keep the newline at the end of the file(otherwise the last name on the list will never be chosen).
- XP Calculator. Total up Challenge Ratings split it with the party. This prompts for CR's that the party has overcome and then divides by the number of players. Pretty standard calculator stuff.
- Insult Generator. Has clean and dirty mode, use depending on your group's style. Defaults to clean. Easily adapted to new words by editing the settings file [data/insults-dirty.dat](data/insults-dirty.dat) or [data/insults-clean.dat](data/insults-clean.dat) - just note that if you change the number of words in that file, it must be adjusted in the code as well, you'll find the number of words hardcoded in [src/gen_insult.cpp](src/gen_insult.cpp) (to be improved later to be more adaptable and automatic).
- Random Encounter CRs. Difficulty Generator that accounts for all party member levels and group size, generates and appropriate Challenge Rating even for the oddest of groups. Seeded from -2 to +2 representing _Very Easy_, _Easy_, _Normal_, _Hard_, _Very Hard_
- Charts. There always seems to be at least one player interested in using poison. Madness can be useful in many cases (causing scenarios, things for the PC's to deal with, etc).
  - Level Up chart
  - Poison Prices chart
  - Madness chart
  - Diseases chart
  - Player problem resolution flowchart walkthrough (based off of and credits to the creator for the idea [Resolving Basic Behavioral Problems in your Tabletop RPG Group: A Flowchart](https://www.reddit.com/r/rpg/comments/3avp57/resolving_basic_behavioral_problems_in_your/)

There are probably more features that I've missed, I've been tweaking this program for years.

### SAVED USER SETTINGS

- Toggle NPC insult settings (clean or dirty)
- Toggle Clear Screen preference (on or off) (part of my custom menu system flow options)

## Running dmpower on any OS

### Run on Linux (easy and optimal)

Dependencies:

- git `git`
- make `make`
- C++11 `g++`
- boost filesystem `libboost-filesystem-dev`

Build and Run:

1. `git clone https://github.com/mattearly/dmpower`  clone this repo (or go to releases and pick a version, or clone however you are comfortable cloning. I would suggest forking if you are going to work on it and make pull requests.)
2. `cd dmpower/`  change directory to where you downloaded the files
3. `make run` use this make command to build the program and run it after the build finishes

Install dependencies if something fails to build, error messages should tell you what you need and it is likely one of the above dependencies.

### Run on Windows (easy)

Use [Cygwin](https://www.cygwin.com/), or [WSL](https://msdn.microsoft.com/commandline/wsl/about), or mingw, or Powershell. Pretty much anything you can get the dependencies on it will work with.

- If you are using Cygwin, you will need the packages `gcc-core`, `make`, `libboost-devel`, and of course `git` for the git clone command, then it should work just like the linux build and run above.
- In case of using the Powershell terminal, you will need to activate the ansi color escape with this command:
  - `Set-ItemProperty HKCU:\Console VirtualTerminalLevel -Type DWORD 1`
  - [more discussion on this topic](https://stackoverflow.com/questions/51680709/colored-text-output-in-powershell-console-using-ansi-vt100-codes)
- I have not tested with Visual Studio. Should work but may need some modifications or project setup.

### Run on Mac (easy and probably optimal)

May need homebrew for boost libraries.

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

## Other Notes

dmpower is an open source non-profit community project that I started on my own while at University. It or I am not directly affiliated with Wizards of the Coast or Hasbro (if someone from one of those companies sees this and would like to have a further discussion about it, I am available).

dmpower is not to be used for any form of profit or sale. I personally just wanted something I was motivated to work on while studying to improve my C++ Programming skills and I was getting tired of flipping through books and causing downtime in my D&D games, thus I was motivated to continue building this program. It has taken many hours and there were many many completely failed early versions that have been scrapped. All the code was written by me (Matthew Early) (unless otherwise noted by the git commits from various contributors).

Also the usual applies of use at your own risk and I am not responsible for damage etc etc the usual stuff you see on free software.

If you wish to contribute or help this program move along, feel free to dig in.
