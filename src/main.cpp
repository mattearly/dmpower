extern void menu();
extern void set_user_pref_from_file();
extern void load_last_save();

int main()
{

  set_user_pref_from_file();

  load_last_save();

  menu();

  return 0;
}


