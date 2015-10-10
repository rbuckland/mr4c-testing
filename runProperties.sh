#!/bin/bash

export MR4C_SITE=./site.json;
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:$PWD/lib

set -e

mr4c_hadoop_remote ./properties.json -Htasks=3 -Hcores.min=1 -Hcores.max=2 -Hmemory.min=1024 -Hmemory.max=2048