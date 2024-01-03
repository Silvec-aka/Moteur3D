#include "pave3D.hpp"

Pave3D::Pave3D(const Pave3D& _pave)
{
    quads = _pave.get_Quads();
}

Pave3D::Pave3D(const Vector3D& leftBotomFront,
                const Vector3D& leftTopFront,
                const Vector3D& rightTopFront,
                const Vector3D& rightBotomFront,
                const Vector3D& rightTopBack,
                const Vector3D& rightBotomBack,
                const Vector3D& leftTopBack,
                const Vector3D& leftBotomBack)
{
    Triangle3D triFront1(rightTopFront,leftTopFront,leftBotomFront);
    Triangle3D triFront2(leftBotomFront,rightBotomFront,rightTopFront);
    Triangle3D triRight1(rightTopBack,rightTopFront,rightBotomFront);
    Triangle3D triRight2(rightBotomFront,rightBotomBack,rightTopBack);
    Triangle3D triBack1(leftTopBack,rightTopBack,rightBotomBack);
    Triangle3D triBack2(rightBotomBack,leftBotomBack,leftTopBack);
    Triangle3D triLeft1(leftTopFront,leftTopBack,leftBotomBack);
    Triangle3D triLeft2(leftBotomBack,leftBotomFront,leftTopFront);
    Triangle3D triTop1(leftTopFront,rightTopFront,rightTopBack);
    Triangle3D triTop2(rightTopBack,leftTopBack,leftTopFront);
    Triangle3D triBotom1(leftBotomFront, leftBotomBack,rightBotomBack);
    Triangle3D triBotom2(rightBotomBack, rightBotomFront,leftBotomFront);

    Quad3D front(triFront1,triFront2);
    Quad3D rigth(triRight1,triRight2);
    Quad3D back(triBack1,triBack2);
    Quad3D left(triLeft1,triLeft2);
    Quad3D top(triTop1,triTop2);
    Quad3D botom(triBotom1,triBotom2);

    quads = std::vector<Quad3D>();
    quads.push_back(front);
    quads.push_back(rigth);
    quads.push_back(back);
    quads.push_back(left);
    quads.push_back(top);
    quads.push_back(botom);
}

std::vector<Quad3D> Pave3D::get_Quads() const
{
    return quads;
}