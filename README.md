# Dungeon Master Power Core Version

_A free and open source heavily featured Dungeon Master toolkit that runs efficiently in a Command Line Interface (CLI)_

<img src="img/cliscreenshot.png" height="140px" align="left">

<img src="img/cliscreenshot_characters2.png" height="140px" align="left">

<img src="img/cliscreenshot_characters.png" height="140px" align="left">

<img src="img/cliscreenshot_treasure.png" height="140px" align="center">

### 0. Index

1. [Introduction](#1-introduction)
2. [How To Run DM Power](#2-how-to-run-dm-power)
3. [Character Builder](#3-character-builder)
4. [Reward Loot](#4-reward-and-loot)
5. [Kismet's Random Name](#5-kismets-random-name)
6. [Other Tools](#6-other-tools)
7. [Dev](#7-dev)
8. [ToDo](#8-todo-and-related-projects)
9. [Support](#9-support)
10. [Credits](#10-credits)


---

### 1. Introduction

My original plan was to create a helpful program for _me_ as a Dungeon Master. I have added in any tools that could save precious minutes of game time. In the improvements and continuation of this project, I strive towards improving and evolving the kit to be as useful as possible. Faster D&D! More D&D! More Story! Less Worry!

* This tool is best suited for Dungeon Masters and assisting them with keeping the game running quickly. Players may find DM-Power to be of some use as well.

* Homebrew is left up to the individual. I try to mainly use official stuff here (unless otherwise noted) and adapting and changing it to your game style should be done at your will.

* This tool does not teach the game or say many specifics about what each ability, magic item, or spell does, as that is just not the intention and it is more of a semi-official guideline of the wotc book's recommendations. You should be decently familiar with the rules and comfortable looking up unknown specific details to make the best use of DM-Power. I recommend purchasing the books and supporting the great company behind this game!

* All dice rolls and generator randomness done with [Mersenne Twister](https://en.wikipedia.org/wiki/Mersenne_Twister), arguably the best randomizer out there.

* Uncrashable. I've taken measures to make sure the end user cannot accidentally crash the program. You can do no wrong. Go crazy testing.

* Efficient C++ code base, uses the c++11 standard with no additional libraries. There should never be a delay in any action being processed, even on old ass computers! Anything deemed clucky or useless should reanalyzed and redone.

[back to index](#0-index)

---

### 2. How To Run DM Power

*Relies on C++ Standard 11 and Make*

* Ubuntu/Mint/Debian Linux. From Bash Command Line -
    1. Install Dependencies

        1. `sudo apt-get update`

        2. `sudo apt-get install build-essential make gcc git`

        * (or whatever the equivalent commands are for your distro)

    2. Clone this repo from github

        * https:

            `git clone https://github.com/mattearly/DM-Power-Core-Version.git`

            or 

        * ssh:

            `git clone git@github.com:mattearly/DM-Power-Core-Version.git`

    3. Move to directory

        * `cd DM-Power-Core-Version/`

    4. Compile 

        * `make`

    5. Run 

        * `./dmpower`

    * or compile and run (steps 4 and 5 sequentially)

        * `make run`

* Windows. Should work about the same as Linux with [Cygwin](https://www.cygwin.com/) or [WSL](https://msdn.microsoft.com/commandline/wsl/about)

* MacOS. Untested but should work about the same as linux once you have make and a c++ compiler.

[back to index](#0-index)

---

### 3. Character Builder

<img src="img/cliscreenshot_character.png" height="350px" align="right">

_Build and Manage Player Characters by the book_

* **Character Creator**. Walks though and prompts all relevant options.

* **Levels**. All classes levels 1 to 20 supported. No multiclassing supported.

* **Character Building Rules and Flow**. Fully configured official `Classes`, `Races`, `Class Archtype Paths`, `Spell Slots`, `Feats`, `Skills`, `Proficiencies`, `Backgrounds`, and `Variant Options` selection systems. Logically based on the wotc books [credited below](#10-credits).

* **Save**. Reliable save and load for your campaign's characters.

* **Unbreakable Standard 5e Rules**. Users cannot break the character building D&D rules unless... (see edit character below)

* **Edit Character**. 'God' powers. Edit stats (min=1, max=30), give feats, give skills, give levels, change name, change alignment. DM Password entry required. Password [hardcoded](src/campaign.cpp) to `password` by default, change it and recompile with `make` if you wish - or remove it all together in some crafty coded fashion. 

* **Versatile Starting Stat Point Options**.

    * **option 1**: 4d6 drop lowest
    * **option 2**: 3d6 legit
    * **option 3**: standard set (15, 14, 13, 12, 10, 8)
    * **option 4**: custom entry (within standard starting 3-18 bounds(before bonuses applied))

* **Limitations**. Doesn't handle equipment or spell choices or personality traits. I generally jot these down near the character name on my campaign notes. 

[back to index](#0-index)

---

### 4. Rewards and Loot

_Magic Item / Reward Roller (by the DM Guide)_

* **Scroll and Spellbook Generators**. I dunno about you, but when a PC gets ahold of a NPC's spellbook, there goes 10+ minutes of game time working up the spells in it. Or just use this and it takes 30 seconds. Spells in this Spellbook Generator chosen randomly to assist with DM's time management. You can also grab a single random spell of any level using the Scroll Generator.

* **Loot Rollers**. Try out the Hoard Loot option for some fun. All scrolls are randomized (no more `level x unspecific scroll` (goodbye game time while the DM figures out what spell it or should be), here you get `Level 9 Scroll of Storm of Vengeance (druid)` for example. 
    * This tool is very powerful. I've found it is often best to use the hoard loot as a guideline or ideas and not necessarily give the players every single thing that it rolls up - just the things that make sense in the context of your game. Too many magical items and variables can overwhelm players and take away from the gameplay.

[back to index](#0-index)

---

### 5. Kismet's Random Name

* **Name Generator**. 7732 names from Kismet's list randomized with Mersenne Twister. Use the name, use something close that is more fitting to the scenario, or just roll a new random name to inspire new name ideas. I find this very helpful when DMing and no longer mind when players constantly keep asking the names of every single (seemingly inconsequential) NPC. A good name can mean a lot for immersion.

[back to index](#0-index)

---

### 6. Other Tools

* **Party Experience Calculator**. Total up session or encounter experience and split it with the party. This prompts for Challenge Ratings that the party has overcame and then divides by the number of players.

* **Insult Generator**. **NSFW**. For when you just need to anger the PC's or antagonize them with a baddie. I just threw this in for fun. It takes two lists from a file and randomly combines words, easily adapted to new words by editing the settings file [insults.dat](settings/insults.dat) - just note that if you change the number of words in that file, it must be adjusted in the code as well, you'll find the number of words hardcoded in [gen_insult.cpp](src/gen_insult.cpp) (to be improved later to be more adaptable and automatic).

* **Random Encounters**. Difficulty Generator that accounts for
    * party member levels (can be of any variety of legal levels)
    * your group size (max 20 members)

        and provides a Challenge Rating ranging from very easy to very hard. Go ahead, give it 20 level 1 characters and see what kind of CR it recommends.

        I plan on improving this tool to include asking for terrain and offering some monster encounter setups, looking for some official charts and setupds from one or several of the books to go off of.

* **Charts**. Just kinda threw these in, and end up using the Poison chart frequently. There always seems to be at least one player interested in using poison.

    * Poison Prices chart
    * Madness chart
    * Diseases chart

[back to index](#0-index)

---

### 7. Dev

* Feel free to correct stuff and make pull requests, or just let me know by raising an issue ticket thingy. If you don't want to dig into the code, general bug reports help a lot. Donations always help as well, it would be a dream to do something like this as an actual job.

[back to index](#0-index)

---

### 8. ToDo and Related Projects

1. Expand core functionality, fix all bugs, and add more character options (see Github projects tab for more info)

**related side projects**

2. Graphical Interfaced Version
    * Reward Loot tools: [Plunder](https://github.com/mattearly/Plunder)
    * Character Manager: **unreleased** 

[back to index](#0-index)

---

### 9. Support
* [![donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=PX2EZKRVB4TTC) to keep this project alive. 
* donations are used to go towards development of this program/project, DM-Power-Core-Version. 
* total donated so far: $0
    * donaters:

[back to index](#0-index)

---

### 10. Credits

* Designed for Dungeons & Dragons 5th Edition Official. The core D&D data used in this program is from:
 
 | [Player's Handbook](http://dnd.wizards.com/products/tabletop-games/rpg-products/rpg_playershandbook) | [Dungeon Master's Guide](http://dnd.wizards.com/products/tabletop-games/rpg-products/dungeon-masters-guide) | [Sword Coast Adventurer's Guide](http://dnd.wizards.com/products/tabletop-games/rpg-products/sc-adventurers-guide) |
 | --- | --- | --- |
 | [![phb](img/DnD_PHB.png)](http://dnd.wizards.com/products/tabletop-games/rpg-products/rpg_playershandbook) | [![dmg](img/DnD_DMG.png)](http://dnd.wizards.com/products/tabletop-games/rpg-products/dungeon-masters-guide) | [![scag](img/DnD_SCAG.png)](http://dnd.wizards.com/products/tabletop-games/rpg-products/sc-adventurers-guide) |

 * Coded by [**_Matthew Jay Early_**](https://twitter.com/matthewjayearly).

[back to index](#0-index)
