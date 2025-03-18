cmake_minimum_required(VERSION 3.10)
project(base_types)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Find SISL
find_path(SISL_INCLUDE_DIR sisl.h PATHS /usr/local/include)
find_library(SISL_LIBRARY sisl PATHS /usr/local/lib)
if (NOT SISL_INCLUDE_DIR OR NOT SISL_LIBRARY)
    message(FATAL_ERROR "SISL not found. Please install SISL and provide paths.")
endif()

find_package(Eigen3 REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(BASE_LOGGING REQUIRED base_logging)

find_package(Boost COMPONENTS system filesystem REQUIRED)

# Define header and source files
set(BASE_HEADERS_SRC
    src/Acceleration.hpp
    src/Angle.hpp
    src/CircularBuffer.hpp
    src/Deprecated.hpp
    src/Eigen.hpp
    src/Float.hpp
    src/JointLimitRange.hpp
    src/JointLimits.hpp
    src/JointState.hpp
    src/JointsTrajectory.hpp
    src/JointTransform.hpp
    src/Logging.hpp
    src/LogMessage.hpp
    src/Matrix.hpp
    src/NamedVector.hpp
    src/Point.hpp
    src/Pose.hpp
    src/Pressure.hpp
    src/RigidBodyStateSE3.hpp
    src/Singleton.hpp
    src/Temperature.hpp
    src/Time.hpp
    src/TimeMark.hpp
    src/Timeout.hpp
    src/TransformWithCovariance.hpp
    src/Twist.hpp
    src/TwistWithCovariance.hpp
    src/Waypoint.hpp
    src/Wrench.hpp
    src/Spline.hpp
    src/Trajectory.hpp
)

set(BASE_HEADERS_COMMANDS
    src/commands/Joints.hpp
    src/commands/Motion2D.hpp
    src/commands/Speed6D.hpp
    src/commands/LinearAngular6DCommand.hpp
)

set(BASE_HEADERS_LOGGING
    src/logging/logging_iostream_style.h
    src/logging/logging_printf_style.h
)

set(BASE_HEADERS_SAMPLES
    src/samples/Acceleration.hpp
    src/samples/BoundingBox.hpp
    src/samples/BodyState.hpp
    src/samples/CommandSamples.hpp
    src/samples/DepthMap.hpp
    src/samples/DistanceImage.hpp
    src/samples/Frame.hpp
    src/samples/IMUSensors.hpp
    src/samples/Joints.hpp
    src/samples/LaserScan.hpp
    src/samples/OrientedBoundingBox.hpp
    src/samples/Pointcloud.hpp
    src/samples/Pressure.hpp
    src/samples/RigidBodyAcceleration.hpp
    src/samples/RigidBodyState.hpp
    src/samples/RigidBodyStateSE3.hpp
    src/samples/RigidBodyStateSE3Vector.hpp
    src/samples/Sonar.hpp
    src/samples/SonarBeam.hpp
    src/samples/SonarScan.hpp
    src/samples/PoseWithCovariance.hpp
    src/samples/Twist.hpp
    src/samples/Temperature.hpp
    src/samples/Wrench.hpp
    src/samples/Wrenches.hpp
    src/samples/Event.hpp
    src/samples/EventArray.hpp
)

set(BASE_HEADERS_TEMPLATES
    src/templates/TimeStamped.hpp
)

set(BASE_SOURCES_SRC
    src/Acceleration.cpp
    src/Angle.cpp
    src/JointLimitRange.cpp
    src/JointLimits.cpp
    src/JointState.cpp
    src/JointsTrajectory.cpp
    src/JointTransform.cpp
    src/Pose.cpp
    src/Pressure.cpp
    src/RigidBodyStateSE3.cpp
    src/Temperature.cpp
    src/Time.cpp
    src/TimeMark.cpp
    src/Timeout.cpp
    src/TransformWithCovariance.cpp
    src/Twist.cpp
    src/TwistWithCovariance.cpp
    src/Waypoint.cpp
    src/Wrench.cpp
    src/Spline.cpp
    src/Trajectory.cpp
)

set(BASE_SOURCES_COMMANDS
    src/commands/Motion2D.cpp
)

set(BASE_SOURCES_SAMPLES
    src/samples/BodyState.cpp
    src/samples/BoundingBox.cpp
    src/samples/DepthMap.cpp
    src/samples/DistanceImage.cpp
    src/samples/Frame.cpp
    src/samples/Joints.cpp
    src/samples/LaserScan.cpp
    src/samples/OrientedBoundingBox.cpp
    src/samples/PoseWithCovariance.cpp
    src/samples/Pressure.cpp
    src/samples/RigidBodyAcceleration.cpp
    src/samples/RigidBodyState.cpp
    src/samples/Sonar.cpp
    src/samples/SonarBeam.cpp
    src/samples/SonarScan.cpp
    src/samples/Temperature.cpp
)

# Create the shared library
add_library(base_types SHARED
    ${BASE_SOURCES_SRC}
    ${BASE_SOURCES_COMMANDS}
    ${BASE_SOURCES_SAMPLES}
)

# Include directories
target_include_directories(base_types PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${BOOST_INCLUDEDIR}
    ${BASE_LOGGING_INCLUDE_DIRS}
    ${SISL_INCLUDE_DIR}
)

# ignores warnings caused by third-party library Eigen3
target_include_directories(base_types SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIR})

# Link with dependencies
target_link_libraries(base_types PRIVATE ${BASE_LOGGING_LIBRARIES})
target_link_libraries(base_types PUBLIC
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY}
    ${SISL_LIBRARY}
)

# Enable all warnings for space-qualification
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -Wconversion -Wsign-conversion -Wshadow -Wfloat-equal -Wnull-dereference -Wformat -Wcast-align -Wpointer-arith -Wunused-result")

# Generate and install pkg-config files
configure_file(base_types.pc.in ${CMAKE_BINARY_DIR}/base_types.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/base_types.pc DESTINATION lib/pkgconfig)

# Install headers
install(FILES ${BASE_HEADERS_SRC} DESTINATION include/base-types/)
install(FILES ${BASE_HEADERS_COMMANDS} DESTINATION include/base-types/commands/)
install(FILES ${BASE_HEADERS_LOGGING} DESTINATION include/base-types/logging/)
install(FILES ${BASE_HEADERS_SAMPLES} DESTINATION include/base-types/samples/)
install(FILES ${BASE_HEADERS_TEMPLATES} DESTINATION include/base-types/templates/)

# Install library
install(TARGETS base_types DESTINATION lib)
