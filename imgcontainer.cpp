//A class container for ascii images
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <streambuf>
#include "imgcontainer.hpp"  
Img_container::Img_container(std::string filename){
    //std::ifstream f(filename.c_str());
    
    img_to_str_vector(filename, image_text);
}

std::vector<std::string> & Img_container::get_img_text(){
    return image_text;
}
void Img_container::print_img(){
  //Debug purposes
  for(unsigned int i = 0; i< image_text.size() ; ++i){
    std::cout << image_text[i] << std::endl;
  }
}

//img_txt
void Img_container::img_to_str_vector(std::string filename, std::vector<std::string> & im_text_ref){
    std::ifstream file(filename.c_str());
    //std::vector<std::string> img_text;
    std::string tempstr;
    int c = 0;
    while(std::getline(file, tempstr)){
      
      //idea
      //while len>12
      //std::vector<string> temp.append(first 12 of tmpstr)
      //When row is done 
      //img_txt.append(temp);
      //possibly add this extra \033[0m as a final "pixel" slot


      int size = 12; //Confirmed size
      while(tempstr.length() > 12){
	tempstr.erase(0,12);
	std::cout << tempstr.length() << std::endl;
      }
      std::cout << "-----------" << std::endl;
      for(int i = 0; i < tempstr.length(); ++i){
	std::cout << tempstr[i] << std::endl;
      }
      //What the fuck does /033[0m do?
      break;
      //The grid is y = height of screen
      //x = width of screen/2 
      //One "pixel" is an escape code followed by to spaces
      im_text_ref.push_back(tempstr);
    } 
    file.close();
  }
