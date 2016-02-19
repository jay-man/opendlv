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

#ifndef SENSOR_CAMERA_CAMERA_HPP_
#define SENSOR_CAMERA_CAMERA_HPP_

#include <memory>

#include "core/base/module/TimeTriggeredConferenceClientModule.h"
#include "core/data/Container.h"

namespace opendlv {
namespace proxy {
namespace sensor {
namespace camera {

class Device;

/**
 * This class provides...
 */
class Camera : public core::base::module::TimeTriggeredConferenceClientModule {
  public:
    Camera(int32_t const &, char **);
    Camera(Camera const &) = delete;
    Camera &operator=(Camera const &) = delete;
    virtual ~Camera();
    coredata::dmcp::ModuleExitCodeMessage::ModuleExitCode body();

  private:
    void setUp();
    void tearDown();

    std::unique_ptr<Device> m_device;
};

} // camera
} // sensor
} // proxy
} // opendlv

#endif
