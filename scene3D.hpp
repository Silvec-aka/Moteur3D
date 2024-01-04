#ifndef SCENE3D_hpp
#define SCENE3D_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

#include "Mesh3D.hpp"



class Scene3D
{
    private:
        /**
         * @brief L'attribut \a meshs un un vecteur de pointeurs vers tous les mesh3D présents dans la scène.
         * Il est de type std::vector<Mesh3D*>.
         */
        std::vector<Mesh3D*> meshs;
        /**
         * @brief L'attribut \a cameraPosition contient la position fixe de la caméra.
         * Il est de type Vector3.
         */
        Vector3D cameraPosition;
        /**
         * @brief L'attribut \a lookDirection repréesnte le sens dans lequel la caméra doit regarder
         * Il est de type Vector3.
         */
        Vector3D cameraDirection;
        /**
         * @brief L'attribut \a anim sert à savoir si l'animation doit se jouer ou non.
         * Il est de type bool.
         */
        bool anim;

    public:
        /**
         * @brief Constructeur par défaut
         */
        Scene3D();
        /**
         * @brief Construit une nouvelle scène
         * 
         * @param \a _mesh (std::vector<Mesh3D*>))
         * @param \a _anim (bool)
         */
        Scene3D(std::vector<Mesh3D*> _meshs, bool _anim);
        /**
         * @brief Getter de l'attribut \a meshs.
         * 
         * @return retourne l'attribut \a meshs de l'instance (std::vector<Mesh3D*>)
         */
        std::vector<Mesh3D*> getMeshs() const;
        /**
         * @brief Getter de l'attribut \a anim.
         * 
         * @return retourne l'attribut \a anim de l'instance (bool)
         */
        bool getAnim();
        /**
         * @brief Ajoute un pointeur vers un mesh à la scène
         * 
         * @param \a _mesh (mesh3D*)
         */
        void addMesh(Mesh3D* _mesh);


                                 //----------CAMERA---------------//
        /**
         * @brief Setter de l'attribut \a cameraPosition.
         * 
         * @param \a _cameraPosition (const Vector3&)
         */
        void setCameraPosition(const Vector3D& _cameraPosition);
        /**
         * @brief Setter de l'attribut \a lookDirection.
         * 
         * @param \a _lookDirection (const Vector3&)
         */
        void setCameraDirection(const Vector3D& _lookDirection);
        /**
         * @brief Getter de l'attribut \a cameraPosition.
         * 
         * @return retourne l'attribut \a cameraPosition de l'instance (Vector3)
         */
        Vector3D getCameraPosition() const;
        /**
         * @brief Getter de l'attribut \a lookDirection.
         * 
         * @return retourne l'attribut \a lookDirection de l'instance (Vector3)
         */
        Vector3D getCameraDirection() const;
};

#endif