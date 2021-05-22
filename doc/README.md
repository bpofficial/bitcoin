Tangerine Core
=============

Setup
---------------------
Tangerine Core is the original Tangerine client and it builds the backbone of the network. It downloads and, by default, stores the entire history of Tangerine transactions, which requires a few hundred gigabytes of disk space. Depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more.

To download Tangerine Core, visit [tangerinecore.org](https://tangerinecore.org/en/download/).

Running
---------------------
The following are some helpful notes on how to run Tangerine Core on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/tangerine-qt` (GUI) or
- `bin/tangerined` (headless)

### Windows

Unpack the files into a directory, and then run tangerine-qt.exe.

### macOS

Drag Tangerine Core to your applications folder, and then run Tangerine Core.

### Need Help?

* See the documentation at the [Tangerine Wiki](https://en.tangerine.it/wiki/Main_Page)
for help and more information.
* Ask for help on [#tangerine](https://webchat.freenode.net/#tangerine) on Freenode. If you don't have an IRC client, use [webchat here](https://webchat.freenode.net/#tangerine).
* Ask for help on the [TangerineTalk](https://tangerinetalk.org/) forums, in the [Technical Support board](https://tangerinetalk.org/index.php?board=4.0).

Building
---------------------
The following are developer notes on how to build Tangerine Core on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [Dependencies](dependencies.md)
- [macOS Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows.md)
- [FreeBSD Build Notes](build-freebsd.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [NetBSD Build Notes](build-netbsd.md)
- [Android Build Notes](build-android.md)
- [Gitian Building Guide (External Link)](https://github.com/tangerine-core/docs/blob/master/gitian-building.md)

Development
---------------------
The Tangerine repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Productivity Notes](productivity.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://doxygen.tangerinecore.org/)
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [JSON-RPC Interface](JSON-RPC-interface.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Shared Libraries](shared-libraries.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)
- [Benchmarking](benchmarking.md)

### Resources
* Discuss on the [TangerineTalk](https://tangerinetalk.org/) forums, in the [Development & Technical Discussion board](https://tangerinetalk.org/index.php?board=6.0).
* Discuss project-specific development on #tangerine-core-dev on Freenode. If you don't have an IRC client, use [webchat here](https://webchat.freenode.net/#tangerine-core-dev).
* Discuss general Tangerine development on #tangerine-dev on Freenode. If you don't have an IRC client, use [webchat here](https://webchat.freenode.net/#tangerine-dev).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [tangerine.conf Configuration File](tangerine-conf.md)
- [Files](files.md)
- [Fuzz-testing](fuzzing.md)
- [Reduce Memory](reduce-memory.md)
- [Reduce Traffic](reduce-traffic.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)
- [ZMQ](zmq.md)
- [PSBT support](psbt.md)

License
---------------------
Distributed under the [MIT software license](/COPYING).
