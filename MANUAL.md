### 0. Index

> 1. [Main Menu](#1-main-menu)
> 2. [Character Builder](#2-character-builder)
> 3. [Reward Loot](#3-rewards-and-loot)
> 4. [Other Tools](#4-other-tools)

> * [Readme](README.md)

### 1. Main Menu

<img src="img/cliscreenshot.png" height="160px" align="center">

> [back to index](#0-index)

### 2. Character Builder

 <img src="img/cliscreenshot_characters.png" height="160px" align="center"> 
 
 <img src="img/cliscreenshot_characters2.png" height="160px" align="center">

_Build and Manage Characters_

* **New Character**. Walks though creating a new character and prompts all relevant options.

    * Class logic for levels 1 to 20 programmed in.
    * Fully configured Races, Class Archtype Paths, Class Spell Slots, Feats, Skills, Proficiencies, Backgrounds, and Variant Options. Logically based on WotC Books ([see credits](#10-credits)).
    * Four Starting Stat Point Options:
        1. 4d6 drop lowest
        2. 3d6 legit
        3. Standard array [15, 14, 13, 12, 10, 8]
        4. Custom entry (within standard starting 3-18 bounds(before bonuses applied))
    * Reliable save and load for your campaign's characters. Each campaign can have any number of characters.
    * Users cannot break the character building D&D rules unless... (see edit character below)

* **Edit Character**. 'God' powers. Edit stats (min=1, max=30), give feats, give skills, give levels, change name, change alignment. DM Password entry required to help prevent unauthorized use. Password [hardcoded](src/campaign.cpp) to `password` by default, change it and recompile with `make` if you wish - or remove it all together in some crafty coded fashion. 

* **Limitations**. Character Builder doesn't handle equipment, spell choices, multiclassing, or personality traits. These may be added in later.

<img src="img/cliscreenshot_character.png" height="300px" align="center">

_What the end Character Sheet looks like within your terminal_

> [back to index](#0-index)

---

### 3. Rewards and Loot

<img src="img/cliscreenshot_treasure.png" height="180px" align="center">

* **Scroll and Spellbook Generators**. 
    
    * Spellbook Generator : Tell it how many of for each level (enter 0 to skip spells of that level), and it generates a spellbook full or randomly chosen Wizard spells. Also tells you how many pages are being used in the spellbook. Excellent for NPC wizards or players that like the idea of having random spells.
    * Scroll Generator : You can also grab a single random spell of any level using the Scroll Generator.

* **Loot Rollers**. Individual Loot or Hoard Loot. Try out the Hoard Loot option for some fun. All scrolls that are given are automatically put through the Scroll Generator (no more `level x unspecific scroll`, here you get `Level 9 Scroll of Storm of Vengeance (druid)` for example).

> [back to index](#0-index)

---

### 4. Other Tools

* **Name Generator**. 7732 names from [Kisment's list](http://www.dnd.kismetrose.com/pdfs/KismetsFantasyNames.pdf) with randomized selection. Edit the file [settings/names.dat](settings/names.dat) to add/remove names. The code that handles it automatically adjusts based on the number of lines in the file. Be sure to keep the newline at the end of the file(otherwise the last name on the list will never be chosen).

* **Party Experience Calculator**. Total up Challenge Ratings split it with the party. This prompts for CR's that the party has overcome and then divides by the number of players. Pretty standard calculator stuff.

* **Insult Generator**. **NSFW** - the default words included here are incredibly vulgur and probably aren't suited to all groups. Insult Generator takes two lists from a file and randomly combines nouns and adverbs, easily adapted to new words by editing the settings file [settings/insults.dat](settings/insults.dat) - just note that if you change the number of words in that file, it must be adjusted in the code as well, you'll find the number of words hardcoded in [src/gen_insult.cpp](src/gen_insult.cpp) (to be improved later to be more adaptable and automatic).

* **Random Encounters**. Difficulty Generator that accounts for all party member levels and group size, generates and appropriate Challenge Rating even for the oddest of groups. Seeded from -2 to +2 representing _Very Easy_, _Easy_, _Normal_, _Hard_, _Very Hard_

* **Charts**. There always seems to be at least one player interested in using poison. Madness can be useful in many cases (causing scenarios, things for the PC's to deal with, etc).

    * Poison Prices chart
    * Madness chart
    * Diseases chart

> [back to index](#0-index)

Enjoy the Power!
