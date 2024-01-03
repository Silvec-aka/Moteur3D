#ifndef ENGINE3D_HPP
#define ENGINE3D_HPP
#include <SDL2/SDL.h>
#include <iostream>
#include "scene3D.hpp"

using namespace std;


/**
 * @class Engine3D Engine.hpp
 * @brief La classe Engine3D initialise la fenêtre SDL et calcule toutes les positions des triangles à afficher dans la fenêtre.
 * Elle se compose de :
 *      - 7 attributs privés :
 *          - \a scene (Scene)
 *          - \a window (SDL_Window*)
 *          - \a rendere (SDL_Renderer*)
 *          - \a window_width (int)
 *          - \a window_height (int)
 *          - \a fov_factor (float)
 *          - \a is_running (bool)
 *          
*/
class Engine3D
{
    private :
        /**
         * @brief Cette attribut correspond à la scène à afficher.
         * Il est du type Scene.
         */
        Scene scene;
        /**
         * @brief L'attribut window est un pointeur vers une SDL_Window qui est la fenêtre de l'executable.
         * Il est du type SDL_Window*.
         */
        SDL_Window* window;
        /**
         * @brief L'attribut renderer est un pointeru vers un SDL_Renderer qui sert à afficher ce qui a été dessine avec la bibliothèque SDL2.
         * Il est de type SDL_Renderer*
         */
        SDL_Renderer* renderer;
        /**
         * @brief L'attribut window_width correspond à la longueur de la fenêtre en nombre de pixels.
         * Il est de type int.
         */
        int window_width;
        /**
         * @brief L'attribut window_height correspond à la hauteur de la fenêtre en nombre de pixels.
         * Il est de type int.
         */
        int window_height;
        /**
         * @brief L'attribut fov_factor représente la mise au point de la caméra.
         * Il est de type float.
         */
        float fov_factor;
        /**
         * @brief L'attribut running sert à savoir si la fenêtre est ouverte ou non.
         * Il est de type bool.
         */
        bool running;

    public:
        /**
         * @brief Construit un affichage scene et la taille de sa fenêtre.
         * 
         * @param _scene (const Scene&)
         * @param _window_width (const int)
         * @param _window_height (const int)
         * @param _fov_factor 
         */
        Engine3D(Scene& _scene, const int _window_width, const int _window_height, const float _fov_factor);
        /**
         * @brief Setter de l'attribut running.
         * 
         * @param _running (bool)
         */
        void Setrunning(bool _running);
        /**
         * @brief Fait le rendu de l'image à afficher à chaque frame par rapport au dernier rendu fait time secondes avant.
         * 
         * @param time (float)
         * @param isAnimated (bool)
         */
        void render(float time, bool isAnimated);
        /**
         * @brief Vérifie si la fenêtre est en cours d'utilisation. C'est un Getter de l'attribut running.
         * 
         * @return L'attribut running de l'instance (bool)
         */
        bool isRunning();
        /**
         * @brief Détruit la fenêtre et vide toute la mémoire utilisée.
         * 
         */
        void destroy_window();
        /**
         * @brief remplit le triangle dont les points sont donnés par des SDL_Points.
         * 
         * @param v1 (SDL_Point)
         * @param v2 (SDL_Point)
         * @param v3 (SDL_Point)
         */
        void fillTriangle(SDL_Point v1, SDL_Point v2, SDL_Point v3);
        /**
         * @brief dessine un triangle projeté sur un plan dont les points sont des SDL_Points et plus des Vector3 selon le mode de rendu de la scene choisi.
         * 
         * @param v1 (SDL_Point)
         * @param v2 (SDL_Point)
         * @param v3 (SDL_Point)
         * @param color (SDL_Color)
         * @param illumination (float)
         */
        void drawTriangle(SDL_Point v1, SDL_Point v2, SDL_Point v3, SDL_Color color, float illumination);
};

#endif 