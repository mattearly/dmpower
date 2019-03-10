### 0. Index

> 1. [BUILD & MANAGE CHARACTERS](#1-build-&-manage-characters)
> 2. [LOOT GENERATION](#2-loot-generation)
> 3. [OTHER TOOLS](#3-other-tools)
> 4. [SETTINGS](#4-settings)

> * [Back to project README](README.md)

### -> MAIN MENU
<img src="img/cliscreenshot.png" height="160px" align="center">

### 1. BUILD & MANAGE CHARACTERS

 <img src="img/cliscreenshot_characters.png" height="200px" align="left"> 
 
 <img src="img/cliscreenshot_characters2.png" height="200px" align="center">

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

<img src="img/cliscreenshot_character.png" height="480px" align="center">

> [back to index](#0-index)

---

### 2. LOOT GENERATION

<img src="img/cliscreenshot_treasure.png" height="200px" align="center">

* **Spellbook Generator** : Tell it how many of for each level (enter 0 to skip spells of that level), and it generates a spellbook full or randomly chosen Wizard spells. Also tells you how many pages are being used in the spellbook. Excellent for NPC wizards or players that like the idea of having random spells.

* **Scroll Generator** : You can also grab a single spell of any level and class randomly using the Scroll Generator.

* **Loot Rollers**. Try out the Hoard Loot option for a treasure cache or to populate a dungeon being built. All scrolls that are given are automatically put through the Scroll Generator (no more `level x unspecific scroll`, here you get `Level 3 Scroll of Fireball (sorcerer, wizard)` for example).

> [back to index](#0-index)

---

### 3. OTHER TOOLS

<img src="img\cliscreenshot_other_tools.png" height="180px" align="center">

* **Name Generator**. 7732 names from [Kisment's list](http://www.dnd.kismetrose.com/pdfs/KismetsFantasyNames.pdf) with randomized selection. Edit the file [data/names.dat](data/names.dat) to add/remove names. The code that handles it automatically adjusts based on the number of lines in the file. Be sure to keep the newline at the end of the file(otherwise the last name on the list will never be chosen).

* **Party Experience Calculator**. Total up Challenge Ratings split it with the party. This prompts for CR's that the party has overcome and then divides by the number of players. Pretty standard calculator stuff.

* **Insult Generator**. Has clean and dirty mode, use depending on your group's style. Defaults to clean. Easily adapted to new words by editing the settings file [data/insults-dirty.dat](data/insults-dirty.dat) or [data/insults-clean.dat](data/insults-clean.dat) - just note that if you change the number of words in that file, it must be adjusted in the code as well, you'll find the number of words hardcoded in [src/gen_insult.cpp](src/gen_insult.cpp) (to be improved later to be more adaptable and automatic).

* **Random Encounters**. Difficulty Generator that accounts for all party member levels and group size, generates and appropriate Challenge Rating even for the oddest of groups. Seeded from -2 to +2 representing _Very Easy_, _Easy_, _Normal_, _Hard_, _Very Hard_

* **Charts**. There always seems to be at least one player interested in using poison. Madness can be useful in many cases (causing scenarios, things for the PC's to deal with, etc).

    * Level Up chart
    * Poison Prices chart
    * Madness chart
    * Diseases chart
    * Player problem resolution flowchart walkthrough (based off of and credits to the creator for the idea [Resolving Basic Behavioral Problems in your Tabletop RPG Group: A Flowchart](https://www.reddit.com/r/rpg/comments/3avp57/resolving_basic_behavioral_problems_in_your/))

> [back to index](#0-index)

### 4. SETTINGS

* Introduced in build 3, a user preferences save area. Currently holds insult mode setting.

Enjoy the Power!
