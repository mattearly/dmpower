#pragma once

#include "characters.h"
#include <string>

class Generic_Character_Class;

class Races
{
public:
  //accessor
  virtual ~Races() {}
  virtual void setRaceDetails(Generic_Character_Class &v) = 0;
  virtual std::string getRaceString() const = 0;
};

class Aasimar : public Races
{
public:
  enum aasimartype
  {
    NA,
    PROTECTOR,
    SCOURGE,
    FALLEN
  } subr;
  virtual void setRaceDetails(Generic_Character_Class &v);
  virtual std::string getRaceString() const;
};

class Dragonborn : public Races
{
public:
  virtual void setRaceDetails(Generic_Character_Class &v);
  virtual std::string getRaceString() const;
};

class Dwarf : public Races
{
public:
  enum dwarftype
  {
    NA,
    DUERGAR,
    HILL,
    MOUNTAIN
  };
  dwarftype subr;
  virtual void setRaceDetails(Generic_Character_Class &v);
  virtual std::string getRaceString() const;
};

class Elf : public Races
{
public:
  enum elftype
  {
    NA,
    HIGH,
    WOOD,
    DROW
  };
  elftype subr;
  virtual void setRaceDetails(Generic_Character_Class &v);
  virtual std::string getRaceString() const;
};

class Firbolg : public Races
{
public:
  virtual void setRaceDetails(Generic_Character_Class &v);
  virtual std::string getRaceString() const;
};

class Gnome : public Races
{
public:
  enum gnometype
  {
    NA,
    FOREST,
    ROCK,
    SVIRFNEBLIN
  };
  gnometype subr;
  virtual void setRaceDetails(Generic_Character_Class &v);
  virtual std::string getRaceString() const;
};

class Goliath : public Races
{
public:
  virtual void setRaceDetails(Generic_Character_Class &v);
  virtual std::string getRaceString() const;
};

class Halfelf : public Races
{
public:
  enum elfheritagetype
  {
    NA,
    AQUATIC,
    DROW,
    MOON,
    SUN,
    WOOD
  } elfheritage;
  virtual void setRaceDetails(Generic_Character_Class &v);
  virtual std::string getRaceString() const;
};

class Halforc : public Races
{
public:
  virtual void setRaceDetails(Generic_Character_Class &v);
  virtual std::string getRaceString() const;
};

class Halfling : public Races
{
public:
  enum halflingtype
  {
    NA,
    GHOSTWISE,
    LIGHTFOOT,
    STOUT
  };
  halflingtype subr;
  virtual void setRaceDetails(Generic_Character_Class &v);
  virtual std::string getRaceString() const;
};

class Human : public Races
{
public:
  virtual void setRaceDetails(Generic_Character_Class &v);
  virtual std::string getRaceString() const;
};

class Kenku : public Races
{
public:
  virtual void setRaceDetails(Generic_Character_Class &v);
  virtual std::string getRaceString() const;
};

class Lizardfolk : public Races
{
public:
  virtual void setRaceDetails(Generic_Character_Class &v);
  virtual std::string getRaceString() const;
};

class Tiefling : public Races
{
public:
  enum tieflingtype
  {
    NA,
    FERAL
  } type;
  virtual void setRaceDetails(Generic_Character_Class &v);
  virtual std::string getRaceString() const;
};
