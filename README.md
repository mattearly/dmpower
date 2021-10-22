# dmpower

A Dungeons & Dragons 5th edition command line toolkit.

Screenshots: [screenshots imgur link](https://imgur.com/a/S3t73rI)
*Screenshots taken on Windows Cygwin64 with green default text and black background. Your experience will vary depending on your terminal settings.*

Its primary use is to hasten game prep and on the fly assistance.  
dmpower runs in a terminal window and prompts all available options.  
See the books listed near the bottom for what books have been integrated into this tool.
Please note: This is a just a personal side project thing I did for fun/practice/my own use. There is no funding or support and as such you should not expect anything.

## Core Feature

### 5th Edition Character builder and Manager (PCs or NPCs)

For Players or Dungeon Masters:
- Main 12 D&D Character Classes. 
- 22 different races including core subraces. 
- Fully programmed level 1-20 class trees and level up system.
- Common starter stats options (3d6, 4d6 drop lowest, point buy). 
- Backgrounds + Custom Background Option (4 things of your choice with a custom background name)
- Feats
- Skills
- Languages
- Standard HP Averaging (mostly as an fyi) (pcs start with max first level HP in most common rule)
- Spell Slots Auto Calculated by level/class/race features
- Save/Load with plain text (integrated into user folders on your OS).
- Export with plain text (saves to documents folder on your OS).

For Dungeon Masters:
- Character Editor with override options: Edit stats (min=1, max=30), give feats, give skills, change name, change alignment.
- Randomized character option.

Limitations:
- Currently, the Character Builder doesn't handle equipment, spell memorization choices, multiclassing, or personality traits. NPC classes (warrior, expert, aristocrat) from the DMG are also not included.

## Other Features

### Loot and Randomizers

- Randomized Loot (based on the charts in the DM Guide). Hoard loot is pretty fun to role, and great for populating lairs/dungeons/poi's.
- Spellbook Generator to assist with the DM's nightmare that is populating an NPC Wizard Spellbook.
- Scrolls auto-generate to spells.

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

#### Dependencies

- C++17

#### Stored Data and Saves

##### Windows

Exports go to `%USERPROFILE%/Documents/DMpowerExports/`.  Saves and settings go to `%USERPROFILE%/AppData/Local/dmpower`
 
##### Linux

Exports go to `%USERPROFILE%/DMpowerExports/`.  Saves and settings go to `%USERPROFILE%/.dmpower`

##### MAC

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

This project and I are not affiliated with Wizards of the Coast or Hasbro. This project was something I personally made to assist with my own personal dming needs. Due to the nature of the game data being used for this software, dmpower is not to be used for any form of profit or sale and no support is provided.

### Development

In development branch named buildXX.

Master branch has latest release.

New versions are tagged with release notes when pushed to master, see the [tags/releases](https://github.com/mattearly/dmpower/releases) for all versions with release notes.

## Special Thanks

For those getting involved in the project and helping out at times! It does mean a lot. Thanks. -Matt
