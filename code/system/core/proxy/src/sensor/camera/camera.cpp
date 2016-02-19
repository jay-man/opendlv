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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <ctype.h>
#include <cstring>
#include <cmath>
#include <iostream>

#include "core/base/KeyValueConfiguration.h"
#include "core/data/Container.h"
#include "core/data/TimeStamp.h"

#include "GeneratedHeaders_OpenDLVData.h"

#include "sensor/camera/camera.hpp"
#include "sensor/camera/device.hpp"

namespace opendlv {
namespace proxy {
namespace sensor {
namespace camera {

/**
  * Constructor.
  *
  * @param a_argc Number of command line arguments.
  * @param a_argv Command line arguments.
  */
Camera::Camera(int32_t const &a_argc, char **a_argv) :
    TimeTriggeredConferenceClientModule(a_argc, a_argv, "proxy-sensor-camera"),
    m_device()
{
}

Camera::~Camera() 
{
}

// This method will do the main data processing job.
coredata::dmcp::ModuleExitCodeMessage::ModuleExitCode Camera::body()
{
  return coredata::dmcp::ModuleExitCodeMessage::OKAY;
}

void Camera::setUp() 
{
  core::base::KeyValueConfiguration kv = getKeyValueConfiguration();

  std::string const type = kv.getValue<std::string>("proxy-sensor-camera.type");
/*  std::string const port = kv.getValue<std::string>("proxy-sensor-camera.port");
  std::string const resolution = kv.getValue<std::string>("proxy-sensor-camera.resolution");
  float const mountX = kv.getValue<float>("proxy-sensor-camera.mount.x");
  float const mountY = kv.getValue<float>("proxy-sensor-camera.mount.y");
  float const mountZ = kv.getValue<float>("proxy-sensor-camera.mount.z");
  float const mountRoll = kv.getValue<float>("proxy-sensor-camera.mount.roll");
  float const mountPitch = kv.getValue<float>("proxy-sensor-camera.mount.pitch");
  float const mountYaw = kv.getValue<float>("proxy-sensor-camera.mount.yaw");
*/
  if (type.compare("axis-opencv") == 0) {
//      m_device = std::unique_ptr<Device>(
//          new OpenCvDevice(NAME, ID, WIDTH, HEIGHT, BPP));
  }

  if (m_device.get() == nullptr) {
    std::cerr << "[proxy-sensor-camera] No valid device driver defined." 
        << std::endl;
  }
}

void Camera::tearDown() 
{
}

} // camera
} // sensor
} // proxy
} // opendlv
