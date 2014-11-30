-------------------------------------------------------------------------
Introduction
-------------------------------------------------------------------------

Omnes relinquite spes, o vos intrante.

Welcome to the README for Protonet.

Protonet is an exercise in unrestrained scope.
Protonet is a communication endpoint for sending and receiving messages

-------------------------------------------------------------------------
Platforms
-------------------------------------------------------------------------

------------------------
  API |     Platform   |
------------------------
  C#  |   C++/CLI      |
  C++ |   Unix/Windows |
  C   |   Unix/Windows |
------------------------

C#:
When this library is built as a DLL with /clr, it will default to a C# API.
The C# library can be referenced by C# code. Must have .NET 4.0 or greater.


C/C++
When compiled with a C++ compiler, both the C++ and C APIs will be exposed.
If compiled with a C compiler, then only the C API will be usable.
The library will then compiled based on the platform type (Unix or Windows)

-------------------------------------------------------------------------
Directories
-------------------------------------------------------------------------

/: 
root directory, where this README is located.

/build: 
build directory, organized by /OS/configuration/architecture.
Configuration denotes build variant, and architecture denotes platform.

For QNX, both debug and release variants are stored under /build/qnx/.

/protonet:
Contains the protonet static C/C++ library 
Source files and include files under /src and /include

/protosharp: 
Contains the example C# test program

/protowrapper:
Contains the C/C++ to C# .dll wrapper

-------------------------------------------------------------------------
Projects
-------------------------------------------------------------------------

A Visual Studio Solution file is included in the root directory
All projects can be built in VS2012 or greater (/protonet.sln).

For QNX, import the QNX project directory (/protonet) using
(General/Existing Projects into Workspace) under File/Import in Momentics.

Protonet:
A static library containing the communication endpoint code.
It is used for the C/C++ API, and can be compiled under Windows or POSIX.

Protowrapper:
A wrapper dll for exposing the protonet class to C#. 

Protosharp:
A test program for C# that demonstrates how to open a node, send messages,
establish datalinks, and handle received messages.

-------------------------------------------------------------------------
Modules
-------------------------------------------------------------------------

Protonet contains multiple modules denoted by header files:

cond.h:				POSIX/Windows condition variables
datalink.h:			Datalink abstraction layer
marshal.h:			Message serialization functions
irc.h:				IRC Protonet access
message.h:			General message serialization used by Protonet
protocol.h:			Contains all the message includes
mutex:				POSIX/Windows mutexes
protonet.h          Contains type, class and function declarations
protonet_parser.h:  Parser ring for Protonet frames
queue.h:			Messaging queue
serial.h			Serial driver
thread.h			Thread based functions
udp.h				UDP driver

-------------------------------------------------------------------------
Using Protonet in a Project
-------------------------------------------------------------------------
For C/C++

1. Add /protonet/include/protonet.h to the include path
2. Add the desired library (OS/variant/architecture) to the library path
3. Verify the header is included
4. Verify that the .lib or .a files are linked.

*for QNX, simply add the library and protonet.h to project properties

For C#

1. Add the protowrapper.dll as a reference
2. Ensure protonet.lib is in the same folder as protowrapper.dll
