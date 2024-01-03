#ifndef MESH3D_HPP
#define MESH3D_HPP

#include "quad3D.hpp"

/**
 * @class Mesh3D mesh3D.hpp
 * @brief Mesh3D est la classe génériquereprésentant les objets représentés en trois dimensiosn.
 * Elle se compose de :
 *      - 2 attributs privés :
 *              - quads (std::vector<Quad3D>)
 *      - un constructeur par défaut
 *      - un destructeur par défaut
 *      - une méthode virtuelle publique :
 *              - get_Quads()
 */
class Mesh3D
{
    private :
        /**
         * @brief \a quads est l'attribut qui stocke tout les quadrilatère représentant le volume.
         * Son type est std::vector<Quad3D>.
        */
        std::vector<Quad3D> quads;

    public :
        /**
         * @brief Constructeur par défaut
        */
        Mesh3D()=default;
        /**
         * @brief Destructeur par défaut.
        */
        ~Mesh3D()=default;

        virtual std::vector<Quad3D> get_Quads()
        {
            return quads;
        }
};

#endif