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

    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/data/)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/saves/)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/settings/)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/exports/)

    configure_file(data/artObjects.dat    ${CMAKE_CURRENT_BINARY_DIR}/data/ COPYONLY)
    configure_file(data/diseaselist.dat   ${CMAKE_CURRENT_BINARY_DIR}/data/ COPYONLY)
    configure_file(data/gems.dat          ${CMAKE_CURRENT_BINARY_DIR}/data/ COPYONLY)
    configure_file(data/insults-clean.dat ${CMAKE_CURRENT_BINARY_DIR}/data/ COPYONLY)
    configure_file(data/insults-dirty.dat ${CMAKE_CURRENT_BINARY_DIR}/data/ COPYONLY)
    configure_file(data/madnesslist.dat   ${CMAKE_CURRENT_BINARY_DIR}/data/ COPYONLY)
    configure_file(data/names.dat         ${CMAKE_CURRENT_BINARY_DIR}/data/ COPYONLY)
    configure_file(data/poisonlist.dat    ${CMAKE_CURRENT_BINARY_DIR}/data/ COPYONLY)
    configure_file(saves/readme.md        ${CMAKE_CURRENT_BINARY_DIR}/saves/ COPYONLY)
    configure_file(settings/readme.md     ${CMAKE_CURRENT_BINARY_DIR}/settings/ COPYONLY)
    configure_file(exports/readme.md      ${CMAKE_CURRENT_BINARY_DIR}/exports/ COPYONLY)

endif()