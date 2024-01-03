#include <iostream>
#include "engine3D.hpp"

/**
 * @brief Ferme la fenêtre et quitte le programme si l'utiliateur clique sur la croix ou appuie sur Echap.
 * 
 * @param affichage (Affichage&)
 */
void process_input(Engine3D& engine){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            engine.Setrunning(false);
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                engine.Setrunning(false);
            }
            break;        
    }
}

int main()
{
    
    Scene3D scene = Scene3D();
    
    Vector3D v1(-2,-1,-1); //Test avec le constructeur qui prend 8 vector3
    Vector3D v2(-2,1,-1);
    Vector3D v3(0,1,-1);
    Vector3D v4(0,-1,-1);
    Vector3D v5(0,1,1);
    Vector3D v6(0,-1,1);
    Vector3D v7(-2,1,1);
    Vector3D v8(-2,-1,1);
    Pave3D cube = Pave3D(v1,v2,v3,v4,v5,v6,v7,v8);
    
    scene.addMesh(&cube);
    std::cerr<<"hello"<<std::endl;
    Engine3D engine = Engine3D(scene,800,600,640.0f);
    std::cerr<<"hello1"<<std::endl;
    float t = 0.0f;
    while (engine.is_running())
    {
        process_input(engine);
        engine.render(t,scene.getAnim());
        // affichage.test();
        t = (float)SDL_GetTicks()/1000.0f;
    }

    //nettoyage
    engine.destroy_window();

    return 0;
}