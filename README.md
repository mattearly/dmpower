### 0. Index

> 1. [Introduction](#1-introduction)
> 2. [How To Run DM Power](#2-how-to-run-dm-power)
> 3. [Dev](#3-dev)
> 4. [ToDo](#5-todo-and-related-projects)
> 5. [Support](#5-support)
> 6. [Credits](#6-credits)

> * [User Manual](MANUAL.md)

---

### 1. Introduction

### Dungeon Master Power Core Version (DM-Power)

_An efficient heavily featured Dungeon Master toolkit that runs in Command Line Interface (CLI)._

_Uses official Wizards of the Coast (WotC) rules and is free and open source._

My original plan was to create a helpful program for _me_ as a Dungeon Master. I have added in any tools that could save precious minutes of game time. In the improvements and continuation of this project, I strive towards improving and evolving the kit to be as useful to me as possible. 

Faster D&D! More D&D! More Story! Less Worry!

* This tool is best suited for Dungeon Masters and assisting them with keeping the game running quickly. Players may find DM-Power to be of some use as well.

* Homebrew is left up to the individual. I mainly use stuff out of the books I've purchased in DM-Power (unless otherwise noted). Adapting and changing results to your game style should be done at your will.

* This toolkit does not teach the game or say many specifics about what each ability, magic item, or spell does, as that is just not the intention. The design is my interpretation of the WotC book's recommendations and guidelines into code form, at its heart I am building it just for me and adding what I would use and desire as a live DM. To use DM-Power to its largest benefit, you should be decently familiar with the rules and comfortable looking up further details as required. I recommend purchasing the official [WotC books](#6-credits)!

* All dice rolls and generator randomness done with [Mersenne Twister](https://en.wikipedia.org/wiki/Mersenne_Twister), arguably the best randomizer out there.

* Fast and Reliable. No known crash cases. All crash case reports are taken as highly critical.

* Efficient C++ code base. All code is c++11 standard with no additional libraries.

> [back to index](#0-index)

---

### 2. How To Run DM-Power

*Relies on C++ Standard 11 , Boost filesystem, and Make*

* Ubuntu/Mint/Debian Linux. From Bash Command Line -
    1. Install Dependencies

        1. `sudo apt-get update`

        2. `sudo apt-get install build-essential make gcc libboost-all-dev git`

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

> [back to index](#0-index)

---


### 3. Dev

* Feel free to correct stuff and make pull requests, or just let me know by raising an issue ticket thingy. If you don't want to dig into the code, general bug reports help a lot. Donations always help as well, it would be a dream to do something like this as an actual job.

> [back to index](#0-index)

---

### 4. To Do and Related Projects

1. Expand core functionality, fix all bugs, and add more character options (see Github projects tab for more info)

**related side projects**

2. Graphical Interfaced Version
    * Reward Loot tools: [Plunder](https://github.com/mattearly/Plunder)
    * Character Manager: **unreleased** 

> [back to index](#0-index)

---

### 5. Support
* [![donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=PX2EZKRVB4TTC) to keep this project alive. 
* Donations are used to go towards development of  DM-Power-Core-Version. (see Github projects tab for more info)
* total donated so far: $0
    * donaters:

> [back to index](#0-index)

---

### 6. Credits

* Designed for Dungeons & Dragons 5th Edition Official. The core D&D data used in this program is from:
 
 | [Player's Handbook](http://dnd.wizards.com/products/tabletop-games/rpg-products/rpg_playershandbook) | [Dungeon Master's Guide](http://dnd.wizards.com/products/tabletop-games/rpg-products/dungeon-masters-guide) | [Sword Coast Adventurer's Guide](http://dnd.wizards.com/products/tabletop-games/rpg-products/sc-adventurers-guide) |
 | --- | --- | --- |
 | [![phb](img/DnD_PHB.png)](http://dnd.wizards.com/products/tabletop-games/rpg-products/rpg_playershandbook) | [![dmg](img/DnD_DMG.png)](http://dnd.wizards.com/products/tabletop-games/rpg-products/dungeon-masters-guide) | [![scag](img/DnD_SCAG.png)](http://dnd.wizards.com/products/tabletop-games/rpg-products/sc-adventurers-guide) |

 * Coded by [**_Matthew Jay Early_**](https://twitter.com/matthewjayearly).

> [back to index](#0-index)
