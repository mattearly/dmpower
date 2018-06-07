# Dungeon Master Power Core Version

_A free and open source heavily featured Dungeon Master toolkit that runs efficiently in a Command Line Interface_

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
7. [Credits](#7-credits)
8. [Dev](#8-dev)
9. [ToDo](#9-todo-and-related-projects)

---

### 1. Introduction
       
My original plan was to create a helpful program for _me_ as a Dungeon Master. I put tools in that could save me precious minutes of game time. Faster D&D, More D&D! More to the story with less worry!

* This tool is best suited for Dungeon Masters, but players may find it of some use as well.  
* All rolls and generator randomness done with [Mersenne Twister](https://en.wikipedia.org/wiki/Mersenne_Twister), arguably the best randomizer out there.
* Uncrashable. I've taken measures to make sure the end user cannot accidentally crash the program. You can do no wrong. Go crazy testing.
* Crazy efficient C++ code base. There should never be a delay in any action being processed, even on old ass computers!

[back to index](#0-index)

---

### 2. How To Run DM Power       

* Ubuntu/Mint/Debian Linux. From Bash Command Line -
    1. install dependencies
        * ````sudo apt-get update````
        * ````sudo apt-get install build-essential make gcc git```` 
        * or whatever the equivalent commands are for your distro
    2. clone this repo from github
        * https: ````git clone https://github.com/mattearly/DM-Power-Core-Version.git```` or 
        * ssh: ````git clone git@github.com:mattearly/DM-Power-Core-Version.git````
    3. move to directory
        * ````cd DM-Power-Core-Version````
	4. compile 
		* ````make````
	5. run 
		* ````./dmpower````
	9. or compile and run (steps 4 and 5 sequentially)
		* ````make run````
* Windows. Should work about the same as Linux with [Cygwin](https://www.cygwin.com/) or [WSL](https://msdn.microsoft.com/commandline/wsl/about)
* MacOS. Untested but should work about the same as linux.

[back to index](#0-index)

---

### 3. Character Builder

<img src="img/cliscreenshot_character.png" height="350px" align="right">

_Build and Manage Player Characters_

* Walk through the prompts to create a character _by the book_
    * Save & Load anytime
    * Levels 1 to 20 available. Start at a level of your choosing, level up via the Edit Character functions to prompt new level changes and options.
    * Unbreakable standard 5e rules - you cannot break the D&D rules within the standard context of this command line interface (CLI)   * Unless you go to edit character and then put in the password.  Wonder what it is? Start digging through code, its hardcoded in there. Change it if you want before compiling. The intention of this password is to deter players from editing their characters without the DM overseeing the changes.
    * Versatile starting stat point options: 
        * **option 1**: 4d6 drop lowest
        * **option 2**: 3d6 legit
        * **option 3**: standard set (15, 14, 13, 12, 10, 8)
        * **option 4**: custom entry (within starting bounds)
    * All **Classes, Races, Level Up Paths, Spell Slots, Feats, Skills, Proficiencies, Backgrounds** (yes I put a lot of time into this program) from three official 5th edition books
        1. Player's Handbook
        2. Dungeon Master's Guide (adds evil paladin paths and a few others)
        3. Sword Coast Adventurer's Guide (adds class archetype paths, backgrounds, and a few other things)  
    * More official options to be added soon! See the support link at the bottom of this document.
    * Limitations : Doesn't handle equipment, spell choices, or multiclassing

[back to index](#0-index)

---

### 4. Rewards and Loot

_Magic Item / Reward Roller (by the DM Guide)_

* Scroll and Spellbook Generators : spells chosen randomly to assist with DM's time management
* Loot Rollers by the book. Try out the Hoard Loot option for some fun items.

[back to index](#0-index)

---

### 5. Kismet's Random Name

* Name Generator. 7732 names from Kismet's list randomized. Great for planning and on the fly naming.   

[back to index](#0-index)

---

### 6. Other Tools

* Party Experience Calculator. Total up session or encounter experience (based on CR's overcame) and split it with the party.
* Insult Generator. **NSFW**. For when you just need to anger the PC's or antagonize them with a baddie. I just threw this in for fun. It takes two lists from files and randomly combines words, easily adapted to new words by editing the settings file.
* Random Encounters - accounts for all party member levels and number of members and provides a challenge Rating ranging from very easy to very hard
* Poison prices chart, madness chart, and a few other various things DM's and players might like.

[back to index](#0-index)

---

### 7. Credits
  
* Designed for Dungeons & Dragons 5th Edition Official. The core D&D data used in this program is from:
 
 | [Player's Handbook](http://dnd.wizards.com/products/tabletop-games/rpg-products/rpg_playershandbook) | [Dungeon Master's Guide](http://dnd.wizards.com/products/tabletop-games/rpg-products/dungeon-masters-guide) | [Sword Coast Adventurer's Guide](http://dnd.wizards.com/products/tabletop-games/rpg-products/sc-adventurers-guide) |
 | --- | --- | --- |
 | [![phb](img/DnD_PHB.png)](http://dnd.wizards.com/products/tabletop-games/rpg-products/rpg_playershandbook) | [![dmg](img/DnD_DMG.png)](http://dnd.wizards.com/products/tabletop-games/rpg-products/dungeon-masters-guide) | [![scag](img/DnD_SCAG.png)](http://dnd.wizards.com/products/tabletop-games/rpg-products/sc-adventurers-guide) |

 * Coded by [**_Matthew Jay Early_**](https://twitter.com/matthewjayearly).

[back to index](#0-index)

---

### 8. Dev

* Feel free to correct stuff, make pull requests, or just let me know by raising an issue ticket thingy.

[back to index](#0-index)

---

### 9. ToDo and Related Projects

1. Expand core functionality and add more character options (see Github projects tab for more info)
2. Partly Done - Build Interfaced Version
    * Some of the more useful tools (**Random Hoard Loot**, **Random Scrolls**, **Random Names**, and **Random Spellbooks**) have been transposed to a graphical interface (using [SDL2](https://www.libsdl.org/) libraries) with some effects and it works great so far. See [PLUNDER](https://github.com/bytePro17124/Plunder_DungeonsAndDragons_Loot_5e) repo.
3. Build Interfaced Character Maker. Pieces of it are done on a private repo but it has a ways to go.

[back to index](#0-index)

---

* [![donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=45RLH5HDMQZ) to keep this project alive. 
    * donations are used to purchase books and put in time to expand this program (see project tab on Github for more info on what will be tackled next, time and funding permitting)
    * total donated so far: $0
        * donaters:


