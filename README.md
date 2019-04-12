# About

[Dungeon Master Power](https://github.com/mattearly/DungeonMasterPower/releases) is a powerful minimalistic interactive terminal-based Dungeons & Dragons's 5th Edition Toolkit. The intention is to make being the Dungeon Master less tedious and time consuming so you can focus more on your game's story, and less on looking up charts and stat blocks. See the [MANUAL](MANUAL.md) for screenshots and information about the ever-evolving toolset.

# Getting Started

Dungeon Master Power runs in a terminal on any operating system and uses text coloring that will look best in a terminal with a solid dark background.

## Prerequisites

C++ Standard 11, Boost filesystem, and Make

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

# Additional Notes

- This tool is best suited for Dungeon Masters and doing stat blocks for characters, treasures, & the like; ideally saving you tons of time and making your planning much much faster so you and you're players can focus more on the story.
- This toolkit does not teach the game or say many specifics about what each ability, magic item, or spell does, as that is just not the intention. These details can be found on the plethora of reference data sites and apps related to D&D 5e, as well as in the official books.
- I tend to update this based on what 'I' need and based on requests. If there is something you would like to see added, feel free to let me know.

# Foundation / Why this program?

A quick story. I decided to start making this tool on my own accord when I, as a DM, couldn't find any D&D software that I liked. This was sometime around late 2015 while I was in college studying Comp Sci and on occasion playing D&D with a few friends. I had a long background of being a DM so I new pretty well what I needed in a tool and I needed a project to work on outside of class, and C++ was what I was learning at the time. At first I was just seeing what I could do, but eventually it grew to be usable and I've been tweaking and expanding it ever since. 

I choose not to steer away from C++ because I like this being fast, responsive, and reliable. C++ allows me to be as meticulous as I prefer (yeah I see all your slow crashing web sites trying to do this stuff). You can run this tool reliably on the oldest of machines and it should still seem fast.

So, how can you say no to making a NPC/PC character in about 1-2 minutes? Sure beats the usual 1-2hr character building sessions we all have experienced... sometimes painfully experienced. With this you get your stats all set without having to dig through books for potential options. You can go straight to the important part: story, gear, and what makes your character unique. If you are a wizard you can even get a randomized Spellbook from dmpower if that's your thing. 

And oh my... speaking of spellbooks, have you ever found a Spellbook in game? How much time did that take? With this program it can be done quickly, reliably and randomly. The amount of time I've lost in the past trying to figure out "what spells..." Never again. 

Can we talk about putting treasure in a dungeon? Say you are populating a dungeon - Try rolling Lair Treasure and pepper it in, add pieces to your monsters, or whatever you like. I found that works quite well.

I still play D&D on occasion, and when I do, I use this tool. It makes the experience so much less stressful and (down)time consuming. So here I am now, still working on this piece of software, showing it to the world now even though it was originally just intended for my personal use.

# Dev Road Map

#### future outline, ETA dates may be pushed back based on how busy I am with real life work and such

- **build7** - focus on code cleanup, refactoring, and documenting the code base to make updating easier in the future. There is a lot to refactor, I have some big redo's in mind! May add in more feats (currently only has Player's Handbook feats) and a few other various smaller things. May add in basic starting gear for stat blocks. *ETA mid-May 2019*
- **build8** - focus on adding a proper Encouner Generator based on terrain, location, and party level. And add a Dungeon Generator (its been a long time coming). *ETA mid-June 2019*
- **build9** - ??? probably fixing bugs and adding stuff I notice while working on build7 and build8. *ETA mid-July 2019*

See release tab for release history. There was also several years of no releases and me just iterating/figuring it out, so this doing release thing is kind of new to dmpower.

# Support

Support this project by giving it a Star or sharing with a friend. After sharing this work with the community and finding out I could get in trouble by allowing anyone kind of financial support, I've taken down the donation link that was to help me fund time and wasn't in any way for the content. Its k, I got $0.00 of donations in the multiple years of it being up, this has never been any sort of monetary gain nor was it expected.

# Credits

Go support WotC and buy their stuff!

The lists and logic D&D data used in this program (so far) are from:

* [Player's Handbook](http://dnd.wizards.com/products/tabletop-games/rpg-products/rpg_playershandbook)
* [Dungeon Master's Guide](http://dnd.wizards.com/products/tabletop-games/rpg-products/dungeon-masters-guide)
* [Sword Coast Adventurer's Guide](http://dnd.wizards.com/products/tabletop-games/rpg-products/sc-adventurers-guide)
* [Volo's Guide to Monsters](http://dnd.wizards.com/products/tabletop-games/rpg-products/volos-guide-to-monsters)
* [Wayfinder's Guide to Eberron](https://www.dmsguild.com/product/247882/wayfinders-guide-to-eberron-5e)
* pending [Xanathar's Guide to Everything]()
* pending [Guildmaster's Guide to Ravnica]()
* [The Tortle Package](https://www.dmsguild.com/product/221716/Tortle-Package-5e)
* pending [Mordenkain's Tome of Foes]()
* [Elemental Guide of Evil](https://www.dmsguild.com/product/145542/Elemental-Evil-Players-Companion-5e)

Trying to keep it based on offical stuff so that this program will be helpful for everyone. However there are some additional sources used.

* [Kismet's Name List](http://www.dnd.kismetrose.com/MyCharacterNameList.html)
* [Resolving Basic Behavioral Problems in your Tabletop RPG Group: A Flowchart](https://www.reddit.com/r/rpg/comments/3avp57/resolving_basic_behavioral_problems_in_your/)

Programmers as accredited in the commit history and contributers file - mostly me but its always nice to have help and I will accept some modifications on a case by case basis if they align with the overall goal of dmpower. See the [CONTRIBUTING](CONTRIBUTING.md) file for more information on how you can help with the code, and of course, feel free to correct or report any typos or issues you find.

DungeonMasterPower is not affiliated with, endorsed, sponsored, or specifically approved by Wizards of the Coast LLC. Dungeons & Dragons® is a trademark of Wizards of the Coast. For more information about Wizards of the Coast or any of Wizards' trademarks or other intellectual property, please visit their website at dnd.wizards.com.
