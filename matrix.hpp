#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

/**
 * @class Matrix matrix.hpp
 * @brief Matrix est une classe qui représente un matrice carré de dimension constante égale à 4.
 * Elle se compose de :
 *      - 1 attribut privé :
 *          - \a data (float[4][4])
 *      - 2 constructeurs :
 *          - un constructeur par défaut
 *          - un constructeur qui a 16 float en entrée
 *      - 1 méthode publique :
 *          - inverse()
*/
class Matrix
{
    private :
        /**
         * @brief L'attribut \a data contient les flottants de l'instance dans un tableau 4, 4.
         * Son type est float[4][4]
        */
        float data[4][4];

    public :
        /**
         * @brief Constructeur par défaut, matrice ne contenant que des 1.
        */
        Matrix();

        /**
         * @brief Construceur de copie.
         * 
         * @param mat (Matrix&)
        */
        Matrix(const Matrix& mat);

        /**
         * @brief Constructeur qui créé une matrice composée des 16 flottants en entrée.
         * 
         * @param a00 (float)
         * @param a01 (float)
         * @param a02 (float)
         * @param a03 (float)
         * @param a10 (float)
         * @param a11 (float)
         * @param a12 (float)
         * @param a13 (float)
         * @param a20 (float)
         * @param a21 (float)
         * @param a22 (float)
         * @param a23 (float)
         * @param a30 (float)
         * @param a31 (float)
         * @param a32 (float)
         * @param a33 (float)
        */
        Matrix(float a00, float a01, float a02, float a03,
               float a10, float a11, float a12, float a13,
               float a20, float a21, float a22, float a23,
               float a30, float a31, float a32, float a33);
        
        /**
         * @brief Calcule l'inverse de la matrice en instance.
         * 
         * @return L'inverse de la matrice en instance.
        */
        Matrix inverse();

        float& operator[](std::pair<int, int> idx);
        const float& operator[](std::pair<int, int> idx) const;

        void initializeZRot(float angle);
        void initializeYRot(float angle);
        void initializeXRot(float angle);
        void initializeProj(int window_width,int window_height);

};

std::ostream& operator<<(std::ostream& os,const Matrix& mat);



#endif