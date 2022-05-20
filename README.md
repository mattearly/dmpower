# DMPOWER
A Dungeons & Dragons 5th edition toolkit intended for Dungeon Masters.  

Its primary use is to hasten game prep and on the fly assistance.  
dmpower runs in a terminal window and prompts all available options.  
See the books listed near the bottom for what books have been integrated into this tool.
Please note: This is a just a personal side project thing I did for fun/practice/my own use. There is no funding or support and as such you should not expect anything.

## Main Features

### 5th Edition Characters Creator and Maintainer

- Levels One to Twenty class trees for all twelve core Character Classes
- Twenty-two different class races.
- All core skills, feats, variants, langauges, spell slots.
- All core background choices or use custom background option.
- Starter stat rolling options:
  - custom entry 
  - standard point buy
  - normal 3d6
  - high powered 4d6 drop lowest
- Save/Load sets of characters (Campaigns).
- Level Up and Editor Tools.
- Random character gen.

_Example created high powered level 6 Human Warlock_

<img src="docs\Level 6 High Powered Warlock Screenshot 2021-11-30.png" align="center">

_[more screenshots](https://imgur.com/a/S3t73rI)_

#### Limitations

- Character Manager **does not** handle: 
  - Equipment
  - Spell memorization choices
  - Multiclassing
  - Personality traits

## Other Tools Within DMPOWER

### Loot Rollers

- Randomized Loot Tool. 
- Spellbook Generator.
- Scroll Spell Names.

### More Various Tools

- Random Name Generator. Names from [Kisment's list](http://www.dnd.kismetrose.com/pdfs/KismetsFantasyNames.pdf). Custom Editable [config file](data/lists/lists/names.dat).
- XP Calculator.
- Insult Generator. Has clean and dirty mode. Easily adapted to new words by editing the settings file [data/lists/insults-dirty.dat](data/lists/insults-dirty.dat) or [data/lists/insults-clean.dat](data/lists/insults-clean.dat) - just note that if you change the number of words in that file, it must be adjusted in the code as well, you'll find the number of words hardcoded in [src/gen_insult.cpp](src/gen_insult.cpp) (to be improved later to be more adaptable and automatic for varying sizes like the name generator already does).
- Random Encounters. Difficulty Generator that accounts for all party member levels and group size, generates an appropriate Challenge Rating even for the oddest of groups. Seeded from -2 to +2 representing _Very Easy_, _Easy_, _Normal_, _Hard_, _Very Hard_. I'm not sure that this is all that useful yet, I would like to add in mob group generators based on location.
- Charts. There always seems to be at least one player interested in using poison. Madness can be useful in many cases (causing scenarios, things for the PC's to deal with, etc).
  - Level Up chart
  - Poison Prices chart
  - Madness chart
  - Diseases chart
  - Player problem resolution flowchart walkthrough (based off of and credits to the creator for the idea [Resolving Basic Behavioral Problems in your Tabletop RPG Group: A Flowchart](https://www.reddit.com/r/rpg/comments/3avp57/resolving_basic_behavioral_problems_in_your/)

## Building dmpower

- Use CMake to generate for the toolchain of your preference

- example:
```bash
git clone https://github.com/mattearly/dmpower.git
cd dmpower
cmake -B build -S .
cd build
make
./dmpower
```

### Dependencies

- C++17

### Data

#### Windows

Exports go to `%USERPROFILE%/Documents/DMpowerExports/`.  Saves and settings go to `%USERPROFILE%/AppData/Local/dmpower`
 
#### Linux

Exports go to `%USERPROFILE%/DMpowerExports/`.  Saves and settings go to `%USERPROFILE%/.dmpower`

#### MAC

Haven't set up, should be similar to linux.

## Sources

### Books Currently Integrated  

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

This project and I are not affiliated with Wizards of the Coast or Hasbro. This project was something I personally made to assist with my DMing. Due to the nature of the game data being used for this software, DMPOWER is not to be used for any form of profit or sale.

### Development

Generally, I develop this when I feel like it (usually after dming and realizing I want to add more). :P

*No longer maintained - the continuation of this project is dmpower2, which can be found [here](https://github.com/mattearly/dmpower2)*

## Special Thanks

For those getting involved in the project and helping out at times with features and improvements!
