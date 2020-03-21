#include "globalfuncts.h"

int main()
{

  set_user_pref_from_file();

  if (autoLoad)
    load_last_save();

  menu();

  return 0;
}


