#!/usr/bin/env bash
###
 # @Author: ChengKeyi
 # @Date: 2024-03-11 11:17:05
 # @LastEditors: ChengKeyi
 # @LastEditTime: 2024-03-11 20:02:38
 # @FilePath: /Desktop/monitor/docker/build/install/grpc/install_grpc.sh
 # @Description: 
### 

set -e

cd  $(dirname ${BASH_SOURCE[0]})

VERSION="1.30.0"
PACK_NAME=grpc-${VERSION}.tar.gz
THREAD_MUM=$(nproc)

tar -zxf ${PACK_NAME}

pushd grpc-${VERSION}
    mkdir -p build && cd build
    cmake .. -DgRPC_INSTALL=ON                \
             -DBUILD_SHARED_LIBS=ON            \
             -DCMAKE_BUILD_TYPE=Release       \
             -DgRPC_ABSL_PROVIDER=package     \
             -DgRPC_CARES_PROVIDER=package    \
             -DgRPC_PROTOBUF_PROVIDER=package \
             -DgRPC_RE2_PROVIDER=package      \
             -DgRPC_SSL_PROVIDER=package      \
             -DgRPC_ZLIB_PROVIDER=package     \
             -DCMAKE_INSTALL_PREFI=/usr/local/
    make -j${THREAD_MUM}
    make install 
popd


ldconfig

rm -rf grpc-${VERSION}
