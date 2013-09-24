# sanity-benchmark

A simple benchmark of disk and CPU performance intended to check whether a VPS is receiving adequate resources. Compare results from your VPS to those on your Mac or Linux box. They should be within an order of magnitude. Not intended as a serious benchmark for comparison of CPUs or operating systems.

    make sanity-benchmark
    ./sanity-benchmark

If you get errors your server probably isn't set up to compile C code.

On Ubuntu:

    sudo apt-get install build-essential

On a Mac:

[Install xcode](https://developer.apple.com/xcode/).
