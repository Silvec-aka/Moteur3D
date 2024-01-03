#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <cmath>
#include<SDL2/SDL.h>
#include "matrix.hpp"

/**
 * @class Vector3D vector3D.hpp
 * @brief Vector3D est une calsse qui représente des vecteurs de dimension constante égale à 3.
 * Elle se compose de :
 *      - 4 attributs privés :
 *          - \a x (float)
 *          - \a y (float)
 *          - \a z (float)
 *          - \a p (float)
 *      - 2 constructeurs :
 *          - un constructeur qui a 3 float en entrée
 *      - des getters/setters pour tout les attributs
 *      - 4 méthodes publiques :
 *          - normalize()
 *          - magnitude()
 *          - dotProduct()
 *          - crossProduct() 
 *      - des operator pour faire des calculs avec les différentse instance de classe.
*/
class Vector3D
{
    private :
        /**
         * @brief \a x est le premier élément du vecteur.
         * C'est un float.
        */
        float x;
        /**
         * @brief \a y est le deuxième élément du vecteur.
         * C'est un float.
        */
        float y;
        /**
         * @brief \a z est le troisième élément du vecteur.
         * C'est un float.
        */
        float z;
        /**
         * @brief \a p sert à homogénéiser les éléments du vecteur lors des projections sur un plan.
         * C'est un float.
        */
        float p;

    public :
        /**
         * @brief Constructuer par défaut et valué, créer un vector3D avec pour valeur \a x, \a y, \a z et \a p = 1.
        */
        Vector3D(float x=0, float y=0, float z=0);

        /**
         * @brief Getter de \a x.
         * 
         * @return \a x (float)
        */
        float get_x() const;

        /**
         * @brief Getter de \a y.
         * 
         * @return \a y (float)
        */
        float get_y() const;

        /**
         * @brief Getter de \a z.
         * 
         * @return \a z (float)
        */
        float get_z() const;

        /**
         * @brief Getter de \a p.
         * 
         * @return \a p (float)
        */
        float get_p() const;

        /**
         * @brief Setter de \a x.
         * 
         * @param \a x (float)
        */
        void set_x(const float x);

        /**
         * @brief Setter de \a y.
         * 
         * @param \a y (float)
        */
        void set_y(const float y);

        /**
         * @brief Setter de \a z.
         * 
         * @param \a z (float)
        */
        void set_z(const float z);

        /**
         * @brief Setter de \a p.
         * 
         * @param \a p (float)
        */
        void set_p(const float p);

        /**
         * @brief Normalise le vecteur de l'instance.
        */
        void normalize();

        /**
         * @brief Calcule et renvoie la norme du vecteur.
         * 
         * @return norme du vecteur de l'instance (float)
        */
       float magnitude();

       /**
        * @brief Clacule le produit scalaire du vecteur de l'instance et de celui en entrée, retourne le résultat.
        * 
        * @param \a other_vect (Vector3D)
        * @return Le résultat du produit scalaire (float)
       */
      float dotProduct(const Vector3D& other_vect) const;

      /**
        * @brief Clacule le produit vectoriel entre le vecteur de l'instance et de celui en entrée, retourne le résultat.
        * 
        * @param \a other_vect (Vector3D)
        * @return Le résultat du produit vectoriel (Vector3)
       */
      Vector3D crossProduct(const Vector3D& other_vect) const;

      /**
       * @brief Calcule le produit matriciel entre le vecteur en instance et la matrice en paramètre.
       * 
       * @param \a vect_out (Vector3D)
       * @param \a mat (Matrix)
       * @return \a vect_out, contenant le resulat du produit matriciel (vector3D)
      */
      Vector3D multiplyVector3ByMatrix4(Vector3D vect_out, const Matrix& mat);

      void operator+=(const Vector3D& vect);
      void operator-=(const Vector3D& vect);
      void operator*=(const float& a);
      void operator/=(const float& a);

      friend Vector3D operator+(const Vector3D& v1, const Vector3D& v2);
      friend Vector3D operator-(const Vector3D& v1, const Vector3D& v2);
      friend Vector3D operator*(const Vector3D& v1, const float& f);
      friend Vector3D operator*(const float& f, const Vector3D& v1);
      friend Vector3D operator*(const Vector3D& v1, const Vector3D& v2);

      /**
       * @brief Calcule le produit matriciel entre le vecteur en instance et la matrice en paramètre.
       * 
       * @param \a mat (Matrix)
       * @return le resulat du produit matriciel (vector3D)
      */
      Vector3D multiplyVector3ByMatrix4(const Matrix& mat);

      /**
         * @brief Mutliplie les attributs x et y par -1. 
         * 
         */
        void inverseXY();
};

std::ostream& operator<<(std::ostream& os, Vector3D v);


Vector3D operator+(const Vector3D& v1, const Vector3D& v2);
Vector3D operator-(const Vector3D& v1, const Vector3D& v2);
Vector3D operator*(const Vector3D& v1, const float& f);
Vector3D operator*(const float& f, const Vector3D& v1);
Vector3D operator*(const Vector3D& v1, const Vector3D& v2);
Vector3D operator/(const Vector3D& v1, const float& f);
Vector3D operator/(const float& f, const Vector3D& v1);


/**
* @brief Clacule le produit vectoriel entre deux vecteurs, retourne le résultat.
* 
* @param \a v1 (Vector3D)
* @param \a v2 (Vector3D)
* @return Le résultat du produit vectoriel (Vector3)
*/
Vector3D CrossProduct(const Vector3D& v1, const Vector3D& v2);

#endif