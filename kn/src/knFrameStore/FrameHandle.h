/* -*- C++ -*- *****************************************************************
 * Copyright (c) 2013 United States Government as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.

******************************************************************************/
#ifndef kn_FrameHandle_h
#define kn_FrameHandle_h

#include "knFrameStore_Export.h"

namespace kn
{
  // forward declaration
  class FrameStore;
  class Frame;
  template<typename P> class TreeNode;
  typedef TreeNode<Frame> FrameTreeNode;
  
  /**
   * @ingroup knFrameStore
   * @brief Handle to a frame tree node stored in a frame-store.
   * 
   * This opaque handle internallly implements a pointer into the FrameTree managed by 
   * the @ref FrameStore. A Frameandle stays valid unless the frame itself or the 
   * managing @ref FrameStore is deleted.
   */
  class knFrameStore_Export FrameHandle
  {
    FrameTreeNode * node;
  public:
    /**
     * @brief  Default constructor.
     * 
     * Initializes itself to the NULL handle.
     */
    FrameHandle() : node(0) {}
    /**
     * @brief Initializing constructor.
     * 
     */
    FrameHandle(FrameTreeNode * n) :
      node(n) {}
      
    bool operator==(FrameHandle const& rhs) const {
      return this->node == rhs.node;
    }
    bool operator!=(FrameHandle const& rhs) const {
      return this->node != rhs.node;
    }
    
    /**
     * @brief A static instance to a NULL handle, for reference.
     */
    static FrameHandle const NULL_HANDLE;
    
    /**
     * @brief Check if handle is initialized.
     * @return true if handle is not null
     */
    inline bool isValid() const {
      return *this != NULL_HANDLE;
    }

    friend class FrameStore;
  };
}

#endif // kn_FrameHandle_h
