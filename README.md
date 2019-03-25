# Dungeon Master Power

Dungeon Master Power (dmpower) is a minimalistic interactive terminal-based Dungeons & Dragons's 5th Edition Toolkit. See the [MANUAL](MANUAL.md) for screenshots and information about the ever-evolving toolset.

- [Download Latest Release](https://github.com/mattearly/DungeonMasterPower/releases)

- If you want to see current new developments, check for a `buildXdev` branch. Stick with a release if you need stability. 

---

## 1. How To Build & Run

*Relies on C++ Standard 11, Boost filesystem, and Make*

*Built on Linux and will probably run best on Linux right now. Runs fine on Cygwin and WSL for Windows*

**Linux**

- open terminal
- `clone` repo (or download release and unzip)
- `cd` into directory
- `make run` (go install dependencies if something fails in the build, then try again)
  - if you are using debian, packages you will need: `make` and `gcc` and `libboost-filesystem-dev`
  -     apt-get install make gcc libboost-filesystem-dev
- run command after it is built is `./dmpower` or you can just use `make run` again, which could be handy if you are making changes to the code.

**Windows**
- use [Cygwin](https://www.cygwin.com/)
- or [WSL](https://msdn.microsoft.com/commandline/wsl/about)
- should also work with mingw compilation
- In case of using the Powershell terminal, you will need to activate the ansi color escape with this command:
  - `Set-ItemProperty HKCU:\Console VirtualTerminalLevel -Type DWORD 1`
  - [more discussion on this topic](https://stackoverflow.com/questions/51680709/colored-text-output-in-powershell-console-using-ansi-vt100-codes)
- I have not tested with Visual Studio. Should work but may need some modifications or project setup.

**Mac**
- untested, should work fine, may need homebrew for boost libraries.

---

## 2. Support

- [![donate/PayPal](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.me/mattearly) Any donations will go towards finding and funding time to continue work on this project. The more support I can get the faster it can advance and come together. This will include improvement, more additions, and more attention to this piece of software.
 
---

## 3. Credits

The core D&D data used in this program is from:

 | [Player's Handbook](http://dnd.wizards.com/products/tabletop-games/rpg-products/rpg_playershandbook) | [Dungeon Master's Guide](http://dnd.wizards.com/products/tabletop-games/rpg-products/dungeon-masters-guide) | [Sword Coast Adventurer's Guide](http://dnd.wizards.com/products/tabletop-games/rpg-products/sc-adventurers-guide) | [Volo's guide to monsters](http://dnd.wizards.com/products/tabletop-games/rpg-products/volos-guide-to-monsters) |
 | --- | --- | --- | --- |
 | [![phb](img/DnD_PHB.png)](http://dnd.wizards.com/products/tabletop-games/rpg-products/rpg_playershandbook) | [![dmg](img/DnD_DMG.png)](http://dnd.wizards.com/products/tabletop-games/rpg-products/dungeon-masters-guide) | [![scag](img/DnD_SCAG.png)](http://dnd.wizards.com/products/tabletop-games/rpg-products/sc-adventurers-guide) | [![vgtm](img/DnD_VGTM.png)](http://dnd.wizards.com/products/tabletop-games/rpg-products/volos-guide-to-monsters) |

- Programmers as accredited in the commit history and contributers file - mostly me but its always nice to have help and I will accept some modifications on a case by case basis if they align with the overall goal of dmpower. See the [CONTRIBUTING](CONTRIBUTING.md) file for more information on how to help with the code.

## 4. Additional Notes

- dmpower uses terminal text coloring that will probably look best in a terminal with a dark background.
- This tool is best suited for Dungeon Masters, however the character creator could be helpful for anyone.
- No known crash cases. All crash case reports are taken as highly critical and will be fixed asap.
- If you run into any cases where the program can't continue, please report with steps if possible. It is possible there are some cases where you need to pick a skill but everything you are allowed to take is already learned and you can't continue (hasn't happend to my knowledge yet, but I'm on the lookout)
- This toolkit does not teach the game or say many specifics about what each ability, magic item, or spell does, as that is just not the intention. These details can be found on the plethora of reference data sites and apps related to D&D 5e, as well as in the official books. I recommend purchasing official [WotC books](#3-credits).

## 5. Foundation / Why this program?

A quick story. I decided to start making this tool on my own accord when I, as a DM, couldn't find any D&D software that I liked. This was sometime around late 2015 while I was in college studying CompSci and on occasion playing D&D with a few friends. I had a long background of being a DM so I new pretty well what I needed in a tool and I needed a project to work on outside of class, and C++ was what I was learning at the time (so that's why this is all C++ and not something easier). At first I was just seeing what I could do, but eventually it grew to be usable, and everyone wanted to make their characters with it, which was cool and motivated me to keep going. Also, I just love the treasure rolling tools, they're so great for planning.

How can you say no to making your D&D character in 20 seconds flat? Sure beats the usual 1-2hr character building sessions we all have experienced... sometimes painfully experienced. With this you get your stats all set right off. You can go straight to the important part: your story and your gear. If you are a wizard you can even get a randomized spellbook from dmpower if that's your thing. 

And oh my... have you ever found a Spellbook in game? How much time did that take? With this program it takes about 30 seconds and that still blows my mind. The amount of time I've lost in the past trying to figure out "what spells."

So here I am now, still working on this piece of software. I am not trying to compete with any other software, nor do I really pay attention, but dndbeyond appears to be my main competition at this point. I tried it once and was like...welp back to dmpower cause this site is slow as sh!t. 
