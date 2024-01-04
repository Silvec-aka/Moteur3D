#include "scene3D.hpp"

Scene3D::Scene3D()
{
    meshs = std::vector<Mesh3D*>();
    cameraPosition = Vector3D(0, 0, -4);
    cameraDirection = Vector3D(0, 45, 0);

    anim=true;
}

Scene3D::Scene3D(std::vector<Mesh3D*> _meshs, bool _anim)
{
    meshs = _meshs;
    anim = _anim;

    cameraPosition = Vector3D(1, 1, 0);
    cameraDirection = Vector3D(0, 45, 0);
}

std::vector<Mesh3D*> Scene3D::getMeshs() const
{
    return meshs;
}

bool Scene3D::getAnim()
{
    return anim;
}

void Scene3D::addMesh(Mesh3D* _mesh)
{
    meshs.push_back(_mesh);
}

void Scene3D::setCameraPosition(const Vector3D& _cameraPosition)
{
    cameraPosition= _cameraPosition;
}

Vector3D Scene3D::getCameraPosition() const
{
    return cameraPosition;
}

Vector3D Scene3D::getCameraDirection() const
{
    return cameraDirection;
}
