#include "sphere3D.hpp"

Sphere3D::Sphere3D(const Sphere3D& _sp)
{
  quads = _sp.get_Quads();
}


Sphere3D::Sphere3D(const Vector3D& center, const float rad, const int nb_Seg)
{
  std::vector<Vector3D> points;
  int k = 0;
  for (int i = 0; i <= nb_Seg; i++) 
  {
    float lat = -M_PI/2 + M_PI * ((float)i) / nb_Seg;
    for (int j = 0; j <= nb_Seg; j++) 
    {
      float lng = 2 * M_PI * ((float)j) / nb_Seg;
      float x = rad * cos(lat) * cos(lng) + center.get_x(); 
      float y = rad * cos(lat) * sin(lng) + center.get_y();
      float z = rad * sin(lat) + center.get_z();
      points.push_back({x, y, z});
      k++;
    }
  }

  for (int i = 0; i < nb_Seg; i++) 
  {
    for (int j = 0; j < nb_Seg; j++) 
    {
      int a = i * (nb_Seg+1) + j;
      int b = (i+1) * (nb_Seg+1) + j;
      int c = (i+1) * (nb_Seg+1) + j + 1;
      int d = i * (nb_Seg+1) + j + 1;
      
      Quad3D quad3D(points[a], points[b], points[c],points[d]);
      quads.push_back(quad3D);

    }
  }
}

std::vector<Quad3D> Sphere3D::get_Quads() const
{
  return quads;
}
