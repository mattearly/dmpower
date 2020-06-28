#include "characters.h"
#include "globalfuncts.h"

using std::cout;

void Generic_Character_Class::setBackground()
{
    if (clearScreens)
        simpleClearScreen();
    cout << "Pick a background for your character.\n\n";
    cout << " 1. Acolyte             14. Inheritor\n";
    cout << " 2. Charlatan           15. Knight of the Order\n";
    cout << " 3. City Watch          16. Mercenary Veteran\n";
    cout << " 4. Clan Crafter        17. Noble\n";
    cout << " 5. Cloistered Scholar  18. Outlander\n";
    cout << " 6. Courtier            19. Sage\n";
    cout << " 7. Criminal            20. Sailor\n";
    cout << " 8. Entertainer         21. Soldier\n";
    cout << " 9. Faction Agent       22. Urban Bounty Hunter\n";
    cout << "10. Far Traveler        23. Urchin\n";
    cout << "11. Folk Hero           24. Uthgardt Tribe Member\n";
    cout << "12. Guild Artisan       25. Waterdhavian Noble\n";
    cout << "13. Hermit              26. CUSTOM\n\n";
    int ss = getNumber("Background choice: ", 1, 26);
    backgroundofpc = static_cast<enum characterbackground>(ss);
    switch (ss)
    {
    case 1: //acolyte
        insight = true;
        religion = true;
        setLanguage("First Acolyte bonus language.\n\n");
        setLanguage("Second Acolyte bonus language.\n\n");
        cout << "Acolyte background: \n ->gained Insight, Religion, & 2 Langs.\n";
        break;
    case 2: //charlatan
        deception = true;
        sleight_of_hand = true;
        disguise = true;
        forgery = true;
        cout << "Charlatan background: \n ->gained Deception, Sleight of Hand, Disquise, & Forgery.\n";
        break;
    case 3: //city watch
        athletics = true;
        insight = true;
        setLanguage("First City Watch bonus language.\n\n");
        setLanguage("Second City Watch bonus language.\n\n");
        cout << "City Watch background: \n ->gained Athletics, Insight, & 2 Langs.\n";
        break;
    case 4: //clan crafter
        history = true;
        insight = true;
        setTools(1);
        if (!dwarvish)
            dwarvish = true;
        else
            setLanguage("Clan Crafter bonus language.\n\n");
        cout << "Clan Crafter background: \n ->gained History, Insight, 1 Artisan Tool & 1 Langs.\n";
        break;
    case 5: //cloistered scholar
    {
        history = true;
        cout << "Skill for Cloistered Scholar Background\n\n Pick from\n"
             << " 1. Arcana\n 2. Nature\n 3. Religion\n\n";
        int tmp = getNumber("Choice: ", 1, 3);
        switch (tmp)
        {
        case 1:
            arcana = true;
            break;
        case 2:
            nature = true;
            break;
        case 3:
            religion = true;
            break;
        default:
            break;
        }
        setLanguage("First Cloistered Scholar bonus language.\n\n");
        setLanguage("Second Cloistered Scholar bonus language.\n\n");
        cout << "Cloistered Scholar background: \n ->gained History, Choice Skill, & 2 Langs.\n";
    }
    break;
    case 6: //courtier
        insight = true;
        persuasion = true;
        setLanguage("First Courtier bonus language.\n\n");
        setLanguage("Second Courtier bonus language.\n\n");
        cout << "Courtier background: \n ->gained Insight, Persuasion, & 2 Langs.\n";
        break;
    case 7: //criminal
        deception = true;
        stealth = true;
        thieves = true;
        //gaming kit here
        cout << "Criminal background: \n ->gained Deception, Stealth, Thieve's Tools, & Gaming Tool.\n";
        break;
    case 8: //entertainer
        acrobatics = true;
        performance = true;
        disguise = true;
        setInstrument("Choose an Entertainer's instrument.\n\n", 1);
        cout << "Entertainer background:\n ->Acrobatics, Performance, Disguise Kit, & Musical Instrument.\n";
        break;
    case 9: //faction agent
        insight = true;
        setAnySkill("Faction Agent background bonus skill.\n\n", 1); //should be int,wis,cha skill choice only
        setLanguage("First Faction Agent bonus language.\n\n");
        setLanguage("Second Faction Agent bonus language.\n\n");
        cout << "Faction Agent background: \n ->gained Insight, int/wis/cha skill, & 2 Langs.\n";
        break;
    case 10: //far traveler
        insight = true;
        perception = true;
        //any instrument or gaming set
        setLanguage("Far Traveler background bonus language.\n\n");
        cout << "Acolyte background: \n ->gained Insight, Religion, & 2 Langs.\n";
        break;
    case 11: //folk hero
        animal_handling = true;
        survival = true;
        setTools(1);
        vehicle = true;
        cout << "Folk Hero background:\n ->gained Animal Handling, Survival, Artisan's Tool, & Land Vehicle.\n";

        break;
    case 12: //guild artisan
        insight = true;
        persuasion = true;
        setTools(1);
        setLanguage("Guild Artisan bonus language.\n\n");
        cout << "Guild Artisan background:\n ->gained Insight, Persuasion, Artisan's Tools, & a Language.\n";

        break;
    case 13: //hermit
        medicine = true;
        religion = true;
        herbalism = true;
        setLanguage("Hermit bonus language.\n\n");
        cout << "Hermit background:\n ->gained Medicine, Religion, Herbalism, & a Language.\n";

        break;
    case 14: //inheritor
    {
        survival = true;
        cout << "Pick a Skill for Inheritor Background:\n\n"
             << " 1. Arcana\n 2. History\n 3. Religion\n\n";
        int tmp = getNumber(" Choice: ", 1, 3);
        switch (tmp)
        {
        case 1:
            arcana = true;
            break;
        case 2:
            history = true;
            break;
        case 3:
            religion = true;
            break;
        default:
            break;
        }
        //gain musical instrument or gaming tool
        setLanguage("Inheritor bonus language.\n\n");
        cout << "Inheritor background: \n ->gained Survival, Choice Skill, Musical Instrument or Gaming set, & 1 Lang.\n";
    }
    break;
    case 15: //knight of the order
    {
        persuasion = true;
        cout << "Skill for Knight of the Order Background\n\n Pick from\n"
             << " 1. Arcana\n 2. History\n 3. Nature \n 4. Religion\n\n";
        int tmp = getNumber("Choice: ", 1, 4);
        switch (tmp)
        {
        case 1:
            arcana = true;
            break;
        case 2:
            history = true;
            break;
        case 3:
            nature = true;
            break;
        case 4:
            religion = true;
            break;
        default:
            break;
        }
        //gain musical instrument or gaming tool
        setLanguage("Knight of the Order bonus language.\n\n");
        cout << "Knight of the Order background: \n ->gained Persuasion, Choice Skill, Musical Instrument or Gaming set, & 1 Lang.\n";
    }
    break;
    case 16: //mercenary veteran
        athletics = true;
        persuasion = true;
        //gain gaming or vehicle
        //something else i must be missing
        cout << "Mercenary Veteran background: \n ->gained Athletics, Persuasion, & gaming set or land vehicle";
        break;
    case 17: //noble
        history = true;
        persuasion = true;
        //gaming kit here
        setLanguage("Noble bonus language.\n\n");
        cout << "Noble background:\n ->gained History, Persuasion, Gaming Kit, & a Language.\n";

        break;
    case 18: //outlander
        athletics = true;
        survival = true;
        setInstrument("Outlander instrument.\n\n", 1);
        setLanguage("Outlander bonus language.\n\n");
        cout << "Outlander background:\n ->gained Atheltics, Survival, Musical Instrument, & a Language.\n";

        break;
    case 19: //sage
        arcana = true;
        history = true;
        setLanguage("First Sage bonus language.\n\n");
        setLanguage("Second Sage bonus language.\n\n");
        cout << "Sage background:\n ->gained Arcana, History, & two Languages.\n";

        break;
    case 20: //sailor
        athletics = true;
        perception = true;
        navigator = true;
        vehicle = true;
        cout << "Sailor background:\n ->gained Athletics, Perception, Navigator's Tools, & Water Vehicle.\n";

        break;
    case 21: //soldier
        athletics = true;
        intimidation = true;
        //gaming set here;
        vehicle = true;
        cout << "Soilder background:\n ->gained Athletics, Intimidation, Gaming Set, & Land Vehicle.\n";

        break;
    case 22: //urban bounty hunter
    {
        for (int i = 0; i < 2; i++)
        {
            cout << '\n';
            if (i == 0)
                cout << "First ";
            else
                cout << "Second ";
            cout << "Skill for Urban Bounty Hunter Background\n\n Pick from:\n\n";

            if (deception)
                cout << " 1. Deception(Already Known)\n";
            else
                cout << " 1. Deception\n";
            if (insight)
                cout << " 2. Insight(Already Known)\n";
            else
                cout << " 2. Insight\n";
            if (persuasion)
                cout << " 3. Persuasion(Already Known)\n";
            else
                cout << " 3. Persuasion\n";
            if (stealth)
                cout << " 4. Stealth(Already Known)\n";
            else
                cout << " 4. Stealth\n";

            int tmp = getNumber("\nChoice: ", 1, 4);
            switch (tmp)
            {
            case 1:
                if (!deception)
                    deception = true;
                else
                {
                    cout << "Deception Already Known, Choose Another Skill.\n";
                    i--;
                }
                break;
            case 2:
                if (!insight)
                    insight = true;
                else
                {
                    cout << "Insight Already Known, Choose Another Skill.\n";
                    i--;
                }
                break;
            case 3:
                if (!persuasion)
                    persuasion = true;
                else
                {
                    cout << "Persuasion Already Known, Choose Another Skill.\n";
                    i--;
                }
                break;
            case 4:
                if (!stealth)
                    stealth = true;
                else
                {
                    cout << "Stealth Already Known, Choose Another Skill.\n";
                    i--;
                }
                break;
            default:
                break;
            }
        }
        thieves = true; //thieves tools
        setInstrument("Gain any instrument for the Urban Bounty Hunter background.\n", 1);
        //gain one gaming set
        cout << "Urban Bounty Hunter background: \n ->gained 2 Choice Skills, Choice instrument, gaming set(not programmed in yet), and thieves tools.\n";
    }
    break;
    case 23: //urchin
        sleight_of_hand = true;
        stealth = true;
        disguise = true;
        thieves = true;
        cout << "Urchin background:\n ->gained Sleight of hand, Stealth, Disguise Kit, & Thieves' Tools.\n";

        break;
    case 24: //uthgardt tribe member
        athletics = true;
        survival = true;
        //gain tool or musical instrument
        setLanguage("Uthgardt Tribe Member bonus Language.\n\n");
        cout << "Uthgardt Tribe Member background: \n ->gained Athletics, Survival, Artisan tool or Musical instrument, & 1 Lang.\n";
        break;
    case 25: //waterdhavian noble
        history = true;
        persuasion = true;
        //gain musical or gaming
        setLanguage("Waterdhavain Noble bonus Language.\n\n");
        cout << "Waterdhavian Noble background: \n ->gained History, Persuasion, Musical or Gaming, & 1 Langs.\n";
        break;
    case 26: // CUSTOM
        // show directions/details
        std::cout << "Custom Backgrounds have your choice of 2 skills + 2(skill, lang, or tool)\n";
        {
            // prompt for name of custom background
            std::string tmpName = "";
            std::cout << "Enter the name of your Custom Background\n ->";

            if (!is_random) // if not random, ask user
            {
              getline(std::cin, tmpName);
            }
            else
            {
              tmpName = "Random";
            }

            custom_background_name = tmpName;

            // prompt for 2 skill proficiencies
            setAnySkill("Custom Background Skill: \n", 2);

            // prompt for skill, lang, or tool prof twice
            for (int i = 0; i < 2; ++i)
            {
                int tmp = getNumber("\n 1. Add Skill\n 2. Add Language\n 3. Add Tool Proficiency\n\n  Choice: ", 1, 3);
                switch (tmp)
                {
                case 1:
                    setAnySkill("Custom Background Skill", 1);
                    break;
                case 2:
                    setLanguage("Custom Background Language");
                    break;
                case 3:
                    setTools(1);
                    break;
                default:
                    break;
                }
            }
        }
        // notes:
        //TOOLS:
        // Artisan's Tools
        // Disguise Kit
        // Forgery Kit
        // Gaming Set
        // Herbalism Kit
        // Musical Instrument
        // Navigator's Tools
        // Thieves' Tools
        // Vehicles (Land)
        // Vehicles (Water)

        break;
    default:
        cout << "Error setting background\n\n";
        break;
    }
    // pressEnterToContinue();
}


std::string Generic_Character_Class::getBackground() const
{
  std::string tmp = "";
  switch (backgroundofpc)
  {
  case NOBACKGROUND:
    break;
  case ACOLYTE:
    tmp = "Acolyte";
    break;
  case CHARLATAN:
    tmp = "Charlatan";
    break;
  case CRIMINAL:
    tmp = "Criminal";
    break;
  case ENTERTAINER:
    tmp = "Entertainer";
    break;
  case FOLK_HERO:
    tmp = "Folk Hero";
    break;
  case GUILD_ARTISAN:
    tmp = "Guild Artisan";
    break;
  case HERMIT:
    tmp = "Hermit";
    break;
  case NOBLE:
    tmp = "Noble";
    break;
  case OUTLANDER:
    tmp = "Outlander";
    break;
  case SAGE:
    tmp = "Sage";
    break;
  case SAILOR:
    tmp = "Sailor";
    break;
  case SOLDIER:
    tmp = "Soldier";
    break;
  case URCHIN:
    tmp = "Urchin";
    break;
  case CITY_WATCH:
    tmp = "City Watch";
    break;
  case CLAN_CRAFTER:
    tmp = "Clan Crafter";
    break;
  case CLOISTERED_SCHOLAR:
    tmp = "Cloistered Scholar";
    break;
  case COURTIER:
    tmp = "Courtier";
    break;
  case FACTION_AGENT:
    tmp = "Faction Agent";
    break;
  case FAR_TRAVELER:
    tmp = "Far Traveler";
    break;
  case INHERITOR:
    tmp = "Inheritoir";
    break;
  case KNIGHT_OF_THE_ORDER:
    tmp = "Knight of the Order";
    break;
  case MERCENARY_VETERAN:
    tmp = "Mercenary Veteran";
    break;
  case URBAN_BOUNTY_HUNTER:
    tmp = "Urban Bounty Hunter";
    break;
  case UTHGARDT_TRIBE_MEMBER:
    tmp = "Uthgardt Tribe Member";
    break;
  case WATERDHAVIAN_NOBLE:
    tmp = "Waterdhavain Noble";
    break;
  case CUSTOM:
    tmp = "Custom: " + custom_background_name;
    break;
  default:
    tmp = "Error Displaying Background - Check Code";
    break;
  }
  return tmp;
}
