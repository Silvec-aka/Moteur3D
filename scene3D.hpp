#ifndef SCENE3D_hpp
#define SCENE3D_HPP

#include <SDL2/SDL.h>
#include <iostream>

struct vec3d
{
	float x, y, z;
};

struct triangle
{
	vec3d p[3];
};

struct Mesh3D
{
	vector<triangle> tris;
};

struct Quad
{
    Mesh3D[2] quad;
};

class Scene
{
    private:
        /**
         * @brief L'attribut meshs un un vecteur de pointeurs vers tous les mesh3D présents dans la scène.
         * Il est de type std::vector<Mesh3D*>.
         */
        std::vector<Mesh*> meshs;
        /**
         * @brief L'attribut cameraPosition contient la position fixe de la caméra.
         * Il est de type Vector3.
         */
        Vector3 cameraPosition;
        /**
         * @brief L'attribut lookDirection repréesnte le sens dans lequel la caméra doit regarder
         * Il est de type Vector3.
         */
        Vector3 cameraDirection;
        /**
         * @brief L'attribut anim sert à savoir si l'animation doit se jouer ou non.
         * Il est de type bool.
         */
        bool anim;

    public:
        /**
         * @brief Constructeur par défaut
         */
        Scene();
        /**
         * @brief Construit une nouvelle scène
         * 
         * @param _mesh (std::vector<Mesh3D*>))
         * @param _anim (bool)
         */
        Scene(std::vector<Mesh3D*> _meshs, bool _anim);
        /**
         * @brief Getter de l'attribut meshs.
         * 
         * @return retourne l'attribut meshs de l'instance (std::vector<Mesh3D*>)
         */
        std::vector<Mesh3D*> getMeshs() const;
        /**
         * @brief Getter de l'attribut anim.
         * 
         * @return retourne l'attribut anim de l'instance (bool)
         */
        bool getAnim();
        /**
         * @brief Ajoute un pointeur vers un mesh à la scène
         * 
         * @param _mesh (mesh3D*)
         */
        void addMesh(Mesh3D* _mesh);


                                 //----------CAMERA---------------//
        /**
         * @brief Setter de l'attribut cameraPosition.
         * 
         * @param _cameraPosition (const Vector3&)
         */
        void setCameraPosition(const Vector3& _cameraPosition);
        /**
         * @brief Setter de l'attribut lookDirection.
         * 
         * @param _lookDirection (const Vector3&)
         */
        void setCameraDirection(const Vector3& _lookDirection);
        /**
         * @brief Getter de l'attribut cameraPosition.
         * 
         * @return retourne l'attribut cameraPosition de l'instance (Vector3)
         */
        Vector3 getCameraPosition() const;
        /**
         * @brief Getter de l'attribut lookDirection.
         * 
         * @return retourne l'attribut lookDirection de l'instance (Vector3)
         */
        Vector3 getCameraDirection() const;
};

#endif