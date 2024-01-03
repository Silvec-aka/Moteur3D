#ifndef PAVE3D_HPP
#define PAVE3D_HPP

#include "mesh3D.hpp"


/**
 * @class Pave3D pave3D.hpp
 * @brief Pave3D est la classe qui hérite de Mesh3D, elle représente les pavés en 3 dimensions.
 * Elle se compose de :
 *      - 2 attributs privés :
 *              - quads (std::vector<Quad3D>)
 *      - 2 constructeurs :
 *              - un constructeur de copie
 *              - un constructeur avec huit Vector3& en entrée
 *      - 1 méthode override publique :
 *              - getQuads()
*/
class Pave3D : public Mesh3D
{
    private :
        /**
         * @brief \a quads est l'attribut qui stocke tout les quadrilatère représentant le volume.
         * Son type est std::vector<Quad3D>.
        */
        std::vector<Quad3D> quads;

    public :
        /**
         * @brief Constructuer de copie.
         * 
         * @param \a _pave (Pave3D&)
        */
        Pave3D(const Pave3D& _pave);

        Pave3D(const Vector3D& leftBotomFront,
                const Vector3D& leftTopFront,
                const Vector3D& rightTopFront,
                const Vector3D& rightBotomFront,
                const Vector3D& rightTopBack,
                const Vector3D& rightBotomBack,
                const Vector3D& leftTopBack,
                const Vector3D& leftBotomBack);

        /**
         * @brief Getter de \a quads.
         * 
         * @return L'attribut \a quad (std::vector<Quad>) 
         */
        std::vector<Quad3D> get_Quads() const override;
};

#endif