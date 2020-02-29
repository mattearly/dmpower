# dmpower-dungeons-and-dragons-5e

Dungeon Master Power (dmpower) is a terminal-based D&D5e toolkit intended for Dungeon Masters to aid in game prep and on the fly assistance. All you have to do is launch it and all options will be prompted in my custom terminal menu system, which is built to be fast and be uncrashable by bad user prompt input.

### Run dmpower on Linux (easy and optimal)

Dependencies:

- git
- make
- C++17
- boost filesystem

`sudo apt install git make g++ libboost-filesystem-dev` *cmd may vary on your OS, this was last tested on lxubuntu*

Build and Run:

1. `git clone https://github.com/mattearly/dmpower`
2. `cd dmpower/`
3. `make run`

Install dependencies if something fails to build, then try again.

### Run on Windows (easy)

Use [Cygwin](https://www.cygwin.com/), or [WSL](https://msdn.microsoft.com/commandline/wsl/about), or mingw, or Powershell. Pretty much anything you can get the dependencies on it will work with.

- If you are using Cygwin, you will need the packages `gcc-core`, `make`, `libboost-devel`, and of course `git` for the git clone command, then it should work just like the linux build and run above.
- In case of using the Powershell terminal, you will need to activate the ansi color escape with this command:
  - `Set-ItemProperty HKCU:\Console VirtualTerminalLevel -Type DWORD 1`
  - [more discussion on this topic](https://stackoverflow.com/questions/51680709/colored-text-output-in-powershell-console-using-ansi-vt100-codes)
- I have not tested with Visual Studio. Should work but may need some modifications or project setup.

### Run on Mac (easy and probably optimal)

May need homebrew for boost libraries.

# Some Screenshots

*Screenshots taken on Windows Cygwin64 with green default text and black background. Your experience will vary depending on your terminal settings.*

<img src="img/character_manager.png" width="400" align="left">
<img src="img/main_menu.png" width="400" align="center">
<img src="img/character_sheet.png" width="400" align="left">
<img src="img/new_character.png" width="400" align="center">
<img src="img/random_spellbook.png" width="400" align="center">

## 0. Manual

> 1. [BUILD & MANAGE CHARACTERS](#1-build-and-manage-characters)
> 2. [LOOT GENERATION](#2-loot-generation)
> 3. [OTHER TOOLS](#3-more-tools)
> 4. [SETTINGS](#4-settings)

---

### 1. BUILD AND MANAGE CHARACTERS

* **Build Characters**. Walk though creating a new character with prompts for ALL relevant options.

    * Level 1 to 20 supported.
    * Almost all core book PC Races, Classes, Archtype Paths, Spell Slots, Feats, Skills, Proficiencies, Backgrounds, and Variant Options.
    * Starting Stat Options: 4d6 drop low, 3d6 legit, Standard (15, 14, 13, 12, 10, 8), Custom(3 to 18 per score).
    * Save, Load, and Export.
    * Random Name Generator (7,700+ names, editable config).
    * Random Character Generator, give it a level of character to build and it does the rest, producing a random character from all available options. Dynamic scalable randomization system.

* **Edit Character**. DM God Powers. Edit stats (min=1, max=30), give feats, give skills, give levels, change name, change alignment.
* **Limitations**. Character Builder doesn't handle equipment, spell choices, multiclassing, or personality traits. These may be great features to add in later.

[back to index](#0-manual)

---

### 2. LOOT GENERATION

* **Spellbook Generator** : Tell it how many of for each level (enter 0 to skip spells of that level), and it generates a spellbook full or randomly chosen Wizard spells. Also tells you how many pages are being used in the spellbook. Excellent for NPC wizards or players that like the idea of having random spells.

* **Scroll Generator** : You can also grab a single spell of any level and class randomly using the Scroll Generator.

* **Loot Rollers**. Try out the Hoard Loot option for a treasure cache or to populate a dungeon being built. All scrolls that are given are automatically put through the Scroll Generator (no more `level x unspecific scroll`, here you get `Level 3 Scroll of Fireball (sorcerer, wizard)` for example).

[back to index](#0-manual)

---

### 3. MORE TOOLS

* **Name Generator**. 7732 names from [Kisment's list](http://www.dnd.kismetrose.com/pdfs/KismetsFantasyNames.pdf) with randomized selection. Edit the file [data/names.dat](data/names.dat) to add/remove names. The code that handles it automatically adjusts based on the number of lines in the file. Be sure to keep the newline at the end of the file(otherwise the last name on the list will never be chosen).

* **Party Experience Calculator**. Total up Challenge Ratings split it with the party. This prompts for CR's that the party has overcome and then divides by the number of players. Pretty standard calculator stuff.

* **Insult Generator**. Has clean and dirty mode, use depending on your group's style. Defaults to clean. Easily adapted to new words by editing the settings file [data/insults-dirty.dat](data/insults-dirty.dat) or [data/insults-clean.dat](data/insults-clean.dat) - just note that if you change the number of words in that file, it must be adjusted in the code as well, you'll find the number of words hardcoded in [src/gen_insult.cpp](src/gen_insult.cpp) (to be improved later to be more adaptable and automatic).

* **Random Encounters**. Difficulty Generator that accounts for all party member levels and group size, generates and appropriate Challenge Rating even for the oddest of groups. Seeded from -2 to +2 representing _Very Easy_, _Easy_, _Normal_, _Hard_, _Very Hard_

* **Charts**. There always seems to be at least one player interested in using poison. Madness can be useful in many cases (causing scenarios, things for the PC's to deal with, etc).

    * Level Up chart
    * Poison Prices chart
    * Madness chart
    * Diseases chart
    * Player problem resolution flowchart walkthrough (based off of and credits to the creator for the idea [Resolving Basic Behavioral Problems in your Tabletop RPG Group: A Flowchart](https://www.reddit.com/r/rpg/comments/3avp57/resolving_basic_behavioral_problems_in_your/)

[back to index](#0-manual)

---

### 4. SETTINGS

* NPC insult settings (clean or dirty)
* Clear Screen preference (on or off)

[back to index](#0-manual)

---

## Sources

*WoTC*
* [Player's Handbook](http://dnd.wizards.com/products/tabletop-games/rpg-products/rpg_playershandbook)
* [Dungeon Master's Guide](http://dnd.wizards.com/products/tabletop-games/rpg-products/dungeon-masters-guide)
* [Sword Coast Adventurer's Guide](http://dnd.wizards.com/products/tabletop-games/rpg-products/sc-adventurers-guide)
* [Volo's Guide to Monsters](http://dnd.wizards.com/products/tabletop-games/rpg-products/volos-guide-to-monsters)
* [Wayfinder's Guide to Eberron](https://www.dmsguild.com/product/247882/wayfinders-guide-to-eberron-5e)
* to analyze [Xanathar's Guide to Everything]()
* to analyze [Guildmaster's Guide to Ravnica]()
* [The Tortle Package](https://www.dmsguild.com/product/221716/Tortle-Package-5e)
* to analyze [Mordenkain's Tome of Foes]()
* [Elemental Guide of Evil](https://www.dmsguild.com/product/145542/Elemental-Evil-Players-Companion-5e)

*Other*
* [Kismet's Name List](http://www.dnd.kismetrose.com/MyCharacterNameList.html)
* [Resolving Basic Behavioral Problems in your Tabletop RPG Group: A Flowchart](https://www.reddit.com/r/rpg/comments/3avp57/resolving_basic_behavioral_problems_in_your/)
