#include "engine3D.hpp"+

using namespace std;



Engine3D::Engine3D(Scene3D& _scene, const int _window_width, const int _window_height, const float _fov_factor)
{
	scene = _scene;
    window_width = _window_width;
    window_height = _window_height;
    fov_factor = _fov_factor;
    running = true;
    //on initialise sdl
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL.\n");
        running = false;
        return;
	}

	//on créé la fenêtre
	window = SDL_CreateWindow(
        "par Jules Pellevoizin et Alec Borel",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        window_width,
        window_height,
        0
    );

	//on retourne une erreur si la fenêtre n'est pas créé
    if (!window) {
        fprintf(stderr, "Error creating SDL window.\n");
        running = false;
        return;
    }
    
    // // on crée l’objet qui affichera la scène
    SDL_Renderer *ren = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        fprintf(stderr, "Error creating SDL renderer.\n");
        running = false;
        return;
    }
    // la couleur noire pour le fond de la fenêtre
    SDL_SetRenderDrawColor(ren, 0, 0, 0,SDL_ALPHA_OPAQUE);
}

Engine3D::Setrunning(bool _running)
{
	running = _running;
}

Engine3D::render(float time, bool isAnimated)
{
	std::vector<Mesh3D*> meshs = scene.getMeshs();

	//On récupère les faces de chaque mesh
    std::vector<std::vector<Quad>> faces ;
}