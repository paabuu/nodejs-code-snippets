cmd_Makefile := cd ..; /usr/local/lib/node_modules/node-gyp/gyp/gyp_main.py -fmake --ignore-environment "--toplevel-dir=." -I/Users/yangwenjie/Desktop/nodejs-mini-program/N-API/build/config.gypi -I/usr/local/lib/node_modules/node-gyp/addon.gypi -I/Users/yangwenjie/.node-gyp/10.10.0/include/node/common.gypi "--depth=." "-Goutput_dir=." "--generator-output=build" "-Dlibrary=shared_library" "-Dvisibility=default" "-Dnode_root_dir=/Users/yangwenjie/.node-gyp/10.10.0" "-Dnode_gyp_dir=/usr/local/lib/node_modules/node-gyp" "-Dnode_lib_file=/Users/yangwenjie/.node-gyp/10.10.0/<(target_arch)/node.lib" "-Dmodule_root_dir=/Users/yangwenjie/Desktop/nodejs-mini-program/N-API" "-Dnode_engine=v8" binding.gyp