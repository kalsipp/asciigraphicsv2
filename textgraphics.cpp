#include <iostream>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <chrono>
#include <ios>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include "textgraphics.hpp"
#include "pixel.hpp"
#include "imgcontainer.hpp"
//#### Special member functions ####
//#### Constructor
Textgrafs::Textgrafs(){ 
  std::cout << std::unitbuf; //Turns off the buffer
  std::ios_base::sync_with_stdio(false); //Turn off sync with in stream

  struct winsize w; //Get size of window
  ioctl(0, TIOCGWINSZ, &w);
  rows_ = w.ws_row;
  cols_ = w.ws_col*0.5;
  std::vector<std::string> p;
  std::string k = "  ";
  //Pixel pix(200);
  p.resize(cols_,k);
  grid.resize(rows_,p);
  //for(int y = 0; y < grid.size(); ++y){
  //for(int x = 0; x < grid[y].size(); ++x){
  //  add_pixel(pix, x, y);
  //}
  //}
  //std::cout << grid.size() << std::endl;
  //std::cout << grid[0].size() << std::endl;
  timer_ = std::chrono::system_clock::now(); //First timepoint
  
}

//#### Member functions
void Textgrafs::paint(){
  //Used for continuous update
  //Refer to print for manual control
  if(next_tick()){ //Limit framerate
    print(); //Print out the current grid
    //save_old_grid();
  }
  clear_grid(); //This empties the grid. You need to enter what you painted every frame
} 


void Textgrafs::cursorpos(int px, int py){
  ++px; //escape is 1 base
  ++py;
  std::cout << "\033[" << py << ";" << px << "H";
} 
std::string Textgrafs::cursorpos_str(int px, int py){
  ++px;
  ++py;
  std::string s = "\033[" + std::to_string(px) + ";" + std::to_string(py) + "H";
  return s;
}
void Textgrafs::hide_cursor(){
  //TODO look up this code
}
void Textgrafs::clear_screen(){
  std::cout << "\033[2J";
}

void Textgrafs::save_old_grid(){
  old_grid = grid;
}
/* 
void Textgrafs::add_image(std::vector<std::vector<std::string>> & img_ref, int px, int py){
  
  for(int y = 0; y < img_ref.size(); ++y){
    for(int x = 0; x < img_ref[y].size(); ++x){
      Pixel p(img_ref[y][x]);
      add_pixel(p, px+x, py+y);
    }
  }
}
*/
void Textgrafs::add_image(const std::vector<std::vector<Pixel>> & imgref, int px, int py){
  for(int y = 0; y <  imgref.size(); ++y){
    for(int x = 0; x < imgref[y].size(); ++x){
      add_pixel(imgref[y][x], px+x, py+y);
    }
  }
}

void Textgrafs::add_image(const Img_container & img, int px, int py){
  add_image(img.get_img(), px, py);
}

void Textgrafs::add_rect(const Pixel & p, int px, int py, int sizex, int sizey){
  for(int y = py; y < py+sizey; ++y){
    for(int x = px; x < px+sizex; ++x){
      add_pixel(p, x, y);
    }
  }
}
void Textgrafs::print(){
  cursorpos(0,0);
  std::string s;
  for(int y = 0; y < grid.size(); ++y){
    for(int x = 0; x < grid[y].size();++x){
      s+= grid[y][x];
    }
    s+= "\033[0m\n";
  }
  s.pop_back();
  std::cout << s;
}
void Textgrafs::fill_grid(const Pixel & p){
  for(int y = 0; y < rows_; ++y){
    for(int x = 0; x < cols_; ++x){
      add_pixel(p, x, y);
    }
  }
}
void Textgrafs::clear_grid(){
  //Fills the grid with space
  for(int y = 0; y < grid.size(); ++y){
    for(int x = 0; y < grid[y].size();++x){
      Pixel p;
      add_pixel(p, x, y);
    }
  }
}
void Textgrafs::clear_grid_specific(int px, int py, int sizex, int sizey){
  for(int y = py; y < py+sizey; ++y){
    for(int x = px; x < px+sizex; ++x){
      Pixel p;
      add_pixel(p,x,y);
    }
  } 
}
bool Textgrafs::next_tick(){
  //Calculate next frame
  std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::system_clock::now()-timer_);
  if(time_span.count() > time_between_frames_){
    timer_ = std::chrono::system_clock::now();
    return true;
  }
  return false;
  
}
void Textgrafs::add_pixel(const Pixel & p, int px, int py){
  if(px < 0 || px >= cols_) return;
  if(py < 0 || py >= rows_) return;

  grid[py][px] = p.get_str();
}
void Textgrafs::add_border(const Pixel & p, int px, int py, int sizex, int sizey){
  for(int y = py; y < py+sizey+1; ++y){
    for(int x = px; x < px+sizex+1; ++x){
      if(x == px || y == py || x == px+sizex || y == py+sizey){
	add_pixel(p, x, y);
      }
    }
  }
}
/*
void Textgrafs::add_gameobject(Gameobject & g, int key){
  if(objects.count(key) == 0){
    objects[key] = g;
  }
  else{
    objects.erase(key);
    objects[key] = g;
  }
}
void Textgrafs::remove_gameobject(int key){
  if(objects.count(key) == 1){
    objects.erase(key);
  }
}
*/
