#include <iostream>
#include "engine3D.hpp"
#include "pave3D.hpp"
#include "sphere3D.hpp"
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

    //creation d'un cube

    Vector3D v1(-2,-1,-1); //Test avec le constructeur qui prend 8 vector3D
    Vector3D v2(-2,1,-1);
    Vector3D v3(0,1,-1);
    Vector3D v4(0,-1,-1);
    Vector3D v5(0,1,1);
    Vector3D v6(0,-1,1);
    Vector3D v7(-2,1,1);
    Vector3D v8(-2,-1,1);

    Vector3D tr(0,0,1);
    Pave3D cube = Pave3D(v1/2+tr,v2/2+tr,v3/2+tr,v4/2+tr,v5/2+tr,v6/2+tr,v7/2+tr,v8/2+tr); 
    scene.addMesh(&cube);
    //creation d'une sphere

    Vector3D v0(0,0,-1);
    Sphere3D sphere = Sphere3D(v0,1,10);
    
    
    scene.addMesh(&sphere);
    Engine3D engine = Engine3D(scene,800,600,640.0f);

    float t = 0.0f;
    while (engine.is_running())
    {
        process_input(engine);
        engine.render(t,scene.getAnim());
        t = (float)SDL_GetTicks()/1000.0f;
    }

    //nettoyage
    engine.destroy_window();

    return 0;
}