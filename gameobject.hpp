#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include "pixel.hpp"
#include <string>
#include <vector>
class Gameobject{
public:
  Gameobject(const std::vector<std::vector<Pixel>> & img, int px = 0, int py = 0, int sizex = 0, int sizey = 0);
  const std::vector<std::vector<Pixel>> & get_img() const;
  void set_img(const std::vector<std::vector<Pixel>> & img);
  void set_pixel(const Pixel & p, int px, int py);
  int sizex_; //Only rects allowed
  int sizey_;
  int px_;
  int py_;
private:
  std::vector<std::vector<Pixel>> img_;

};
#endif
