/*
Copyright (c) 2013-2020 Ubidots.
Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:
The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
Developed and maintained by Jose Garcia and Cristian Arrieta for IoT Services
Inc
@jotathebest at github: https://github.com/jotathebest
@crisap94 at github: https://github.com/crisap94
*/

#include "UbiUdp.h"

/**************************************************************************
 * Overloaded constructors
 ***************************************************************************/

UbiUDP::UbiUDP(const char *host, const int port, const char *user_agent, const char *token) {
  _host = host;
  _user_agent = user_agent;
  _token = token;
  _port = port;
}

/**************************************************************************
 * Destructor
 ***************************************************************************/

UbiUDP::~UbiUDP() {
  delete[] _host;
  delete[] _user_agent;
  delete[] _token;
  _client_udp_ubi.flush();
  _client_udp_ubi.stop();
}

bool UbiUDP::sendData(const char *device_label, const char *device_name, char *payload) {
  /* Sends data to Ubidots */
  _client_udp_ubi.begin(UBIDOTS_TCP_PORT);
  bool dataSent = (bool)_client_udp_ubi.beginPacket(UBI_INDUSTRIAL, UBIDOTS_TCP_PORT);
  int i = 0;
  while (payload[i] != 0) {
    if (i > MAX_BUFFER_SIZE) {
      if (_debug) {
        Serial.print(F("Datagram max length exceed, please split your data"));
      }
      break;
    }
    dataSent = dataSent && (bool)_client_udp_ubi.write((uint8_t)payload[i++]);
  }
  dataSent = dataSent && (bool)_client_udp_ubi.endPacket();

  _client_udp_ubi.stop();

  return dataSent;
}

double UbiUDP::get(const char *device_label, const char *variable_label) { return ERROR_VALUE; }

/**
 * Makes available debug traces
 */

void UbiUDP::setDebug(bool debug) { _debug = debug; }

/*
 * Checks if the socket is still opened with the Ubidots Server
 */

bool UbiUDP::serverConnected() {
  Serial.println(F("This method is not supported using UDP"));
  return false;
}
