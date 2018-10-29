extern void menu();
extern void set_user_pref_from_file();

//extern void loadUserSettings();

int main()
{

  set_user_pref_from_file();

  menu();

  return 0;
}


