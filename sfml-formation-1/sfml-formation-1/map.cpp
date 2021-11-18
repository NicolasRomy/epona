#include <SFML/Graphics.hpp>
#include "headers/map.h"
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using namespace sf;
typedef Vector2f vec2;
typedef Vector2i vec2i;

/*
Dans cet example, vous allez devoir charger et afficher un tileset
Vous devrez charger plusieurs sprites, de préférences dans un vector<>.
Vous devrez utiliser la fonction Sprite::setTextureRect() qui prend un IntRect en argument.

Un IntRect est un struct POD (plain old data type) contenant une origine et une taille, en entier.

Cette fonction permet de n'afficher que une certaine région de texture dans votre Sprite.

Je vous ai fourni un niveau à charger, une std::map<string,string> et une std::map<string, Vector2i> préremplies, et une image qui permet de visualiser la disposition des tiles.

Votre travail consiste à écrire la fonction load_level(), qui doit:
* instancier les Sprite et appeler la fonction setTextureRect() sur chacun d'entre eux.
* positionner les Sprites
Les tiles font 16x16px, il faudra donc multiplier par 16 les offset fournis dans la map
Il sera nécessaire de charger deux grilles de tiles, la première étant celle du sol, et l'autre des objets.
*/

namespace level {
    vector<string> tile_strings_backgroung = {
    "GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD ",
    "GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD ",
    "GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD ",
    "GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD ",
    "GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD ",
    "GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD ",
    "GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD ",
    "GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD ",
    "GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD ",
    "GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD ",
    "GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD ",
    "GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD ",
    "GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD ",
    "GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD ",
    "GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD ",
    "GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD ",
    "GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD ",
    "GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD GD ",
    };
    map<string, vec2i> tile_offsets = {
        { "convex_angle1", {0,0}},    //
        { "convex_angle2", {1,0}},    //

        { "convex_side1", {0,1}},     //
        { "convex_side2", {1,1}},     //

        { "convex_angle3", {0,2}},    //
        { "convex_angle4", {1,2}},    //


        { "forest_NW", {2,0}},        //
        { "forest_N", {3,0}},         //
        { "forest_NE", {4,0}},        //

        { "forest_W", {2,1}},         //
        { "forest_C", {3,1}},         //
        { "forest_E", {4,1}},         //

        { "forest_SW", {2,2}},        //
        { "forest_S", {3,2}},         //
        { "forest_SE", {4,2}},        //

        { "forest_S2", {0,5}},        //


        { "tree_big_1", {0,3}},       //
        { "tree_big_2", {1,3}},       //
        { "tree_big_3", {0,4}},       //
        { "tree_big_4", {1,4}},       //


        { "stump1", {2,3}},           //
        { "stump2", {2,4}},           //
        { "flowers", {3,3}},          //
        { "grass", {1,5}},            //

        { "ground", {4,6}},           //

        { "pool", {3,3}},  //
        { "river_corner_BL", {1,6}},  //
        { "river_corner_BR", {0,6}},  //

        { "river_corner_TR", {2,6}},  //
        { "river_corner_TL", {3,6}},  //

        { "river_vert", {2,5}},       //
        { "river_horiz", {3,5}},      //


        { "tree_base", {4,5}},        //
        { "tree_middle", {4,4}},      //
        { "tree_top", {4,3}},         //
        { "nothing", {0,7}}
    };
    map<string, string> aliasses = {

        { "A1", "convex_angle1" },
        { "A2", "convex_angle2" },

        { "S1", "convex_side1" },
        { "S2", "convex_side2" },

        { "A3", "convex_angle3" },
        { "A4", "convex_angle4" },


        { "F1", "forest_NW" },
        { "FN", "forest_N" },
        { "F2", "forest_NE" },

        { "FW", "forest_W" },
        { "FC", "forest_C" },
        { "FE", "forest_E" },

        { "F7", "forest_SW" },
        { "FS", "forest_S" },
        { "F4", "forest_SE" },

        { "FZ", "forest_S2" },


        { "T1", "tree_big_1" },
        { "T2", "tree_big_2" },
        { "T3", "tree_big_3" },
        { "T4", "tree_big_4" },


        { "d1", "stump1" },
        { "d2", "stump2" },
        { "FL", "flowers" },
        { "GS", "grass" },

        { "GD", "ground" },
        { "PL", "pool" },

        { "R2", "river_corner_BL" },
        { "R1", "river_corner_BR" },

        { "R3", "river_corner_TR" },
        { "R4", "river_corner_TL" },

        { "RH", "river_horiz" },
        { "RV", "river_vert" },


        { "tb", "tree_base" },
        { "tm", "tree_middle" },
        { "tt", "tree_top" },
        { "--", "nothing" },

    };
    vector<string> tile_strings = {
    "   GS GS FL             FW FC A2 -- -- -- -- S1 F4                      ",
    "      GS GS             F7 FS S2 -- -- -- A1 FE                R1 RH RH ",
    "   FL GS          tt          FW FC FC FC S1 F4             R1 R4       ",
    "   GS    GS       tb    tt    F7 FS FS FS F4 T1 T2    tt R1 R4          ",
    "FL T1 T2 GS FL          tm                   T3 T4    tb RV    FL       ",
    "GS T3 T4          GS    tb    F1 FN FN F2          tt    RV FL          ",
    "d2 GS FL GS GS       F1 FN FN A4 -- -- A3 F2       tb    RV    FL T1 T2 ",
    "GS FL GS GS    F1 FN A4 -- -- -- -- -- -- A3 F2          R3 RH R2 T3 T4 ",
    "d1 GS T1 T2    FW A2 -- -- -- -- -- -- -- -- FE       GS       RV    GS ",
    "GS GS T3 T4    F7 S2 -- -- -- -- -- -- A1 FC S1             FL RV       ",
    "FL    GS GS       S2 A2 -- -- -- -- -- S1 FS F4       FL       RV FL d1 ",
    "T1 T2 GS FL d2    F7 S2 -- -- -- -- A1 FE d2    tt R1 RH RH RH R4       ",
    "T3 T4    GS          FW FC FC FC FC S1 F4       tm RV FL FL FL          ",
    "         GS          F7 FS FS FS FS F4          tm RV    FL       GS GS ",
    "   FL       GS                   GS             tb RV       d2    d1    ",
    "GS    GS             GS T1 T2       GS    R1 RH RH R4          GS GS    ",
    "            FL       GS T3 T4    R1 RH RH R4 d2       GS                ",
    "GS    d1                   GS    RV                                     ",
    };
}

vector <Sprite>  load_level(vector<string> tile, map<string, string> aliasses, map<string, vec2i> tile_offsets, bool isleaf)
{

    vector <Sprite> fantastik;
    Sprite map_objects;

    int y = 0;
    for (auto& str : tile)
    {
        sf::Vector2i size(16, 16);
        sf::Vector2i emptyspace(6, 9);
        vector <IntRect> o;
        for (int i = 0; i < str.length() / 3; i++)
        {

            std::string str2 = str.substr(i * 3, 2);
            if (isleaf == false) {
                if (str2 != "  " && str2 != "R1" && str2 != "RH" && str2 != "RV" && str2 != "R4" && str2 != "R3" && str2 != "R2" && str2 != "GS" && str2 != "FL")
                {
                    auto search = aliasses.find(str2)->second;
                    auto search2 = tile_offsets.find(search)->second;
                    search2.x *= 16;
                    search2.y *= 16;
                    sf::IntRect r1(search2, size);
                    o.push_back(r1);
                }
                else
                {
                    sf::IntRect r2(emptyspace, size);
                    o.push_back(r2);
                }
            }
            else {
                if (str2 != "  ")
                {
                    auto search = aliasses.find(str2)->second;
                    auto search2 = tile_offsets.find(search)->second;
                    search2.x *= 16;
                    search2.y *= 16;
                    sf::IntRect r1(search2, size);
                    o.push_back(r1);
                }
                else
                {
                    sf::IntRect r2(emptyspace, size);
                    o.push_back(r2);
                }
            }

            for (int l = 0; l < o.size(); l++)
            {

                if (o[l].left == 6 && o[l].top == 9)
                {


                }
                else
                {
                    map_objects.setTextureRect(o[l]);
                    map_objects.setPosition(l * 16, (y * 16));
                    fantastik.push_back(map_objects);
                }
            }
        }
        y++;
    }
    return(fantastik);
}

void monde::drawmap(RenderWindow& window, monde map2)
{
    bool isleaf;
    map2.background = load_level(level::tile_strings_backgroung, level::aliasses, level::tile_offsets, isleaf = true);
    map2.middleground = load_level(level::tile_strings, level::aliasses, level::tile_offsets, isleaf = true);
    for (int i = 0; i < map2.background.size(); i++)
    {
        map2.background[i].setTexture(map2.texture2);
        window.draw(map2.background[i]);
    }
    for (int i = 0; i < map2.middleground.size(); i++)
    {
        map2.middleground[i].setTexture(map2.texture2);
        window.draw(map2.middleground[i]);
    }


}
void monde::drawmap2(RenderWindow& window, monde map2)
{
    bool isleaf;
    map2.forground = load_level(level::tile_strings, level::aliasses, level::tile_offsets, isleaf = false);
    for (int i = 0; i < map2.forground.size(); i++)
    {
        map2.forground[i].setTexture(map2.texture2);
        window.draw(map2.forground[i]);
    }


}