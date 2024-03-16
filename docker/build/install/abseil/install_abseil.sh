#!/usr/bin/env bash
cd  "$(dirname ${BASH_SOURCE[0]})"
VERSION=20200225
PACK_NAME=abseil-cpp-${VERSION}.tar.gz
THREAD_MUM=$(nproc)
tar -zxf abseil-cpp-${VERSION}.tar.gz
pushd abseil-cpp-${VERSION}
    mkdir -p build && cd build
    cmake .. -DABSL_BUILD_TESTING=ON \
             -DABSL_USE_GOOGLETEST_HEAD=ON \
             -DBUILD_SHARED_LIBS=ON
             -DCMAKE_CXX_STANDARD=14 \
             -DCMAKE_INSTALL_PREFI=usr/local/
    make -j${THREAD_MUM}
    make install
popd

ldconfig

rm -rf abseil-cpp-${VERSION}

