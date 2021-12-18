#include "characters.h"

using std::cout;

void Generic_Character_Class::setAnyFeat()
{
  bool set = false;
  cout << "List of Feats to choose from:\n\n";
  while (!set)
  {
    cout << " 1. Alert                25. Mobile\n";
    cout << " 2. Athlete              26. Moderately Armored\n";
    cout << " 3. Actor                27. Mounted Combat\n";
    cout << " 4. Charger              28. Observant\n";
    cout << " 5. Crossbow Expert      29. Polearm Master\n";
    cout << " 6. Defensive Duelist    30. Resilient\n";
    cout << " 7. Dual Wielder         31. Ritual Caster\n";
    cout << " 8. Dungeon Delver       32. Savage Attacker\n";
    cout << " 9. Durable              33. Sentinel\n";
    cout << "10. Elemental Adapt      34. Sharpshooter\n";
    cout << "11. Grappler             35. Shield Master\n";
    cout << "12. Great Weapon Master  36. Skilled\n";
    cout << "13. Healer               37. Skulker\n";
    cout << "14. Heavily Armored      38. Spell Sniper\n";
    cout << "15. Heavy Armor Master   39. Tavern Brawler\n";
    cout << "16. Inspiring Leader     40. Tough\n";
    cout << "17. Keen Mind            41. War Caster\n";
    cout << "18. Lightly Armored      42. Weapon Master\n";
    cout << "19. Linguist             43. Svirfneblin Magic\n";
    cout << "20. Lucky\n";
    cout << "21. Mage Slayer\n";
    cout << "22. Magic Initiate\n";
    cout << "23. Martial Adept\n";
    cout << "24. Medium Armor Master\n\n";
    int ss = getNumber("  Feat Choice:", 1, 43);
    switch (ss) {
      case 1:
        gainAlert(set);
        break;
      case 2:
        gainAthlete(set);
        break;
      case 3:
        gainActor(set);
        break;
      case 4:
        gainCharger(set);
        break;
      case 5:
        gainCrossbow_expert(set);
        break;
      case 6:
        gainDefensive_duelist(set);
        break;
      case 7:
        gainDual_wielder(set);
        break;
      case 8:
        gainDungeon_delver(set);
        break;
      case 9:
        gainDurable(set);
        break;
      case 10:
        gainElemental_adept(set);
        break;
      case 11:
        gainGrappler(set);
        break;
      case 12:
        gainGreat_weapon_master(set);
        break;
      case 13:
        gainHealer(set);
        break;
      case 14:
        gainHeavily_armored(set);
        break;
      case 15:
        gainHeavy_armor_master(set);
        break;
      case 16:
        gainInspiring_leader(set);
        break;
      case 17:
        gainKeen_mind(set);
        break;
      case 18:
        gainLightly_armored(set);
        break;
      case 19:
        gainLinguist(set);
        break;
      case 20:
        gainLucky(set);
        break;
      case 21:
        gainMage_slayer(set);
        break;
      case 22:
        gainMagic_initiate(set);
        break;
      case 23:
        gainMartial_adept(set);
        break;
      case 24:
        gainMedium_armor_master(set);
        break;
      case 25:
        gainMobile(set);
        break;
      case 26:
        gainModerately_armored(set);
        break;
      case 27:
        gainMounted_combatant(set);
        break;
      case 28:
        gainObservant(set);
        break;
      case 29:
        gainPolearm_master(set);
        break;
      case 30:
        gainResilient(set);
        break;
      case 31:
        gainRitual_caster(set);
        break;
      case 32:
        gainSavage_attaker(set);
        break;
      case 33:
        gainSentinel(set);
        break;
      case 34:
        gainSharpshooter(set);
        break;
      case 35:
        gainShield_master(set);
        break;
      case 36:
        gainSkilled(set);
        break;
      case 37:
        gainSkulker(set);
        break;
      case 38:
        gainSpell_sniper(set);
        break;
      case 39:
        gainTavern_brawler(set);
        break;
      case 40:
        gainTough(set);
        break;
      case 41:
        gainWar_caster(set);
        break;
      case 42:
        gainWeapon_master(set);
        break;
      case 43:
        gainSvirfneblin_magic(set);
        break;
      default:
        std::cout << "this... is not possible! check code.\n";
    }
  }
}

void Generic_Character_Class::gainAlert(bool &s)
{
  if (!alert)
  {
    alert = true;
    cout << "Alert feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainAthlete(bool &s)
{
  if (!athlete)
  {
    athlete = true;
    cout << "Athlete feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainActor(bool &s)
{
  if (!actor)
  {
    actor = true;
    cout << "Actor feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainCharger(bool &s)
{
  if (!charger)
  {
    charger = true;
    cout << "Charger feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainCrossbow_expert(bool &s)
{
  if (!crossbow_expert)
  {
    crossbow_expert = true;
    cout << "Crossbow Expert feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainDefensive_duelist(bool &s)
{
  if (!defensive_duelist)
  {
    defensive_duelist = true;
    cout << "Defensive Dualist feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainDual_wielder(bool &s)
{
  if (!dual_wielder)
  {
    dual_wielder = true;
    cout << "Dual Wielder feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainDungeon_delver(bool &s)
{
  if (!dungeon_delver)
  {
    dungeon_delver = true;
    cout << "Dungeon Delver feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainDurable(bool &s)
{
  if (!durable)
  {
    durable = true;
    cout << "Durable feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainElemental_adept(bool &s)
{
  if (!elemental_adept)
  {
    elemental_adept = true;
    cout << "Elemental Adept feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainGrappler(bool &s)
{
  if (!grappler)
  {
    grappler = true;
    cout << "Grappler feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainGreat_weapon_master(bool &s)
{
  if (!great_weapon_master)
  {
    great_weapon_master = true;
    cout << "Great Weapon Master feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainHealer(bool &s)
{
  if (!healer)
  {
    healer = true;
    cout << "Healer feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainHeavily_armored(bool &s)
{
  if (!heavily_armored)
  {
    heavily_armored = true;
    cout << "Heavily Armored feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainHeavy_armor_master(bool &s)
{
  if (!heavy_armor_master)
  {
    heavy_armor_master = true;
    cout << "Heavy Armor Master feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainInspiring_leader(bool &s)
{
  if (!inspiring_leader)
  {
    inspiring_leader = true;
    cout << "Inspiring Leader feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainKeen_mind(bool &s)
{
  if (!keen_mind)
  {
    keen_mind = true;
    cout << "Keen Mind feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainLightly_armored(bool &s)
{
  if (!lightly_armored)
  {
    lightly_armored = true;
    cout << "Lightly Armored feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainLinguist(bool &s)
{
  if (!linguist)
  {
    linguist = true;
    cout << "Linguist feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainLucky(bool &s)
{
  if (!lucky)
  {
    lucky = true;
    cout << "Lucky feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainMage_slayer(bool &s)
{
  if (!mage_slayer)
  {
    mage_slayer = true;
    cout << "Mage Slayer feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainMagic_initiate(bool &s)
{
  if (!magic_initiate)
  {
    magic_initiate = true;
    cout << "Magic Initiate feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainMartial_adept(bool &s)
{
  if (!martial_adept)
  {
    martial_adept = true;
    cout << "Martial Adept feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainMedium_armor_master(bool &s)
{
  if (!medium_armor_master)
  {
    medium_armor_master = true;
    cout << "Medium Armor Master feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainMobile(bool &s)
{
  if (!mobile)
  {
    mobile = true;
    cout << "Mobile feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainModerately_armored(bool &s)
{
  if (!moderately_armored)
  {
    moderately_armored = true;
    cout << "Moderately Armored feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainMounted_combatant(bool &s)
{
  if (!mounted_combatant)
  {
    mounted_combatant = true;
    cout << "Mounted Combatant feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainObservant(bool &s)
{
  if (!observant)
  {
    observant = true;
    cout << "Observant feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainPolearm_master(bool &s)
{
  if (!polearm_master)
  {
    polearm_master = true;
    cout << "Polearm Master feat learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainResilient(bool &s)
{
  if (!resilient)
  {
    resilient = true;
    cout << "Resilient learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainRitual_caster(bool &s)
{
  if (!ritual_caster)
  {
    ritual_caster = true;
    cout << "Ritual Caster learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainSavage_attaker(bool &s)
{
  if (!savage_attacker)
  {
    savage_attacker = true;
    cout << "Savage Attacker learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainSentinel(bool &s)
{
  if (!sentinel)
  {
    sentinel = true;
    cout << "Sentinel learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainSharpshooter(bool &s)
{
  if (!sharpshooter)
  {
    sharpshooter = true;
    cout << "Sharpshooter learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainShield_master(bool &s)
{
  if (!shield_master)
  {
    shield_master = true;
    cout << "Sheild Master learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainSkilled(bool &s)
{
  if (!skilled)
  {
    skilled = true;
    cout << "Skilled learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainSkulker(bool &s)
{
  if (!skulker)
  {
    skulker = true;
    cout << "Skulker learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainSpell_sniper(bool &s)
{
  if (!spell_sniper)
  {
    spell_sniper = true;
    cout << "Spell Sniper learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainTavern_brawler(bool &s)
{
  if (!tavern_brawler)
  {
    tavern_brawler = true;
    cout << "Tavern Brawler learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainTough(bool &s)
{
  if (!tough)
  {
    tough = true;
    cout << "Tough learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainWar_caster(bool &s)
{
  if (!war_caster)
  {
    war_caster = true;
    cout << "War Caster learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainWeapon_master(bool &s)
{
  if (!weapon_master)
  {
    weapon_master = true;
    cout << "Weapon Master learned!\n";
    s = true;
  }
  else
  {
    cout << "Feat already known.\n";
  }
}

void Generic_Character_Class::gainSvirfneblin_magic(bool &s) {
  if (race.find("Svirfneblin") == std::string::npos) {
    std:: cout << "feat only available to Svirfneblin Gnomes! Choose another.\n";
  } else if (!svirfneblin_magic) {
    svirfneblin_magic = true;
    std::cout << "Svirfneblin Magic learned!\n";
    s = true;
  } else {
    cout << "Feat already known.\n";
  }
}