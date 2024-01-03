#include "scene3D.hpp"

Scene3D::Scene3D()
{
    // Quad3D face_sud = Quad3D(
    //     Triangle3D(Vector3D(0.0f, 0.0f, 0.0f),    Vector3D(0.0f, 1.0f, 0.0f),    Vector3D(1.0f, 1.0f, 0.0f)),
    //     Triangle3D(Vector3D(0.0f, 0.0f, 0.0f),    Vector3D(1.0f, 1.0f, 0.0f),    Vector3D(1.0f, 0.0f, 0.0f)) 
    // );
    
    // Quad3D face_est = Quad3D(
    //     Triangle3D(Vector3D(1.0f, 0.0f, 0.0f),    Vector3D(1.0f, 1.0f, 0.0f),    Vector3D(1.0f, 1.0f, 1.0f)),
    //     Triangle3D(Vector3D(1.0f, 0.0f, 0.0f),    Vector3D(1.0f, 1.0f, 1.0f),    Vector3D(1.0f, 0.0f, 1.0f)) 
    // );

    // Quad3D face_nord = Quad3D(
    //     Triangle3D(Vector3D(1.0f, 0.0f, 1.0f),    Vector3D(1.0f, 1.0f, 1.0f),    Vector3D(0.0f, 1.0f, 1.0f)),
    //     Triangle3D(Vector3D(1.0f, 0.0f, 1.0f),    Vector3D(0.0f, 1.0f, 1.0f),    Vector3D(0.0f, 0.0f, 1.0f)) 
    // );

    // Quad3D face_ouest = Quad3D(
    //     Triangle3D(Vector3D(0.0f, 0.0f, 1.0f),    Vector3D(0.0f, 1.0f, 1.0f),    Vector3D(0.0f, 1.0f, 0.0f)),
    //     Triangle3D(Vector3D(0.0f, 0.0f, 1.0f),    Vector3D(0.0f, 1.0f, 0.0f),    Vector3D(0.0f, 0.0f, 0.0f)) 
    // );

    // Quad3D face_top = Quad3D(
    //     Triangle3D(Vector3D(0.0f, 1.0f, 0.0f),    Vector3D(0.0f, 1.0f, 1.0f),    Vector3D(1.0f, 1.0f, 1.0f)),
    //     Triangle3D(Vector3D(0.0f, 1.0f, 0.0f),    Vector3D(1.0f, 1.0f, 1.0f),    Vector3D(1.0f, 1.0f, 0.0f)) 
    // );

    // Quad3D face_bottom = Quad3D(
    //     Triangle3D(Vector3D(1.0f, 0.0f, 1.0f),    Vector3D(0.0f, 0.0f, 1.0f),    Vector3D(0.0f, 0.0f, 0.0f)),
    //     Triangle3D(Vector3D(1.0f, 0.0f, 1.0f),    Vector3D(0.0f, 0.0f, 0.0f),    Vector3D(1.0f, 0.0f, 0.0f)) 
    // );

    // cube.tris = {face_sud,face_est,face_nord,face_ouest,face_top,face_bottom};
    // meshs = std::vector<Mesh3D*>();
    // meshs.push_back(&cube);
    // std::cerr<<"cube : "<<meshs[0]->tris[0].quad[0]<<std::endl;
    
    meshs = std::vector<Mesh3D*>();
    cameraPosition = Vector3D(0, 0, -4);
    cameraDirection = Vector3D(0, 45, 0);

    anim=true;
}

Scene3D::Scene3D(std::vector<Mesh3D*> _meshs, bool _anim)
{
    meshs = _meshs;
    anim = _anim;

    cameraPosition = Vector3D(0, 0, -4);
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
