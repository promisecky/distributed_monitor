#!/usr/bin/env bash
###
 # @Author: ChengKeyi
 # @Date: 2024-03-11 12:53:28
 # @LastEditors: ChengKeyi
 # @LastEditTime: 2024-03-11 20:34:57
 # @FilePath: /Desktop/monitor/docker/build/install/protobuf/install_protobuf.sh
 # @Description: 
### 

cd $(dirname ${BASH_SOURCE[0]})
VERSION=3.14.0
PACK_NAME=protobuf-${VERSION}.tar.gz
THREAD_MUM=$(nproc)
tar -zxf ${PACK_NAME}

pushd protobuf-${VERSION}
    mkdir -p cmake/build && cd cmake/build
    cmake .. \
            -DBUILD_SHARED_LIBS=ON \
            -DCMAKE_CXX_STANDARD=14 \
            -DCMAKE_INSTALL_PREFIX=/usr/local \
            -Dprotobuf_BUILD_TESTS=OFF
    make -j${THREAD_MUM}
    make install
popd
ldconfig

rm -rf protobuf-${VERSION}

