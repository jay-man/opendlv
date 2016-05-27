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

#include <ctype.h>
#include <cstring>
#include <cmath>
#include <iostream>

#include "opendavinci/odcore/base/KeyValueConfiguration.h"
#include "opendavinci/odcore/data/Container.h"
#include "opendavinci/odcore/data/TimeStamp.h"

#include "opendlvdata/GeneratedHeaders_opendlvdata.h"

#include "ledstrip/ledstrip.hpp"
#include "ledstrip/device.hpp"

namespace opendlv {
namespace proxy {
namespace ledstrip {


using namespace std;

// We add some of OpenDaVINCI's namespaces for the sake of readability.
using namespace odcore;
using namespace odcore::wrapper;

/**
  * Constructor.
  *
  * @param a_argc Number of command line arguments.
  * @param a_argv Command line arguments.
  */
Ledstrip::Ledstrip(int32_t const &a_argc, char **a_argv)
    : DataTriggeredConferenceClientModule(
      a_argc, a_argv, "proxy-ledstrip")
    , m_device()
{
}

Ledstrip::~Ledstrip()
{
}

// This method will do the main data processing job.
odcore::data::dmcp::ModuleExitCodeMessage::ModuleExitCode Ledstrip::body()
{

  while (getModuleStateAndWaitForRemainingTimeInTimeslice() 
      == odcore::data::dmcp::ModuleStateMessage::RUNNING) { 

    const string SERIAL_PORT = "/dev/ttyACM0";
    const uint32_t BAUD_RATE = 9600;

    // We are using OpenDaVINCI's std::shared_ptr to automatically
    // release any acquired resources.
    try {
        std::shared_ptr<SerialPort> serial(SerialPortFactory::createSerialPort(SERIAL_PORT, BAUD_RATE));

        serial->send("Hello World\r\n");
    }
    catch(string &exception) {
        cerr << "Serial port could not be created: " << exception << endl;
    }

  }

  return odcore::data::dmcp::ModuleExitCodeMessage::OKAY;
}

void Ledstrip::nextContainer(odcore::data::Container &)
{
}

void Ledstrip::setUp()
{
  odcore::base::KeyValueConfiguration kv = getKeyValueConfiguration();

  std::string const type =
  kv.getValue<std::string>("proxy-ledstrip.type");
  /*  std::string const port = kv.getValue<std::string>(
   *      "proxy-ledstrip.port");
  */
  if (type.compare("victor") == 0) {
    //      m_device = std::unique_ptr<Device>(new VictorDevice());
  }

  // if (m_device.get() == nullptr) {
  //   std::cerr << "[proxy-ledstrip] No valid device driver defined."
  //             << std::endl;
  // }
}

void Ledstrip::tearDown()
{
}

} // ledstrip
} // proxy
} // opendlv
