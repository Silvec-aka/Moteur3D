#ifndef QUAD3D_HPP
#define QUAD3D_HPP

#include <vector>
#include "triangle3D.hpp"


/**
 * @class Quad3D quad3D.hpp
 * @brief Quad3D est une classe qui représente un quadrialtère composé de 2 triangles.
 * Elle se compose de :
 *      - 2 attributs privés
 *          - \a trig1 (Triangle3D)
 *          - \a trig2 (Triangle3D)
 *      - 3 constructeurs :
 *          - un constructeur par défaut
 *          - un constructuer valué, prennant 2 Triangle3D en entrée.
 *          - un constructeur valué, prennant 4 Vector3D& en entrée.
 *      - des getters pour tout les attributs
*/
class Quad3D
{
    private :
        /**
         * @brief \a trig1 est le premier triangle du quadrialtre.
         * Son type est Triangle3D.
        */
        Triangle3D trig1;
        /**
         * @brief \a trigé est le second triangle du quadrialtre.
         * Son type est Triangle3D.
        */
        Triangle3D trig2;

    public :
        /**
         * @brief Constructeur par défaut.
        */
        Quad3D() = default;

        /**
         * @brief Constructeur qui créé un quad3D avec 2 Triangle3D,
         * ces deux triangles doivent avoir un côté en commun.
         * 
         * @param \a t1 (Triangle3D&)
         * @param \a t2 (Triangle3D&)
        */
        Quad3D(const Triangle3D& t1, const Triangle3D t2);

        /**
         * @brief Constructeur qui créé un quad3D avec 4 points dans le sens trigonométrique.
         * l'odre est en haut à droite, en haut à gauche puis en en bas à gauche et bas à droite.
         * 
         * @param \a _a (const Vector3D&)
         * @param \a _b (const Vector3D&)
         * @param \a _c (const Vector3D&)
         * @param \a _d (const Vector3D&)
        */
        Quad3D(const Vector3D& _a, const Vector3D& _b, const Vector3D& _c, const Vector3D& _d);

        /**
         * @brief Getter de \a trig1.
         * 
         * @return L'attribut \a trig1 (Triangle3D)
        */
        Triangle3D get_trig1() const;

        /**
         * @brief Getter de \a trig2.
         * 
         * @return L'attribut \a trig2 (Triangle3D)
        */
        Triangle3D get_trig2() const;

};



#endif