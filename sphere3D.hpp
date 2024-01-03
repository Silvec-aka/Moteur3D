#ifndef SPHERE3D_HPP
#define SPHERE3D_HPP

#include "mesh3D.hpp"

/**
 * @class Sphere3D sphere3D.hpp
 * @brief La classe Sphere3D est une classe qui hérite de Mesh3D, elle représente une sphèree en 3D.
 * Elle se compose de :
 *      - un attribut privé :
 *              - quads (std::vector<Quad>)
 *      - un constructeur prenant un Vector3&, un const float et un const int.
 *      - une méthode override publique :
 *              - get_Quads()
 */
class Sphere3D : public Mesh3D
{
    private :
    /**
         * @brief \a quads est l'attribut qui stocke tout les quadrilatère représentant le volume.
         * Son type est std::vector<Quad3D>.
        */
        std::vector<Quad3D> quads;

    public :
        /**
         * @brief Construsteur de copie.
         * 
         * @param \a _sp (Sphere3D&)
        */
        Sphere3D(const Sphere3D& _sp);

        /**
         * @brief Construit une nouvelle Sphere3D de centre center, de rayon rad, avec nb_Seg subdivisions.
         * 
         * @param center (Vector3&)
         * @param rad (const float)
         * @param nb_Seg (const int)
         */
        Sphere3D(const Vector3D& center, const float rad, const int nb_Seg);

        /**
         * @brief Getter de \a quads.
         * 
         * @return l'attribut quads (std::vector<Quad3D>)
         */
        std::vector<Quad3D> get_Quads() const override;

};







#endif