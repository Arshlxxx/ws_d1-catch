#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/nvidia/ws_d1/src/easy_handeye/easy_handeye"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/nvidia/ws_d1/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/nvidia/ws_d1/install/lib/python3/dist-packages:/home/nvidia/ws_d1/build/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/nvidia/ws_d1/build" \
    "/usr/bin/python3" \
    "/home/nvidia/ws_d1/src/easy_handeye/easy_handeye/setup.py" \
    egg_info --egg-base /home/nvidia/ws_d1/build/easy_handeye/easy_handeye \
    build --build-base "/home/nvidia/ws_d1/build/easy_handeye/easy_handeye" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/nvidia/ws_d1/install" --install-scripts="/home/nvidia/ws_d1/install/bin"
