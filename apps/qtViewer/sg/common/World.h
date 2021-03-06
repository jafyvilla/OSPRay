// ======================================================================== //
// Copyright 2009-2015 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

#include "sg/common/Node.h"
#include "sg/common/Serialization.h"
#include "sg/camera/Camera.h"

namespace ospray {
  namespace sg {

    /*! a world node */
    struct World : public sg::Node {
      World() : ospModel(NULL) {};

      /*! \brief returns a std::string with the c++ name of this class */
      virtual    std::string toString() const { return "ospray::viewer::sg::World"; }

      //! serialize into given serialization state 
      virtual void serialize(sg::Serialization::State &serialization);

      std::vector<Ref<Node> > node;

      OSPModel ospModel;
      /*! 'render' the object for the first time */
      virtual void render(RenderContext &ctx);

      /*! \brief return bounding box in world coordinates.

        This function can be used by the viewer(s) for calibrating
        camera motion, setting default camera position, etc. Nodes
        for which that does not apply can simpy return
        box3f(embree::empty) */
      virtual box3f getBounds();

      template<typename T>
      inline void add(const Ref<T> &t) { add(t.ptr); }
      template<typename T>
      inline void add(T *t) { node.push_back(t); }
    };
      
    
  } // ::ospray::sg
} // ::ospray


