### 0. Index

> 1. [Character Builder](#1-character-builder)
> 2. [Reward Loot](#2-reward-and-loot)
> 3. [Kismet's Random Name](#3-kismets-random-name)
> 4. [Other Tools](#4-other-tools)

> * [Readme](README.md)

### 1. Main Menu

<img src="img/cliscreenshot.png" height="160px" align="center">

### 2. Character Builder

_Build and Manage Characters_

<img src="img/cliscreenshot_characters.png" height="160px" align="center">

* **New Character**. Walks though creating a new character and prompts all relevant options.

* **Levels**. All classes levels 1 to 20 supported. No multiclassing.

* **Rules and Flow**. Fully configured official Classes, Races, Class Archtype Paths, Spell Slots, Feats, Skills, Proficiencies, Backgrounds, and Variant Options selection systems. Logically based on WotC Books ([see credits](#10-credits)).

<img src="img/cliscreenshot_characters2.png" height="160px" align="center">

* **Save**. Reliable save and load for your campaign's characters.

* **Unbreakable Standard 5e Rules**. Users cannot break the character building D&D rules unless... (see edit character below)

* **Edit Character**. 'God' powers. Edit stats (min=1, max=30), give feats, give skills, give levels, change name, change alignment. DM Password entry required. Password [hardcoded](src/campaign.cpp) to `password` by default, change it and recompile with `make` if you wish - or remove it all together in some crafty coded fashion. 

* **Versatile Starting Stat Point Options**.

    * **option 1**: 4d6 drop lowest
    * **option 2**: 3d6 legit
    * **option 3**: standard set (15, 14, 13, 12, 10, 8)
    * **option 4**: custom entry (within standard starting 3-18 bounds(before bonuses applied))

* **Limitations**. Doesn't handle equipment or spell choices or personality traits. I generally jot these down near the character name on my campaign notes. 

**Character Sheet**.

<img src="img/cliscreenshot_character.png" height="320px" align="center">


> [back to index](#0-index)

---

### 4. Rewards and Loot

<img src="img/cliscreenshot_treasure.png" height="180px" align="center">

_Magic Item / Reward Roller (by the DM Guide)_

* **Scroll and Spellbook Generators**. I dunno about you, but when a PC gets ahold of a NPC's spellbook, there goes 10+ minutes of game time working up the spells in it. Or just use this and it takes 30 seconds. Spells in this Spellbook Generator are chosen randomly to assist with DM's time management. You can also grab a single random spell of any level using the Scroll Generator.

* **Loot Rollers**. Try out the Hoard Loot option for some fun. All scrolls are randomized (no more `level x unspecific scroll` (goodbye game time while the DM figures out what spell it is or should be), here you get `Level 9 Scroll of Storm of Vengeance (druid)` for example.
    * This tool is very powerful - use it wisely.

> [back to index](#0-index)

---

### 5. Random Name Generator

* **Name Generator**. Default 7,732 names from Kismet's list randomized with Mersenne Twister. Use the name, use something close that is more fitting to the scenario, or just roll a new random name to inspire new name ideas. I find this very helpful when DMing and no longer mind when players constantly keep asking the names of every single (seemingly inconsequential) NPC. A good name can mean a lot for immersion.
    * related file: [settings/names.dat](settings/names.dat)
        * you may edit this file to add/remove/customize to your own names. The code that handles it automatically adjusts based on the number of lines in the file. Be sure to keep the newline at the end of the file(otherwise the last name on the list will never be chosen).

> [back to index](#0-index)

---

### 6. Other Tools

* **Party Experience Calculator**. Total up session or encounter experience and split it with the party. This prompts for Challenge Ratings that the party has overcame and then divides by the number of players.

* **Insult Generator**. **NSFW**. For when you just need to anger the PC's or antagonize them with a baddie. I just threw this in for fun. It takes two lists from a file and randomly combines words, easily adapted to new words by editing the settings file [insults.dat](settings/insults.dat) - just note that if you change the number of words in that file, it must be adjusted in the code as well, you'll find the number of words hardcoded in [gen_insult.cpp](src/gen_insult.cpp) (to be improved later to be more adaptable and automatic).

* **Random Encounters**. Difficulty Generator that accounts for

    * party member levels (can be of any variety of legal levels)
    * your group size (max 10 members)

        and provides a Challenge Rating ranging from very easy to very hard. Go ahead, give it 10 level 1 characters and see what kind of CR it recommends.

        I plan on improving this tool to include prompting for terrain and offering some monster encounter setups, looking for some official charts and setups from one or several of the books to go off of.

* **Charts**. Just kinda threw these in, and end up using the Poison chart frequently. There always seems to be at least one player interested in using poison.

    * Poison Prices chart
    * Madness chart
    * Diseases chart

> [back to index](#0-index)

---