/**
 * Copyright (C) 2017 Chalmers Revere
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

#ifndef LOGIC_SENSATION_DIRECTIONOFMOVEMENT_DIRECTIONOFMOVEMENT_HPP
#define LOGIC_SENSATION_DIRECTIONOFMOVEMENT_DIRECTIONOFMOVEMENT_HPP

#include <memory>
#include <Eigen/Dense>

#include "opendavinci/odcore/base/module/DataTriggeredConferenceClientModule.h"
#include "opendavinci/odcore/data/Container.h"

#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

namespace opendlv {
namespace logic {
namespace sensation {

class DirectionOfMovement
: public odcore::base::module::DataTriggeredConferenceClientModule {
 public:
  DirectionOfMovement(int32_t const &, char **);
  DirectionOfMovement(DirectionOfMovement const &) = delete;
  DirectionOfMovement &operator=(DirectionOfMovement const &) = delete;
  virtual ~DirectionOfMovement();
  virtual void nextContainer(odcore::data::Container &);

 private:
  void setUp();
  void tearDown();

  void SendContainer();

  Eigen::VectorXd m_foePix;
  Eigen::VectorXd m_foeWorld;
  Eigen::MatrixXd m_pixel2World;
  cv::Mat m_image;
};

}
}
}

#endif
