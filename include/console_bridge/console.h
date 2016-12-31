/*********************************************************************
* Software License Agreement (BSD License)
*
*  Copyright (c) 2008, Willow Garage, Inc.
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of the Willow Garage nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/

/* Author: Ryan Luna, Ioan Sucan */

#ifndef URDFDOM_HEADERS_CONSOLE_HH
# define URDFDOM_HEADERS_CONSOLE_HH

# include <cstdio>
# include <sstream>
# include <cstdarg>

# define CONSOLE_BRIDGE_logError(...) ros::console::logError (__FILE__, __LINE__, ##__VA_ARGS__)
# define CONSOLE_BRIDGE_logDebug(...)
# define CONSOLE_BRIDGE_logInform(...)
# define MAX_BUFFER_SIZE 1024

namespace ros {
  namespace console {
    inline const char* logError (const char *file, int line, const char* m, ...)
    {
      va_list __ap;
      va_start(__ap, m);
      char* buf (new char [MAX_BUFFER_SIZE]);
      vsnprintf(buf, sizeof(buf), m, __ap);
      va_end(__ap);
      buf[MAX_BUFFER_SIZE - 1] = '\0';
      return buf;
    }
  } // namespace console
} // namespace ros

#endif // URDFDOM_HEADERS_CONSOLE_HH
