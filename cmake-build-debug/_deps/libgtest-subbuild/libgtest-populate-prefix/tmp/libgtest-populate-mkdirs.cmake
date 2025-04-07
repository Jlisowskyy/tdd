# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/Jlisowskyy/storage/shit/io2/cmake-build-debug/_deps/libgtest-src")
  file(MAKE_DIRECTORY "/home/Jlisowskyy/storage/shit/io2/cmake-build-debug/_deps/libgtest-src")
endif()
file(MAKE_DIRECTORY
  "/home/Jlisowskyy/storage/shit/io2/cmake-build-debug/_deps/libgtest-build"
  "/home/storage/shit/io2/cmake-build-debug/_deps/libgtest-subbuild/libgtest-populate-prefix"
  "/home/storage/shit/io2/cmake-build-debug/_deps/libgtest-subbuild/libgtest-populate-prefix/tmp"
  "/home/storage/shit/io2/cmake-build-debug/_deps/libgtest-subbuild/libgtest-populate-prefix/src/libgtest-populate-stamp"
  "/home/storage/shit/io2/cmake-build-debug/_deps/libgtest-subbuild/libgtest-populate-prefix/src"
  "/home/storage/shit/io2/cmake-build-debug/_deps/libgtest-subbuild/libgtest-populate-prefix/src/libgtest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/storage/shit/io2/cmake-build-debug/_deps/libgtest-subbuild/libgtest-populate-prefix/src/libgtest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/storage/shit/io2/cmake-build-debug/_deps/libgtest-subbuild/libgtest-populate-prefix/src/libgtest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
