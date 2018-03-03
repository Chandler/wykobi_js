/*
(***********************************************************************)
(*                                                                     *)
(* Wykobi Computational Geometry Library                               *)
(* Release Version 0.0.5                                               *)
(* http://www.wykobi.com                                               *)
(* Copyright (c) 2005-2017 Arash Partow, All Rights Reserved.          *)
(*                                                                     *)
(* The Wykobi computational geometry library and its components are    *)
(* supplied under the terms of the General Wykobi License agreement.   *)
(* The contents of the Wykobi computational geometry library and its   *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of that agreement.                                        *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/


#include <iostream>
#include <vector>
#include "wykobi.hpp"
#include "wykobi_utilities.hpp"
#include <emscripten/emscripten.h>
#include <numeric>
#include <string>

#ifdef __cplusplus
extern "C" {
#endif

/*
Javascript bindings for some wykobi C++ methods


*/

const char* EMSCRIPTEN_KEEPALIVE segmentTriangleIntersect(
   double segmentx1,
   double segmenty1,
   double segmentx2,
   double segmenty2,
   double triAx,
   double triAy,
   double triBx,
   double triBy,
   double triCx,
   double triCy){

   typedef double T;

   wykobi::segment<T,2> segment = wykobi::make_segment(segmentx1,segmenty1,segmentx2,segmenty2);
   wykobi::triangle <T,2> triangle  = wykobi::make_triangle(triAx,triAy,triBx,triBy,triCx,triCy);

   std::vector<std::string> clipped_segment_list;

   wykobi::segment<T,2> clipped_segment;
   if (wykobi::clip(segment, triangle, clipped_segment)){
      for (std::size_t i = 0; i < clipped_segment.size(); i++){
         clipped_segment_list.push_back(std::to_string(clipped_segment[i].x));
         clipped_segment_list.push_back(std::to_string(clipped_segment[i].y));
      }
   }
   std::string s;
   for (const auto &piece : clipped_segment_list){
       s += piece;
       s += ",";
   }
   return s.c_str();
}

#ifdef __cplusplus
}
#endif