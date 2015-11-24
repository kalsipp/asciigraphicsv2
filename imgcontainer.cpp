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
    std::cout << "done ";
    //std::cout << img_txt.size() << std::endl;
    //std::cout << img_txt[2].size() << std::endl;
    //std::cout << img_txt[0][0];
    int c = 0;
    for(int y = 0; y < img_txt.size(); ++y){
      //std::cout << "y " << y << std::endl;
      //std::cout << "ysize " << img_txt[y].size() << std::endl;
      for(int x = 0; x < img_txt[y].size(); ++x){
	//std::cout << "-------------" << std::endl;
	//for(int z = 0; z < img_txt[y][x].length(); ++z){
	//std::cout << img_txt[y][x][z] << std::endl;
	  std::cout << img_txt[y][x];
	++c;
	//  }
	//std::cout << "------------" << std::endl;
	//break;
      }
      std::cout << std::endl;
      //break;
    }
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
    std::vector<std::string> tempvec;
    std::string tempstr;
    int c = 0;
    while(std::getline(file, tempstr)){
      //tempvec.erase(tempvec.begin(), tempvec.end());
      std::vector<std::string> tempvec;
      while(tempstr.length() > 12){ // > smallest length
	int p = 0;
	std::string s;
	while(tempstr[0] != '@'){
	  s+= tempstr[0];
	  if(tempstr.length() == 0) break;
	  tempstr.erase(tempstr.begin());
	  ++p;
	  //std::cout << "STUCK";
	}
	//for(int i = 0; i < s.length() ; ++i) std::cout << s[i] << std::endl;
	
	tempvec.push_back(s);
	
	if(tempstr[0] == '@')tempstr.erase(tempstr.begin());
	  //tempvec.push_back(tempstr.substr(0, 12));
	//tempstr.erase(0,12);
	//std::cout <<tempstr.length() << std::endl;
	++c;
      }
      tempvec.push_back(tempstr);
      img_txt.push_back(tempvec);
    } 
    //std::cout << c << " pixels." << std::endl;
    file.close();
  }
