#!/usr/bin/env bash
###
 # @Author: ChengKeyi
 # @Date: 2024-03-10 23:36:50
 # @LastEditors: ChengKeyi
 # @LastEditTime: 2024-03-15 11:07:02
 # @FilePath: /Desktop/monitor/docker/scripts/docker_run.sh
 # @Description: 
### 

MONITOR_HOME_DIR="$(cd "$(dirname ${BASH_SOURCE[0]})/../.." && pwd)"

display=""
if [ -z ${DISPLAY} ];then
    display=":1"
else
    display="${DISPLAY}"
fi

local_host="$(hostname)"
user="${USER}"
uid="$(id -u)"
group="$(id -g -n)"
gid="$(id -g)"


echo "stop and rm docker" 
docker stop learn_monitor > /dev/null
docker rm -v -f learn_monitor > /dev/null

echo "start docker"
docker run -it -d \
--name learn_monitor \
-e DISPLAY=$display \
-p 50001:50001 \
--privileged=true \
-e DOCKER_USER="${user}" \
-e USER="${user}" \
-e DOCKER_USER_ID="${uid}" \
-e DOCKER_GRP="${group}" \
-e DOCKER_GRP_ID="${gid}" \
-e XDG_RUNTIME_DIR=$XDG_RUNTIME_DIR \
-v ${MONITOR_HOME_DIR}:/work \
-v ${XDG_RUNTIME_DIR}:${XDG_RUNTIME_DIR} \
--net monitor \
learn_monitor:latest