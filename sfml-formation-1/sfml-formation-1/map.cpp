/*#include <SFML/Graphics.hpp>
#include <C:\Users\nicol\source\repos\sfml\sfml-formation-1\sfml-formation-1\headers\map.h>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using namespace sf;
typedef Vector2f vec2;
typedef Vector2i vec2i;
monde map2;

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





namespace level {
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
    vector<string> tile_strings_backgroung = {
        "GD GD GD GD GD GD GD GD GD GD GD GD ",
        "GD GD GD GD GD GD GD GD GD GD GD GD ",
        "GD GD GD GD GD GD GD GD GD GD GD GD ",
        "GD GD GD GD GD GD GD GD GD GD GD GD ",
        "GD GD GD GD GD GD GD GD GD GD GD GD ",
        "GD GD GD GD GD GD GD GD GD GD GD GD ",
        "GD GD GD GD GD GD GD GD GD GD GD GD ",
        "GD GD GD GD GD GD GD GD GD GD GD GD ",
    };

    vector<string> tile_strings = {
    "   GS GS                FW FC A2 -- ",
    "      GS GS       tt    F7 FS S2 -- ",
    "                  tb    tt    FW FC ",
    "   T1 T2    FL          tm    F7 FS ",
    "   T3 T4          GS    tb    F1 FN ",
    "                     F1 FN FN A4 -- ",
    "      R1 R2    F1 FN A4 -- -- -- -- ",
    "R1 RH R4 R3 R2 FW -- -- -- -- -- -- ",
    };
}



vector <Sprite>  load_level(vector<string> tile, map<string, string> aliasses, map<string, vec2i> tile_offsets)
{

    vector <Sprite> fantastik;

    int y = 0;
    for (auto& str : tile)
    {
        map2.map_objects.setTexture(map2.texture2);
        sf::Vector2i size(16, 16);
        sf::Vector2i emptyspace(6, 9);
        vector <IntRect> o;
        for (int i = 0; i < str.length() / 3; i++)
        {

            std::string str2 = str.substr(i * 3, 2);
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


            for (int l = 0; l < o.size(); l++)
            {

                if (o[l].left == 6 && o[l].top == 9)
                {


                }
                else
                {
                    map2.map_objects.setTextureRect(o[l]);
                    map2.map_objects.setPosition(l * 16, (y * 16));
                    fantastik.push_back(map2.map_objects);
                }
            }
        }
        y++;
    }
    return(fantastik);
}

void monde::drawmap(RenderWindow &window,vector <Sprite> map_objects, vector <Sprite> map_background)
{
    map2.texture2.loadFromFile("foresttiles2-t.png");
    for (int i = 0; i < map2.background.size(); i++)
    {
        map2.background[i].setTexture(map2.texture2);
        window.draw(map2.background[i]);
    }

    for (int i = 0; i < map2.forground.size(); i++)
    {
        map2.forground[i].setTexture(map2.texture2);
        window.draw(map2.forground[i]);
    }
}
int si()
{
    vector <Sprite> map_objects;
    vector <Sprite> map_background;
    map_background = load_level(level::tile_strings_backgroung, level::aliasses, level::tile_offsets);
    map_objects = load_level(level::tile_strings, level::aliasses, level::tile_offsets);
    sf::RenderWindow window(sf::VideoMode(192, 128), "SFML works!");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        map2.drawmap(&window,map_objects,map_background);
        /*for (int i = 0; i < map_background.size(); i++)
        {
            
            map_background[i].setTexture(texture);
            window.draw(map_background[i]);
        }

        for (int i = 0; i < map_objects.size(); i++)
        {
            map_objects[i].setTexture(texture);
            window.draw(map_objects[i]);
        }
        
        window.display();
        window.clear();
    }


    return 0;
}
*/