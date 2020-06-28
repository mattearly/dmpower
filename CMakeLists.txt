cmake_minimum_required(VERSION 3.13)

project(dmpower)

find_package(Boost REQUIRED COMPONENTS filesystem)

if (Boost_FOUND)

    include_directories(${Boost_INCLUDE_DIRS})
        add_executable(dmpower
        src/campaign.cpp
        src/character_background.cpp
        src/character_classes.cpp
        src/character_export.cpp
        src/character_feats.cpp
        src/character_print.cpp
        src/character_random_name.cpp
        src/character_skills.cpp
        src/character_update.cpp
        src/characters.cpp
        src/charts.cpp
        src/gear.cpp
        src/gen_dungeon.cpp
        src/gen_encounter.cpp
        src/gen_experience.cpp
        src/gen_insult.cpp
        src/gen_name.cpp
        src/gen_reward.cpp
        src/globalfuncts.cpp
        src/main.cpp
        src/menu.cpp
        src/races.cpp
        src/save.cpp
        src/user_settings.cpp
    )

    target_link_libraries(dmpower Boost::filesystem)

    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/data/lists/)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/user/saves/)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/user/settings/)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/user/exports/)

    configure_file(data/lists/artObjects.dat    ${CMAKE_CURRENT_BINARY_DIR}/data/lists COPYONLY)
    configure_file(data/lists/diseaselist.dat   ${CMAKE_CURRENT_BINARY_DIR}/data/lists COPYONLY)
    configure_file(data/lists/gems.dat          ${CMAKE_CURRENT_BINARY_DIR}/data/lists COPYONLY)
    configure_file(data/lists/insults-clean.dat ${CMAKE_CURRENT_BINARY_DIR}/data/lists COPYONLY)
    configure_file(data/lists/insults-dirty.dat ${CMAKE_CURRENT_BINARY_DIR}/data/lists COPYONLY)
    configure_file(data/lists/madnesslist.dat   ${CMAKE_CURRENT_BINARY_DIR}/data/lists COPYONLY)
    configure_file(data/lists/names.dat         ${CMAKE_CURRENT_BINARY_DIR}/data/lists COPYONLY)
    configure_file(data/lists/poisonlist.dat    ${CMAKE_CURRENT_BINARY_DIR}/data/lists COPYONLY)
    
    configure_file(user/saves/readme.md        ${CMAKE_CURRENT_BINARY_DIR}/user/saves/    COPYONLY)
    configure_file(user/settings/readme.md     ${CMAKE_CURRENT_BINARY_DIR}/user/settings/ COPYONLY)
    configure_file(user/exports/readme.md      ${CMAKE_CURRENT_BINARY_DIR}/user/exports/  COPYONLY)

endif()