# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/terra/Desktop/Fall2023/CSE491/Blog/Blog_Range_v3/cmake-build-debug/_deps/range-v3-src"
  "/Users/terra/Desktop/Fall2023/CSE491/Blog/Blog_Range_v3/cmake-build-debug/_deps/range-v3-build"
  "/Users/terra/Desktop/Fall2023/CSE491/Blog/Blog_Range_v3/cmake-build-debug/_deps/range-v3-subbuild/range-v3-populate-prefix"
  "/Users/terra/Desktop/Fall2023/CSE491/Blog/Blog_Range_v3/cmake-build-debug/_deps/range-v3-subbuild/range-v3-populate-prefix/tmp"
  "/Users/terra/Desktop/Fall2023/CSE491/Blog/Blog_Range_v3/cmake-build-debug/_deps/range-v3-subbuild/range-v3-populate-prefix/src/range-v3-populate-stamp"
  "/Users/terra/Desktop/Fall2023/CSE491/Blog/Blog_Range_v3/cmake-build-debug/_deps/range-v3-subbuild/range-v3-populate-prefix/src"
  "/Users/terra/Desktop/Fall2023/CSE491/Blog/Blog_Range_v3/cmake-build-debug/_deps/range-v3-subbuild/range-v3-populate-prefix/src/range-v3-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/terra/Desktop/Fall2023/CSE491/Blog/Blog_Range_v3/cmake-build-debug/_deps/range-v3-subbuild/range-v3-populate-prefix/src/range-v3-populate-stamp/${subDir}")
endforeach()
