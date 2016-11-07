```
               __________              ____        ____
              /           \           /    \      /    \
             /            /          /      \    /      \
            /            /          /        \  /        |
           /            /          /                     /
          /            /          /                     /
         /            /          /                     /
        /            /          /                     /
       /            /          /                     /
      /            /          /                     /
     /            /          /                     /
    /           /           /                     /
   /__________/            /                     /
```
#### Support
  
Consider donating something if you found these alogrithm's I've created useful. (or if you just want to help) 
* [PayPal](https://www.paypal.me/mattearly/)  
* Bitcoin: 1Nwi1GBJtsuo1WQJqK83Ckr5NDJ3zwi5mM  

Now, onto stuff about this program.  

####DMPOWER - A tool for 5th edition Dungeons & Dragons  
_The program I've always wanted but could never find._  
The plan is to make a complete program that can keep your D&D game going and going with very little downtime and prep.

### Main Features  
1. **Player Characters.** Build and Manage Characters in minutes.
    * Walk through and answer the prompts to create a full character by the book.  
    * All Classes, Archetype Paths, Races, Feats, Skills, Proficiencies, Backgrounds, and Stats  
        * from the 5e books: Dungeon Master's Guide, Player's Handbook, and Sword Coast Adventurer's Guide.  
    * Level 1-20. Character Editor for leveling up and making changes anytime  
    * Load and Save fully functional for characters.  
2. **Reward Loot.** Magic Item Roller, Scroll and Spellbook Generators. **This program's hidden gem.**  
    * **All** Loot Reward rolling charts from the DMG. Magical items, gems, art, currency.
        * done by the book's logic - any rolled scrolls are automatically ran through the Random Scroll Generator. **save tons of time**
    * Spellbook creator that randomizes wizard spells, just tell it how many of each level and it does the rest. Perfect for when a player asks 'What is in this stolen/looted NPC wizard spellbook?'   
    * Random Scroll generator, just tell it what level scroll and it gives a random spell of that level.
3. **Party Experience Calculator.**  
	* Total up session or encounter experience and split it with the party.  
4. **Name Generator.** 
    * 7732 names from Kismet's list randomized.  
5. **Insult Generator.**  
	* For when you just need to piss off the PC's or antagonize them with a baddie.  

#### How-to compile and run:  

* This runs in terminal. Several options, you decide on what is easiest for you. Mac won't be much different than linux.  

1. Linux  
    * launch Terminal  
    * Clone this repo with ```git clone https://github.com/bytePro17124/DM-Power-Core-Version.git```  
    * ```cd DM-Power-Core-Version``` to enter the main directory  
    * ```make```  to compile the program with gcc  
    * After it compiles, type ```./dmpower``` to run the program.  

2. Windows  
    * Use Cygwin 64 or 32 bit. When installing Cygwin search 'gcc' and then install all, same with 'git' and same with 'make'  (this will take a while to complete the install)
    * Follow same directions as Linux while using Cygwin Terminal

NOTE: There are probably many other ways to compile this. It is basic C++ code that is using C++11 features.
NOTE: This program uses special colored words, which is kinda optional but unfortunantly some terminals don't display these correctly, notably the Visual Studio one.  

#### ToDo
* Work on display clarity and ease of use (ongoing).
* Add more needed tools to keep the game flowing.

#### Problems?

* If you run into a problem or something unclear - please open an issue ticket or email me. The more details the better.
* Anything you would like to see added to this program - open a issue ticket with the enhancement tag or email me.

###### About

* All Code by **_Matthew Jay Early_** 
* This program doesn't replace them or go into details about what abilities, spells, and items do, so you'll be lost without the books.
* Material and Data (other than the names and insult lists) by Wizards of the Coast
* Email me at _matthewjearly@gmail.com_
* Why did I go through the pain of making this? Ever since I started playing D&D many years ago, I began looking for useful programs to go along with the game. There seemed to be a million little half-built tools and websites or many that don't follow the rules enough to be both useful and fair. I wasn't interested in a random person's homebrew ideas, which ruled out 90% of what I found. Since I couldn't find a program that did all this stuff legit from the books, and even Wizard's paid programs are too convoluted to be of use during gameplay, in my opinion, I decided to hack it myself. It also gave me something to work on while not taking classes and a motive to keep programming. So there you go. If you find it useful, let me know. Any feedback is good feedback.

