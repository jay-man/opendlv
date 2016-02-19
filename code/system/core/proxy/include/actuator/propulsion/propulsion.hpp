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

#ifndef ACTUATOR_PROPULSION_PROPULSION_HPP_
#define ACTUATOR_PROPULSION_PROPULSION_HPP_

#include <memory>

#include "core/base/module/DataTriggeredConferenceClientModule.h"
#include "core/data/Container.h"

namespace opendlv {
namespace proxy {
namespace actuator {
namespace propulsion {

class Device;

/**
 * This class provides...
 */
class Propulsion : 
    public core::base::module::DataTriggeredConferenceClientModule {
  public:
    Propulsion(int32_t const &, char **);
    Propulsion(Propulsion const &) = delete;
    Propulsion &operator=(Propulsion const &) = delete;
    virtual ~Propulsion();
    virtual void nextContainer(core::data::Container &);

  private:
    void setUp();
    void tearDown();

    std::unique_ptr<Device> m_device;
};

} // propulsion
} // actuator
} // proxy
} // opendlv

#endif
