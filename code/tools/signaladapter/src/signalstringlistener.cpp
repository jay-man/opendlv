/**
 * Copyright (C) 2016 Chalmers REVERE
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

#include <cmath>

#include <bitset>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include <opendavinci/odcore/data/Container.h>

#include "odvdopendlvdata/GeneratedHeaders_ODVDOpenDLVData.h"

#include "samplebuffer.hpp"
#include "signalstringlistener.hpp"

namespace opendlv {
namespace tools {
namespace signaladapter {

SignalStringListener::SignalStringListener(odcore::io::conference::ContainerConference &a_conference)
    : m_conference(a_conference)
{
}

SignalStringListener::~SignalStringListener() 
{
}

void SignalStringListener::nextString(std::string const &a_string) 
{
  SampleBuffer buffer;
  buffer.AppendStringRaw(a_string);

  auto it = buffer.GetIterator();
  uint32_t messageId = it->ReadInteger32();

  switch (messageId) {
    case 160:
      {
        float acceleration = it->ReadFloat32();
        float steering = it->ReadFloat32();
        bool isValid = it->ReadBoolean();

        opendlv::proxy::ActuationRequest actuationRequest(acceleration, steering, isValid);
        odcore::data::Container actuationRequestContainer(actuationRequest);
        m_conference.send(actuationRequestContainer);

        break;
      }
    default:
      {
        std::cout << "Unknown message received (" << messageId << ")." << std::endl;
      }
  }
}

} // signaladapter
} // tools
} // opendlv