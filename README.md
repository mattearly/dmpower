# Dungeon Master Power Core Version (DMPOWER)

<img src="img/cliscreenshot.png" height="140px" align="left">

<img src="img/cliscreenshot_characters2.png" height="140px" align="left">

<img src="img/cliscreenshot_characters.png" height="140px" align="left">

<img src="img/cliscreenshot_treasure.png" height="140px" align="center">

### 0. Index

1. [Introduction](#1-introduction)
2. [How To Run DM Power](#2-how-to-run-dm-power)
3. [Character Builder](#3-character-builder)
4. [Reward Loot](#4-reward-loot)
5. [Kismet's Random Name](#5-kismets-random-name)
6. [Other Tools](#6-other-tools)
7. [Credits](#7-credits)
8. [Dev](#8-dev)
9. [ToDo](#9-todo)

---

### 1. Introduction
       
My original plan was to create a helpful program for _me_ as a Dungeon Master. I put tools in that could save me precious minutes of game time. Faster and better D&D!

* This tool is best suited for Dungeon Masters, but players may find it of some use as well.  
* All rolls and generator randomness done with [Mersenne Twister](https://en.wikipedia.org/wiki/Mersenne_Twister), arguably the best randomizer out there.
* Uncrashable. I've taken measures to make sure the end user cannot accidentally crash the program. You can do no wrong. Go crazy testing.
* My main goal with this program is to keep it crazy efficient codewise and use-wise. There should never be a delay in any action being processed, even on old ass computers!

[back to index](#0-index)

---

### 2. How To Run DM Power       

**DMPOWER is a Command Line Interface program**


* Linux. From Command Line -
    1. c++11 dependencies
        * ````sudo apt-get update````
        * ````sudo apt-get install build-essential make gcc git````
    2. clone from github
        * ````git clone https://github.com/bytePro17124/DMPOWER````
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

* Walk through the prompts to create a full character _by the book_
    * Save & Load Working
    * Levels 1 to 20. Leveling up works so you can manage a character over time and on the fly - you can't break the D&D book rules within the standard context of the command line interface.
    * Versatile starting stat point options: 4d6 drop lowest, 3d6 legit, standard set (15, 14, 13, 12, 10, 8)
    * Has All **Classes, Races, Level Up Paths, Spell Slots, Feats, Skills, Proficiencies, Backgrounds** EVERY Class and Race option (yes I put a lot of time into this program) from three official 5th edition books
        1. Player's Handbook
        2. Dungeon Master's Guide (adds evil paladin paths and a few others)
        3. Sword Coast Adventurer's Guide (adds class archetype paths, backgrounds, and a few other things)  
    * Limitations : Doesn't handle equipment, spell choices, or multiclassing

[back to index](#0-index)

---

### 4. Reward Loot

_Magic Item / Reward Roller (by the DM Guide)_

* Scroll and Spellbook Generators : Randomized
* Loot Rollers by the book. Try out the Hoard Loot option for some fun items.

[back to index](#0-index)

---

### 5. Kismet's Random Name

* Name Generator. 7732 names from Kismet's list randomized. Great for planning and on the fly naming.   

[back to index](#0-index)

---

### 6. Other Tools

* Party Experience Calculator. Total up session or encounter experience (based on CR's overcame) and split it with the party. Pretty straightforward, could use some UI improvements but it is fully functional.
* Insult Generator. **NSFW**. For when you just need to anger the PC's or antagonize them with a baddie. I just threw this in for fun. It takes two lists from files and randomly combines words, easily adapted to new words by editing the settings file.
* Random Encounters(only minorly built right now but does a good job of providing a Challenge Rating for adventuring parties of various sizes and levels)
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

* Feel free to correct stuff and make pull requests, or just let me know by raising an Issue ticket thingy.

[back to index](#0-index)

---

### 9. ToDo 

1. Partly Done - Build Interfaced Version
    * Some of the more useful tools (**Random Hoard Loot**, **Random Scrolls**, **Random Names**, and **Random Spellbooks**) have been transposed to a graphical interface (using [SDL2](https://www.libsdl.org/) libraries) with some effects and it works great so far: [PLUNDER D&D LOOT](https://github.com/bytePro17124/Plunder_DungeonsAndDragons_Loot_5e)
2. Build Interfaced Character Maker. Pieces of it are done on a private repo but it has a ways to go.
3. Find time to work on this more.

[back to index](#0-index)

---

* [![donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=45RLH5HDMQZ) to keep this project alive. 

