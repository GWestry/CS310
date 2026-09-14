# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/workspaces/CS310/lab-1.2/build/_deps/yaml-cpp-src"
  "/workspaces/CS310/lab-1.2/build/_deps/yaml-cpp-build"
  "/workspaces/CS310/lab-1.2/build/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix"
  "/workspaces/CS310/lab-1.2/build/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix/tmp"
  "/workspaces/CS310/lab-1.2/build/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix/src/yaml-cpp-populate-stamp"
  "/workspaces/CS310/lab-1.2/build/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix/src"
  "/workspaces/CS310/lab-1.2/build/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix/src/yaml-cpp-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/workspaces/CS310/lab-1.2/build/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix/src/yaml-cpp-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/workspaces/CS310/lab-1.2/build/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix/src/yaml-cpp-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
