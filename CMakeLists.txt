#*********************************************************************
# Software License Agreement (BSD License)
#
#  Copyright (c) 2016, 2017 Centre National de la Recherche Scientifique
#  All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#   * Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#   * Redistributions in binary form must reproduce the above
#     copyright notice, this list of conditions and the following
#     disclaimer in the documentation and/or other materials provided
#     with the distribution.
#   * Neither the name of the Willow Garage nor the names of its
#     contributors may be used to endorse or promote products derived
#     from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
#  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
#  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
#  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
#  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
#  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
#  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
#  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
#  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#  POSSIBILITY OF SUCH DAMAGE.
#
# Author: Florent Lamiraux

cmake_minimum_required (VERSION 2.6)

include (cmake/base.cmake)
include (cmake/python.cmake)

findpython ()

set (PROJECT_NAME ros-compat)
set (PROJECT_DESCRIPTION
  "Implement base functions from ROS to avoid depending on ROS"
  )
set (PROJECT_URL "")

setup_project ()

add_required_dependency (tinyxml)

install (DIRECTORY include/console_bridge DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR})
install (DIRECTORY include/ros DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install (FILES
  python/rospkg/__init__.py
  python/rospkg/rospack.py
  DESTINATION ${PYTHON_SITELIB}/rospkg
  )

setup_project_finalize ()
