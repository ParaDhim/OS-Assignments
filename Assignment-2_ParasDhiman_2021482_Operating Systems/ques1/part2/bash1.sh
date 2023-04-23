#! /bin/bash
# echo bash1
cd ..
cd meth_lab/linux-6.0.3
make -j$(nproc)
make modules
make modules_install