/**
 * Copyright (C) 2015 Chalmers REVERE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */

#ifndef SCENE_SCENE_HPP_
#define SCENE_SCENE_HPP_

#include <memory>
#include <ctype.h>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

#include "opendavinci/odcore/data/Container.h"
#include "opendavinci/odcore/data/TimeStamp.h"
#include "opendlvdata/GeneratedHeaders_opendlvdata.h"

#include "opendavinci/odcore/base/module/DataTriggeredConferenceClientModule.h"
#include "opendavinci/odcore/data/Container.h"

namespace opendlv {
namespace knowledge {
namespace scene {

/**
 * This class provides...
 */
class Scene : public odcore::base::module::DataTriggeredConferenceClientModule {
 public:
  Scene(int32_t const &, char **);
  Scene(Scene const &) = delete;
  Scene &operator=(Scene const &) = delete;
  virtual ~Scene();
  virtual void nextContainer(odcore::data::Container &);

 private:
  void setUp();
  void tearDown();
  void SendObjects();
  double PointDistance(float a_angle1, double a_dist1, float a_angle2, double a_dist2);
  void MergeObjects(opendlv::perception::Object a_object, uint32_t a_index);
  void TimeCheck();

  std::vector<opendlv::perception::Surface> m_savedSurfaces;
  std::vector<opendlv::perception::Object> m_savedObjects;
  uint32_t m_objectCounter;
};

} // scene
} // knowledge
} // opendlv

#endif
