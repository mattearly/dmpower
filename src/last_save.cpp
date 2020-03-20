#include <fstream>
#include <string>
std::string lastSave;
extern void load_file(const std::string& filename);

/** Routine to check what the user last saved and load it. Variable last_save is cleared if this fails. */
void load_last_save()
{
    lastSave.clear();
    std::ifstream fs("./settings/lastSave.dat");
    if (fs.is_open())
    {
        std::string holder;
        std::getline(fs, holder); // should be the first line
        if (!holder.empty())
        {
            lastSave = holder;  
        }

    
        load_file(lastSave);


        //     we only what the first line this is just here to process the rest of the file for later expansion    

        // while (!fs.eof())
        // {
        //     std::getline(fs, holder);
        // }
        
    }

}


/** Routine to take not of the last save so that load_last_save() func can use it. */
void note_last_save(const std::string& save_name)
{
    lastSave = save_name;
    std::ofstream os("./settings/lastSave.dat");
    if (os.is_open())
    {
        os << lastSave;
    }
    else 
    {
        lastSave.clear();
    }
}