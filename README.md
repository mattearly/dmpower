DungeonMasterPower is a terminal-based D&D5e toolkit. Its use is intended for Game Masters to aid in game prep and on the fly assistance. This toolkit does not teach the game or say many specifics about what each ability, magic item, or spell does, as that is just not the intention. These details can be found on from D&D Beyond or from the books as referenced in the Credits below. You will need to purchase all the normal stuff from Wizards of the Coast to fully utilize this tool.

<img src="img/character_manager.png" height="360px" align="left"> 
<img src="img/character_sheet.png" height="360px" align="center"> 

[DMPOWER BUILD 6 VIDEO](https://youtu.be/9VJpPyqnssY)

### Run on Linux

- Open terminal, clone master or download release, then build and run.

````
git clone https://github.com/mattearly/DungeonMasterPower.git
cd DungeonMasterPower/
make run
````

- `make run` builds and runs the program right away. There are other make options. Try `make help` to see other options.
- go install dependencies if something fails in the build, then try again. If you are using debian, the packages you will need are:

````
make gcc libboost-filesystem-dev
````

- run once built

````
./dmpower
````

### Run on Windows

Use [Cygwin](https://www.cygwin.com/), or [WSL](https://msdn.microsoft.com/commandline/wsl/about), or mingw, or Powershell. Pretty much anything you can get the dependencies on it will work with.

- If you are using Cygwin, you will need the packages `gcc-core`, `make`, `libboost-devel`, and of course `git` for the git clone command, then it should work just like the linux build and run above.
- In case of using the Powershell terminal, you will need to activate the ansi color escape with this command:
  - `Set-ItemProperty HKCU:\Console VirtualTerminalLevel -Type DWORD 1`
  - [more discussion on this topic](https://stackoverflow.com/questions/51680709/colored-text-output-in-powershell-console-using-ansi-vt100-codes)
- I have not tested with Visual Studio. Should work but may need some modifications or project setup.

### Run on Mac

I haven't tested but it should work fine, may need homebrew for boost libraries.

# Foundation / Why this program?

I decided to start making this tool on my own accord when I, as a GM, couldn't find any D&D software that I liked. This was sometime around late 2015 while I was in college studying Computer Science and on occasion playing D&D with a few friends. I had a long background of being a GM so I knew pretty well what I needed in a tool and I needed a project to work on outside of class, and C++ was what I was learning at the time. At first I was just seeing what I could do, but eventually it grew to be usable and I've been tweaking and expanding it ever since.

Going forward, I choose not to steer away from C++ because I found it to be fast, responsive, and reliable. You can run this tool reliably on the oldest of machines and it should still seem fast.

So, how can you say no to making a NPC/PC character in about 1-2 minutes? You can go straight to the important part: story, gear, and what makes your character unique. This process sure beats the usual 1-2hr character building sessions we all have experienced... sometimes painfully experienced. Having all your options available without having to dig through books saves a lot of time. If you are a wizard you can even get a randomized Spellbook if that's your thing.

Speaking of Spellbooks, have you ever found a Spellbook in game? How much time did that take? I would guess more than a couple minutes. I've experienced this pain and seen other GM's go through it many times. I built and included a tool to help GM's handle this time-sink.

I have also found that adding content to a dungeon or lair is a creative process that can take a long time. I'm working on tools to help with that as well, some of them are still in progress. One thing that really helps is to roll up the treasure ahead of time with the reward generator, and then have the creatures have pieces that makes sense, and place/hide the rest accordingly. I found that works quite well and the continuity feels better.

I still play D&D on occasion, and when I do, I use this tool and take notes on how to improve it. It would be great if you could leave any notes that you think would make the program better as well. I'll try to keep this moving forward when I have time to work on it.

So here I am now, still working on this piece of software, showing it to the world now even though it was originally just intended for my personal use.

# Support

Share this project with a friend and/or give it a star to support this project.

# Dev Road Map

Varies. This is not a funded project, so it depends on how busy I am with real life and how much D&D I'm playing. I tend to update this based on what 'I' need and based on requests. If there is something you would like to see added, feel free to let me know or create an issue, or add it yourself and make a pull request if you think it should be in the main version.

# Contributing

See the [CONTRIBUTING](CONTRIBUTING.md) file for more information on how you can help with the code, and of course, feel free to correct or report any typos or issues you find.

# Credits

The list of abilites and items are from D&D books. Nothing has been added from the pending ones yet.

* [Player's Handbook](http://dnd.wizards.com/products/tabletop-games/rpg-products/rpg_playershandbook)
* [Dungeon Master's Guide](http://dnd.wizards.com/products/tabletop-games/rpg-products/dungeon-masters-guide)
* [Sword Coast Adventurer's Guide](http://dnd.wizards.com/products/tabletop-games/rpg-products/sc-adventurers-guide)
* [Volo's Guide to Monsters](http://dnd.wizards.com/products/tabletop-games/rpg-products/volos-guide-to-monsters)
* [Wayfinder's Guide to Eberron](https://www.dmsguild.com/product/247882/wayfinders-guide-to-eberron-5e)
* pending ~~[Xanathar's Guide to Everything]()~~
* pending ~~[Guildmaster's Guide to Ravnica]()~~
* [The Tortle Package](https://www.dmsguild.com/product/221716/Tortle-Package-5e)
* pending ~~[Mordenkain's Tome of Foes]()~~
* [Elemental Guide of Evil](https://www.dmsguild.com/product/145542/Elemental-Evil-Players-Companion-5e)

Trying to keep DungeonMasterPower based on offical stuff so that this program will be helpful for everyone. However there are some additional sources used.

* [Kismet's Name List](http://www.dnd.kismetrose.com/MyCharacterNameList.html)
* [Resolving Basic Behavioral Problems in your Tabletop RPG Group: A Flowchart](https://www.reddit.com/r/rpg/comments/3avp57/resolving_basic_behavioral_problems_in_your/)

# Legal
DungeonMasterPower is not affiliated with, endorsed, sponsored, or specifically approved by Wizards of the Coast LLC. Dungeons & Dragons® is a trademark of Wizards of the Coast. For more information about Wizards of the Coast or any of Wizards' trademarks or other intellectual property, please visit their website at dnd.wizards.com.

# Some Additional Screenshots

<img src="img/main_menu.png" height="360px" align="left"> 
<img src="img/new_character.png" height="360px" align="center"> 

<img src="img/race_select.png" height="360px" align="left"> 
<img src="img/treasure_hoard.png" height="360px" align="center"> 

<img src="img/spellbook_gen.png" height="360px" align="left"> 
<img src="img/random_spellbook.png" height="360px" align="center"> 

### 0. Index

> 1. [BUILD & MANAGE CHARACTERS](#1-build-&-manage-characters)
> 2. [LOOT GENERATION](#2-loot-generation)
> 3. [OTHER TOOLS](#3-other-tools)
> 4. [SETTINGS](#4-settings)

### 1. BUILD & MANAGE CHARACTERS

* **New Character**. Walks though creating a new character and prompts all relevant options.

    * Class logic for levels 1 to 20 programmed in.
    * Fully configured Races, Class Archtype Paths, Class Spell Slots, Feats, Skills, Proficiencies, Backgrounds, and Variant Options. Logically based on WotC Books ([see credits](#10-credits)).
    * Four Starting Stat Point Options:
        1. 4d6 drop lowest
        2. 3d6 legit
        3. Standard array [15, 14, 13, 12, 10, 8]
        4. Custom entry (within standard starting 3-18 bounds(before bonuses applied))
    * Characters Save by Unique Name
    * Random Name Suggestions Available from Kismet's list (see name generator below).
    * Reliable save and load for your campaign's characters. Each campaign can have any number of characters. You can merge your saved files together as explained at the load prompt.
    * Users cannot break the character building D&D rules unless... (see edit character below)

* **Edit Character**. DM God Powers. Edit stats (min=1, max=30), give feats, give skills, give levels, change name, change alignment.  

* **Limitations**. Character Builder doesn't handle equipment, spell choices, multiclassing, or personality traits. These may be added in later.

_What the end Character Sheet looks like within your terminal_

> [back to index](#0-index)

---

### 2. LOOT GENERATION

* **Spellbook Generator** : Tell it how many of for each level (enter 0 to skip spells of that level), and it generates a spellbook full or randomly chosen Wizard spells. Also tells you how many pages are being used in the spellbook. Excellent for NPC wizards or players that like the idea of having random spells.

* **Scroll Generator** : You can also grab a single spell of any level and class randomly using the Scroll Generator.

* **Loot Rollers**. Try out the Hoard Loot option for a treasure cache or to populate a dungeon being built. All scrolls that are given are automatically put through the Scroll Generator (no more `level x unspecific scroll`, here you get `Level 3 Scroll of Fireball (sorcerer, wizard)` for example).

---

### 3. OTHER TOOLS

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

> [back to index](#0-index)

### 4. SETTINGS

* Introduced in build 3, a user preferences save area. Currently holds insult mode setting.
